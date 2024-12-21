#include "CercadoraVisualitzaCapitol.h"


std::vector<PassarelaVisualitzaCapitol> CercadoraVisualitzaCapitol::cercaVisualitzacions(std::string sobrenomU) {

    std::vector<PassarelaVisualitzaCapitol> passareles;

    try {
        ConnexioBD connexio;
        std::string sql = "SELECT * FROM visualitzacio_capitol WHERE sobrenom_usuari ='" + sobrenomU + "'";
        sql::ResultSet* res = connexio.executarConsulta(sql);

        // Verificar si hay resultados
        while (res->next()) {
            PassarelaVisualitzaCapitol passarela;
            passarela.posaSobrenom(res->getString("sobrenom_usuari"));
            passarela.posaTitolSerie(res->getString("titol_serie"));
            passarela.posaNumTemporada(res->getInt("num_temporada"));
            passarela.posaNumCapitol(res->getInt("num_capitol"));
            passarela.posaData(res->getString("data"));
            passarela.posaNumVisualitzacions(res->getInt("num_visualitzacions"));

            passareles.push_back(passarela); // Añadir al vector
        }

        // Si el vector sigue vacío, el usuario no existe
        if (passareles.empty()) {

            throw std::runtime_error("Usuari no existeix");
        }

        delete res; // Liberar memoria
    }
    catch (const sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
    return passareles;
}

