#include "CtrlModificaUsuari.h"


CtrlModificaUsuari::CtrlModificaUsuari(){ }

DTOUsuari CtrlModificaUsuari::consultarUsuari(){
    
    TxConsultaUsuari tx;
    tx.executa();
    DTOUsuari dto;
    dto = tx.obteResultat();
    usuari = tx.obteUsuari();
    return dto;
}

void CtrlModificaUsuari::modificaUsuari(std::string nomU, std::string contraU, std::string correuU, std::string neixU, std::string modalitatU) {

    bool modificat = false;

    if (nomU != "" ) {

        usuari.posaNom(nomU);
        modificat = true;
    }

    if (contraU != ""){
        
        usuari.posaContrasenya(contraU);
        modificat = true;
    }

    if (correuU != "") {

        usuari.posaCorreu(correuU);
        modificat = true;
    }

    if (neixU != ""){

        usuari.posaDataNaixament(neixU);
        modificat = true;
    }

    if (modalitatU != ""){
        
        usuari.posaModalitatSubscripcio(modalitatU);
        modificat = true;
    }

    if (modificat) {

        usuari.modifica();

        PetitFlix& petitF = PetitFlix::getInstance();
        petitF.actualitzaUsuari(usuari);   
    }
}