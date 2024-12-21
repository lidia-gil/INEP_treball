#include "TxInfoVisualitzacions.h"

TxInfoVisualitzacions::TxInfoVisualitzacions(){

    result.nP = 0;
    result.nS = 0;
}

void TxInfoVisualitzacions::executa(){

    PetitFlix& petitF = PetitFlix::getInstance();
    PassarelaUsuari usuari;
    usuari =  petitF.obteUsuari();
        
    std::string sobrenomU;
    sobrenomU = usuari.obteSobrenom();

    std::vector<PassarelaVisualitzaPel> vectorPelicules;
    CercadoraVisualitzaPel visualitzacionsPel;
    
    vectorPelicules = visualitzacionsPel.cercaVisualitzacions(sobrenomU);

    result.nP = vectorPelicules.size();
}

TxInfoVisualitzacions::Resultat TxInfoVisualitzacions::obteResultat() const {

    return result;
}
