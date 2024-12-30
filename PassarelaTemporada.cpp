#include "PassarelaTemporada.h"

PassarelaTemporada::PassarelaTemporada(){

    titol = "" ;
    numTemporada = 0;
}
PassarelaTemporada::PassarelaTemporada(std::string titolS, int numTemp){

    titol = titolS;
    numTemporada = numTemp;
}


std::string PassarelaTemporada::obteTitolSerie(){

    return titol;
}
int PassarelaTemporada::obteNumTemporada(){

    return numTemporada;
}


void PassarelaTemporada::posaTitolSerie(std::string titolS){

    titol = titolS;
}
void PassarelaTemporada::posaNumTemporada(int numTemp){

    numTemporada = numTemp;
}


void PassarelaTemporada::insereix(){
    
    ConnexioBD& con = ConnexioBD::getInstance();

    std::string query = "INSERT INTO temporada (titol_serie, numero) VALUES('" + titol + "' , '" + std::to_string(numTemporada) + "')";
    con.executarComanda(query);
}
void PassarelaTemporada::modifica(){

    ConnexioBD& con = ConnexioBD::getInstance();

    std::string query = "UPDATE temporada SET numero = '" + std::to_string(numTemporada) + "' WHERE titol_serie = '" + titol + "'";
    con.executarComanda(query);
}
void PassarelaTemporada::esborra() {

    ConnexioBD& con = ConnexioBD::getInstance();

    std::string query = "DELETE FROM temporada WHERE titol_serie = '" + titol + "'";
    con.executarComanda(query);
}