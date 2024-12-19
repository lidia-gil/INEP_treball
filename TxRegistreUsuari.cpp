#include "TxRegistreUsuari.h"

TxRegistreUsuari::TxRegistreUsuari(std::string nom, std::string sobrenom, std::string contrasenya, 
	std::string correuElectronic, std::string data_naixement, std::string modalitat){

	nomU = nom;
    sobrenomU = sobrenom;
    contrasenyaU = contrasenya;
    correuElectronicU = correuElectronic;
    dataNaixementU = data_naixement;
    modalitatSubscripcio = modalitat;
}
	

void TxRegistreUsuari::executa() {
    
	PassarelaUsuari usuari(nomU, sobrenomU, contrasenyaU, correuElectronicU, dataNaixementU, modalitatSubscripcio);
    usuari.insereix();
}