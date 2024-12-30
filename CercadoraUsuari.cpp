#include "CercadoraUsuari.h"

CercadoraUsuari::CercadoraUsuari(){ }

PassarelaUsuari CercadoraUsuari::cercaPerSobrenom(std::string sobrenomU) {

    PassarelaUsuari u;
    
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string sql = "SELECT * FROM usuari WHERE sobrenom = '" + sobrenomU + "'";
    sql::ResultSet* res = con.executarConsulta(sql);
    // Si no troba cap fila, activa excepcio
    if (!res->next()) {
        
        throw std::runtime_error("Usuari no existeix");
    }
    else {

        u.posaSobrenom(res->getString("sobrenom"));
        u.posaNom(res->getString("nom"));
        u.posaCorreu(res->getString("correu_electronic"));
        u.posaContrasenya(res->getString("contrasenya"));
        u.posaDataNaixament(res->getString("data_naixement"));
        u.posaModalitatSubscripcio(res->getString("subscripcio"));

        delete res; //Alliberar memoria
    }
    return u;
}

