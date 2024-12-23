#include "PassarelaVisualitzaCapitol.h"

PassarelaVisualitzaCapitol::PassarelaVisualitzaCapitol() {

    sobrenom = "";
    titolSerie = "";
    numVisualitzacions = 0;
    numTemporada = 0;
    numCapitol = 0;
    data = "";
}

PassarelaVisualitzaCapitol::PassarelaVisualitzaCapitol(std::string sobrenomU, std::string titolSerieV, int numVisualitzacionsU, int numTemporadaV, int numCapitolV, std::string dataV ) {

    sobrenom = sobrenomU;
    titolSerie = titolSerieV;
    numVisualitzacions = numVisualitzacionsU;
    numTemporada = numTemporadaV;
    numCapitol = numCapitolV;
    data = dataV;
}

std::string PassarelaVisualitzaCapitol::obteSobrenom() {

    return sobrenom;
}
std::string PassarelaVisualitzaCapitol::obteTitolSerie() {

    return titolSerie;
}
int PassarelaVisualitzaCapitol::obteNumVisualitzacions() {

    return numVisualitzacions;
}
int PassarelaVisualitzaCapitol::obteNumTemporada() {

    return numTemporada;
}
int PassarelaVisualitzaCapitol::obteNumCapitol() {

    return numCapitol;
}

std::string PassarelaVisualitzaCapitol::obteData() {

    return data;
}



void PassarelaVisualitzaCapitol::posaSobrenom(std::string sobrenomU) {

    sobrenom = sobrenomU;
}

void PassarelaVisualitzaCapitol::posaTitolSerie(std::string titolSerieV) {

    titolSerie = titolSerieV;
}
void PassarelaVisualitzaCapitol::posaNumVisualitzacions(int numVisualitzacionsV) {

    numVisualitzacions = numVisualitzacionsV;
}
void PassarelaVisualitzaCapitol::posaNumTemporada(int numTemporadaV) {

    numTemporada = numTemporadaV;
}
void PassarelaVisualitzaCapitol::posaNumCapitol(int numCapitolV) {

    numCapitol = numCapitolV;
}
void PassarelaVisualitzaCapitol::posaData(std::string dataV) {

    data = dataV;
}



void PassarelaVisualitzaCapitol::insereix() {

    ConnexioBD& con = ConnexioBD::getInstance();
    //ConnexioBD con;
    std::ostringstream numTemp, numCap, numVisu;
    numTemp << numTemporada;
    numCap << numCapitol;
    numVisu << numVisualitzacions;
    
    std::string query = "INSERT INTO visualitzacio_capitol (sobrenom_usuari, titol_serie, num_temporada, num_capitol, data, num_visualitzacions) VALUES('" + sobrenom + "', '" + titolSerie + "', '" + numTemp.str() + "', '" + numCap.str() + "', '" + data + "', '" + numVisu.str() + "')";
    con.executarComanda(query);
}

void PassarelaVisualitzaCapitol::modifica() {

    ConnexioBD& con = ConnexioBD::getInstance();
    //ConnexioBD con;

    std::ostringstream numTemp, numCap, numVisu;
    numTemp << numTemporada;
    numCap << numCapitol;
    numVisu << numVisualitzacions;

std::string query = "UPDATE visualitzacio_capitol SET data = '" + data + "', num_visualitzacions = '" + numVisu.str() +
    "' WHERE sobrenom_usuari = '" + sobrenom + "' AND titol_serie = '" + titolSerie + "' AND num_temporada = '" + numTemp.str() +
    "' AND num_capitol = '" + numCap.str() + "'";



    con.executarComanda(query);
}


void PassarelaVisualitzaCapitol::esborra() {

    ConnexioBD& con = ConnexioBD::getInstance();
    //ConnexioBD con;
    std::ostringstream numTemp, numCap, numVisu;
    numTemp << numTemporada;
    numCap << numCapitol;
    con.executarComanda("DELETE FROM visualitzacio_capitol WHERE sobrenom_usuari = '" + sobrenom + "' AND titol_capitol = '" + titolSerie + "' AND num_capitol = '" + numCap.str() + "' AND num_temporada = '" + numTemp.str() + "'");

}