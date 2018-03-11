#ifndef NEW_USER_H
#define NEW_USER_H
#include "global.h"
#include <string>
#include <random>
#include<ctime>
class New_user
{
    unsigned int id, mobile_number,account_number;
    string name, username, password, address;
    float balance;

public:
    New_user();
    void ReturnNewUserInfo();
    void GenerateIdAndAccountNo(DB_connector* connector);
    bool IsAvailable(unsigned int _id, QString param, DB_connector* connector);
    void AssignCredentials();
};

#endif // NEW_USER_H
