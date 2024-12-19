#include "CapaDePresentacio.h"


// Constructor privado
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
        std::cout << "S'ha iniciat sessio correctament" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: Algun dels parametres no existeix o es incorrecte" << std::endl; // NO e.what(), ja que el missatge no ha de dir que ha fallat per seguretat
    }
}
void CapaDePresentacio::procesarRegistreUsuari() {
    std::string sobrenomU, nomU, correuU;
    std::cout << "** Registra usuari **" << std::endl;
    std::cout << "Sobrenom: ";
    std::cin >> sobrenomU;
    std::cout << "Nom: ";
    std::cin >> nomU;
    std::cout << "Correu electronic: ";
    std::cin >> correuU;
    CapaDeDomini& domini = CapaDeDomini::getInstance();
    try {
            domini.registrarUsuari(sobrenomU, nomU, correuU);
            std::cout << "Usuari registrat correctament!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: "  << e.what() << std::endl;
    }
}

void CapaDePresentacio::procesarConsultaUsuari() {
    std::cout << "Sobreom usuari:";
    std::string sobrenomU;
    std::cin >> sobrenomU;
    CapaDeDomini& domini = CapaDeDomini::getInstance();
    try {
        DTOUsuari usu = domini.consultarUsuari(sobrenomU);
        std::cout << "Informació usuari: " << usu.obteNom();
        std::cout << std::endl;
        std::cout << "Nom: " << usu.obteNom() << std::endl;
        //Aplicació patrons de disseny 4 Introducció a l’Enginyeria del Programari Laboratori, sessió 3
        std::cout << "Correu: " << usu.obteCorreu() << std::endl;
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