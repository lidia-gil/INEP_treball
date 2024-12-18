#pragma once
#include "PassarelaUsuari.h"
class PetitFlix
{
	private:	
		PetitFlix();
		PassarelaUsuari usuari;
	public: 
		static PetitFlix& getInstance();
		PassarelaUsuari obtéUsuari();
		void iniciaSessió(PassarelaUsuari);
		void tancaSessió();
};

