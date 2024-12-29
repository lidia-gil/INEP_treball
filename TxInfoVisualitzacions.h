#pragma once
#include "PassarelaUsuari.h"
#include "CercadoraVisualitzaPel.h"
#include "CercadoraVisualitzaCapitol.h"
#include "PetitFlix.h"
class TxInfoVisualitzacions
{
    public:
        struct Resultat {
            int nP;
            int nS;
        };
    private:

        Resultat result;
    public:
        
        TxInfoVisualitzacions();
        void executa();
        Resultat obteResultat() const;
};

