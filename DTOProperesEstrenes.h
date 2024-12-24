#pragma once
#include <iostream>
class DTOProperesEstrenes
{
        private:
            std::string dataEstrena;
            std::string titol;
            std::string qualificacioEdat;
            std::string duracioOnumTemp;
            int numCap;
        public:
            DTOProperesEstrenes();
		    DTOProperesEstrenes(std::string dataEstrenaC, std::string titolC, std::string qualificacioEdatC, std::string duracioOnumTempC, int numCapC);

            std::string obteData();
            std::string obteTitol();
            std::string obteQualificacioEdat();
            std::string obteDuracioOnumTemp();
            int obteNumCap();
 };

