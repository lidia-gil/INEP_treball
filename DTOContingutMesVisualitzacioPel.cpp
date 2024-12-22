#include "DTOContingutMesVisualitzacioPel.h"

DTOContingutMesVisualitzacioPel::DTOContingutMesVisualitzacioPel(){ }

DTOContingutMesVisualitzacioPel::DTOContingutMesVisualitzacioPel(std::string dataVisualitzacioU, std::string titolC, std::string descripcioC, std::string qualificacio_edatC, int visualitzacionsU) {

    dataVisualitzacio = dataVisualitzacioU;
    titol = titolC;
    descripcio = descripcioC;
    qualificacioEdat = qualificacio_edatC;
    visualitzacions = visualitzacionsU;
}
std::string DTOContingutMesVisualitzacioPel::obteDataVisualitzacio(){

    return  dataVisualitzacio;
}
std::string DTOContingutMesVisualitzacioPel::obteTitol(){

    return titol;
}
std::string DTOContingutMesVisualitzacioPel::obteDescripcio(){

    return descripcio;
}
std::string DTOContingutMesVisualitzacioPel::obteQualificacioEdat(){

    return qualificacioEdat;
}
int DTOContingutMesVisualitzacioPel::obteVisualitzacions(){
        
    return visualitzacions;
}