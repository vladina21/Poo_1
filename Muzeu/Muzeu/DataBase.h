#pragma once
#include <string>
#include <mysql.h>
#include <iostream>
#include <sstream>
#include"ISchema.h"

using namespace std;

class DataBase
{
	static DataBase* instance;
	int state;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	DataBase()
	{
		conn = mysql_init(0);
		conn = mysql_real_connect(conn, "localhost", "root", "password", "proiect", 3306, NULL, 0);
		if (conn)
		{
			cout << "S-a conectat" << endl;
		}
		else
		{
			cout << "Nu s-a conectat" << endl;
		}
	}
public:
	static DataBase* getInstance();
	bool logare(ISchema * logare);
	bool inregistrare(ISchema * inregistrare);
	bool adaugaRezervare(ISchema * rezervare);
	bool afiseazaRezervare();
	bool updateRezervare(ISchema* update);
	bool adaugareOpera(ISchema* adauga);
	bool mutaOpera(ISchema* muta);
	bool afiseazaOpera();
	bool adaugaEveniment(ISchema* adauga);
	bool stergeEveniment(ISchema* sterge);
	bool afiseazaEveniment();
};

