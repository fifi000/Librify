#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include <QObject>
#include <QString>

#include "Models/book_model.h"
#include "database_controller.h"
#include "enums.h"

class BookManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVector<BookModel *> Books READ Books WRITE setBooks NOTIFY BooksChanged)
  public:
    explicit BookManager(QObject *parent = nullptr);
    Q_INVOKABLE void addBook(QString title, QString author, QString description, QString coverPath, QString status);
    Q_INVOKABLE void updateBook(QString title, QString author, QString description, QString coverPath, QString status);
    Q_INVOKABLE void changeStatus(QString status);
    Q_INVOKABLE QString getStringStatus();

    QVector<BookModel *> Books() const;
    void setBooks(const QVector<BookModel *> &newBooks);
    ~BookManager();

  signals:

    void BooksChanged();

  private:
    BookModel *getBook(QString title, QString author, QString description, QString coverPath, QString status);
    QVector<BookModel *> m_Books;
    Status m_CurrentStatus;
    DatabaseController m_DbController;
};

#endif // BOOKMANAGER_H
