#pragma once
#include <iostream>
class DTOPeliculesMesVistes
{
    private:

        std::string dataEstrena;
        std::string titol;
        std::string qualificacioEdat;
        std::string duracio;
        int numVisu;
        bool vista;

    public:

        DTOPeliculesMesVistes();
        DTOPeliculesMesVistes(std::string dataEstrenaC, std::string titolC, std::string qualificacioEdatC, std::string duracioC, int numVisuC, bool vista);

        std::string obteData();
        std::string obteTitol();
        std::string obteQualificacioEdat();
        std::string obteDuracioOnumTemp();
        int obteNumVisu();
        bool obteVista();
};

