#include "CercadoraUsuari.h"

PassarelaUsuari CercadoraUsuari::cercaPerSobrenom(std::string sobrenomU) {

    PassarelaUsuari u;
    ConnexioBD con ;
    std::string sql = "SELECT * FROM usuari WHERE sobrenom = '" + sobrenomU + "'";
    sql::ResultSet* res = con.executarConsulta(sql);
    // Si no troba cap fila, activa excepciÃ³
    if (!res->next()) {
        //throw exception("Usuari no existeix");  // no ens funciona aquesta operació 
        throw std::runtime_error("Usuari no existeix");
    }
    else {
        u.posaSobrenom(res->getString("sobrenom"));
        u.posaNom(res->getString("nom"));
        u.posaCorreu(res->getString("correu_electronic"));
        delete res;
    }
    return u;
}

