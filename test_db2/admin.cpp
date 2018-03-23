#include "admin.h"
#include <QtDebug>
Admin::Admin(int _id)
    :User(_id)
{


}

bool Admin::CreateAccount(DB_connector* connector){
    bool result = false;
    New_user* nuser = new New_user();
    nuser->GenerateIdAndAccountNo(connector);
    nuser->AssignCredentials();
    map<string, QString> user_data_map = nuser->ReturnNewUserData();
    query = "INSERT INTO users VALUES(" + user_data_map["id"] + ", '" + user_data_map["name"] + "', '"
            + user_data_map["address"] + "', '" + user_data_map["mobile_num"] + "','" + user_data_map["account_num"]+"')";
    //qDebug("%s", qUtf8Printable(insert_query));

    result = connector->QueryExecute(query);
    if(result == 1) {
        query = "INSERT INTO credentials VALUES(" + user_data_map["id"] + ", '" + user_data_map["username"] + "', '"
                + user_data_map["password"] + "', '" + user_data_map["balance"] +"')";
        result = connector->QueryExecute(query);
    }
    delete nuser;
    return result;
}


int Admin::DeleteAccount(DB_connector* connector, int delete_id){
    QString qdelete_id = QString::number(delete_id);
    query = "SELECT id from users WHERE id = " + qdelete_id;
    qDebug("%s", qUtf8Printable(query));
    if(!(connector->SingleSelectQuery(query)).isEmpty()) {
        query = "DELETE FROM users WHERE id = " + qdelete_id;
        connector->QueryExecute(query);
        query = "DELETE FROM credentials WHERE id = " + qdelete_id;
        connector->QueryExecute(query);
        query = "DELETE FROM transactions WHERE id = " + qdelete_id;
        connector->QueryExecute(query);
        return 1;
        }
    return 0; // nie ma takiego id
}

User* LogIn(DB_connector* connector){

    const int admin_id = 1;
    const string  admin_username = "admin123";
    const string admin_password = "admin123";


    string username, password;
//    cout << "Enter username: ";
//    cin >> username;
//    password = GetPassword("Enter password:");
    username = password = "admin123";

    QString q_user = QString::fromStdString(username);
    QString q_pass = QString::fromStdString(password);
    QString query = "SELECT id from credentials WHERE username = '" +q_user +"' AND password = '" + q_pass +"'";
    QString result;

    result =  connector->SingleSelectQuery(query);

    //qDebug() << result.toInt() << endl;
    if(result.toInt() == admin_id) {
         qDebug() << "Logged in as admin\n";
        return new Admin(result.toInt());
    }
    else if(!result.isEmpty()) return new User(result.toInt());
    else return nullptr;
}



