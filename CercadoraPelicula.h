#pragma once
#include "PassarelaPelicula.h"
#include "PassarelaVisualitzaPel.h"
#include <vector>
#include <stdexcept>
class CercadoraPelicula
{

    private:

    public:
        CercadoraPelicula();
        PassarelaPelicula cercaPerTitol (std::string titolP);
        std::vector<PassarelaVisualitzaPel> cercaTopPelicules();
        std::vector<PassarelaVisualitzaPel> cercaTopPeliculesInfantils();
        std::vector < PassarelaPelicula> cercaUltimesPelicules(std::string dataHora);
};

