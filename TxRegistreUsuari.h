#pragma once
#include "PassarelaUsuari.h"
class TxRegistreUsuari
{
	private:

        std::string nomU;
        std::string sobrenomU;
        std::string contrasenyaU;
        std::string correuElectronicU;
        std::string dataNaixementU;
        std::string modalitatSubscripcio;
    public:

        TxRegistreUsuari(std::string nomU, std::string sobrenomU, std::string contrasenyaU, std::string coreuElectronicU, std::string data_naixementU, std::string modalitatSubscripcio);
        void executa();
};

