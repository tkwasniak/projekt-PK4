#ifndef GLOBAL_H
#define GLOBAL_H
#include <QtGlobal>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QtSql/QSqlRecord>
using namespace std;

extern const string  admin_username;
extern const string admin_password;




unsigned int DisplayMainMenu();
unsigned int DisplayAccountMenu();
unsigned int DisplayAdminMenu();

#endif // GLOBAL_H
