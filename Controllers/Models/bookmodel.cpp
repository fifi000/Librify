#include "bookmodel.h"

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
