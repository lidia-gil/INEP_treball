#include "TxUltimesNovetats.h"



TxUltimesNovetats::TxUltimesNovetats(std::string modalitatEscollida, std::string dataHoraActual) {

    modalitatSub = modalitatEscollida;
    dataHora = dataHoraActual;
}
void TxUltimesNovetats::executa(){

    if (modalitatSub == "."){ //obtenim la modalitat de subscripcio de l'usuari que ha iniciat sessió

		PetitFlix& petitF = PetitFlix::getInstance();
		PassarelaUsuari usuari;
		usuari = petitF.obteUsuari();

		modalitatSub = usuari.obteModalitatSubs();
	}
	if (modalitatSub == "Cinefil" or modalitatSub == "Completa") {

		std::vector<PassarelaPelicula> passarelesPelicules;
		CercadoraPelicula cercadoraPelicula;
		passarelesPelicules = cercadoraPelicula.cercaUltimesPelicules(dataHora);

		int midaVecPelicules = passarelesPelicules.size();
		std::string titol, dataEstrena, qualificacioEdat, duracio;

		CercadoraContingut cercaCont;

		for (int i = 0; i < midaVecPelicules; i++) {

			titol = passarelesPelicules[i].obteTitol();

			PassarelaContingut cont;
			cont = cercaCont.cercaPerTitol(titol);
			qualificacioEdat = cont.obteQualificacioEdat();

			duracio = passarelesPelicules[i].obteDuracio();
			dataEstrena = passarelesPelicules[i].obteDataEstrena();
			DTOEstrenes dtoPel(dataEstrena, titol, qualificacioEdat, duracio, 0); //0 pq és una pel.licula i no té numero de capitol
			resultat.push_back(dtoPel);
			
		}

		//ordenem les pelis
		// Bubble Sort per ordenar `resultat` en ordre descendent segons `dataEstrena`
		//for (size_t i = 0; i < resultat.size(); i++) { 
		//	for (size_t j = 0; j < resultat.size() - i - 1; j++) {
		//		if (resultat[j].obteData() < resultat[j + 1].obteData()) {
		//
		//			std::swap(resultat[j], resultat[j + 1]);
		//		}
		//	}
		//}
		// Ens quedem només amb els 5 primers elements si n'hi ha més de 5
		//if (resultat.size() > 5) {
		//	resultat.resize(5);
		// }

		if (modalitatSub == "Completa") {

			CercadoraCapitol cercaCapitols;
			std::vector<PassarelaCapitol> passarelesCapitols;
			passarelesCapitols = cercaCapitols.cercaUltimsCapitols(dataHora);


			int midaVecCapitols = passarelesCapitols.size();
			std::string titol, dataEstrena, qualificacioEdat;
			int numTemp, numCap;

			for (int i = 0; i < midaVecCapitols and i < 5; i++) {

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
	else { //modalitatSub == "Infantil"

		std::vector<PassarelaContingut> passarelesPelicules;
		CercadoraContingut passarelaContingut;
		passarelesPelicules = passarelaContingut.cercaPeliInfantil(); // cerca les infantils on qualificacioEdat == TP
		CercadoraPelicula passarelaPelicula;

		int midaVecPelicules = passarelesPelicules.size();
		std::string titol, dataEstrena, qualificacioEdat, duracio;
		for (int i = 0; i < midaVecPelicules; i++) {

			titol = passarelesPelicules[i].obteTitol();
			PassarelaPelicula pelicula;
			pelicula = passarelaPelicula.cercaPerTitol(titol);
			dataEstrena = pelicula.obteDataEstrena();
			if (dataEstrena < dataHora) { // s'ha estrenat

				qualificacioEdat = passarelesPelicules[i].obteQualificacioEdat();
				duracio = pelicula.obteDuracio();
				DTOEstrenes dtoPel(dataEstrena, titol, qualificacioEdat, duracio, 0); //0 pq és una pel.licula i no té numero de capitol
				resultat.push_back(dtoPel);
			}
		}

		//ordenem les pelis
		// Bubble Sort per ordenar `resultat` en ordre descendent segons `dataEstrena`
		for (size_t i = 0; i < resultat.size(); i++) {
			for (size_t j = 0; j < resultat.size() - i - 1; j++) {
				if (resultat[j].obteData() < resultat[j + 1].obteData()) {

					std::swap(resultat[j], resultat[j + 1]);
				}
			}
		}
		// Ens quedem només amb els 5 primers elements si n'hi ha més de 5
		if (resultat.size() > 5) {
			resultat.resize(5);
		}

		CercadoraCapitol cercaCapitols;
		std::vector<PassarelaCapitol> passarelesCapitols;
		passarelesCapitols = cercaCapitols.cercaUltimsCapitols(dataHora);


		int midaVecCapitols = passarelesCapitols.size();
		int numTemp, numCap;
		for (int i = 0; i < midaVecCapitols and i < 5; i++) {

			titol = passarelesCapitols[i].obteTitolSerie();
			dataEstrena = passarelesCapitols[i].obteData();
			CercadoraContingut cercaCont;
			PassarelaContingut cont;
			cont = cercaCont.cercaPerTitol(titol);
			qualificacioEdat = cont.obteQualificacioEdat();
			if (qualificacioEdat == "TP") {
				
				numTemp = passarelesCapitols[i].obteNumTemporada();
				numCap = passarelesCapitols[i].obteNumCapitol();
				DTOEstrenes dtoCap(dataEstrena, titol, qualificacioEdat, std::to_string(numTemp), numCap);
				resultat.push_back(dtoCap);
			}
		}
	}
}
std::vector<DTOEstrenes> TxUltimesNovetats::obteResultat(){

    return resultat;
}

