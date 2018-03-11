#ifndef GLOBAL_H
#define GLOBAL_H
#include <QtGlobal>
#include "db_connector.h"
using namespace std;
extern const int admin_id;
extern const string  admin_username;
extern const string admin_password;
unsigned int DisplayMainMenu();
unsigned int DisplayAccountMenu();
unsigned int DisplayAdminMenu();
string GetPassword(const string& prompt = "Enter password: ");
#endif // GLOBAL_H
