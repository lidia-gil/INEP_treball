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

    public:
        // Constructor: estableix la connexió
        ConnexioBD();

        // Destructor: tanca la connexió
        ~ConnexioBD();

        // Mètode per a consultes (SELECT)
        sql::ResultSet* executarConsulta(const std::string& consultaSQL);

        // Mètode per a comandes (INSERT, UPDATE, DELETE)
        void executarComanda(const std::string& comandaSQL);
};

