#include "DTOContingutMesVisualitzacioCap.h"

DTOContingutMesVisualitzacioCap::DTOContingutMesVisualitzacioCap(){ }

DTOContingutMesVisualitzacioCap::DTOContingutMesVisualitzacioCap(std::string dataVisualitzacioU, std::string titolC, int num_TemporadaC, int num_CapitolC, std::string qualificacio_edatC, int visualitzacionsU){

    dataVisualitzacio = dataVisualitzacioU;
	titol = titolC;
	numTemporada = num_TemporadaC;
	numCapitol = num_CapitolC;
	qualificacioEdat = qualificacio_edatC;
	visualitzacions = visualitzacionsU;
}

std::string DTOContingutMesVisualitzacioCap::obteDataVisualitzacio() {

    return dataVisualitzacio;
}
std::string DTOContingutMesVisualitzacioCap::obteTitol() {

    return titol;
}
int DTOContingutMesVisualitzacioCap::obteNumTemporada() {

    return numTemporada;
}
int DTOContingutMesVisualitzacioCap::obteNumCapitol() {

    return numCapitol;
}
std::string DTOContingutMesVisualitzacioCap::obteQualificacioEdat() {

	return qualificacioEdat;
}
int DTOContingutMesVisualitzacioCap::obteVisualitzacions() {

	return visualitzacions;
}