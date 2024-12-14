#include "CapaDeDomini.h"

CapaDeDomini::CapaDeDomini(){ }


CapaDeDomini& CapaDeDomini::getInstance() {
	static CapaDeDomini instance;
	return instance;
}

void CapaDeDomini::registrarUsuari(std::string sobrenomU, std::string nomU, std::string correuU) {
	// El vostre codi que monta la sentència SQL per fer l’INSERT i l’executa

	ConnexioBD connexio;
	std::string sql = "INSERT INTO usuari (sobrenom, nom, correu_electronic) VALUES('" + sobrenomU + "', '" + nomU + "', '" + correuU + "')";
	connexio.executarComanda(sql);
}
