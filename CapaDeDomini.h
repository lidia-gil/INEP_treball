#pragma once
#include <iostream>
#include "ConnexioBD.h"
class CapaDeDomini
{
	private:
		CapaDeDomini();
	public:
		//Metode per obtenir la única instància
		static CapaDeDomini& getInstance();

		void registrarUsuari(std::string sobrenomU, std::string nomU, std::string correuU);

};

