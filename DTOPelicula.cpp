#include "DTOPelicula.h"


DTOPelicula::DTOPelicula(){ }

DTOPelicula::DTOPelicula(std::string dataEstrenaP, std::string titolP, std::string qualificacioEdatP, std::string duracioP){

    dataEstrena = dataEstrenaP;
    titol = titolP;
    qualificacioEdat = qualificacioEdatP;
    duracio = duracioP;
}

std::string DTOPelicula::obteData(){

    return dataEstrena;
}
std::string DTOPelicula::obteTitol(){

    return titol;
}
std::string DTOPelicula::obteQualificacioEdat(){

    return qualificacioEdat;
}
std::string DTOPelicula::obteDuracio(){

    return duracio;
}