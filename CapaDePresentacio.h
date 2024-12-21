#pragma once
#include "ConnexioBD.h"
#include "TxIniciSessio.h"
#include "TxTancaSessio.h"
#include "TxRegistreUsuari.h"
#include "TxConsultaUsuari.h"
#include "TxInfoVisualitzacions.h"
#include "CtrlModificaUsuari.h"
// classe singleton

class CapaDePresentacio {
    private:
        
        CapaDePresentacio();
    public:
        bool sessioIniciadaCorrectament = true;
        //Metode per obtenir la única instància
        static CapaDePresentacio& getInstance();

        // aquí tots els métodes que
        void iniciSessio();
        void tancarSessio();
        void procesarRegistreUsuari();
        void procesarConsultaUsuari();
        void procesarEsborraUsuari();
        void procesarModificarUsuari();
};

