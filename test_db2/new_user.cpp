#include "new_user.h"

#include <QDebug>
New_user::New_user()
{
    srand(time(NULL));
    user_data_map.insert(make_pair("balance", QString::number(0)));


}

void New_user::AssignCredentials(){
    string tmp;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "Name:\n";
    getline(cin, tmp);
    user_data_map.insert(make_pair("name", QString::fromStdString(tmp)));
    cout << "Address:\n";
    getline(cin, tmp);
    user_data_map.insert(make_pair("address", QString::fromStdString(tmp)));
    cout << "Mobile number:\n";
    getline(cin, tmp);
    user_data_map.insert(make_pair("mobile_num", QString::fromStdString(tmp)));
    cout << "Username:\n";
    getline(cin, tmp);
    user_data_map.insert(make_pair("username", QString::fromStdString(tmp)));
    tmp = GetPassword("Password:\n") ;
    user_data_map.insert(make_pair("password", QString::fromStdString(tmp)));



}
void New_user::GenerateIdAndAccountNo(DB_connector* connector){

    default_random_engine engine(time(NULL));
    uniform_int_distribution<int> account_num_generator (10000, 99999);
    user_data_map.insert(make_pair("account_num",QString::number(account_num_generator(engine))));
    QString result = connector->SingleSelectQuery("SELECT MAX(id) from users");
    int id= result.toInt();
    user_data_map.insert(make_pair("id",QString::number(++id)));

  }


map<string, QString>& New_user::ReturnNewUserData(){
    return this->user_data_map;

}


