#include "ConnexioBD.h"

ConnexioBD::ConnexioBD() {

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep02", "rai2Laavaey6ph");
    con->setSchema("inep02");
}

void ConnexioBD::inicialitzar_atributs(std::string dbname, std::string user, std::string password, std::string hostaddr, std::string port) {
    
    _dbname = dbname;
    _user = user;
    _password = password;
    _hostaddr = hostaddr;
    _port = port;

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect(_hostaddr + ":" + _port, _user, _password);
    con->setSchema(_dbname);
}

ConnexioBD& ConnexioBD::getInstance() {

    static ConnexioBD instance;
    return instance;
}

ConnexioBD::~ConnexioBD() {
    
    if (con) con->close();
}

sql::ResultSet* ConnexioBD::executarConsulta(const std::string& consultaSQL) {

    sql::Statement* stmt = con->createStatement();
    return stmt->executeQuery(consultaSQL);
}

void ConnexioBD::executarComanda(const std::string& comandaSQL) {

    sql::Statement* stmt = con->createStatement();
    stmt->executeUpdate(comandaSQL);
}
