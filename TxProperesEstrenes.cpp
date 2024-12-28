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

		std::vector<PassarelaPelicula> passarelesPelicules;
		CercadoraPelicula cercaPel;
		passarelesPelicules = cercaPel.cercaProperesPelicules(dataHora);
		CercadoraContingut cercaCont;

		int midaVecPelicules = passarelesPelicules.size();
		std::string titol, dataEstrena, qualificacioEdat, duracio;

		for (int i = 0; i < midaVecPelicules; i++ ) {

			titol = passarelesPelicules[i].obteTitol();

			PassarelaContingut cont;
			cont = cercaCont.cercaPerTitol(titol);
			qualificacioEdat = cont.obteQualificacioEdat();

			duracio = passarelesPelicules[i].obteDuracio();
			dataEstrena = passarelesPelicules[i].obteDataEstrena();
			DTOEstrenes dtoPel(dataEstrena, titol, qualificacioEdat, duracio, 0); //0 pq �s una pel.licula i no t� numero de capitol
			resultat.push_back(dtoPel);
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
				DTOEstrenes dtoCap(dataEstrena, titol, qualificacioEdat, std::to_string(numTemp), numCap); 
				resultat.push_back(dtoCap);
			}
		}
	}
	else{ //modalitatSub == "Infantil"

		std::vector<PassarelaPelicula> passarelesPelicules;
		CercadoraPelicula cercaPel;
		passarelesPelicules = cercaPel.cercaProperesPelicules(dataHora);
		CercadoraContingut cercaCont;

		int midaVecPelicules = passarelesPelicules.size();
		std::string titol, dataEstrena, qualificacioEdat, duracio;
		
		for (int i = 0; i < midaVecPelicules; i++ ) {
			
			titol = passarelesPelicules[i].obteTitol();
			PassarelaContingut cont;
			cont = cercaCont.cercaPerTitol(titol);
			qualificacioEdat = cont.obteQualificacioEdat();

			if (qualificacioEdat == "TP") {

				dataEstrena = passarelesPelicules[i].obteDataEstrena();
				duracio = passarelesPelicules[i].obteDuracio();
				DTOEstrenes dtoPel(dataEstrena, titol, qualificacioEdat, duracio, 0); //0 pq �s una pel.licula i no t� numero de capitol
				resultat.push_back(dtoPel);
			}
		}

		CercadoraCapitol cercaCapitols;
		std::vector<PassarelaCapitol> passarelesCapitols;
		passarelesCapitols = cercaCapitols.cercaProximsCapitols(dataHora);


		int midaVecCapitols = passarelesCapitols.size();
		int numTemp, numCap;

		for (int i = 0; i < midaVecCapitols; i++) {

			titol = passarelesCapitols[i].obteTitolSerie();
			dataEstrena = passarelesCapitols[i].obteData();
			CercadoraContingut cercaCont;
			PassarelaContingut cont;
			cont = cercaCont.cercaPerTitol(titol);
			qualificacioEdat = cont.obteQualificacioEdat();
			if ( qualificacioEdat == "TP" ) {
				numTemp = passarelesCapitols[i].obteNumTemporada();
				numCap = passarelesCapitols[i].obteNumCapitol();
				DTOEstrenes dtoCap(dataEstrena, titol, qualificacioEdat, std::to_string(numTemp), numCap);
				resultat.push_back(dtoCap);
			}
		}
	}
}

std::vector<DTOEstrenes> TxProperesEstrenes::obteResultat() {

	return resultat;
}