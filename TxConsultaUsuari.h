#pragma once
#include "PassarelaUsuari.h"
#include "PetitFlix.h"
#include "DTOUsuari.h"

class TxConsultaUsuari
{
	private:

		PassarelaUsuari usuari;
        DTOUsuari resultat;
	public:

		TxConsultaUsuari();
		void executa();
        DTOUsuari obteResultat();
};

