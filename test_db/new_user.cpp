#include "new_user.h"

New_user::New_user()
{
// wygenerować losowy id i account_number


}


bool New_user::IsIdAvailable(unsigned int _id){

   // QSqlQuery query(db);
    QString id_query = "SELECT id from users WHERE id = " + _id;
   // cout << id_query;
}
