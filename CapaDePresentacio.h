#pragma once
#include "ConnexioBD.h"
#include "TxIniciSessio.h"
#include "TxTancaSessio.h"
#include "TxRegistreUsuari.h"
#include "TxConsultaUsuari.h"
#include "TxInfoVisualitzacions.h"
#include "CtrlModificaUsuari.h"
#include "TxEsborraUsuari.h"
#include "TxConsultaVisualitzacions.h"
#include "CtrlVisualitzarPel.h"
#include "CtrlVisualitzarCapitol.h"
#include "TxProperesEstrenes.h"
#include "TxUltimesNovetats.h"
#include "TxPeliculesMesVistes.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

// classe singleton
class CapaDePresentacio {
    private:
        
        //Constructora en privat pq �s singleton
        CapaDePresentacio();
    public:

        bool sessioIniciada = true;
        //Metode per obtenir la �nica inst�ncia
        static CapaDePresentacio& getInstance();

        // aqu� tots els m�todes que ens demanen
        void iniciSessio();
        void tancarSessio();
        void procesarRegistreUsuari();
        void procesarConsultaUsuari();
        void procesarEsborraUsuari();
        void procesarModificarUsuari();
        void procesarVisualitzarPel();
        void procesarVisualitzarCapitol();
        void procesarConsultaVisualitzacions();
        void procesarProperesEstrenes();
        void procesarUltimesNovetats();
        void procesarPeliculesMesVistes();
};

