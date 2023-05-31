#include "book_model.h"
#include <QBuffer>
#include <QDebug>

BookModel::BookModel(QObject *parent)
    : QObject{parent}
{
}

QString BookModel::Title() const
{
    return m_Title;
}

void BookModel::setTitle(const QString &newTitle)
{
    if (m_Title == newTitle)
        return;
    m_Title = newTitle;
    emit TitleChanged();
}

QString BookModel::Author() const
{
    return m_Author;
}

void BookModel::setAuthor(const QString &newAuthor)
{
    if (m_Author == newAuthor)
        return;
    m_Author = newAuthor;
    emit AuthorChanged();
}

QString BookModel::Description() const
{
    return m_Description;
}

void BookModel::setDescription(const QString &newDescription)
{
    if (m_Description == newDescription)
        return;
    m_Description = newDescription;
    emit DescriptionChanged();
}

QImage BookModel::Cover() const
{
    return m_Cover;
}

void BookModel::setCover(const QImage &newCover)
{
    if (m_Cover == newCover)
        return;
    m_Cover = newCover;
    emit CoverChanged();
}

QString BookModel::Picture()
{
    QByteArray bArray;
    QBuffer buffer(&bArray);
    buffer.open(QIODevice::WriteOnly);
    this->m_Cover.save(&buffer, "JPG");

    QString image("data:image/jpg;base64," + QString::fromLatin1(bArray.toBase64().data()));

    return image;
}

Status BookModel::ReadingStatus() const
{
    return m_ReadingStatus;
}

void BookModel::setReadingStatus(Status newReadingStatus)
{
    if (m_ReadingStatus == newReadingStatus)
        return;
    m_ReadingStatus = newReadingStatus;
    emit ReadingStatusChanged();
}
