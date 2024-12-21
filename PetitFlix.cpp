#include "PetitFlix.h"


PetitFlix::PetitFlix() { }
PetitFlix& PetitFlix::getInstance() {

	static PetitFlix instance;
	return instance;
}

PassarelaUsuari PetitFlix::obteUsuari() {

	return usuari;	// retornem usuari que és un atribut privat
}

void PetitFlix::iniciaSessio(PassarelaUsuari pUsuari) {

	usuari = pUsuari;
}

void PetitFlix::actualitzaUsuari(PassarelaUsuari pUsuari) {

	usuari = pUsuari;
}

void PetitFlix::tancaSessio() {

	PassarelaUsuari pUsuari;
	usuari = pUsuari;
}

