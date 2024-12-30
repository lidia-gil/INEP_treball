#pragma once
#include "DTOContingutPelicula.h"
#include "CercadoraPelicula.h"
#include "CercadoraContingut.h"
#include "PassarelaPelicula.h"
#include "PassarelaContingut.h"
#include "PassarelaVisualitzaPel.h"
#include "CercadoraVisualitzaPel.h"
#include "PassarelaContingutsRelacionats.h"
#include "CercadoraContingutsRelacionats.h"
#include "PetitFlix.h"
class CtrlVisualitzarPel
{
	private:

	public: 

		CtrlVisualitzarPel();
        
		DTOContingutPelicula consultaInfoPeli(std::string titolP, std::string dataHora);
		void registrarVisualitzacions(std::string titolP, std::string dataHora);
		std::vector<DTOContingutPelicula> pelisRelacionades(std::string titolP);
};
