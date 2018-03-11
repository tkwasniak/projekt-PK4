#include "admin.h"
#include <QtDebug>
Admin::Admin(const string& _username, const string& _password)
    :User(_username, _password)
{


}

void Admin::CreateAccount(DB_connector* connector){
// 1. Stworzyc obiekt NewUser
// 2. Zapisac go do bazy
    cout << "CreateAccount <-admin: ";
    New_user* nuser = new New_user();
    nuser->GenerateIdAndAccountNo(connector);
}





User* LogIn(DB_connector* connector){


    string username, password;
//    cout << "Enter username: ";
//    cin >> username;
//    password = GetPassword("Enter password:");
    username = password = "admin";
    QString q_user = QString::fromStdString(username);
    QString q_pass = QString::fromStdString(password);
    QString query = "SELECT id from users WHERE username = '" +q_user +"' AND password = '" + q_pass +"'";
    QString result;
    //qDebug() << "Query:" << query;

    result =  connector->SingleSelectQuery(query);
    if(result.toInt() == admin_id) {
       // Admin* admin = new Admin(username, password);
        return new Admin(username, password);
    }
    else if(!result.isEmpty()) return new User(username, password);
    else return nullptr;
}
