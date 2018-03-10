#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"

class Admin: public User
{
public:
    Admin(const string& _username, const string& password);
//    void CreateAccount();
//    void DeleteAccount();

};

#endif // ADMIN_H
