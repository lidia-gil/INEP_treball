#pragma once
#include <iostream>
#include "ConnexioBD.h"
class PassarelaUsuari
{
private: 
	std::string sobrenom;
	std::string nom;
	std::string correu_electronic;

public:
	PassarelaUsuari();
	//constructora
	PassarelaUsuari(std::string sobrenomU, std::string nomU, std::string correuElectronicU);
	//obte
	std::string obteSobrenom();
	std::string obteNom();
	std::string obteCorreu();

	//posa
	void posaSobrenom(std::string sobrenomU);
	void posaNom(std::string nomU);
	void posaCorreu(std::string correuElectronicU);

	//insereix 
	void insereix();
		
	//modifica 

	//esborra
};

