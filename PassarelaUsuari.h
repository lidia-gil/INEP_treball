#pragma once
#include <iostream>
#include "ConnexioBD.h"
class PassarelaUsuari
{
private: 
	std::string sobrenom;
	std::string nom;
	std::string contrasenya;
	std::string correu_electronic;
	//std::string dataNaixament; (DATE)?
	std::string modalitatSubscripcio;

public:
	PassarelaUsuari();
	//constructora
	PassarelaUsuari(std::string sobrenomU, std::string nomU, std::string correuElectronicU);
	//obte
	//FALTAN OBTE I POSA PER FER, DE MOMENT NO ELS HEM NECESITAT
	std::string obteSobrenom();
	std::string obteNom();
	std::string obteContrasenya();
	std::string obteCorreu();

	//posa
	void posaSobrenom(std::string sobrenomU);
	void posaNom(std::string nomU);
	void posaCorreu(std::string correuElectronicU);
	void posaContrasenya(std::string contrasenyaU);

	//insereix 
	void insereix();
		
	//modifica 

	//esborra
};

