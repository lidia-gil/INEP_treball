#include "TxEsborraUsuari.h"

TxEsborraUsuari::TxEsborraUsuari(std::string contra) {
    contraU = contra;
}

void TxEsborraUsuari::executa() {

	PassarelaUsuari usuari;
	PetitFlix& petitF = PetitFlix::getInstance();
	usuari = petitF.obteUsuari();
    std::string contrasenya = usuari.obteContrasenya();
    if (contrasenya != contraU){

        throw std::runtime_error("La contrasenya proporcionada no es valida, l'usuari no s'ha esborrat.");
    }
    usuari.esborra();
}