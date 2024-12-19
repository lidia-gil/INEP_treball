#include "CapaDeDomini.h"

CapaDeDomini::CapaDeDomini(){ }


CapaDeDomini& CapaDeDomini::getInstance() {
	static CapaDeDomini instance;
	return instance;
}

/*void CapaDeDomini::registrarUsuari(std::string sobrenomU, std::string nomU, std::string correuU) {
	// El vostre codi que monta la sentència SQL per fer l’INSERT i l’executa

	//PassarelaUsuari& pasarela = PassarelaUsuari::getInstance();
	PassarelaUsuari usuari(sobrenomU, nomU, correuU);
	usuari.insereix();
}*/

/*DTOUsuari CapaDeDomini::consultarUsuari(std::string sobrenomU) {

	CercadoraUsuari cerca;
	DTOUsuari dto = cerca.cercaPerSobrenom(sobrenomU);
	return dto;
}*/



