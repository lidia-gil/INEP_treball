#include "CtrlVisualitzarPel.h"
#include <string>
CtrlVisualitzarPel::CtrlVisualitzarPel() { }


DTOContingutPelicula CtrlVisualitzarPel::consultaInfoPeli(std::string titolP, std::string dataHora) {

	PassarelaPelicula pelicula;
	CercadoraPelicula cercaPeli;

	pelicula = cercaPeli.cercaPerTitol(titolP);

	std::string dataEstrena, duracio;
	dataEstrena = pelicula.obteDataEstrena();

	// Comparem si la Data D'estrena de la pel.licula és major que la actual
	//-------------------------------------------
	if (dataEstrena > dataHora){
		
		throw std::runtime_error("La pelicula encara no s'ha estrenat. S'estrenara el '" + dataEstrena.substr(0, 10) + "'.");
	}
	//-------------------------------------------
	duracio = pelicula.obteDuracio();

	PassarelaContingut contingut;
	CercadoraContingut cercaCont;

	contingut = cercaCont.cercaPerTitol(titolP);

	std::string descripcio, qualificacioEdat;
	descripcio = contingut.obteDescripcio();
	qualificacioEdat = contingut.obteQualificacioEdat();

	DTOContingutPelicula dto(titolP, descripcio, qualificacioEdat, dataEstrena, duracio);
	return dto;
}

void CtrlVisualitzarPel::registrarVisualitzacions(std::string titolP, std::string dataHora) {

	std::vector <PassarelaVisualitzaPel> visualitzaPel;
	CercadoraVisualitzaPel cercaPel;

	PassarelaUsuari usuari;
	PetitFlix& petitF = PetitFlix::getInstance();
	usuari = petitF.obteUsuari();

	std::string sobrenomU;
	sobrenomU = usuari.obteSobrenom();

	// comparació data Naixement del Usuari amb la qualificació d'edat de la pel.licula 
	//----------------------------------------------------

	PassarelaContingut cont;
	CercadoraContingut cercaCont;
	cont = cercaCont.cercaPerTitol(titolP);

	std::string qualificacioEdat = cont.obteQualificacioEdat();
	if (qualificacioEdat != "TP"){

		std::string modalitatSub = usuari.obteModalitatSubs();
		if (modalitatSub == "Infantil"){

			throw std::runtime_error("L'usuari loguejat no pot veure la pelicula, degut a que la seva modalitat de subscripcio es infantil.");
		}
		std::string edat;
		int i=0;
		while (qualificacioEdat[i] != '+'){

			edat+=qualificacioEdat[i]; 
			i++;
		}
		
		std::string dataNaixement = usuari.obteDataNaixement();

		//Calculem l'edat de l'usuari a partir de la data de neixament i la data actual:
		int edatUsuari = 0;
		if (dataNaixement.substr(0, 4) <= dataHora.substr(0, 4)) { // Comparar anys
			edatUsuari = std::stoi(dataHora.substr(0, 4)) - std::stoi(dataNaixement.substr(0, 4));

			// Verificar si ja ha complert anys aquest any
			if (dataNaixement.substr(5, 2) > dataHora.substr(5, 2) ||  // Si el mes no ha arribat
			(dataNaixement.substr(5, 2) == dataHora.substr(5, 2) && dataNaixement.substr(8, 2) > dataHora.substr(8, 2))) { // Si el dia no ha arribat
				edatUsuari--;
			}
		}
		
		if ( std::stoi(edat) > edatUsuari){
			
			throw std::runtime_error("L'usuari loguejat no pot veure la pelicula. Edat de l'usuari: '" +  std::to_string(edatUsuari) + "' Edat necessaria: '" + edat + "'.");

		}
			
	}
	//-----------------------------------------------------
	

	visualitzaPel = cercaPel.cercaVisualitzacions(sobrenomU);
	bool trobat = false;
	int i = 0;
    while ((not trobat) and (i < visualitzaPel.size())){

		std::string titolC = visualitzaPel[i].obteTitolPelicula();
        if (titolC == titolP){
            trobat = true;
        }
		else {
			++i;
		}
    }
	if (trobat) {
		
        int visualitzacions = visualitzaPel[i].obteNumVisualitzacions();
		visualitzaPel[i].posaNumVisualitzacions(++visualitzacions);
		visualitzaPel[i].posaData(dataHora);
		visualitzaPel[i].modifica();
	}
	else {

		PassarelaVisualitzaPel peli(sobrenomU, titolP, dataHora, 1);
        peli.insereix();
	}
}

std::vector<DTOContingutPelicula> CtrlVisualitzarPel::pelisRelacionades(std::string titolP) {

	
	std::vector <PassarelaContingutsRelacionats> vecRelacionats;
	CercadoraContingutsRelacionats contingutsRel;
	vecRelacionats = contingutsRel.cercaPerTitol(titolP);

	std::vector<DTOContingutPelicula> vecDTOContingutPeli (vecRelacionats.size());

	int midaPeliculesRelacionades = vecRelacionats.size();

	std::string titolX, titolY, titolRelacionat;

	for (int i = 0; i < midaPeliculesRelacionades; i++) {

		titolX = vecRelacionats[i].obteTitolContingutX();
		titolY = vecRelacionats[i].obteTitolContingutY();

		if (titolX != titolP) {

			titolRelacionat = titolX;
		}
		else {

            titolRelacionat = titolY;
		}
		PassarelaPelicula pelicula;
		CercadoraPelicula cercaPeli;

		pelicula = cercaPeli.cercaPerTitol(titolRelacionat);

		std::string dataEstrena, duracio;
		dataEstrena = pelicula.obteDataEstrena();
		duracio = pelicula.obteDuracio();   

		PassarelaContingut contingut;
		CercadoraContingut cercaCont;

		contingut = cercaCont.cercaPerTitol(titolRelacionat);

		std::string descripcio, qualificacioEdat;
		descripcio = contingut.obteDescripcio();
		qualificacioEdat = contingut.obteQualificacioEdat();


		DTOContingutPelicula dto(titolRelacionat, descripcio, qualificacioEdat, dataEstrena, duracio);
		vecDTOContingutPeli[i] = dto;
	}
	return vecDTOContingutPeli;
}