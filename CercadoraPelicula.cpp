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
    std::string sql = "SELECT vp.sobrenom_usuari, vp.titol_pelicula, vp.data, SUM(vp.num_visualitzacions) AS num_visualitzacions "
                      "FROM visualitzacio_pelicula vp "
                      "JOIN contingut c ON vp.titol_pelicula = c.titol "
                      "WHERE c.qualificacio = 'TP' "
                      "GROUP BY vp.titol_pelicula "
                      "ORDER BY num_visualitzacions DESC, vp.data DESC "
                      "LIMIT 5";

    sql::ResultSet* res = con.executarConsulta(sql);

    // Si no troba cap fila, retorna un vector buit
    /*if (!res) {

        throw std::runtime_error("No hi ha pel.licules amb qualificació TP.");
    }*/

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


std::vector<PassarelaPelicula> CercadoraPelicula::cercaProperesPelicules(std::string dataHora) {
    
    std::vector<PassarelaPelicula> passareles;

    ConnexioBD& con = ConnexioBD::getInstance();
    std::string sql = "SELECT * FROM pelicula WHERE data_estrena > '" + dataHora + "' ORDER BY data_estrena ASC";
    sql::ResultSet* res = con.executarConsulta(sql);
    
    while (res->next()) {
        PassarelaPelicula passarela;
        passarela.posaTitol(res->getString("titol"));
        passarela.posaDataEstrena(res->getString("data_estrena"));
        passarela.posaDuracio(res->getString("duracio"));

        passareles.push_back(passarela); // Añadir al vector
    }
    
    delete res; // Liberar memoria

    return passareles;
}
/*
std::vector<PassarelaPelicula> CercadoraPelicula::cercaProperesPeliculesInfantils(std::string dataHora) {
    
    std::vector<PassarelaPelicula> passareles;

    ConnexioBD& con = ConnexioBD::getInstance();
    std::string sql = "SELECT * FROM pelicula WHERE data_estrena > '" + dataHora + " AND ' ORDER BY data_estrena ASC";
    sql::ResultSet* res = con.executarConsulta(sql);
    
    while (res->next()) {
        PassarelaPelicula passarela;
        passarela.posaTitol(res->getString("titol"));
        passarela.posaDataEstrena(res->getString("data_estrena"));
        
        passarela.posaDuracio(res->getString("duracio"));

        passareles.push_back(passarela); // Añadir al vector
    }
    
    delete res; // Liberar memoria

    return passareles;
}
*/
std::vector<PassarelaPelicula> CercadoraPelicula::cercaUltimesPelicules(std::string dataHora) {

    std::vector<PassarelaPelicula> passareles;

    ConnexioBD& con = ConnexioBD::getInstance();
    std::string sql = "SELECT * FROM pelicula WHERE data_estrena < '" + dataHora + "' ORDER BY data_estrena DESC LIMIT 5";
    sql::ResultSet* res = con.executarConsulta(sql);

    while (res->next()) {
        PassarelaPelicula passarela;
        passarela.posaTitol(res->getString("titol"));
        passarela.posaDataEstrena(res->getString("data_estrena"));

        passarela.posaDuracio(res->getString("duracio"));

        passareles.push_back(passarela); // Añadir al vector
    }

    delete res; // Liberar memoria

    return passareles;
}