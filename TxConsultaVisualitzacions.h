#pragma once
#include <iostream>
#include "CercadoraVisualitzaPel.h"
#include "CercadoraVisualitzaCapitol.h"
#include "PetitFlix.h"
#include "DTOContingutMesVisualitzacioPel.h"
#include "DTOContingutMesVisualitzacioCap.h"
#include "CercadoraContingut.h"
class TxConsultaVisualitzacions
{

    public:
        struct Resultat {

            std::vector<DTOContingutMesVisualitzacioCap> vec_Cap;
            std::vector<DTOContingutMesVisualitzacioPel> vec_Pel;
        };
    private:

        Resultat result;
	public:

		TxConsultaVisualitzacions();

		void executa();

        TxConsultaVisualitzacions::Resultat obteResultat();
};

