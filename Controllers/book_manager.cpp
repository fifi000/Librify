#include "book_manager.h"

#include <QDebug>
#include <QPainter>

BookManager::BookManager(QObject *parent) : QObject{parent}
{
    this->m_DbController = DatabaseController();
}

QImage createInfoCover(QString title, QString author)
{
    QImage coverImage(200, 300, QImage::Format_RGB32);
    coverImage.fill(Qt::white);

    QPainter painter(&coverImage);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw a rounded rectangle as the background
    QPen pen(Qt::black, 2);
    painter.setPen(pen);
    painter.setBrush(Qt::lightGray);
    painter.drawRoundedRect(10, 10, 180, 280, 10, 10);

    // Set font and color for title
    QFont titleFont("Arial", 16, QFont::Bold);
    painter.setFont(titleFont);
    painter.setPen(Qt::black);

    // Draw title centered horizontally with word wrap
    QRectF titleRect(20, 20, 160, 60);
    painter.drawText(titleRect, Qt::AlignCenter | Qt::TextWordWrap, title);

    // Set font and color for author
    QFont authorFont("Arial", 12);
    painter.setFont(authorFont);

    // Draw author centered horizontally below title with word wrap
    QRectF authorRect(20, 90, 160, 40);
    painter.drawText(authorRect, Qt::AlignCenter | Qt::TextWordWrap, author);

    return coverImage;
}

BookModel *BookManager::getBook(QString title, QString author, QString description, QString coverPath, QString status)
{
    BookModel *book = new BookModel();

    book->setTitle(title);
    book->setAuthor(author);
    book->setDescription(description);
    book->setReadingStatus(StatusConventer[status]);

    if (coverPath.startsWith("file:///"))
    {
        coverPath.remove("file:///");
    }

    QImage cover = coverPath.isEmpty() ? createInfoCover(title, author) : QImage(coverPath);

    book->setCover(cover);

    return book;
}

void BookManager::addBook(QString title, QString author, QString description, QString coverPath, QString status)
{
    BookModel *book = getBook(title, author, description, coverPath, status);

    this->m_DbController.CreateBook(*book);

    delete book;
}

void BookManager::updateBook(QString title, QString author, QString description, QString coverPath, QString status)
{
    BookModel *book = getBook(title, author, description, coverPath, status);

    this->m_DbController.UpdateBook(*book);

    delete book;
}

void BookManager::changeStatus(QString status)
{   
    if (StatusConventer.contains(status))
    {
        for (int i = 0; i < this->m_Books.count(); i++)
        {
            delete m_Books.at(i);
        }
        this->m_CurrentStatus = StatusConventer[status];
        setBooks(m_DbController.ReadByStatus(this->m_CurrentStatus));
    }
    else
    {
        qDebug() << "Status '" << status << "' not found.";
    }
}

QString BookManager::getStringStatus()
{
    for (auto it = StatusConventer.begin(); it != StatusConventer.end(); ++it)
    {
        if (it.value() == this->m_CurrentStatus)
        {
            return it.key();
        }
    }

    return "";
}

QVector<BookModel *> BookManager::Books() const
{
    return m_Books;
}

void BookManager::setBooks(const QVector<BookModel *> &newBooks)
{
    if (m_Books == newBooks)
        return;
    m_Books = newBooks;
    emit BooksChanged();
}

BookManager::~BookManager()
{
    for (int i = 0; i < this->m_Books.count(); i++)
    {
        delete m_Books.at(i);
    }
}
