#include "CercadoraContingut.h"


PassarelaContingut CercadoraContingut::cercaPerTitol(std::string titolC) {

    PassarelaContingut contingut;
    //ConnexioBD con;
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string sql = "SELECT * FROM contingut WHERE titol = '" + titolC + "'";
    sql::ResultSet* res = con.executarConsulta(sql);
    // Si no troba cap fila, activa excepciÃ³
    if (!res->next()) {
        //throw exception("Usuari no existeix");  // no ens funciona aquesta operació 
        throw std::runtime_error("El contingut consultat no existeix");
    }
    else {
        contingut.posaTitol(res->getString("titol"));
        contingut.posaDescripcio(res->getString("descripcio"));
        contingut.posaQualificacioEdat(res->getString("qualificacio"));
        contingut.posaTipus(res->getString("tipus"));
        delete res;
    }
    return contingut;
}