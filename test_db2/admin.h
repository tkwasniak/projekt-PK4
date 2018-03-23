#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"
#include "new_user.h"
class Admin: public User
{

public:
    Admin(int _id);

   bool CreateAccount(DB_connector* connector);
   int DeleteAccount(DB_connector* connector, int delete_id);


};

User* LogIn(DB_connector* connector);

#endif // ADMIN_H
