#pragma once
#include <iostream>
#include "ConnexioBD.h"
#include <sstream> // Para std::ostringstream
class PassarelaPelicula
{
    private:

        std::string titol;
        std::string dataEstrena;
        std::string duracio; 
    public:

        PassarelaPelicula();
        PassarelaPelicula(std::string titolP, std::string dataEstrenaP, std::string duracioP);

        std::string obteTitol();
        std::string obteDataEstrena();
        std::string obteDuracio();

        void posaTitol(std::string titolP);
        void posaDataEstrena(std::string dataEstrenaP);
        void posaDuracio(std::string duracioP);
        

        void insereix();
        void modifica();
        void esborra();
};

