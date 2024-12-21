#pragma once
#include "PassarelaUsuari.h"
#include "DTOUsuari.h"
#include "CercadoraUsuari.h"
#include "TxConsultaUsuari.h";
class CtrlModificaUsuari
{
    private:
        PassarelaUsuari usuari;
    public:
        CtrlModificaUsuari();
        DTOUsuari consultarUsuari();
        void modificaUsuari(std::string nomU, std::string contraU, std::string correuU, std::string neixU, std::string modalitatU);
};

