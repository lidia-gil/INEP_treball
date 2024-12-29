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

        // Constructor: estableix la connexió
        ConnexioBD();

        std::string _dbname;
        std::string _user;
        std::string _password;
        std::string _hostaddr;
        std::string _port;
    public:
       
        static ConnexioBD& getInstance();
        // Destructor: tanca la connexió
        ~ConnexioBD();

        void inicialitzar_atributs(std::string dbname, std::string user, std::string password, std::string hostaddr, std::string port);

        // Mètode per a consultes (SELECT)
        sql::ResultSet* executarConsulta(const std::string& consultaSQL);

        // Mètode per a comandes (INSERT, UPDATE, DELETE)
        void executarComanda(const std::string& comandaSQL);
};

