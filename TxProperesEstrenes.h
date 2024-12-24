#pragma once
#include <iostream>
#include <vector>
#include "PassarelaContingut.h"
#include "CercadoraContingut.h"
#include "PassarelaPelicula.h"
#include "CercadoraPelicula.h"
#include "DTOProperesEstrenes.h"
#include "CercadoraCapitol.h"
#include "PassarelaCapitol.h"
#include "PetitFlix.h"
#include "PassarelaUsuari.h"

class TxProperesEstrenes
{
	private:
		std::string dataHora;
		std::string modalitatSub;
		std::vector<DTOProperesEstrenes> resultat;
	public:

		TxProperesEstrenes(std::string modalitatEscollida, std::string dataHoraActual);
		void executa();
		std::vector<DTOProperesEstrenes> obteResultat();
		//PassarelaUsuari obteUsuari();
};

