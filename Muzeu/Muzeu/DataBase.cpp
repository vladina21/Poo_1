#include "DataBase.h"
DataBase* DataBase::instance = nullptr;
DataBase* DataBase::getInstance()
{
    if (!instance)
        instance = new DataBase();
    return instance;
}

bool DataBase::logare(ISchema * logare)
{
    string username = logare->getAtribute();
    string password = logare->getAtribute();
    string query = "Select * from utilizatori where username = '"+username+"' and password = '"+ password +"';";
    const char* q = query.c_str();
    state = mysql_query(conn, q);
    if (!state)
    {
        res = mysql_store_result(conn); //res retine rezultatul interogarii adica tot tabelul
        row = mysql_fetch_row(res); //row imparte tabelul pe randuri (row[0] = primul rand) functioneaza ca un vector
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

bool DataBase::inregistrare(ISchema * inregistrare)
{

    string username=inregistrare->getAtribute();
    string password=inregistrare->getAtribute();
    string query= "Select * from utilizatori where username = '" + username + "' and password = '" + password + "';";
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
            string query2 = "insert into utilizatori values ('" + username + "', '" + password + "')";
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

bool DataBase::adaugaRezervare(ISchema * rezervare)
{
    string username = rezervare->getAtribute();
    string data= rezervare->getAtribute();
    string ora = rezervare->getAtribute();
    string categorie= rezervare->getAtribute();
    string query = "insert into rezervari(username, data, ora, categorie, status) values ('"+ username+"', '"+ data+"','"+ ora+"', '"+ categorie+"','pending');";
    const char* q = query.c_str();
    state = mysql_query(conn, q);
    if (!state) {
        return true;

    }
    else
    {
        cout << "Query failed" << mysql_error(conn);
        return false;
    }
    
}

bool DataBase::afiseazaRezervare()
{
    string query = "select * from rezervari;";
    const char* q = query.c_str();
    state = mysql_query(conn, q);
    if (!state) {
        return true;
    }
    else
    {
        cout << "Query failed" << mysql_error(conn);
        return false;
    }
    
}

bool DataBase::updateRezervare(ISchema* update)
{
    string ID = update->getAtribute();
    string status = update->getAtribute();
    string query = "update rezervari set status = '" + status + "' where ID_rezervare = " + ID + ";";
    const char* q = query.c_str();
    state = mysql_query(conn, q);
    if (!state) {
        return true;
    }
    else
    {
        cout << "Query failed" << mysql_error(conn);
        return false;
    }
    
}

bool DataBase::adaugareOpera(ISchema* adauga)
{
    string denumire = adauga->getAtribute();
    string autor = adauga->getAtribute();
    string locatie = adauga->getAtribute();
    string query = "insert into opere (denumire, autor, locatie) values ('" + denumire + "', '" + autor + "','" + locatie + "');";
    const char* q = query.c_str();
    state = mysql_query(conn, q);
    if (!state) {
        return true;
    }
    else
    {
        cout << "Query failed" << mysql_error(conn);
        return false;
    }
}

bool DataBase::mutaOpera(ISchema* muta)
{
    string ID = muta->getAtribute();
    string locatieNoua = muta->getAtribute();
    string query = "update opere set locatie = '" + locatieNoua + "' where ID_opera =" + ID + ";";
    const char* q = query.c_str();
    state = mysql_query(conn, q);
    if (!state) {
        return true;
    }
    else
    {
        cout << "Query failed" << mysql_error(conn);
        return false;
    }

}

bool DataBase::afiseazaOpera()
{
    string query = "select * from opere;";
    const char* q = query.c_str();
    state = mysql_query(conn, q);
    if (!state) {
        return true;
    }
    else
    {
        cout << "Query failed" << mysql_error(conn);
        return false;
    }

}

bool DataBase::adaugaEveniment(ISchema* adauga)
{
    string titlu = adauga->getAtribute();
    string descriere = adauga->getAtribute();
    string data = adauga->getAtribute();
    string query = "insert into evenimente(titlu, descriere, data) values('" + titlu + "', '" + descriere + "', '" + data + "');";
    const char* q = query.c_str();
    state = mysql_query(conn, q);
    if (!state) {
        return true;
    }
    else
    {
        cout << "Query failed" << mysql_error(conn);
        return false;
    }

    
}

bool DataBase::stergeEveniment(ISchema* sterge)
{
    string ID = sterge->getAtribute();
    string query = "delete from evenimente where ID_eveniment = " + ID + ";";
    const char* q = query.c_str();
    state = mysql_query(conn, q);
    if (!state) {
        return true;
    }
    else
    {
        cout << "Query failed" << mysql_error(conn);
        return false;
    }

}

bool DataBase::afiseazaEveniment()
{
    string query = "select * from evenimente;";
    const char* q = query.c_str();
    state = mysql_query(conn, q);
    if (!state) {
        return true;
    }
    else
    {
        cout << "Query failed" << mysql_error(conn);
        return false;
    }

}
