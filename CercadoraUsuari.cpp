#include "CercadoraUsuari.h"

CercadoraUsuari& CercadoraUsuari::getInstance() {
	static CercadoraUsuari instance;
	return instance;
}

PassarelaUsuari CercadoraUsuari::cercaPerSobrenom(std::string sobrenomU) {

    PassarelaUsuari u;
    ConnexioBD con ;
    std::string sql = "SELECT * FROM Usuari WHERE sobrenom = '" + sobrenomU + "'";
    sql::ResultSet* res = con.executarConsulta(sql);
    // Si no troba cap fila, activa excepció
    if (!res->next()) {
        //throw runtime_error("Usuari no existeix");
    }
    else {
        u.posaSobrenom(res->getString("sobrenom"));
        u.posaNom(res->getString("nom"));
        u.posaCorreu(res->getString("correu_electronic"));
        delete res;
    }
    return u;
}
