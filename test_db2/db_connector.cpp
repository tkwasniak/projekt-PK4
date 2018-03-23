#include "db_connector.h"
#include <QVariant>
#include <QDebug>
DB_connector::DB_connector()
{


}

bool DB_connector::open(){
    bool result = false;
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setUserName("postgres");
    db.setPassword("root");
    db.setDatabaseName("bankdb");
    if(db.open())
        result = true;
    return result;

}

bool DB_connector::close(){
    bool result = true;
    QString connection;
    connection=db.connectionName();
    db.close();
    QSqlDatabase::removeDatabase(connection);
     return result;
}



QString DB_connector::SingleSelectQuery(const QString& _query){
    query = QSqlQuery(db);
    QString result = "";
    query.next();
    query.exec(_query);
        if(query.size() == 1) {
            query.first();
            result = query.value(0).toString();
        }
        else {
         qDebug() << "querie size: ";
         qDebug("%s", qUtf8Printable(QString::number(query.size()) + "\n"));
        }
        qDebug("%s", qUtf8Printable("SingleSelectQuery return:: " + result));
    return result;
}

bool DB_connector::QueryExecute(const QString& _query){


    query = QSqlQuery(db);
    if( query.exec(_query))
        qDebug()<< "OK";
    return true;
    //return query.exec(_query);

}



