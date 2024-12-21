#pragma once
#include<iostream>
#include "PassarelaUsuari.h"
#include "PetitFlix.h"
class TxEsborraUsuari
{
	private:

        std::string contraU;
	public:

		TxEsborraUsuari(std::string contraU);

		void executa();
};

