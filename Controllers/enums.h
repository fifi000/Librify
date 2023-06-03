#ifndef ENUMS_H
#define ENUMS_H

#include <QHash>
#include <QString>

enum Status
{
    Reading,
    ToRead,
    Finished
};

const QHash<QString, Status> StatusConventer{{"Reading", Reading}, {"To Read", ToRead}, {"Finished", Finished}};

#endif // ENUMS_H
