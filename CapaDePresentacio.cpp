#include "CapaDePresentacio.h"


// Constructor privat
CapaDePresentacio::CapaDePresentacio() {}

CapaDePresentacio& CapaDePresentacio::getInstance() {

    static CapaDePresentacio instance;
    return instance;
}

void CapaDePresentacio::iniciSessio() {

    std::string sobrenomU, contrasenyaU;
    std::cout << "** Inici Sessio **" << std::endl;
    std::cout << "Sobrenom: ";
    std::cin >> sobrenomU;
    std::cout << "Contrasenya: ";
    std::cin >> contrasenyaU;
    TxIniciSessio Tx(sobrenomU, contrasenyaU);
    try {
        Tx.executa();
        std::cout << "Sessio iniciada correctament!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: Hi ha hagut un error amb el sobrenom o la contrasenya." << std::endl; // NO e.what(), ja que el missatge no ha de dir que ha fallat per seguretat
    }
}

void CapaDePresentacio::tancarSessio() {

    std::string resposta;
    std::cout << "** Tancar Sessio **" << std::endl;
    std::cout << "Vols tancar la sessio (S/N):" << std::endl;
    std::cin >> resposta; 
    if (resposta == "S"){

        TxTancaSessio tx;
        tx.executa();
        std::cout << "Sessio tancada correctament!" << std::endl;
    }
}

void CapaDePresentacio::procesarRegistreUsuari() {
    std::string sobrenomU, nomU, contrasenyaU, correuU, dataNaixementU, modalitatU;
    std::cout << "** Registra usuari **" << std::endl;
    std::cout << "Nom complet: ";
    std::cin >> nomU;
    std::cout << "Sobrenom: ";
    std::cin >> sobrenomU;
    std::cout << "contrasenya: ";
    std::cin >> contrasenyaU;
    std::cout << "Correu electronic: ";
    std::cin >> correuU;
    std::cout << "Data naixement (YYYY-MM-DD): ";
    std::cin >> dataNaixementU;
    std::cout << "Modalitats de subscripcio disponibles " << std::endl;
    std::cout << " > 1. Completa" << std::endl;
    std::cout << " > 2. Cinefil" << std::endl;
    std::cout << " > 3. Infantil" << std::endl;
    std::string eleccio;
    std::cout << "Escriu el numero de la modalitat a escollir: ";
    std::cin >> eleccio;
    bool continua = true;
    if (eleccio == "1"){
        
        modalitatU = "Completa";
    }
    else if (eleccio == "2"){
        
        modalitatU = "Cinefil";
    }
    else if (eleccio == "3"){
        
        modalitatU = "Infantil";
    }
    else {
        continua = false;
        std::cout << "Error: La modalitat escollida no es valida." << std::endl;
    }

    if (continua){
        try {
                TxRegistreUsuari tx(nomU, sobrenomU, contrasenyaU, correuU, dataNaixementU, modalitatU);
                tx.executa();
                std::cout << "Usuari registrat correctament!" << std::endl;
        }
        catch (const std::exception& e) {

            std::cout << "Error: "  << e.what() << std::endl;
        }
    }
}

void CapaDePresentacio::procesarConsultaUsuari() {
    
    std::cout << "** Consulta Usuari **" << std::endl;
   
    //CapaDeDomini& domini = CapaDeDomini::getInstance();
    try {

        TxConsultaUsuari tx;
        tx.executa();
        DTOUsuari usu = tx.obteResultat();

        TxInfoVisualitzacions TxInfoVis;
        TxInfoVis.executa();
        TxInfoVisualitzacions::Resultat res;
        res = TxInfoVis.obteResultat();


        std::cout << "Nom complet: " << usu.obteNom() << std::endl;
        //Aplicació patrons de disseny 4 Introducció a l’Enginyeria del Programari Laboratori, sessió 3
        std::cout << "Sobrenom: " << usu.obteSobrenom() << std::endl;
        std::cout << "Correu electronic: " << usu.obteCorreu() << std::endl;
        std::string dataNeix = usu.obteDataNeix();
        dataNeix = dataNeix.substr(0, 10);  // Obtener solo los primeros 10 caracteres (YYYY-MM-DD)
        std::cout << "Data naixement (AAAA-MM-DD): " << dataNeix << std::endl;
        std::cout << "Modalitat subscripcio: " << usu.obteModalitatSubscripcio() << std::endl;
        std::cout  << std::endl;
        if (res.nP == 1){
            std::cout << res.nP << " pel.licula visualitzada" << std::endl;
        }
        else {
            std::cout << res.nP << " pel.licules visualitzades" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
/*
void CapaDePresentacio::procesarConsultaUsuari() {
    std::cout << "** Consulta Usuari **" << std::endl;
    std::cout << "Escriu el sobrenom d'un usuari:" ;
    std::string sobrenomU;
    std::cin >> sobrenomU;
    CapaDeDomini& domini = CapaDeDomini::getInstance();
    try {

        sql::ResultSet* res = domini.consultarUsuari(sobrenomU);

        while (res->next()) {
            std::cout << "Sobrenom: " << res->getString("sobrenom") << std::endl;
            std::cout << "Nom: " << res->getString("nom") << std::endl;
            std::cout << "Correu: " << res->getString("correu_electronic") << std::endl << std::endl;
        }
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}*/

void CapaDePresentacio::procesarEsborraUsuari() {
    std::cout << "Escriu el sobrenom d'un usuari" << std::endl;
    std::string sobrenom_usuari;
    std::cin >> sobrenom_usuari;

    try {
        ConnexioBD connexio;
        std::string sql = "DELETE FROM usuari WHERE sobrenom = '" + sobrenom_usuari + "'";
        connexio.executarComanda(sql);
        std::cout << "S'ha eliminat l'usuari amb el sobrenom especificat." << std::endl << std::endl;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}