#ifndef BOOKMODEL_H
#define BOOKMODEL_H

#include <QObject>

class BookModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString Title READ Title WRITE setTitle NOTIFY TitleChanged)
    Q_PROPERTY(QString Author READ Author WRITE setAuthor NOTIFY AuthorChanged)
  public:
    explicit BookModel(QObject *parent = nullptr);

    QString Title() const;
    void setTitle(const QString &newTitle);

    QString Author() const;
    void setAuthor(const QString &newAuthor);

  signals:

    void TitleChanged();
    void AuthorChanged();

  private:
    QString m_Title;
    QString m_Author;
};

#endif // BOOKMODEL_H
