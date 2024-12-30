#include "TxConsultaUsuari.h"

TxConsultaUsuari::TxConsultaUsuari(){ }

void TxConsultaUsuari::executa(){

    PetitFlix& petitF = PetitFlix::getInstance();
    usuari =  petitF.obteUsuari();
    
    std::string nomU;
    nomU = usuari.obteNom();
    std::string sobrenomU;
    sobrenomU = usuari.obteSobrenom();
    std::string correuU;
    correuU = usuari.obteCorreu();
    std::string dataNeixU;
    dataNeixU = usuari.obteDataNaixement();
    std::string modalitatU;
    modalitatU = usuari.obteModalitatSubs();

    DTOUsuari dto(nomU, sobrenomU, correuU, dataNeixU, modalitatU);
    resultat = dto;
}

DTOUsuari TxConsultaUsuari::obteResultat(){

    return resultat;
}

PassarelaUsuari TxConsultaUsuari::obteUsuari(){

    return usuari;
}