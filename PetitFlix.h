#pragma once
#include "PassarelaUsuari.h"
class PetitFlix
{
	private:	
		// creadora 
		PetitFlix();
		PassarelaUsuari usuari;
	public: 
		static PetitFlix& getInstance();
		PassarelaUsuari obteUsuari();
		void iniciaSessio(PassarelaUsuari);
		void tancaSessio();

};

