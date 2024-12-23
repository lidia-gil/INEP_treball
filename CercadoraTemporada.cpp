#include "CercadoraTemporada.h"

CercadoraTemporada::CercadoraTemporada(){ }

PassarelaTemporada CercadoraTemporada::cercaPerTitol(std::string titolS) {

    ConnexioBD& con = ConnexioBD::getInstance();

    std::string sql = "SELECT * FROM temporada WHERE titol_serie ='" + titolS + "'";
    sql::ResultSet* res = con.executarConsulta(sql);

    PassarelaTemporada passarela;
    //Verificar si hay resultados
    if (!res->next()) {

        throw std::runtime_error("La serie no s'ha trobat o no te cap temporada disponible");
    }
   
    int numTempMax = 0;

    while (res->next()) {
            
        int numTemp = (res->getInt("numero"));
       
        if (numTemp > numTempMax) {

            passarela.posaNumTemporada(numTemp);
            passarela.posaTitolSerie(res->getString("titol_serie"));
        }
    }
    return passarela;
}