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
        //Metode per obtenir la única instància
        static CapaDePresentacio& getInstance();

        // aquí tots els métodes que
        void iniciSessio();
        void tancarSessio();
        void procesarRegistreUsuari();
        void procesarConsultaUsuari();
        void procesarEsborraUsuari();
};

