#include "DTOEstrenes.h"

DTOEstrenes::DTOEstrenes(){

    dataEstrena = "";
    titol = "";
    qualificacioEdat = "";
    duracioOnumTemp = "";
    numCap = 0;
}

DTOEstrenes::DTOEstrenes(std::string dataEstrenaC, std::string titolC, std::string qualificacioEdatC, std::string duracioOnumTempC, int numCapC){

    dataEstrena = dataEstrenaC;
    titol = titolC;
    qualificacioEdat = qualificacioEdatC;
    duracioOnumTemp = duracioOnumTempC;
    numCap = numCapC;
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
int DTOEstrenes::obteNumCap() {

    return numCap;
}