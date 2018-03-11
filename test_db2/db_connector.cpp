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
    if(db.open())
    {
        query.exec(_query);
        if(!query.size()) {
           // qDebug() << "No such user exists\n";
        }
        else {
            query.first();
            result = query.value(0).toString();
            qDebug() << "querie result: " << result << endl;
        }
        QString wynik = query.lastQuery();
        qDebug("%s", qUtf8Printable(wynik));
    }
    else{
        qDebug() << "Database not open\n";
    }
    return result;



}
