#include "CercadoraCapitol.h"

CercadoraCapitol::CercadoraCapitol(){ }

std::vector<PassarelaCapitol> CercadoraCapitol::cercaPerTitoliTemporada(std::string titolS, int numTemp) {

	std::vector<PassarelaCapitol> passareles;

    ConnexioBD& con = ConnexioBD::getInstance();
    std::string sql = "SELECT * FROM capitol WHERE titol_serie = '" + titolS + "' AND numero_temporada = " + std::to_string(numTemp);

    sql::ResultSet* res = con.executarConsulta(sql);
    while (res->next()) {
        PassarelaCapitol passarela;
        passarela.posaTitolSerie(res->getString("titol_serie"));
        passarela.posaNumTemporada(res->getInt("numero_temporada"));
        passarela.posaNumCapitol(res->getInt("numero"));
        passarela.posaTitolCapitol(res->getString("titol"));
        passarela.posaDataEstrena(res->getString("data_estrena"));

        passareles.push_back(passarela); // Añadir al vector
    }

    // Si no hay registros, lanzar excepción
    /*if (passareles.empty()) {

        throw std::runtime_error("La temporada consultada no existeix o no te cap capitol");
    }*/
    delete res; // Liberar memoria

	return passareles;
}

std::vector<PassarelaCapitol> CercadoraCapitol::cercaProximsCapitols(std::string dataHora) {

    std::vector<PassarelaCapitol> passareles;

    ConnexioBD& con = ConnexioBD::getInstance();
    std::string sql = "SELECT * FROM capitol WHERE data_estrena > '" + dataHora + "' ORDER BY data_estrena ASC";

    sql::ResultSet* res = con.executarConsulta(sql);
    while (res->next()) {
        PassarelaCapitol passarela;
        passarela.posaTitolSerie(res->getString("titol_serie"));
        passarela.posaNumTemporada(res->getInt("numero_temporada"));
        passarela.posaNumCapitol(res->getInt("numero"));
        passarela.posaTitolCapitol(res->getString("titol"));
        passarela.posaDataEstrena(res->getString("data_estrena"));

        passareles.push_back(passarela); // Añadir al vector
    }

    // Si no hay registros, lanzar excepción
    /*if (passareles.empty()) {

        throw std::runtime_error("No hi ha capitols per a estrenar.");
    }*/
    delete res; // Liberar memoria

	return passareles;
}

std::vector<PassarelaCapitol> CercadoraCapitol::cercaUltimsCapitols(std::string dataHora) {

    std::vector<PassarelaCapitol> passareles;

    ConnexioBD& con = ConnexioBD::getInstance();
    std::string sql = "SELECT * FROM capitol WHERE data_estrena < '" + dataHora + "' ORDER BY data_estrena DESC";
    sql::ResultSet* res = con.executarConsulta(sql);
    while (res->next()) {
        PassarelaCapitol passarela;
        passarela.posaTitolSerie(res->getString("titol_serie"));
        passarela.posaNumTemporada(res->getInt("numero_temporada"));
        passarela.posaNumCapitol(res->getInt("numero"));
        passarela.posaTitolCapitol(res->getString("titol"));
        passarela.posaDataEstrena(res->getString("data_estrena"));

        passareles.push_back(passarela); // Añadir al vector
    }

    // Si no hay registros, lanzar excepción
    /*if (passareles.empty()) {

        throw std::runtime_error("No hi ha capitols per a estrenar.");
    }*/
    delete res; // Liberar memoria

	return passareles;
}
