#pragma once
#include <iostream>
#include "ConnexioBD.h"
class PassarelaContingutsRelacionats
{
	private:

        std::string titolContingutX;
        std::string titolContingutY;
    public:

        PassarelaContingutsRelacionats();
        PassarelaContingutsRelacionats(std::string titolContingutA, std::string titolContingutB);

        std::string obteTitolContingutX();
        std::string obteTitolContingutY();

        void posaTitolContingutX(std::string titolContingutA);
        void posaTitolContingutY(std::string titolContingutB);

        void insereix();
        void esborra();
};

