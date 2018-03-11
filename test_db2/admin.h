#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"
#include "new_user.h"
class Admin: public User
{
public:
    Admin(const string& _username, const string& password);

     void CreateAccount(DB_connector* connector);
//    void DeleteAccount();


};


//User* LogIn(string& username, string& password, QSqlDatabase& db);
User* LogIn(DB_connector* connector);

#endif // ADMIN_H
