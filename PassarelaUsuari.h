#pragma once
#include <iostream>
#include <sstream> 
#include "ConnexioBD.h"
class PassarelaUsuari
{
private: 

	std::string sobrenom;
	std::string nom;
	std::string contrasenya;
	std::string correuElectronic;
	std::string dataNaixement; 
	std::string modalitatSubs;

public:

	PassarelaUsuari();
	PassarelaUsuari(std::string nomU, std::string sobrenomU, std::string correuElectronicU, std::string contrasenyaU, std::string dataNaixement, std::string modalitatU);
	
	std::string obteSobrenom();
	std::string obteNom();
	std::string obteContrasenya();
	std::string obteCorreu();
	std::string obteDataNaixement();
	std::string obteModalitatSubs();

	
	void posaSobrenom(std::string sobrenomU);
	void posaNom(std::string nomU);
	void posaCorreu(std::string correuElectronicU);
	void posaContrasenya(std::string contrasenyaU);
	void posaDataNaixament(std::string DataNaixU);
	void posaModalitatSubscripcio(std::string modalitatU);

	
	void insereix(); 
	void modifica();
	void esborra();
};

