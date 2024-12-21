#include "TxConsultaVisualitzacions.h"
TxConsultaVisualitzacions::TxConsultaVisualitzacions(){ }



void TxConsultaVisualitzacions::executa(){
    
    PassarelaUsuari usuari;
    PetitFlix& petitF = PetitFlix::getInstance();
    usuari = petitF.obteUsuari();

    std::string sobrenomU;
    sobrenomU = usuari.obteSobrenom();

    CercadoraVisualitzaPel visualitzacionsPel;
    result.vec_Pel = visualitzacionsPel.cercaVisualitzacions(sobrenomU);

    CercadoraVisualitzaCapitol visualitzacionsCapitol;
    result.vec_Cap = visualitzacionsCapitol.cercaVisualitzacions(sobrenomU);
}

TxConsultaVisualitzacions::Resultat TxConsultaVisualitzacions::obteResultat() {

    return result;
}