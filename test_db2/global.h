#ifndef GLOBAL_H
#define GLOBAL_H
#include <QtGlobal>
using namespace std;
#include <string>


unsigned int DisplayMainMenu();
unsigned int DisplayAccountMenu();
unsigned int DisplayAdminMenu();
string GetPassword(const string& prompt = "Enter password: ");
#endif // GLOBAL_H
