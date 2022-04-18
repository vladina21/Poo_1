#include "DataBase.h"
DataBase* DataBase::instance = nullptr;
DataBase* DataBase::getInstance()
{
    if (!instance)
        instance = new DataBase();
    return instance;
}

bool DataBase::logare(string username, string parola)
{
    string query = "Select * from utilizatori where username = '"+username+"' and password = '"+parola+"';";
    const char* q = query.c_str();
    state = mysql_query(conn, q);
    if (!state)
    {
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);
        //while (row)
        //{
        //    printf("%s %s", row[0], row[1]);
        //    row= mysql_fetch_row(res);
        //}
        if (row)
        {
            cout << "s-a gasit userul"<<endl;
            return true;
        }
        else
        {
            cout << "nu s-a gasit userul"<<endl;
            return false;
        }

    }
    return false;
}

bool DataBase::inregistrare(string username, string parola)
{
    string query= "Select * from utilizatori where username = '" + username + "' and password = '" + parola + "';";
    const char* q = query.c_str();
    state = mysql_query(conn, q);
    if (!state) { //s-a apelat query ul
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        if (row) //exista row (deci exista utilizatorul deja)
        {
            cout << "Exista utilizatorul" << endl;
            return false;
        }
        else {
            cout << "Utilizatorul nu exista. Se adauga" << endl;
            string query2 = "insert into utilizatori values ('" + username + "', '" + parola + "')";
            const char* q2 = query2.c_str();
            state = mysql_query(conn, q2);
            if (!state) {
                res = mysql_store_result(conn);
                return true;

            }
            else {
                cout << "Query-ul nu s-a executat" << endl;
            }
        }
    }
    return false;
}
