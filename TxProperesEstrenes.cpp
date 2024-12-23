#include "TxProperesEstrenes.h"

TxProperesEstrenes::TxProperesEstrenes(std::string modalitatEscollida, std::string dataHoraActual){

	modalitatSub = modalitatEscollida;
	dataHora = dataHoraActual;
}

void TxProperesEstrenes::executa() {

	std::vector<PassarelaContingut> passarelesPelicules;
	CercadoraContingut passarelaContingut;
	passarelesPelicules = passarelaContingut.cercaPerTipus();
	CercadoraPelicula passarelaPelicula;

	int midaVecPelicules = passarelesPelicules.size();
	std::string titol, dataEstrena, qualificacioEdat, duracio;

	for (int i = 0; i < midaVecPelicules; i++ ) {
		titol = passarelesPelicules[i].obteTitol();

		PassarelaPelicula pelicula;
		pelicula = passarelaPelicula.cercaPerTitol(titol);
		dataEstrena = pelicula.obteDataEstrena();

		if ( dataEstrena > dataHora ) {

			qualificacioEdat = passarelesPelicules[i].obteQualificacioEdat();
			duracio = pelicula.obteDuracio();
			DTOPelicula dtoPel(dataEstrena, titol, qualificacioEdat, duracio);
			resultat.push_back(dtoPel);
		}
	}
}

std::vector<DTOPelicula> TxProperesEstrenes::obteResultat() {

	return resultat;
}