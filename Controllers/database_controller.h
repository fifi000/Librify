#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include <QSqlDatabase>

#include "Models/book_model.h"
#include "enums.h"

class DatabaseController
{
  public:
    DatabaseController();
    int CreateBook(const BookModel &model);
    QVector<BookModel *> ReadAll();
    QVector<BookModel *> ReadByStatus(Status readingStatus);

  private:
    void CreateTable();
};

#endif // DATABASECONTROLLER_H
