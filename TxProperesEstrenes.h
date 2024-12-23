#pragma once
#include <iostream>
#include <vector>
#include "PassarelaContingut.h"
#include "CercadoraContingut.h"
#include "PassarelaPelicula.h"
#include "CercadoraPelicula.h"
#include "DTOPelicula.h"

class TxProperesEstrenes
{
	private:
		std::string dataHora;
		std::string modalitatSub;
		std::vector<DTOPelicula> resultat;
	public:

		TxProperesEstrenes(std::string modalitatEscollida, std::string dataHoraActual);
		void executa();
		std::vector<DTOPelicula> obteResultat();
		//PassarelaUsuari obteUsuari();
};

