#include "CercadoraVisualitzaPel.h"

CercadoraVisualitzaPel::CercadoraVisualitzaPel(){ }

std::vector<PassarelaVisualitzaPel> CercadoraVisualitzaPel::cercaVisualitzacions(std::string sobrenomU) {

    std::vector<PassarelaVisualitzaPel> passareles;
    
    ConnexioBD& connexio = ConnexioBD::getInstance();
    std::string sql = "SELECT * FROM visualitzacio_pelicula WHERE sobrenom_usuari ='" + sobrenomU + "' ORDER BY data DESC ";
    sql::ResultSet* res = connexio.executarConsulta(sql);

    while (res->next()) {
            
        PassarelaVisualitzaPel passarela;
        passarela.posaSobrenom(res->getString("sobrenom_usuari"));
        passarela.posaTitolPelicula(res->getString("titol_pelicula"));
        passarela.posaData(res->getString("data"));
        passarela.posaNumVisualitzacions(res->getInt("num_visualitzacions"));

        passareles.push_back(passarela); 
    }
    delete res; // Alliberar memoria
    
    return passareles;
}

