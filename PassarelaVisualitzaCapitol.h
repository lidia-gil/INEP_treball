#pragma once
#include <iostream>
#include "ConnexioBD.h"
#include <sstream> // Para std::ostringstream
class PassarelaVisualitzaCapitol
{
    private:

        std::string sobrenom;
        std::string titolSerie;
        int numVisualitzacions;
        int numTemporada;
        int numCapitol;
        std::string data;
    public:

        PassarelaVisualitzaCapitol();
        PassarelaVisualitzaCapitol(std::string sobrenomU, std::string titolSerieV, int numVisualitzacionsU, int numTemporadaV, int numCapitolV, std::string dataV);

        std::string obteSobrenom();
        std::string obteTitolSerie();
        int obteNumVisualitzacions();
        int obteNumTemporada();
        int obteNumCapitol();
        std::string obteData();

        void posaSobrenom(std::string sobrenomU);
        void posaTitolSerie(std::string titolSerieV);
        void posaNumVisualitzacions(int numVisualitzacionsV);
        void posaNumTemporada(int numTemporadaV);
        void posaNumCapitol(int numCapitolV);
        void posaData(std::string dataV);

        void insereix();
        void modifica();
        void esborra();
};

