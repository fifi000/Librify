#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include "Models/book_model.h"
#include <QSqlDatabase>

class DatabaseController
{
  public:
    DatabaseController();
    void CreateDatabase();
    void Create(const BookModel &model);
    QVector<BookModel *> ReadAll();
    QVector<BookModel *> ReadReading();
    QVector<BookModel *> ReadFinished();
    QVector<BookModel *> ReadToRead();
    void Update(const BookModel &model);
    void Delete(const BookModel &model);
};

#endif // DATABASECONTROLLER_H
