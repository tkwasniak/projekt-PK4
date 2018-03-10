#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User
{
    string username, password;
public:
    User(const string& _username, const string& _password);


//   virtual void ExportMyHistory();
//   virtual void TransferMoney(int _account_num);
//   virtual void ChangeMyCredetials();
//   virtual void WithdrawMoney();
//   virtual void DepositMoney();

};

#endif // USER_H
