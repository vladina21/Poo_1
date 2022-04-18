#pragma once
#include <string>
#include <mysql.h>
#include <iostream>
#include <sstream>

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
	bool logare(string username, string parola);
	bool inregistrare(string username, string parola);
};

