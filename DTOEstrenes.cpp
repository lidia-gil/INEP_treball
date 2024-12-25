#include "DTOEstrenes.h"

DTOEstrenes::DTOEstrenes(){

}

DTOEstrenes::DTOEstrenes(std::string dataEstrenaC, std::string titolC, std::string qualificacioEdatC, std::string duracioOnumTempC, int numCapOnumVisuC){

    dataEstrena = dataEstrenaC;
    titol = titolC;
    qualificacioEdat = qualificacioEdatC;
    duracioOnumTemp = duracioOnumTempC;
    numCapOnumVisu = numCapOnumVisuC;
}

std::string DTOEstrenes::obteData(){

    return dataEstrena;
}
std::string DTOEstrenes::obteTitol(){

    return titol;
}
std::string DTOEstrenes::obteQualificacioEdat(){

    return qualificacioEdat;
}
std::string DTOEstrenes::obteDuracioOnumTemp(){

    return duracioOnumTemp;
}

int DTOEstrenes::obteNumCapOnumVisu() {

    return numCapOnumVisu;
}