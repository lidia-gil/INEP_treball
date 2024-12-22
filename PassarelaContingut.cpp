#include "PassarelaContingut.h"

   
PassarelaContingut::PassarelaContingut(){}
//constructora
PassarelaContingut::PassarelaContingut(std::string titolC, std::string descripcioC, std::string qualificacio_edatC, std::string tipusC) {

	titol = titolC;
	descripcio = descripcioC;
	qualificacio_edat = qualificacio_edatC;
	tipus = tipusC;
}

std::string PassarelaContingut::obteTitol() {

	return titol;
}
std::string PassarelaContingut::obteDescripcio() {

	return descripcio;
}
std::string PassarelaContingut::obteQualificacioEdat() {

	return qualificacio_edat;
}
std::string PassarelaContingut::obteTipus() {

	return tipus;
}

void PassarelaContingut::posaTitol(std::string titolC) {

	titol = titolC;
}
void PassarelaContingut::posaDescripcio(std::string descripcioC) {

	descripcio = descripcioC;
}
void PassarelaContingut::posaQualificacioEdat(std::string qualificacio_edatC) {

	qualificacio_edat = qualificacio_edatC;
}
void PassarelaContingut::posaTipus(std::string tipusC) {

	tipus = tipusC;
}

void PassarelaContingut::insereix() {

	ConnexioBD con;

	std::string query = "INSERT INTO contingut (titol, descripcio, qualificacio, tipus) VALUES('" + titol + "', '" + descripcio + "', '" + qualificacio_edat +  "' , '" + tipus + "')";
	con.executarComanda(query);
}
void PassarelaContingut::modifica() {

	ConnexioBD con;

    std::string query = "UPDATE contingut SET descripcio = '" + descripcio + "', qualificacio = '" + qualificacio_edat + "', tipus = '" + tipus + "' WHERE titol = '" + titol + "'";
    con.executarComanda(query);
}
void PassarelaContingut::esborra() {

	ConnexioBD con;
	std::string query = "DELETE FROM contingut WHERE titol = '" + titol + "'";
	con.executarComanda(query);
}