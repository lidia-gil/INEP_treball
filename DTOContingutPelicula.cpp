#include "DTOContingutPelicula.h"

DTOContingutPelicula::DTOContingutPelicula(){ }

DTOContingutPelicula::DTOContingutPelicula(std::string descripcioP, std::string qualificacioP, std::string dataEstrenaP, std::string duracioP){
    
    descripcio = descripcioP;
    qualificacio = qualificacioP;
    duracio = duracioP;
    dataEstrena = dataEstrenaP;
}

std::string DTOContingutPelicula::obteDescripcio() {

    return descripcio;
}
std::string DTOContingutPelicula::obteQualificacioEdat() {

    return qualificacio;
}
std::string DTOContingutPelicula::obteDuracio() {

    return duracio;
}
std::string DTOContingutPelicula::obteDataEstrena(){

    return dataEstrena;
}