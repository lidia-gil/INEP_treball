#pragma once
#include <iostream>
class DTOPelicula
{
        private:
            std::string dataEstrena;
            std::string titol;
            std::string qualificacioEdat;
            std::string duracio;
        public:
            DTOPelicula();
		    DTOPelicula(std::string dataEstrenaP, std::string titolP, std::string qualificacioEdatP, std::string duracioP);

            std::string obteData();
            std::string obteTitol();
            std::string obteQualificacioEdat();
            std::string obteDuracio();
    };

