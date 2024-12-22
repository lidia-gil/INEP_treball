#pragma once
//#include "PassarelaUsuari.h"
//#include "CercadoraUsuari.h"
#include <iostream>

class DTOUsuari
{
	private:
		std::string sobrenom = "";
		std::string nom = "";
		std::string correu = "";
		std::string dataNeix = "";
		std::string modalitatSubscripcio = "";
	public:
		DTOUsuari();
		//DTOUsuari(PassarelaUsuari usu);
		DTOUsuari(std::string nomU, std::string sobrenomU, std::string correuElectronicU, std::string dataNaixementU, std::string modalitatSubU);
		std::string obteSobrenom();
		std::string obteNom();
		std::string obteCorreu();
		std::string obteDataNeix();
		std::string obteModalitatSubscripcio();

		//DTOUsuari consultaUsuari(std::string sobrenom)
};


