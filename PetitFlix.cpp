#include "PetitFlix.h"


PetitFlix::PetitFlix() { }

PetitFlix& PetitFlix::getInstance() {

	static PetitFlix instance;
	return instance;
}

PassarelaUsuari PetitFlix::obteUsuari() {

	return usuari;
}

void PetitFlix::iniciaSessio(PassarelaUsuari pUsuari) {

	usuari = pUsuari;
}

void PetitFlix::actualitzaUsuari(PassarelaUsuari pUsuari) {

	usuari = pUsuari; // actualitzem l'usuari al Petit Flix. Mateixa funcionalitat que iniciarSessio, pero l'hem refet per questions d'estetica.
}

void PetitFlix::tancaSessio() {

	PassarelaUsuari pUsuari;
	usuari = pUsuari;
}

