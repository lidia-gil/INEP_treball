#include "CercadoraContingutsRelacionats.h"

CercadoraContingutsRelacionats::CercadoraContingutsRelacionats(){ }

std::vector <PassarelaContingutsRelacionats> CercadoraContingutsRelacionats::cercaPerTitol(std::string titolC) {

    std::vector<PassarelaContingutsRelacionats> passareles;
    
    ConnexioBD& connexio = ConnexioBD::getInstance();
    std::string sql = "SELECT * FROM relacionat WHERE titol_x = '" + titolC + "' OR titol_y = '" + titolC + "'";
    sql::ResultSet* res = connexio.executarConsulta(sql);

    while (res->next()) {

        PassarelaContingutsRelacionats passarela;
        passarela.posaTitolContingutX(res->getString("titol_x"));
        passarela.posaTitolContingutY(res->getString("titol_y"));

        passareles.push_back(passarela); // afegir al vector
    }
    delete res; //Alliberar memoria

    return passareles;
}