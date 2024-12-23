#include "DTOCapitol.h"

DTOCapitol::DTOCapitol(){ 

	numCapitol = 0;
	titol = "";
	dataPublicacio = "";
	dataVisualitzacio = "";
}

DTOCapitol::DTOCapitol(int numCapitolC, std::string titolC, std::string dataPublicacioC, std::string dataVisualitzacioU){

	numCapitol = numCapitolC;
	titol = titolC;
	dataPublicacio = dataPublicacioC;
	dataVisualitzacio = dataVisualitzacioU;
}


int DTOCapitol::obteNumCapitol() {

    return numCapitol;
}
std::string DTOCapitol::obteTitol() {

    return titol;
}
std::string DTOCapitol::obteDataPublicacio() {

    return dataPublicacio;
}
std::string DTOCapitol::obteDataVisualitzacio() {

    return dataVisualitzacio;
}