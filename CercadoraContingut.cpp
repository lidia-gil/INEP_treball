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

std::vector<PassarelaContingut> CercadoraContingut::cercaPerTipus() {

    std::vector<PassarelaContingut> passarelesPelis;
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string tipus = "pelicula";
    std::string sql = "SELECT * FROM contingut WHERE tipus = '" + tipus + "'";
    sql::ResultSet* res = con.executarConsulta(sql);
    // Verificar si hay resultados
    if (!res) {
        throw std::runtime_error("Consulta SQL no vàlida o no es pot obtenir ResultSet.");
    }

    while (res->next()) {
        PassarelaContingut passarela;
        passarela.posaTitol(res->getString("titol"));
        passarela.posaDescripcio(res->getString("descripcio"));
        passarela.posaQualificacioEdat(res->getString("qualificacio"));
        passarela.posaTipus(res->getString("tipus"));

        passarelesPelis.push_back(passarela); // Afegir al vector
    }
    // Si no hay registros, lanzar excepción
    if (passarelesPelis.empty()) {

        throw std::runtime_error("No hi ha pel.licules.");
    }
    delete res; // Liberar memoria
    return passarelesPelis;
}