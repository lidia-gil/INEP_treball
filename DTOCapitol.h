#pragma once
#include <iostream>
class DTOCapitol
{
    private:

		int numCapitol = 0;
		std::string titol = "";
		std::string dataPublicacio = "";
		std::string dataVisualitzacio = "";
		
	public:

		DTOCapitol();
		DTOCapitol(int numCapitolC, std::string titolC, std::string dataPublicacioC, std::string dataVisualitzacioU);
		
		int obteNumCapitol();
		std::string obteTitol();
		std::string obteDataPublicacio();
		std::string obteDataVisualitzacio();
};

