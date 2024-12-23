#pragma once

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <iostream>
#include <string>
class ConnexioBD
{
    private:
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;
        // Constructor: estableix la connexi�
        ConnexioBD();
    public:
       
        static ConnexioBD& getInstance();
        // Destructor: tanca la connexi�
        ~ConnexioBD();

        // M�tode per a consultes (SELECT)
        sql::ResultSet* executarConsulta(const std::string& consultaSQL);

        // M�tode per a comandes (INSERT, UPDATE, DELETE)
        void executarComanda(const std::string& comandaSQL);
};

