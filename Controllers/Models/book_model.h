#ifndef BOOKMODEL_H
#define BOOKMODEL_H

#include <QImage>
#include <QObject>

#include "../enums.h"

class BookModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString Title READ Title WRITE setTitle NOTIFY TitleChanged)
    Q_PROPERTY(QString Author READ Author WRITE setAuthor NOTIFY AuthorChanged)
    Q_PROPERTY(QString Description READ Description WRITE setDescription NOTIFY DescriptionChanged)
    Q_PROPERTY(QImage Cover READ Cover WRITE setCover NOTIFY CoverChanged)
    Q_PROPERTY(Status ReadingStatus READ ReadingStatus WRITE setReadingStatus NOTIFY ReadingStatusChanged)
    Q_PROPERTY(QString Picture READ Picture CONSTANT)
  public:
    explicit BookModel(QObject *parent = nullptr);

    QString Title() const;
    void setTitle(const QString &newTitle);

    QString Author() const;
    void setAuthor(const QString &newAuthor);

    QString Description() const;
    void setDescription(const QString &newDescription);

    QImage Cover() const;
    void setCover(const QImage &newCover);

    QString Picture();

    Status ReadingStatus() const;
    void setReadingStatus(Status newReadingStatus);

  signals:

    void TitleChanged();

    void AuthorChanged();

    void DescriptionChanged();

    void CoverChanged();

    void ReadingStatusChanged();

  private:
    QString m_Title;
    QString m_Author;
    QString m_Description;
    QImage m_Cover;
    QString m_Picture;
    Status m_ReadingStatus;
};

#endif // BOOKMODEL_H
