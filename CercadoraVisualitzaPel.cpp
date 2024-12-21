#include "CercadoraVisualitzaPel.h"


std::vector<PassarelaVisualitzaPel> CercadoraVisualitzaPel::cercaVisualitzacions(std::string sobrenomU) {

    std::vector<PassarelaVisualitzaPel> passareles;

    try {
        ConnexioBD connexio;
        std::string sql = "SELECT * FROM visualitzacio_pelicula WHERE sobrenom_usuari ='" + sobrenomU + "'";
        sql::ResultSet* res = connexio.executarConsulta(sql);

        // Verificar si hay resultados
        while (res->next()) {
            PassarelaVisualitzaPel passarela;
            passarela.posaSobrenom(res->getString("sobrenom_usuari"));
            passarela.posaTitolPelicula(res->getString("titol_pelicula"));
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

