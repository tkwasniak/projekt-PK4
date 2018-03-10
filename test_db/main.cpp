#include <QCoreApplication>
#include <QProcess>
#include <QtDebug>
#include <stdlib.h>
#include "db_connection.h"
#include "admin.h"
#include <typeinfo>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



   string username, password;
   bool user_type; // 1 - admin, 0 - normal user
//   cout << "Username: ";
//   cin >> username;
//   cout << "\nPassword: ";
//   cin >> password;

   if(LogIntoDb(username, password, user_type))
   {
       if(user_type) cout << "Connected as admin\n";
       else cout << "Connected as user\n";
       unsigned int menu_index;
       User* user = new User(username, password);
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
              if(typeid(*user) != typeid(Admin)){ //TYPEID
              cout << "This option requires administrator account.\n";
              break; }
              else {
              system("cls");
              do
              {
                  menu_index = DisplayAdminMenu();
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

   }
   else cout << "LogIntoDb returned false";







    return a.exec();
}

