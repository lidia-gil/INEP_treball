#include "PassarelaUsuari.h"

PassarelaUsuari::PassarelaUsuari(){ }

PassarelaUsuari::PassarelaUsuari(std::string sobrenomU, std::string nomU, std::string correuElectronicU) {
	
	sobrenom = sobrenomU; // sobrenom atribut privat de la classe
	nom = nomU; // nom atribut privat de la classe
	correu_electronic = correuElectronicU; // correuElectronic atribut
}

std::string PassarelaUsuari::obteSobrenom() {

	return sobrenom;
}
std::string PassarelaUsuari::obteNom() {

	return nom;
}
std::string PassarelaUsuari::obteCorreu() {

	return correu_electronic;
}

void PassarelaUsuari::posaSobrenom(std::string sobrenomU) {

	sobrenom=sobrenomU;
}
void PassarelaUsuari::posaNom(std::string nomU){

	nom = nomU;
}
void PassarelaUsuari::posaCorreu(std::string correuElectronicU){
	
	correu_electronic = correuElectronicU;
}

void PassarelaUsuari::insereix() {

	ConnexioBD con;
	//ConnexioBD con = ConnexioBD::getInstance();
	std::string query = "INSERT INTO usuari (sobrenom, nom, correu_electronic) VALUES('" + sobrenom + "', '" + nom + "', '" + correu_electronic + "')";
	con.executarComanda(query);
}

