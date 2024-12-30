#pragma once
#include "PassarelaUsuari.h"
class PetitFlix
{
	private:	

		PetitFlix();
		PassarelaUsuari usuari;
	public: 

		static PetitFlix& getInstance();
		PassarelaUsuari obteUsuari();
		void iniciaSessio(PassarelaUsuari);
		void actualitzaUsuari(PassarelaUsuari);
		void tancaSessio();
};

