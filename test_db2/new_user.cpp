#include "new_user.h"

#include <QDebug>
New_user::New_user()
    :balance(0)
{
// wygenerować losowy id i account_number
    srand(time(NULL));

}

void New_user::AssignCredentials(){
 //TUTAJ JESTEM OBECNIE

};
void New_user::GenerateIdAndAccountNo(DB_connector* connector){

    default_random_engine engine(time(NULL));
    uniform_int_distribution<int> id_generator (1, 99);
    uniform_int_distribution<int> account_num_generator (10000, 99999);

    do
    {
       id = id_generator(engine);
    }
    while(!IsAvailable(id, "id", connector));

    qDebug() << "Wylosowane id: " << id;

    do
    {
       account_number = account_num_generator(engine);

    }
    while(!IsAvailable(account_number, "account_number", connector));
    qDebug() << "Wylosowane account num: " << account_number << endl;
}




bool New_user::IsAvailable(unsigned int num, QString str, DB_connector* connector){

    QString query = QString("SELECT %1 FROM users WHERE %1 =%2").arg(str).arg(num);
    QString result;
    result = connector->SingleSelectQuery(query);
    return result.isEmpty()? true : false;
}
