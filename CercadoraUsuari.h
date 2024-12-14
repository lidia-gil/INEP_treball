#pragma once
#include "PassarelaUsuari.h"
class CercadoraUsuari
{
    private:
        
        
    public:
        //Metode per obtenir la única instància
        static CercadoraUsuari& getInstance();
	    PassarelaUsuari cercaPerSobrenom(std::string sobrenomU);
};

