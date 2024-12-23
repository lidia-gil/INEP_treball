#include "CercadoraUsuari.h"

PassarelaUsuari CercadoraUsuari::cercaPerSobrenom(std::string sobrenomU) {

    PassarelaUsuari u;
    //ConnexioBD con ;
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string sql = "SELECT * FROM usuari WHERE sobrenom = '" + sobrenomU + "'";
    sql::ResultSet* res = con.executarConsulta(sql);
    // Si no troba cap fila, activa excepció
    if (!res->next()) {
        //throw exception("Usuari no existeix");  // no ens funciona aquesta operaci� 
        throw std::runtime_error("Usuari no existeix");
    }
    else {
        u.posaSobrenom(res->getString("sobrenom"));
        u.posaNom(res->getString("nom"));
        u.posaCorreu(res->getString("correu_electronic"));
        u.posaContrasenya(res->getString("contrasenya"));
        u.posaDataNaixament(res->getString("data_naixement"));
        u.posaModalitatSubscripcio(res->getString("subscripcio"));
        delete res;
    }
    return u;
}

