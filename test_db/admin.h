#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"

class Admin: public User
{
public:
    Admin(const string& _username, const string& password);
    void CreateAccount();
//    void DeleteAccount();

};

//User* LogIn(string& username, string& password, QSqlDatabase& db);
User* LogIn(QSqlDatabase& db);

#endif // ADMIN_H
