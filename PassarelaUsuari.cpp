#include "PassarelaUsuari.h"
//#include <iomanip>

PassarelaUsuari::PassarelaUsuari(){ 
	
	sobrenom = "";
	nom = "";
	contrasenya = "";
	correuElectronic = "";
	dataNaixement = "";
	modalitatSubs = "";
}

PassarelaUsuari::PassarelaUsuari( std::string nomU, std::string sobrenomU, std::string contrasenyaU,
	std::string correuElectronicU, std::string dataNaixementU, std::string modalitatU) {
	
	sobrenom = sobrenomU; // sobrenom atribut privat de la classe
	nom = nomU; // nom atribut privat de la classe
	contrasenya = contrasenyaU;
	correuElectronic = correuElectronicU; // correuElectronic atribut
	dataNaixement = dataNaixementU;
	modalitatSubs = modalitatU;
}

std::string PassarelaUsuari::obteSobrenom() {

	return sobrenom;
}
std::string PassarelaUsuari::obteNom() {

	return nom;
}
std::string PassarelaUsuari::obteContrasenya() {

	return contrasenya;
}
std::string PassarelaUsuari::obteCorreu() {

	return correuElectronic;
}
std::string PassarelaUsuari::obteDataNaixement() {

	return dataNaixement;
}
std::string PassarelaUsuari::obteModalitatSubs() {

	return modalitatSubs;
}



void PassarelaUsuari::posaSobrenom(std::string sobrenomU) {

	sobrenom=sobrenomU;
}
void PassarelaUsuari::posaNom(std::string nomU){

	nom = nomU;
}
void PassarelaUsuari::posaCorreu(std::string correuElectronicU){
	
	correuElectronic = correuElectronicU;
}
void PassarelaUsuari::posaContrasenya(std::string contrasenyaU) {

	contrasenya = contrasenyaU;
}
void PassarelaUsuari::posaDataNaixament(std::string DataNaixU) {

	dataNaixement = DataNaixU;
}
void PassarelaUsuari::posaModalitatSubscripcio(std::string modalitatU) {

	modalitatSubs = modalitatU;
}

void PassarelaUsuari::insereix() {

	ConnexioBD& con = ConnexioBD::getInstance();
	//ConnexioBD con;

	std::string query = "INSERT INTO usuari (sobrenom, nom, correu_electronic, contrasenya, data_naixement, subscripcio) VALUES('" + sobrenom + "', '" + nom + "', '" + correuElectronic + "' , '" + contrasenya + "' , '" + dataNaixement +  "' , '" + modalitatSubs + "')";
	con.executarComanda(query);
}

void PassarelaUsuari::modifica(){

	ConnexioBD& con = ConnexioBD::getInstance();
	//ConnexioBD con;

    std::string query = "UPDATE usuari SET nom = '" + nom + "', correu_electronic = '" + correuElectronic + "', contrasenya = '" + contrasenya + "', data_naixement = '" + dataNaixement + "', subscripcio = '" + modalitatSubs + "' WHERE sobrenom = '" + sobrenom + "'";
    con.executarComanda(query);
}

void PassarelaUsuari::esborra(){

	ConnexioBD& con = ConnexioBD::getInstance();
	//ConnexioBD con;

	std::string query = "DELETE FROM usuari WHERE sobrenom = '" + sobrenom + "'";
	con.executarComanda(query);
}