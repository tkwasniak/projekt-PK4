#include "global.h"
#include <iostream>
#include <windows.h>



//unsigned int read_int(){
//
//
//}

string GetPassword(const string& prompt){
    string result;
    DWORD mode, count;
    HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE oh = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!GetConsoleMode( ih, &mode ))
       throw runtime_error(
         "getpassword: You must be connected to a console to use this program.\n"
         );
     SetConsoleMode( ih, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT) );
     // Get the password string
       WriteConsoleA( oh, prompt.c_str(), prompt.length(), &count, NULL );
       char c;
       while (ReadConsoleA( ih, &c, 1, &count, NULL) && (c != '\r') && (c != '\n'))
         {
         if (c == '\b')
           {
           if (result.length())
             {
             WriteConsoleA( oh, "\b \b", 3, &count, NULL );
             result.erase( result.end() -1 );
             }
           }
         else
           {
           WriteConsoleA( oh, "*", 1, &count, NULL );
           result.push_back( c );
           }
         }

       // Restore the console mode
       SetConsoleMode( ih, mode );

       return result;

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
