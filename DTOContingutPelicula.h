#pragma once
#include "PassarelaPelicula.h"

class DTOContingutPelicula
{
	private:
        std::string titol;
        std::string descripcio;
        std::string qualificacio;
        std::string duracio;
        std::string dataEstrena;
	public:
        
        DTOContingutPelicula();
        DTOContingutPelicula(std::string titolP, std::string descripcioP, std::string qualificacioP, std::string duracioP, std::string dataEstrenaP);
        std::string obteTitol();
        std::string obteDescripcio();
        std::string obteQualificacioEdat();
        std::string obteDuracio();
        std::string obteDataEstrena();
};