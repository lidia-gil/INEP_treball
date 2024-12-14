#include "DTOUsuari.h"

DTOUsuari::DTOUsuari() { }

DTOUsuari::DTOUsuari(PassarelaUsuari usu) {
	sobrenom = usu.obteSobrenom();
	nom = usu.obteNom();
	correu = usu.obteCorreu();
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

DTOUsuari DTOUsuari::consultaUsuari(std::string sobrenom) {

	CercadoraUsuari& cerca = CercadoraUsuari::getInstance();
	PassarelaUsuari usu = cerca.cercaPerSobrenom(sobrenom);
	return DTOUsuari(usu);
}