#include "CercadoraContingut.h"

PassarelaContingut CercadoraContingut::cercaPerTitol(std::string titolC) {

    PassarelaContingut contingut;
    //ConnexioBD con;
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string sql = "SELECT * FROM contingut WHERE titol = '" + titolC + "'";
    sql::ResultSet* res = con.executarConsulta(sql);
    // Si no troba cap fila, activa excepcio
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
/*
std::vector<PassarelaContingut> CercadoraContingut::cercaPerPelicula() {

    std::vector<PassarelaContingut> passarelesPelis;
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string tipus = "pelicula";
    std::string sql = "SELECT * FROM contingut WHERE tipus = '" + tipus + "'";
    sql::ResultSet* res = con.executarConsulta(sql);
    // Verificar si hay resultados

    while (res->next()) {
        PassarelaContingut passarela;
        passarela.posaTitol(res->getString("titol"));
        passarela.posaDescripcio(res->getString("descripcio"));
        passarela.posaQualificacioEdat(res->getString("qualificacio"));
        passarela.posaTipus(res->getString("tipus"));

        passarelesPelis.push_back(passarela); // Afegir al vector
    }
    // Si no hay registros, lanzar excepción
    //if (passarelesPelis.empty()) {

    //    throw std::runtime_error("No hi ha pel.licules.");
    //}
    delete res; // Liberar memoria
    return passarelesPelis;
}
*/
/*std::vector<PassarelaContingut> CercadoraContingut::cercaPerCapitol() {

    std::vector<PassarelaContingut> passarelesCapitols;
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string tipus = "capitol";
    std::string sql = "SELECT * FROM contingut WHERE tipus = '" + tipus + "'";
    sql::ResultSet* res = con.executarConsulta(sql);
    // Verificar si hay resultados

    while (res->next()) {
        PassarelaContingut passarela;
        passarela.posaTitol(res->getString("titol"));
        passarela.posaDescripcio(res->getString("descripcio"));
        passarela.posaQualificacioEdat(res->getString("qualificacio"));
        passarela.posaTipus(res->getString("tipus"));

        passarelesCapitols.push_back(passarela); // Afegir al vector
    }
    // Si no hay registros, lanzar excepción
    if (passarelesCapitols.empty()) {

        throw std::runtime_error("No hi ha capitols.");
    }
    delete res; // Liberar memoria
    return passarelesCapitols;
}*/
/*
std::vector<PassarelaContingut> CercadoraContingut::cercaPeliInfantil(){

    std::vector<PassarelaContingut> passarelesInfantils;
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string edat = "TP";
    std::string tipus = "pelicula";

    std::string sql = "SELECT * FROM contingut WHERE qualificacio = '" + edat + "' AND tipus = '" + tipus + "'";
    sql::ResultSet* res = con.executarConsulta(sql);

    while (res->next()) {
        PassarelaContingut passarela;
        passarela.posaTitol(res->getString("titol"));
        passarela.posaDescripcio(res->getString("descripcio"));
        passarela.posaQualificacioEdat(res->getString("qualificacio"));
        passarela.posaTipus(res->getString("tipus"));

        passarelesInfantils.push_back(passarela); // Afegir al vector
    }
    // Si no hay registros, lanzar excepción
    //if (passarelesInfantils.empty()) {

    //    throw std::runtime_error("No s'ha trobat cap contingut infantil.");
    //}
    delete res; // Liberar memoria
    return passarelesInfantils;
}*/