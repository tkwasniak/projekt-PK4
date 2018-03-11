#include "admin.h"

Admin::Admin(const string& _username, const string& _password)
    :User(_username, _password)
{


}

void Admin::CreateAccount(){


}






User* LogIn(QSqlDatabase& db){


    string username, password;

 //   cout << "Username: ";
 //   cin >> username;
 //   cout << "\nPassword: ";
 //   cin >> password;
    QSqlQuery query(db);
    QString q_user = QString::fromStdString(username);
    QString q_pass = QString::fromStdString(password);
    if(db.open())
    {
        q_user = q_pass = "admin";
        if(query.exec("SELECT id FROM users WHERE username = '"+q_user+"'"
                       " AND password = '"+q_pass+"'")){
            if(!query.size()) {
                cout << "No such user exists\n";
                return nullptr;
            }
            else{
                 query.first(); // retrieves the first record in the result
                 int X = query.value(0).toInt();
                // user_type =  query.value(0).toInt() == 1? 1:0;
                 cout << "User's id: " << X << endl;
             if(username == admin_username && password == admin_password)
                 return new Admin(username, password);
             else return new User(username,password);
            }
        }
       else cout << "QUERY exec failed\n";
       QString wynik = query.lastQuery();
       qDebug("%s", qUtf8Printable(wynik));
       return nullptr;

    }
    else
    cout << "Database not opened\n";
    return nullptr;
}
