#pragma once
#include<iostream>
#include "PassarelaUsuari.h"
#include "PetitFlix.h"
#include "TxTancaSessio.h"
class TxEsborraUsuari
{
	private:

        std::string contraU;
	public:

		TxEsborraUsuari(std::string contraU);
		void executa();
};

