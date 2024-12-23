#include "PassarelaCapitol.h"

 
PassarelaCapitol::PassarelaCapitol(){

    titolSerie = "";
    numTemporada = 0;
    numCapitol = 0;
    titol = "";
    dataEstrena = "";
}
//constructora
PassarelaCapitol::PassarelaCapitol(std::string titolS, int numTemp, int numeroCap, std::string titolCap, std::string data){

    titolSerie = titolS;
    numTemporada = numTemp;
    numCapitol = numeroCap;
    titol = titolCap;
    dataEstrena = data;
}

std::string PassarelaCapitol::obteTitolSerie(){

    return titolSerie;
}
int PassarelaCapitol::obteNumTemporada(){

    return numTemporada;
}
int PassarelaCapitol::obteNumCapitol(){

    return numCapitol;
}
std::string PassarelaCapitol::obteTitolCapitol(){

    return titol;
}
std::string PassarelaCapitol::obteData(){

    return dataEstrena;
}

void PassarelaCapitol::posaTitolSerie(std::string titolS){

    titolSerie = titolS;
}
void PassarelaCapitol::posaNumTemporada(int numTemp){

    numTemporada = numTemp;
}
void PassarelaCapitol::posaNumCapitol(int numCap){
    numCapitol = numCap;
}
void PassarelaCapitol::posaTitolCapitol(std::string titolCap){

    titol = titolCap;
}
void PassarelaCapitol::posaDataEstrena(std::string dataEstrenaC){

    dataEstrena = dataEstrenaC;
}

void PassarelaCapitol::insereix(){

    ConnexioBD& con = ConnexioBD::getInstance();
    //ConnexioBD con;

    std::string query = "INSERT INTO capitol (titol_serie, numero_temporada, numero, titol, data_estrena) VALUES('" + titolSerie + "', '" + std::to_string(numTemporada) + "', '" + std::to_string(numCapitol) +  "' , '" + titol + "', '" + dataEstrena + "')";
    con.executarComanda(query);
}

void PassarelaCapitol::modifica(){

    ConnexioBD& con = ConnexioBD::getInstance();
    //ConnexioBD con;

    std::string query = "UPDATE capitol SET titol = '" + titol + "' AND data_estrena = '" + dataEstrena +  "' WHERE titol_serie = '" + titolSerie + "' AND numero_temporada = '" + std::to_string(numTemporada) + "'AND numero = '" + std::to_string(numCapitol) +  "'";
    con.executarComanda(query);
}
void PassarelaCapitol::esborra(){
    
    ConnexioBD& con = ConnexioBD::getInstance();
    //ConnexioBD con;

	std::string query = "DELETE FROM capitol WHERE titol_serie = '" + titolSerie + "'AND numero_temporada = '" + std::to_string(numTemporada) + "' AND numero = '" + std::to_string(numCapitol) + "'";
	con.executarComanda(query);
}
