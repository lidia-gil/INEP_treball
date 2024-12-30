#include "CercadoraContingut.h"

CercadoraContingut::CercadoraContingut(){ }

PassarelaContingut CercadoraContingut::cercaPerTitol(std::string titolC) {

    PassarelaContingut contingut;
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string sql = "SELECT * FROM contingut WHERE titol = '" + titolC + "'";
    sql::ResultSet* res = con.executarConsulta(sql);
    // Si no troba cap fila, activa excepcio
    if (!res->next()) {
        
        throw std::runtime_error("El contingut consultat no existeix");
    }
    else {

        contingut.posaTitol(res->getString("titol"));
        contingut.posaDescripcio(res->getString("descripcio"));
        contingut.posaQualificacioEdat(res->getString("qualificacio"));
        contingut.posaTipus(res->getString("tipus"));
        delete res; //Alliberar memoria
    }
    return contingut;
}