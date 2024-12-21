#include "TxIniciSessio.h"

TxIniciSessio::TxIniciSessio(std::string sU, std::string cU){
    
    sobrenomU = sU;
    contrasenyaU = cU;
}

void TxIniciSessio::executa(){

    CercadoraUsuari cercadoraU;
    PassarelaUsuari usuari;
    usuari = cercadoraU.cercaPerSobrenom(sobrenomU);
    std::string contrasenyaRealUsuari;
    contrasenyaRealUsuari = usuari.obteContrasenya();
    if (contrasenyaRealUsuari != contrasenyaU) {

        throw std::runtime_error("Algun dels parametres no existeix o es incorrecte");
    }
    PetitFlix& petitFlix = PetitFlix::getInstance();
    petitFlix.iniciaSessio(usuari);
}   