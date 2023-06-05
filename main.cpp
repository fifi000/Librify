#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <iostream>

#include "Controllers/Models/book_model.h"
#include "Controllers/book_manager.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    BookManager m_bookManager;
    m_bookManager.changeStatus("Reading");

    // default stuff
    // ====================================================
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);
    // ====================================================

    qmlRegisterType<BookModel>("test.test", 1, 0, "BookModel");

    QQmlContext *context(engine.rootContext());
    context->setContextProperty("BookManager", &m_bookManager);

    return app.exec();
}
