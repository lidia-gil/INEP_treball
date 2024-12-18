#pragma once
#include "PassarelaUsuari.h"
class PetitFlix
{
	private:	
		PetitFlix();
		PassarelaUsuari u;
	public: 
		static PetitFlix& getInstance();
		PassarelaUsuari obtéUsuari();
};

