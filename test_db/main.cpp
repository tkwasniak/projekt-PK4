#include <QCoreApplication>
#include <QProcess>
#include <QtDebug>
#include <stdlib.h>

#include <iostream>
#include "admin.h"
#include <typeinfo>
using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase db;

    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setUserName("postgres");
    db.setPassword("root");
    db.setDatabaseName("bankdb");



   //string username, password;

//   cout << "Username: ";
//   cin >> username;
//   cout << "\nPassword: ";
//   cin >> password;


     //User* user = LogIn(username, password, db);
     User* user = LogIn(db);
     if(user) cout << "OK";

       unsigned int menu_index;

//       do
//       {
//          menu_index = DisplayMainMenu();

//          switch(menu_index){

//          case 1:{

//              break;
//          }
//          case 2:{


//              break;
//          }
//          case 3:{

//              break;
//          }
//          case 4:{
//            //  int menu_index2;
//              system("cls");
//              do
//              {
//                  menu_index = DisplayAccountMenu();
//                  switch(menu_index){
//                  case 1:{

//                      break;
//                  }
//                  case 2:{

//                      break;
//                  }
//                  case 3:{

//                      break;
//                  }
//                  case 4:{

//                      break;
//                  }
//                  case 5:{


//                      break;
//                  }
//                  default: {
//                  cout << "No such option available. Choose again.\n";
//                  break;}
//                  }
//              }
//               while(menu_index != 6);
//               menu_index = 0;
//               system("cls");
//              break;
//          }
//          case 5:{
//              if(typeid(*user) != typeid(Admin)){ //TYPEID
//              cout << "This option requires administrator account.\n";
//              break; }
//              else {
//              system("cls");
//              do
//              {
//                  menu_index = DisplayAdminMenu();
//                  switch(menu_index){
//                  case 1:{


//                      break;
//                  }
//                  case 2:{

//                      break;
//                  }
//                  case 3:{

//                      break;
//                  }
//                  case 4:{

//                      break;
//                  }
//                  default: {
//                  cout << "No such option available. Choose again.\n";
//                  break;
//                  }
//                  }
//              }
//               while(menu_index != 5);
//               menu_index = 0;
//               system("cls");
//              break;}
//          }
//          case 6:{

//              break;
//          }
//          case 7:{


//              break;
//          }
//          default:
//          {
//              cout << "No such option available. Choose again.\n";
//              break;
//          }
//        }
//       }
//       while(menu_index != 6);


    return a.exec();
}

