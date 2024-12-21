#pragma once
#include <iostream>
#include "ConnexioBD.h"
class PassarelaVisualitzaPel
{
    private:
        std::string sobrenom;
        std::string titolPelicula;
        std::string data;
        int numVisualitzacions;
    public:
        PassarelaVisualitzaPel();
        //constructora
        PassarelaVisualitzaPel(std::string sobrenomU, std::string titolPeliculaV, std::string dataV, int numVisualitzacionsU);

        std::string obteSobrenom ();
        std::string obteTitolPelicula ();
        std::string obteData ();
        int obteNumVisualitzacions ();

        void posaSobrenom (std::string sobrenomU);
        void posaTitolPelicula (std::string titolPeliculaV);
        void posaData (std::string dataV);
        void posaNumVisualitzacions (int numVisualitzacionsV);

        void insereix();
        void modifica();
        void esborra();
};

