#include "CercadoraPelicula.h"

CercadoraPelicula::CercadoraPelicula(){ }

PassarelaPelicula CercadoraPelicula::cercaPerTitol(std::string titolP){

    PassarelaPelicula pelicula;
    //ConnexioBD con;
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string sql = "SELECT * FROM pelicula WHERE titol = '" + titolP + "'";
    sql::ResultSet* res = con.executarConsulta(sql);
    // Si no troba cap fila, activa excepciÃ³
    if (!res->next()) {
        //throw exception("Usuari no existeix");  // no ens funciona aquesta operació 
        throw std::runtime_error("La pelicula consultada no existeix");
    }
    else {
        pelicula.posaTitol(res->getString("titol"));
        pelicula.posaDataEstrena(res->getString("data_estrena"));
        pelicula.posaDuracio(res->getString("duracio"));
        delete res;
    }
    return pelicula;
}

//std::vector<PassarelaPelicula> CercadoraPelicula::cercaPerDataEstrena() {

//}


std::vector<PassarelaVisualitzaPel> CercadoraPelicula::cercaTopPelicules() {

    std::vector<PassarelaVisualitzaPel> peliculesMésVistes;
    ConnexioBD& con = ConnexioBD::getInstance();

    // Consulta SQL per obtenir les 5 pel·lícules més visualitzades
    std::string sql = "SELECT sobrenom_usuari, titol_pelicula, data, SUM(num_visualitzacions) AS num_visualitzacions "
        "FROM visualitzacio_pelicula "
        "GROUP BY titol_pelicula "
        "ORDER BY num_visualitzacions DESC, data DESC "
        "LIMIT 5";

    sql::ResultSet* res = con.executarConsulta(sql);

    // Si no troba cap fila, retorna un vector buit
    if (!res) {
        throw std::runtime_error("No s'han trobat pel·lícules més vistes.");
    }

    // Iterem sobre el resultat i omplim el vector
    while (res->next()) {
        PassarelaVisualitzaPel pel;
        pel.posaSobrenom(res->getString("sobrenom_usuari"));
        pel.posaTitolPelicula(res->getString("titol_pelicula"));
        pel.posaData(res->getString("data"));
        pel.posaNumVisualitzacions(res->getInt("num_visualitzacions"));
        peliculesMésVistes.push_back(pel);
    }

    delete res;
    return peliculesMésVistes;
}

std::vector<PassarelaVisualitzaPel> CercadoraPelicula::cercaTopPeliculesInfantils() {

    std::vector<PassarelaVisualitzaPel> peliculesMésVistes;
    ConnexioBD& con = ConnexioBD::getInstance();

    // Consulta SQL per obtenir les 5 pel·lícules més visualitzades amb qualificació "TP"
    std::string sql = "SELECT sobrenom_usuari, titol_pelicula, data, SUM(num_visualitzacions) AS num_visualitzacions "
        "FROM visualitzacio_pelicula "
        "JOIN pelicula ON visualitzacio_pelicula.titol_pelicula = pelicula.titol "
        "WHERE pelicula.qualificacio_edat = 'TP' "
        "GROUP BY titol_pelicula "
        "ORDER BY num_visualitzacions DESC, data DESC "
        "LIMIT 5";

    sql::ResultSet* res = con.executarConsulta(sql);

    // Si no troba cap fila, retorna un vector buit
    if (!res) {
        throw std::runtime_error("No s'han trobat pel·lícules més vistes amb qualificació TP.");
    }

    // Iterem sobre el resultat i omplim el vector
    while (res->next()) {
        PassarelaVisualitzaPel pel;
        pel.posaSobrenom(res->getString("sobrenom_usuari"));
        pel.posaTitolPelicula(res->getString("titol_pelicula"));
        pel.posaData(res->getString("data"));
        pel.posaNumVisualitzacions(res->getInt("num_visualitzacions"));
        peliculesMésVistes.push_back(pel);
    }

    delete res;
    return peliculesMésVistes;
}
