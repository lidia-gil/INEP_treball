#pragma once
#include "PassarelaVisualitzaPel.h"
#include "CercadoraPelicula.h"
#include "DTOEstrenes.h"
#include "PetitFlix.h"
#include "PassarelaPelicula.h"
#include "CercadoraContingut.h"
class TxPeliculesMesVistes
{

	private:
        std::string modalitatSub;
        std::vector<DTOEstrenes> resultat;
	public:

		TxPeliculesMesVistes(std::string modalitatEscollida);
		void executa();
		std::vector<PassarelaVisualitzaPel> obteResultat();
};

