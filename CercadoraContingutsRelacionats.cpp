#include "CercadoraContingutsRelacionats.h"

CercadoraContingutsRelacionats::CercadoraContingutsRelacionats(){ }

std::vector <PassarelaContingutsRelacionats> CercadoraContingutsRelacionats::cercaPerTitol(std::string titolC) {

    std::vector<PassarelaContingutsRelacionats> passareles;
    /*try {*/
        ConnexioBD connexio;
        std::string sql = "SELECT * FROM relacionat WHERE titol_x = '" + titolC + "' OR titol_y = '" + titolC + "'";
        sql::ResultSet* res = connexio.executarConsulta(sql);

        // Verificar si hay resultados
        while (res->next()) {
            PassarelaContingutsRelacionats passarela;
            passarela.posaTitolContingutX(res->getString("titol_x"));
            passarela.posaTitolContingutY(res->getString("titol_y"));

            passareles.push_back(passarela); // afegir al vector
        }


        delete res; // Liberar memoria
    /*}
    catch (const sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }*/
    return passareles;
}