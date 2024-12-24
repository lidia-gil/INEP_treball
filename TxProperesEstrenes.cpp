#include "TxProperesEstrenes.h"

TxProperesEstrenes::TxProperesEstrenes(std::string modalitatEscollida, std::string dataHoraActual){

	modalitatSub = modalitatEscollida;
	dataHora = dataHoraActual;
}

void TxProperesEstrenes::executa() {

	if (modalitatSub == "."){ //obtenim la modalitat de subscripcio de l'usuari que ha iniciat sessi�

		PetitFlix& petitF = PetitFlix::getInstance();
		PassarelaUsuari usuari;
		usuari =  petitF.obteUsuari();

		modalitatSub = usuari.obteModalitatSubs();
	}
	if (modalitatSub == "Cinefil" or modalitatSub == "Completa"){

		std::vector<PassarelaContingut> passarelesPelicules;
		CercadoraContingut passarelaContingut;
		passarelesPelicules = passarelaContingut.cercaPerPelicula();
		CercadoraPelicula passarelaPelicula;

		int midaVecPelicules = passarelesPelicules.size();
		std::string titol, dataEstrena, qualificacioEdat, duracio;

		for (int i = 0; i < midaVecPelicules; i++ ) {

			titol = passarelesPelicules[i].obteTitol();

			PassarelaPelicula pelicula;
			pelicula = passarelaPelicula.cercaPerTitol(titol);
			dataEstrena = pelicula.obteDataEstrena();

			if (dataEstrena > dataHora) {
				qualificacioEdat = passarelesPelicules[i].obteQualificacioEdat();
				duracio = pelicula.obteDuracio();
				DTOProperesEstrenes dtoPel(dataEstrena, titol, qualificacioEdat, duracio, 0); //0 pq �s una pel.licula i no t� numero de capitol
				resultat.push_back(dtoPel);
			}
		}

		if (modalitatSub == "Completa") {

			CercadoraCapitol cercaCapitols;
			std::vector<PassarelaCapitol> passarelesCapitols;
			passarelesCapitols = cercaCapitols.cercaProximsCapitols(dataHora);


			int midaVecCapitols = passarelesCapitols.size();
			std::string titol, dataEstrena, qualificacioEdat;
			int numTemp, numCap;

			for (int i = 0; i < midaVecCapitols; i++) {

				titol = passarelesCapitols[i].obteTitolSerie();
				dataEstrena = passarelesCapitols[i].obteData();
				CercadoraContingut cercaCont;
				PassarelaContingut cont;
				cont = cercaCont.cercaPerTitol(titol);
				qualificacioEdat = cont.obteQualificacioEdat(); 

				numTemp = passarelesCapitols[i].obteNumTemporada();
				numCap = passarelesCapitols[i].obteNumCapitol();
				DTOProperesEstrenes dtoCap(dataEstrena, titol, qualificacioEdat, std::to_string(numTemp), numCap); 
				resultat.push_back(dtoCap);
			}

		}
	}
	
}

std::vector<DTOProperesEstrenes> TxProperesEstrenes::obteResultat() {

	return resultat;
}