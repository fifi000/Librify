#include <QBuffer>
#include <QDebug>
#include <QDir>
#include <QImageWriter>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>

#include "database_controller.h"

DatabaseController::DatabaseController()
{
    QSqlDatabase db;

    // create db
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./librify.db");

    // open connection
    if (db.open() == false)
    {
        qDebug() << "Could not open connection";
    }

    // create table
    if (db.tables().contains("books") == false)
    {
        this->CreateTable();
    }
}

void DatabaseController::CreateTable()
{
    QSqlQuery query{QSqlDatabase::database()};

    QString sql = "CREATE TABLE IF NOT EXISTS books ("
                  "Id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "Title TEXT NOT NULL, "
                  "Author TEXT, "
                  "Description TEXT, "
                  "Cover BLOB, "
                  "ReadingStatus INT)";

    if (query.exec(sql) == false)
    {
        qDebug() << "Failed to create table: " << query.lastError().text();
    }
}

QByteArray imageToBlob(const QImage &img)
{
    QByteArray blob;
    QBuffer buffer(&blob);
    buffer.open(QIODevice::WriteOnly);

    // Determine the supported image formats
    QList<QByteArray> supportedFormats = QImageWriter::supportedImageFormats();

    // Try saving the image in each format until successful
    foreach (const QByteArray &format, supportedFormats)
    {
        QImageWriter writer(&buffer, format);
        writer.write(img);
        if (writer.error() == 0)
            break;               // Successfully saved in this format, exit the loop
        buffer.buffer().clear(); // Clear the buffer and try the next format
    }

    return blob;
}

int DatabaseController::CreateBook(const BookModel &bookModel)
{
    QSqlTableModel model(nullptr, QSqlDatabase::database());
    model.setTable("books");

    QSqlRecord record = model.record();
    record.setValue("Title", bookModel.Title());
    record.setValue("Author", bookModel.Author());
    record.setValue("Description", bookModel.Description());
    auto data = imageToBlob(bookModel.Cover());
    record.setValue("Cover", data);
    record.setValue("ReadingStatus", static_cast<int>(bookModel.ReadingStatus()));

    if (model.insertRecord(-1, record) == false)
    {
        qDebug() << "Unable to add book into table\n" << model.lastError().text();

        return -1;
    }

    return model.record(model.rowCount() - 1).value("Id").toInt();
}

QVector<BookModel *> DatabaseController::ReadAll()
{
    QVector<BookModel *> books;

    QSqlTableModel model(nullptr, QSqlDatabase::database());
    model.setTable("books");
    model.select();

    QSqlRecord record;
    BookModel *book{nullptr};
    for (int i = 0; i < model.rowCount(); i++)
    {
        book = new BookModel();
        record = model.record(i);

        book->setId(record.value("Id").toInt());
        book->setTitle(record.value("Title").toString());
        book->setAuthor(record.value("Author").toString());

        // check description
        auto description = record.value("Description");
        book->setDescription(description.isNull() ? "" : description.toString());

        book->setCover(QImage::fromData(record.value("Cover").toByteArray()));
        book->setReadingStatus(static_cast<Status>(record.value("ReadingStatus").toInt()));

        books.append(book);
    }

    return books;
}

QVector<BookModel *> DatabaseController::ReadByStatus(Status readingStatus)
{
    QVector<BookModel *> books;

    QSqlTableModel model(nullptr, QSqlDatabase::database());
    model.setTable("books");
    model.setFilter("ReadingStatus=" + QString::number(static_cast<int>(readingStatus)));
    model.select();

    QSqlRecord record;
    BookModel *book{nullptr};
    for (int i = 0; i < model.rowCount(); i++)
    {
        book = new BookModel();
        record = model.record(i);

        book->setId(record.value("Id").toInt());
        book->setTitle(record.value("Title").toString());
        book->setAuthor(record.value("Author").toString());
        book->setDescription(record.value("Description").toString());
        book->setCover(QImage::fromData(record.value("Cover").toByteArray()));
        book->setReadingStatus(static_cast<Status>(record.value("ReadingStatus").toInt()));

        books.append(book);
    }

    return books;
}

bool DatabaseController::UpdateBook(BookModel &model)
{
    QSqlTableModel table(nullptr, QSqlDatabase::database());
    table.setTable("books");
    table.setFilter("Id=" + QString::number(model.Id()));
    table.select();

    if (table.rowCount() != 1)
    {
        qDebug() << "Found " << table.rowCount() << "mathing rows with id = " << model.Id();
        return false;
    }

    QSqlRecord record = table.record(0);

    record.setValue("Id", model.Id());
    record.setValue("Title", model.Title());
    record.setValue("Author", model.Author());
    record.setValue("Description", model.Description());
    auto data = imageToBlob(model.Cover());
    record.setValue("Cover", data);
    record.setValue("ReadingStatus", static_cast<int>(model.ReadingStatus()));

    if (table.setRecord(0, record) == false)
    {
        qDebug() << "Unable to update book with ID " << model.Id() << "\n Error: " << table.lastError().text();

        return false;
    }

    return true;
}
