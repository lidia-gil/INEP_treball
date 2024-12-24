#include "DTOProperesEstrenes.h"

DTOProperesEstrenes::DTOProperesEstrenes(){

}

DTOProperesEstrenes::DTOProperesEstrenes(std::string dataEstrenaC, std::string titolC, std::string qualificacioEdatC, std::string duracioOnumTempC, int numCapC){

    dataEstrena = dataEstrenaC;
    titol = titolC;
    qualificacioEdat = qualificacioEdatC;
    duracioOnumTemp = duracioOnumTempC;
    numCap = numCapC;
}

std::string DTOProperesEstrenes::obteData(){

    return dataEstrena;
}
std::string DTOProperesEstrenes::obteTitol(){

    return titol;
}
std::string DTOProperesEstrenes::obteQualificacioEdat(){

    return qualificacioEdat;
}
std::string DTOProperesEstrenes::obteDuracioOnumTemp(){

    return duracioOnumTemp;
}

int DTOProperesEstrenes::obteNumCap() {

    return numCap;
}