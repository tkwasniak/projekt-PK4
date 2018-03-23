#ifndef NEW_USER_H
#define NEW_USER_H
#include "global.h"
#include "db_connector.h"
#include <random>
#include<ctime>
#include <iostream>
#include <map>
class New_user
{
    map<string, QString> user_data_map;


public:
    New_user();
    map<string, QString>& ReturnNewUserData();
    void GenerateIdAndAccountNo(DB_connector* connector);
    bool IsAvailable(unsigned int _id, QString param, DB_connector* connector);
    void AssignCredentials();
};

#endif // NEW_USER_H
