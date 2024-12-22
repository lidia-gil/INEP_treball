#pragma once
#include <iostream>
class DTOContingutMesVisualitzacioCap
{
	private:
		std::string dataVisualitzacio = "";
		std::string titol = "";
		int numTemporada = 0;
		int numCapitol = 0;
		std::string qualificacioEdat = "";
		int visualitzacions = 0;
	public:
		DTOContingutMesVisualitzacioCap();
		//DTOUsuari(PassarelaUsuari usu);
		DTOContingutMesVisualitzacioCap(std::string dataVisualitzacioU, std::string titolC, int num_TemporadaC, int num_CapitolC, std::string qualificacio_edatC, int visualitzacionsU);
		std::string obteDataVisualitzacio();
		std::string obteTitol();
        int obteNumTemporada();
        int obteNumCapitol();
		std::string obteQualificacioEdat();
		int obteVisualitzacions();
};

