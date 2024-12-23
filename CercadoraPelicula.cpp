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