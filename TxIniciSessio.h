#pragma once
#include <iostream>
#include "CercadoraUsuari.h"
#include "PetitFlix.h"
class TxIniciSessio
{
    private:	
		// creadora 
		
		std::string sobrenomU;
        std::string contrasenyaU;
	public: 
        TxIniciSessio (std::string sU, std::string cU);
		void executa();
};

