#pragma once
#include "CercadoraTemporada.h"
#include "PassarelaTemporada.h"
#include "PassarelaVisualitzaCapitol.h"
#include "CercadoraCapitol.h"
#include "PassarelaCapitol.h"
#include "PassarelaUsuari.h"
#include "PetitFlix.h"
#include "CercadoraVisualitzaCapitol.h"

#include "DTOCapitol.h"

#include "PassarelaContingut.h"
#include "CercadoraContingut.h"
class CtrlVisualitzarCapitol
{
    private:

	public: 

		CtrlVisualitzarCapitol();

        int consultaNumeroTemporades(std::string titolS);

        std::vector<DTOCapitol> consultaCapitols (std::string titolS, int numTemp);

		void registrarVisualitzacio(std::string titolS, int numTemp, int numCap, std::string dataHora);
};

