#include "TxPeliculesMesVistes.h"

TxPeliculesMesVistes::TxPeliculesMesVistes(std::string modalitatEscollida){

    modalitatSub = modalitatEscollida;
}

void TxPeliculesMesVistes::executa() {

    if (modalitatSub == "."){ //obtenim la modalitat de subscripcio de l'usuari que ha iniciat sessió

		PetitFlix& petitF = PetitFlix::getInstance();
		PassarelaUsuari usuari;
		usuari = petitF.obteUsuari();

		modalitatSub = usuari.obteModalitatSubs();
	}
    if (modalitatSub == "Cinefil" or modalitatSub == "Completa") {

        std::vector<PassarelaVisualitzaPel> passarelesVisualitzaPel;
		CercadoraPelicula cercaPeli;
        passarelesVisualitzaPel = cercaPeli.cercaTopPelicules();
		
        int midaVecPelicules = passarelesVisualitzaPel.size();
		std::string titol, duracio, qualificacioEdat;
        int numVisu;

        CercadoraContingut cercaCon;
        PassarelaPelicula pel;
        PassarelaContingut cont;

      
        for (int i = 0; i < midaVecPelicules; i++) {

            titol = passarelesVisualitzaPel[i].obteTitolPelicula();
            pel = cercaPeli.cercaPerTitol(titol);
            duracio = pel.obteDuracio();

            cont = cercaCon.cercaPerTitol(titol);
            qualificacioEdat = cont.obteQualificacioEdat();
            numVisu
        }
    }
    else{


    }

}

std::vector<PassarelaVisualitzaPel> TxPeliculesMesVistes::obteResultat() {


}