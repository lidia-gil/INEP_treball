#pragma once
#include <iostream>
#include "ConnexioBD.h"
#include <sstream> // Para std::ostringstream
class PassarelaContingut
{
    private:
        std::string titol;
        std::string descripcio;
        std::string qualificacio_edat; // o int pq és 7+ ?
        std::string tipus;
    public:
        PassarelaContingut();
        //constructora
        PassarelaContingut(std::string titolC, std::string descripcioC, std::string qualificacio_edatC, std::string tipusC);

        std::string obteTitol();
        std::string obteDescripcio();
        std::string obteQualificacioEdat();
        std::string obteTipus();

        void posaTitol(std::string titolC);
        void posaDescripcio(std::string descripcioC);
        void posaQualificacioEdat(std::string qualificacio_edatC);
        void posaTipus(std::string tipusC);

        void insereix();
        void modifica();
        void esborra();
};

