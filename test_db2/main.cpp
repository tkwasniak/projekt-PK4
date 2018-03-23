#include <QCoreApplication>
#include <QProcess>
#include <QtDebug>
#include <stdlib.h>
#include <iostream>

#include "admin.h"
#include <typeinfo>
using namespace std;

void MenuSwitch();
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DB_connector* connector = new DB_connector();
    if(connector->open()){
    cout << "Connection established\n";
    User* USER;
    do
    {
        USER = LogIn(connector);
        if(!USER) cout << "Incorrect username or password, please try again.\n";

    }while(!USER);
//-------------------------------------------!!!!!!!!!!!!!!!!!!!!!!!!!!!!---------------------
//    bool result = USER->CreateAccount(connector);
//    system("cls");
//    if (result ) cout << "new user added to database\n";
//    else cout << "failed to add new user\n";
//-------------------------------------------!!!!!!!!!!!!!!!!!!!!!!!!!!!!---------------------
//-------------------------------------------!!!!!!!!!!!!!!!!!!!!!!!!!!!!---------------------
//    int id;
//    cout << "Enter id\n:";
//    cin >> id;
//    int result2 = USER->DeleteAccount(connector, id);
//    system("cls");
//    if (result2 == 1 ) cout << "user deleted from database\n";
//    else if(result2 == 0) cout << "no such user id exists in database\n";
//    else cout << "failed to delete'n";
 //-------------------------------------------!!!!!!!!!!!!!!!!!!!!!!!!!!!!---------------------
    unsigned int menu_index;

      do
      {
         menu_index = DisplayMainMenu();

         switch(menu_index){

         case 1:{

             break;
         }
         case 2:{


             break;
         }
         case 3:{

             break;
         }
         case 4:{
           //  int menu_index2;
             system("cls");
             do
             {
                 menu_index = DisplayAccountMenu();
                 switch(menu_index){
                 case 1:{

                     break;
                 }
                 case 2:{

                     break;
                 }
                 case 3:{

                     break;
                 }
                 case 4:{

                     break;
                 }
                 case 5:{


                     break;
                 }
                 default: {
                 cout << "No such option available. Choose again.\n";
                 break;}
                 }
             }
              while(menu_index != 6);
              menu_index = 0;
              system("cls");
             break;
         }
         case 5:{
             if(typeid(*USER) != typeid(Admin)){
             cout << "This option requires administrator account.\n";
             break; }
             else {
             system("cls");
             do
             {
             menu_index = DisplayAdminMenu();
             switch(menu_index){
             case 1:{ // CREATE AN ACCOUNT
             bool result = USER->CreateAccount(connector);
             system("cls");
             if(result ) cout << "new user added to database\n";
             else cout << "failed to add new user\n";
             break;
                 }
                 case 2:{

                     break;
                 }
                 case 3:{

                     break;
                 }
                 case 4:{

                     break;
                 }
                 default: {
                 cout << "No such option available. Choose again.\n";
                 break;
                 }
                 }
             }
              while(menu_index != 5);
              menu_index = 0;
              system("cls");
             break;}
         }
         case 6:{

             break;
         }
         case 7:{


             break;
         }
         default:
         {
             cout << "No such option available. Choose again.\n";
             break;
         }
       }
      }
      while(menu_index != 6);
 } else cout << "Connection failed.\n";

    return a.exec();
}

void MenuSwitch(){

}
