#include "CercadoraVisualitzaCapitol.h"

CercadoraVisualitzaCapitol::CercadoraVisualitzaCapitol(){ }

std::vector<PassarelaVisualitzaCapitol> CercadoraVisualitzaCapitol::cercaVisualitzacions(std::string sobrenomU) {

    std::vector<PassarelaVisualitzaCapitol> passareles;
    
    ConnexioBD& connexio = ConnexioBD::getInstance();
    std::string sql = "SELECT * FROM visualitzacio_capitol WHERE sobrenom_usuari ='" + sobrenomU + "' ORDER BY data DESC";
    sql::ResultSet* res = connexio.executarConsulta(sql);

    while (res->next()) {
        
        PassarelaVisualitzaCapitol passarela;
        passarela.posaSobrenom(res->getString("sobrenom_usuari"));
        passarela.posaTitolSerie(res->getString("titol_serie"));
        passarela.posaNumTemporada(res->getInt("num_temporada"));
        passarela.posaNumCapitol(res->getInt("num_capitol"));
        passarela.posaData(res->getString("data"));
        passarela.posaNumVisualitzacions(res->getInt("num_visualitzacions"));

        passareles.push_back(passarela);
    }
    delete res; // Alliberar memoria

    return passareles;
}

