#include "TxPeliculesMesVistes.h"

TxPeliculesMesVistes::TxPeliculesMesVistes(std::string modalitatEscollida){

    modalitatSub = modalitatEscollida;
}

void TxPeliculesMesVistes::executa() {

    bool sessioIniciada = false;
    std::string sobrenom;
    if (modalitatSub == "."){ //obtenim la modalitat de subscripcio de l'usuari que ha iniciat sessió

        sessioIniciada=true;
		PetitFlix& petitF = PetitFlix::getInstance();
		PassarelaUsuari usuari;
		usuari = petitF.obteUsuari();

        sobrenom = usuari.obteSobrenom();

		modalitatSub = usuari.obteModalitatSubs();
	}
    


    if (modalitatSub == "Cinefil" or modalitatSub == "Completa") {
        std::vector<PassarelaVisualitzaPel> passarelesVisualitzaPel;
        CercadoraPelicula cercaPeli;
        passarelesVisualitzaPel = cercaPeli.cercaTopPelicules();
		
        int midaVecPelicules = passarelesVisualitzaPel.size();
		std::string titol, duracio, qualificacioEdat, data;
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

            numVisu = passarelesVisualitzaPel[i].obteNumVisualitzacions();

            data = passarelesVisualitzaPel[i].obteData();

            bool vista = false;
            if ( sessioIniciada){

                std::vector <PassarelaVisualitzaPel> pelVistes;
                CercadoraVisualitzaPel cercaPelVistaPerUsuari;
                pelVistes = cercaPelVistaPerUsuari.cercaVisualitzacions(sobrenom);
                
                int j=0;
                int midaPelVistes = pelVistes.size();
                while (not vista and j < midaPelVistes) {

                    std::string titolP = pelVistes[j].obteTitolPelicula();
                    if (titol == titolP) {

                        vista = true;
                        data = pelVistes[j].obteData();
                    }
                    ++j;
                }
            }
            DTOPeliculesMesVistes dto(data, titol, qualificacioEdat, duracio, numVisu, vista);
            resultat.push_back(dto);
        }
    }
    else{


    }

}

std::vector<DTOPeliculesMesVistes> TxPeliculesMesVistes::obteResultat() {

    return resultat;
}