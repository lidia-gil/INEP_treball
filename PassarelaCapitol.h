#pragma once
#include <iostream>
#include "ConnexioBD.h"
class PassarelaCapitol
{
    private:

        std::string titolSerie;
        int numTemporada;
        int numCapitol;
        std::string titol;
        std::string dataEstrena;
    public:

        PassarelaCapitol();
        PassarelaCapitol(std::string titolS, int numTemp, int numeroCap, std::string titolCap, std::string data);

        std::string obteTitolSerie();
        int obteNumTemporada();
        int obteNumCapitol();
        std::string obteTitolCapitol();
        std::string obteData();

        void posaTitolSerie(std::string titolS);
        void posaNumTemporada(int numTemp);
        void posaNumCapitol(int numCap);
        void posaTitolCapitol(std::string titolCap);
        void posaDataEstrena(std::string dataEstrenaC);

        void insereix();
        void modifica();
        void esborra();
};

