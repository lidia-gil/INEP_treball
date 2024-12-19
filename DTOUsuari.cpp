#include "DTOUsuari.h"

DTOUsuari::DTOUsuari() { }

DTOUsuari::DTOUsuari(std::string nomU, std::string sobrenomU, std::string correuElectronicU, std::string dataNaixementU, std::string modalitatSubU) {
	
	nom = nomU;
	sobrenom = sobrenomU;
	correu = correuElectronicU;
	dataNeix = dataNaixementU;
	modalitatSubscripcio = modalitatSubU;
}
std::string DTOUsuari::obteSobrenom() {
	return sobrenom; 
}
std::string DTOUsuari::obteNom() { 
	return nom; 
}
std::string DTOUsuari::obteCorreu() { 
	return correu; 
}
std::string DTOUsuari::obteDataNeix() {
	return dataNeix;
}
std::string DTOUsuari::obteModalitatSubscripcio() {
	return modalitatSubscripcio;
}

/*
DTOUsuari DTOUsuari::consultaUsuari(std::string sobrenom) {

	CercadoraUsuari cerca;
	PassarelaUsuari usu = cerca.cercaPerSobrenom(sobrenom);
	return DTOUsuari(usu);
}
*/

