#include "ConnexioBD.h"
ConnexioBD::ConnexioBD() {

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep02", "rai2Laavaey6ph");
    con->setSchema("inep02");
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
