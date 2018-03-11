#include "global.h"
#include <iostream>

const string  admin_username = "admin";
const string admin_password = "admin";




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
