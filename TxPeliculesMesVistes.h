#pragma once
#include "PassarelaVisualitzaPel.h"
#include "CercadoraPelicula.h"
#include "PetitFlix.h"
#include "PassarelaPelicula.h"
#include "CercadoraContingut.h"
#include "CercadoraVisualitzaPel.h"
#include "DTOPeliculesMesVistes.h"
class TxPeliculesMesVistes
{
	private:

        std::string modalitatSub;
        std::vector<DTOPeliculesMesVistes> resultat;
	public:

		TxPeliculesMesVistes(std::string modalitatEscollida);
		void executa();
		std::vector<DTOPeliculesMesVistes> obteResultat();
};

