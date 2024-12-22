#pragma once
#include "DTOContingutPelicula.h"
#include "CercadoraPelicula.h"
#include "CercadoraContingut.h"
#include "PassarelaPelicula.h"
#include "PassarelaContingut.h"
class CtrlVisualitzarPel
{
	private:

        std::string titolPelicula;
	public: 

		CtrlVisualitzarPel();

        DTOContingutPelicula consultaInfoPeli(std::string titolP);

		std::vector<DTOContingutPelicula> pelisRelacionades(std::string titolP);
};

