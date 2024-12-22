#pragma once
#include <iostream>
class DTOContingutMesVisualitzacioPel
{

	private:
		std::string dataVisualitzacio = "";
		std::string titol = "";
		std::string descripcio = "";
		std::string qualificacioEdat = "";
		int visualitzacions = 0;
	public:
		DTOContingutMesVisualitzacioPel();
		//DTOUsuari(PassarelaUsuari usu);
		DTOContingutMesVisualitzacioPel(std::string dataVisualitzacioU, std::string titolC, std::string descripcioC, std::string qualificacio_edatC, int visualitzacionsU);
		std::string obteDataVisualitzacio();
		std::string obteTitol();
		std::string obteDescripcio();
		std::string obteQualificacioEdat();
		int obteVisualitzacions();

		//DTOUsuari consultaUsuari(std::string sobrenom);
};

