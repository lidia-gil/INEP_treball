#pragma once
#include "PassarelaUsuari.h"
class CercadoraUsuari
{
    private:
        
        
    public:
        //Metode per obtenir la �nica inst�ncia
        static CercadoraUsuari& getInstance();
	    PassarelaUsuari cercaPerSobrenom(std::string sobrenomU);
};

