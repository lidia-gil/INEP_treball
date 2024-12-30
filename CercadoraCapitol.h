#pragma once
#include <vector>
#include "PassarelaCapitol.h"
class CercadoraCapitol
{
    private:

    public:

        CercadoraCapitol();
        
        PassarelaCapitol cercaCapitol(std::string titolS, int numTemp, int numCap);
        std::vector<PassarelaCapitol> cercaPerTitoliTemporada(std::string titolS, int numTemp);
        std::vector<PassarelaCapitol> cercaProximsCapitols(std::string datraHora);
        std::vector<PassarelaCapitol> cercaUltimsCapitols(std::string datraHora);
};

