#pragma once
#include "ConnexioBD.h"
#include "CapaDeDomini.h"


// classe singleton

class CapaDePresentacio {
    private:
        CapaDePresentacio();
    public:
        //Metode per obtenir la �nica inst�ncia
        static CapaDePresentacio& getInstance();

        // aqu� tots els m�todes que
        void IniciSessio();
        void procesarRegistreUsuari();
        void procesarConsultaUsuari();
        void procesarEsborraUsuari();
};

