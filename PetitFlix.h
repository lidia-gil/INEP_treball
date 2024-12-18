#pragma once
#include "PassarelaUsuari.h"
class PetitFlix
{
	private:	
		PetitFlix();
		PassarelaUsuari usuari;
	public: 
		static PetitFlix& getInstance();
		PassarelaUsuari obt�Usuari();
		void iniciaSessi�(PassarelaUsuari);
		void tancaSessi�();
};

