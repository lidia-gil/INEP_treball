#pragma once
#include <iostream>
#include "ConnexioBD.h"
class PassarelaTemporada
{
    private:

        std::string titol;
        int numTemporada;
    public:

        PassarelaTemporada();
        //constructora
        PassarelaTemporada(std::string titolS, int numTemp);

        std::string obteTitolSerie();
        int obteNumTemporada();

        void posaTitolSerie(std::string titolS);
        void posaNumTemporada(int numTemp);

        void insereix();
        void modifica();
        void esborra();
};

