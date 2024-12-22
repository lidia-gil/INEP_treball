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

	DTOContingutPelicula dto(descripcio, qualificacioEdat, dataEstrena, duracio);
	return dto;
}

std::vector<DTOContingutPelicula> pelisRelacionades(std::string titolP) {


}