#ifndef USER_H
#define USER_H
#include "global.h"
#include <iostream>
#include "db_connector.h"
class User
{
protected:
    int id;
    QString query;
public:
    User();
    User(int _id);
    virtual ~User();
    virtual bool CreateAccount(DB_connector* connector){
        cout << "User function";
    }
    virtual int DeleteAccount(DB_connector* connector, int delete_id){}


//   virtual void ExportMyHistory();
//   virtual void TransferMoney(int _account_num);
//   virtual void ChangeMyCredetials();
//   virtual void WithdrawMoney();
//   virtual void DepositMoney();

};




#endif // USER_H
