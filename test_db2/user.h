#ifndef USER_H
#define USER_H
#include <string>
#include "global.h"
#include <iostream>
using namespace std;

class User
{
private:
    string username, password;
public:
    User();
    User(const string& _username, const string& _password);
    virtual ~User();
    virtual void CreateAccount(DB_connector* connector){
        cout << "User function";
    }

//   virtual void ExportMyHistory();
//   virtual void TransferMoney(int _account_num);
//   virtual void ChangeMyCredetials();
//   virtual void WithdrawMoney();
//   virtual void DepositMoney();

};




#endif // USER_H
