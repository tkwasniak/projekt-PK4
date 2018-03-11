#ifndef DB_CONNECTOR_H
#define DB_CONNECTOR_H
#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QtSql/QSqlRecord>

class DB_connector
{
    QSqlDatabase db;
    QSqlQuery query;
public:
    DB_connector();    
    bool open();
    bool close();
    QString SingleSelectQuery(const QString& _query);
};

#endif // DB_CONNECTOR_H
