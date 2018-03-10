#include "db_connection.h"
#include <QVariant>
#include <QtSql/QSqlRecord>

bool LogIntoDb(string& username, string& password,bool& user_type){

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setUserName("postgres");
    db.setPassword("root");
    db.setDatabaseName("bankdb");
    QSqlQuery query(db);
        if(db.open())
        {
           cout << "Database opened successfully.\n";
           QString q_user = QString::fromStdString(username);
           QString q_pass = QString::fromStdString(password);

           q_user = q_pass = "admin";
           if(query.exec("SELECT id FROM users WHERE username = '"+q_user+"'"
                          " AND password = '"+q_pass+"'")){
               if(!query.size()) {
                   cout << "No such user exists\n";
                   return false;
               }
               else{
                    query.first(); // retrieves the first record in the result
                    int X = query.value(0).toInt();
                    user_type =  query.value(0).toInt() == 1? 1:0;
                    cout << "User's id: " << X << endl;
                    return true;


               }
           }
           else cout << "QUERY exec failed\n";

          QString wynik = query.lastQuery();
         qDebug("%s", qUtf8Printable(wynik));
        }
        else
        {
            cout << "Database connection failed!\n";
            return false;
        }
}

unsigned int read_int(){


}

unsigned int DisplayMainMenu(){
    int menu_index;
    bool valid = false;
    cout << "---------------------------- Welcome To Our Bank --------------------------" << endl;
    cout << "1.Withdrawal.\n";
    cout << "2.Deposit.\n";
    cout << "3.Transfer.\n";
    cout << "4.Account information.\n"; //
    cout << "5.Administrator's options.\n";
    cout << "6.Exit.\n";
    cout << "-----------------------------------------------------------" << endl;
    while(!valid)
    {
        cin >> menu_index;
        if(cin.fail()){
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        else valid = true;
    }
    return menu_index;
}

unsigned int DisplayAccountMenu()
{
    int menu_index;
    bool valid = false;
    cout << "---------------------------- Welcome To Our Bank --------------------------" << endl;
    cout << "1.Balance.\n";
    cout << "2.Change credentials.\n";
    cout << "3.View transaction history.\n";
    cout << "4.Export transaction history.\n"; //
    cout << "5.Close account.\n";
    cout << "6.Return.\n";
    cout << "-----------------------------------------------------------" << endl;
    while(!valid)
    {
        cin >> menu_index;
        if(cin.fail()){
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        else valid = true;
    }
    return menu_index;

}

unsigned int DisplayAdminMenu()
{
    int menu_index;
    bool valid = false;
    cout << "---------------------------- Welcome To Our Bank --------------------------" << endl;
    cout << "1.Create new account.\n";
    cout << "2.Delete existing account.\n";
    cout << "3.Export all transactions history.\n";
    cout << "4.Bank deposit charge\n"; //
    cout << "5.Return.\n";
    cout << "-----------------------------------------------------------" << endl;
    while(!valid)
    {
        cin >> menu_index;
        if(cin.fail()){
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        else valid = true;
    }
    return menu_index;


}
