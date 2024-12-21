#pragma once
#include <iostream>
#include "CercadoraVisualitzaPel.h"
#include "CercadoraVisualitzaCapitol.h"
#include "PetitFlix.h"
class TxConsultaVisualitzacions
{

    public:
        struct Resultat {

            std::vector<PassarelaVisualitzaCapitol> vec_Cap;
            std::vector<PassarelaVisualitzaPel> vec_Pel;
        };
    private:

        Resultat result;
	public:

		TxConsultaVisualitzacions();

		void executa();

        TxConsultaVisualitzacions::Resultat obteResultat();
};

