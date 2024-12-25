#include "DTOPeliculesMesVistes.h"
DTOPeliculesMesVistes::DTOPeliculesMesVistes(){

    dataEstrena = "";
    titol = "";
    qualificacioEdat = "";
    duracio = "";
    numVisu = 0;
    vista = false;
}

DTOPeliculesMesVistes::DTOPeliculesMesVistes(std::string dataEstrenaC, std::string titolC, std::string qualificacioEdatC, std::string duracioC, int numVisuC, bool vistaC){

    dataEstrena = dataEstrenaC;
    titol = titolC;
    qualificacioEdat = qualificacioEdatC;
    duracio = duracioC;
    numVisu = numVisuC;
    vista = vistaC;
}

std::string DTOPeliculesMesVistes::obteData(){

    return dataEstrena;
}
std::string DTOPeliculesMesVistes::obteTitol(){

    return titol;
}
std::string DTOPeliculesMesVistes::obteQualificacioEdat(){

    return qualificacioEdat;
}
std::string DTOPeliculesMesVistes::obteDuracioOnumTemp(){

    return duracio;
}

int DTOPeliculesMesVistes::obteNumVisu() {

    return numVisu;
}
bool DTOPeliculesMesVistes::obteVista(){

    return vista;
}