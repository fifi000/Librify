#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <iostream>

#include "Controllers/Models/book_model.h"

QVector<BookModel *> sampleBooks(int n)
{
    QVector<BookModel *> books;

    for (int i = 0; i < n; i++)
    {
        BookModel *book = new BookModel();
        book->setTitle("1984");
        book->setAuthor("G. Orwell");
        book->setCover(QImage(":/UI/assets/sample_cover.jpg"));
        book->setReadingStatus(Reading);
        books.append(book);
    }

    return books;
}

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QVector<BookModel *> m_books = sampleBooks(25);

    qmlRegisterType<BookModel>("test.test", 1, 0, "BookModel");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    QQmlContext *context(engine.rootContext());
    context->setContextProperty("Books", QVariant::fromValue(m_books));

    return app.exec();
}
