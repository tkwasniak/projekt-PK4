#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H
#include <iostream>
#include <exception>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

using namespace std;
const int admin_id = 1;
const string  admin_username = "admin";
const string admin_password = "admin";
class database_exception:public exception{
    virtual const char* what() const throw() {
        return "Connection not established";
    }
};

//QSqlQuery query;

bool LogIntoDb(string& username, string& password, bool& user_type);
unsigned int DisplayMainMenu();
unsigned int DisplayAccountMenu();
unsigned int DisplayAdminMenu();
#endif // DB_CONNECTION_H
