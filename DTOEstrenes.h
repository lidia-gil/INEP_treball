#pragma once
#include <iostream>
class DTOEstrenes
{
        private:
            std::string dataEstrena;
            std::string titol;
            std::string qualificacioEdat;
            std::string duracioOnumTemp;
            int numCapOnumVisu;
        public:
            DTOEstrenes();
		    DTOEstrenes(std::string dataEstrenaC, std::string titolC, std::string qualificacioEdatC, std::string duracioOnumTempC, int numCapOnumVisuC);

            std::string obteData();
            std::string obteTitol();
            std::string obteQualificacioEdat();
            std::string obteDuracioOnumTemp();
            int obteNumCapOnumVisu();
 };

