#pragma once
#include <iostream>
#include <vector>
#include "PassarelaContingut.h"
#include "CercadoraContingut.h"
#include "PassarelaPelicula.h"
#include "CercadoraPelicula.h"
#include "DTOEstrenes.h"
#include "CercadoraCapitol.h"
#include "PassarelaCapitol.h"
#include "PetitFlix.h"
#include "PassarelaUsuari.h"
class TxUltimesNovetats
{
    private:

		std::string dataHora;
		std::string modalitatSub;
        std::vector<DTOEstrenes> resultat;
    public:

        TxUltimesNovetats(std::string modalitatEscollida, std::string dataHoraActual);
        void executa();
        std::vector<DTOEstrenes> obteResultat();
};

