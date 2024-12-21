#pragma once
#include "ConnexioBD.h"
#include "CapaDeDomini.h"
#include "TxIniciSessio.h"
#include "TxTancaSessio.h"
#include "TxRegistreUsuari.h"
#include "TxConsultaUsuari.h"
#include "TxInfoVisualitzacions.h"
// classe singleton

class CapaDePresentacio {
    private:
        CapaDePresentacio();
    public:
        //Metode per obtenir la �nica inst�ncia
        static CapaDePresentacio& getInstance();

        // aqu� tots els m�todes que
        void iniciSessio();
        void tancarSessio();
        void procesarRegistreUsuari();
        void procesarConsultaUsuari();
        void procesarEsborraUsuari();
};

