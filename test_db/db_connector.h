#ifndef DB_CONNECTOR_H
#define DB_CONNECTOR_H


class DB_connector
{
    QSqlDatabase db;
    QSqlQuery query;
public:
    DB_connector();
};

#endif // DB_CONNECTOR_H
