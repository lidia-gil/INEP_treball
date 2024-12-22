#include "CtrlVisualitzarPel.h"

CtrlVisualitzarPel::CtrlVisualitzarPel() { }


DTOContingutPelicula CtrlVisualitzarPel::consultaInfoPeli(std::string titolP) {

	PassarelaPelicula pelicula;
	CercadoraPelicula cercaPeli;

	pelicula = cercaPeli.cercaPerTitol(titolP);

	std::string dataEstrena, duracio;
	dataEstrena = pelicula.obteDataEstrena();
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

	visualitzaPel = cercaPel.cercaVisualitzacions(titolP);
	bool trobat = false;
	int i = 0;
    while ((not trobat) and (i < visualitzaPel.size())){

		std::string titolC = visualitzaPel[i].obteTitolPelicula();
        if (titolC == titolP){
            trobat = true;
        }
		++i;
    }
	if (trobat) {

        int visualitzacions = visualitzaPel[i].obteNumVisualitzacions();
		visualitzaPel[i].posaNumVisualitzacions(++visualitzacions);
		visualitzaPel[i].posaData(dataHora);
		visualitzaPel[i].modifica();
	}
	else {

		PassarelaUsuari usuari;
        PetitFlix& petitF = PetitFlix::getInstance();
		usuari = petitF.obteUsuari();
 
        std::string sobrenomU;
		sobrenomU = usuari.obteSobrenom();
        
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