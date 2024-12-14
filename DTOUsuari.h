#pragma once
#include "PassarelaUsuari.h"
#include "CercadoraUsuari.h"

class DTOUsuari
{
private:
	std::string sobrenom = "";
	std::string nom = "";
	std::string correu = "";
public:
	DTOUsuari();
	DTOUsuari(PassarelaUsuari usu);
	std::string obteSobrenom();
	std::string obteNom();
	std::string obteCorreu();

	DTOUsuari consultaUsuari(std::string sobrenom);

};


