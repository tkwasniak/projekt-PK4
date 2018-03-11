#ifndef NEW_USER_H
#define NEW_USER_H
#include "global.h"
#include <string>
#include <random>
#include<ctime>



default_random_engine generator (time(NULL));
uniform_int_distribution<int> distribution(1,999);
class New_user
{
    unsigned int id, mobile_number,account_number;
    string name, username, password, address;
    float balance;

public:
    New_user();
    void ReturnNewUserInfo();
    void GenerateId();
    bool IsIdAvailable(unsigned int _id);
};

#endif // NEW_USER_H
