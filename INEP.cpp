#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <iostream>
#include <string>

#include "CapaDePresentacio.h"

// Modifiquem les funcions existents per utilitzar la classe ConnexioBD

//menu principal Usuari Sense Inici de Sessió
void menuPrincipalUsuariSenseIniciSessio() {

    std::cout << "**************** \n";
    std::cout << "  Menu inicial \n";
    std::cout << "**************** \n";
    std::cout << "1. Iniciar sessio \n";
    std::cout << "2. Registrar usuari \n";
    std::cout << "3. Consultes \n";
    std::cout << "4. Sortir \n\n";
    std::cout << "Escull una opcio: ";
}

//menu principal Usuari Amb Inici de Sessió
void menuPrincipalUsuariAmbIniciSessio() {

    std::cout << "**************** \n";
    std::cout << "  Menu inicial \n";
    std::cout << "**************** \n";
    std::cout << "1. Gestio usuaris \n";
    std::cout << "2. Visualitzar \n";
    std::cout << "3. Consultes \n";
    std::cout << "4. Tancar sessio \n";
    std::cout << "5. Sortir \n\n";
    std::cout << "Escull una opcio: ";
}
//submenus
void subMenuGestioUsuari() {

    std::cout << "- - - - - - - - - - - - - \n";
    std::cout << "  Menu Gestio Usuaris \n";
    std::cout << "- - - - - - - - - - - - - \n";
    std::cout << "1. Consulta usuari \n"; 
    std::cout << "2. Modifica usuari \n";
    std::cout << "3. Esborra usuari \n";
    std::cout << "4. Tornar \n\n";
    std::cout << "Escull una opcio: ";
}
void subMenuVisualitzar() {

    std::cout << "- - - - - - - - - - - - - \n";
    std::cout << "  Menu Gestio Continguts \n";
    std::cout << "- - - - - - - - - - - - - \n";
    std::cout << "1. Visualitzar pel.licula \n";
    std::cout << "2. Visualitzar capitol \n";
    std::cout << "3. Consultar visualitzacions \n";
    std::cout << "4. Tornar \n\n";
    std::cout << "Escull una opcio: ";
}
void subMenuConsultes() {

    std::cout << "- - - - - - - - - - - - - \n";
    std::cout << "  Menu Consultes \n";
    std::cout << "- - - - - - - - - - - - - \n";
    std::cout << "1. Properes estrenes \n";
    std::cout << "2. Ultimes novetats \n";
    std::cout << "3. Pel.licules mes vistes \n";
    std::cout << "4. Tornar \n\n";
    std::cout << "Escull una opcio: ";
}


//subfuncions gestio usu
/*void procesarRegistreUsuari() {
    std::cout << "Escriu el nou usuari aixi: sobrenom nom correu_electronic" << std::endl;
    std::string sobrenomNou, nomNou, correuNou;
    std::cin >> sobrenomNou >> nomNou >> correuNou;

    try {
        ConnexioBD connexio;
        std::string sql = "INSERT INTO usuari (sobrenom, nom, correu_electronic) VALUES('" + sobrenomNou + "', '" + nomNou + "', '" + correuNou + "')";
        connexio.executarComanda(sql);
        std::cout << "S'ha registrat l'usuari correctament." << std::endl << std::endl;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}*/
/*void procesarConsultaUsuari() {
    std::cout << "Escriu el sobrenom d'un usuari" << std::endl;
    std::string sobrenom_usuari;
    std::cin >> sobrenom_usuari;

    try {
        ConnexioBD connexio;
        std::string sql = "SELECT * FROM usuari WHERE sobrenom='" + sobrenom_usuari + "'";
        sql::ResultSet* res = connexio.executarConsulta(sql);

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
/*void procesarModificaUsuari() {
    std::cout << "Escriu el nou usuari aixi: sobrenom nom_nou correu_electronic_nou" << std::endl;
    std::string sobrenom_usuari, nomNou, correuNou;
    std::cin >> sobrenom_usuari >> nomNou >> correuNou;

    try {
        ConnexioBD connexio;
        std::string sql = "UPDATE usuari SET nom = '" + nomNou + "', correu_electronic = '" + correuNou + "' WHERE sobrenom = '" + sobrenom_usuari + "'";
        connexio.executarComanda(sql);
        std::cout << "S'ha modificat l'usuari correctament." << std::endl << std::endl;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}*/
/*void procesarEsborraUsuari() {
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
}*/
/*void procesarConsultaUsuaris() {
    try {
        ConnexioBD connexio;
        std::string sql = "SELECT * FROM usuari";
        sql::ResultSet* res = connexio.executarConsulta(sql);

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

//menu gestio usuari
void menuGestioUsuari() {

    std::string entrada2;
    subMenuGestioUsuari();
    bool continua = true;
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();

    while (continua and std::cin >> entrada2) {

        std::cout << "\n";
        if (entrada2 == "1") {

            //std::cout << "Has escollit l'opcio " + entrada2 + ": Consulta usuari. \n\n";
            presentacio.procesarConsultaUsuari(); 
            continua = false;
            //procesarConsultaUsuari();
        }
        else if (entrada2 == "2") {

            //std::cout << "Has escollit l'opcio " + entrada2 + ": Modifica usuari. \n\n";
            presentacio.procesarModificarUsuari(); 
            continua = false;
        }
        else if (entrada2 == "3") {

            //std::cout << "Has escollit l'opcio " + entrada2 + ": Esborra usuari. \n\n";
            presentacio.procesarEsborraUsuari();
            continua = false;
        }
        else if (entrada2 == "4") {

            std::cout << "Has escollit l'opcio " + entrada2 + ": Tornar. \n\n";
            continua = false;
        }
        else {
            std::cout << "No existeix l'opcio escollida, torna a intentar-ho. \n\n";
        }
        if (continua) {

            subMenuGestioUsuari();
        }
    }
}

//subfuncions visualitzar
/*subfuncions visualitzar 
void procesarGestioPelicules() {

    std::string nom_peli;
    std::cout << "Escriu el nom de la pel.licula que busques: ";
    std::cin >> nom_peli;
    if (nom_peli == " ") {
        std::cout << "No s,ha trobat la pel.licula que busques. \n\n";
    }
    else {
        std::cout << "La pel.licula " + nom_peli + " s,ha trobat. \n\n";
    }
}*/
/*void procesarGestioSeries() {

    std::string nom_serie;
    std::cout << "Escriu el nom de la serie que busques: ";
    std::cin >> nom_serie;
    if (nom_serie == " ") {
        std::cout << "No s,ha trobat la serie que busques. \n\n";
    }
    else {
        std::cout << "La serie " + nom_serie + " s,ha trobat. \n\n";
    }
}*/

//menu visualitzar
void menuVisualitzar() {

    std::string entrada2;
    subMenuVisualitzar();
    bool continua = true;
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    while (continua and std::cin >> entrada2) {

        std::cout << "\n";
        if (entrada2 == "1") {

            //std::cout << "Has escollit l'opcio " + entrada2 + ": Visualitzar pel.licula. \n\n";
            presentacio.procesarVisualitzarPel();
            continua = false;
            //procesarGestioPelicules(); CANVIAR!!!!!!!
        }
        else if (entrada2 == "2") {

            //std::cout << "Has escollit l'opcio " + entrada2 + ": Visualitzar capitol. \n\n";
            presentacio.procesarVisualitzarCapitol();
            continua = false;
            //procesarGestioSeries(); CANVIAR!!!!!!!
        }
        else if (entrada2 == "3") {

            //std::cout << "Has escollit l'opcio " + entrada2 + ": Consultar visualitzacions. \n\n";
            presentacio.procesarConsultaVisualitzacions();
            continua = false;
        }
        else if (entrada2 == "4") {

            std::cout << "Has escollit l'opcio " + entrada2 + ": Tornar. \n\n";
            continua = false;
        }
        else {

            std::cout << "No existeix l'opcio escollida, torna a intentar-ho. \n\n";
        }
        if (continua) {
            subMenuVisualitzar();
        }
    }
}

//subfuncions consultes
/*void procesarProperesEstrenes() {

    std::cout << " prox estrenes ...\n \n";
}*/
/*void procesarUltimesNovetats() {

    std::cout << "Mostrant les ultimes novetats. \n\n ... \n\n";
}*/
void procesarPeliculesMesVistes() {

    std::cout << "Mostrant les pelicules més vistes. \n\n ... \n\n";
}

//consultes
void consultes() {

    std::string entrada2;
    subMenuConsultes();
    bool continua = true;
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();

    while (continua and std::cin >> entrada2) {

        //std::cout << "\n";
        if (entrada2 == "1") {

            //std::cout << "Has escollit l'opcio " + entrada2 + ": Properes estrenes. \n\n";
            presentacio.procesarProperesEstrenes();
            continua = false;
        }
        else if (entrada2 == "2") {

            std::cout << "Has escollit l'opcio " + entrada2 + ": Ultimes novetats. \n\n";
            presentacio.procesarUltimesNovetats();
            continua = false;
            //procesarUltimesNovetats();
        }
        else if (entrada2 == "3") {

            std::cout << "Has escollit l'opcio " + entrada2 + ": Pel.licules mes vistes. \n\n";
            procesarPeliculesMesVistes();
        }
        else if (entrada2 == "4") {

            std::cout << "Has escollit l'opcio " + entrada2 + ": Tornar. \n\n";
            continua = false;
        }
        else {

            std::cout << "No existeix l'opcio escollida, torna a intentar-ho. \n\n";
        }
        if (continua) {
            subMenuConsultes();
        }
    }
}

//menu sessio iniciada 
void menuSessioIniciada() {

    std::string entrada;
    menuPrincipalUsuariAmbIniciSessio();
    bool continua_programa = true;

    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    while (continua_programa and std::cin >> entrada) {

        if (entrada == "1") {

            std::cout << "\nHas escollit l'opcio " + entrada + ": Gestio Usuaris. \n\n";
            menuGestioUsuari();
            if (not presentacio.sessioIniciada) {
                
                continua_programa = false;
            }
        }
        else if (entrada == "2") {

            std::cout << "\nHas escollit l'opcio " + entrada + ": Visualitzar. \n\n";
            menuVisualitzar();
        }
        else if (entrada == "3") {

            //std::cout << "\nHas escollit l'opcio " + entrada + ": Consultes. \n\n";
            consultes();
        }
        else if (entrada == "4") {

            std::cout << "\nHas escollit l'opcio " + entrada + ": Tancar sessio. \n\n";
            presentacio.tancarSessio(); 
            if (not presentacio.sessioIniciada) {
                
                continua_programa = false;
            }
        }
        else if (entrada == "5"){

            std::cout << "\nHas escollit l'opcio " + entrada + ": Sortir. \n\n";
            continua_programa = false;
            exit(1);
        }
        else {

            std::cout << "No existeix l'opcio escollida, torna a intentar-ho. \n\n";
        }
        if (continua_programa) {

           menuPrincipalUsuariAmbIniciSessio();
        }
    }
}

int main()
{
    menuPrincipalUsuariSenseIniciSessio();
    bool continua_programa = true;
    std::string entrada;

    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    while (continua_programa and std::cin >> entrada) {

        presentacio.sessioIniciada = false;
        if (entrada == "1") {

            //std::cout << "\nHas escollit l'opcio " + entrada + ": Iniciar sessio. \n\n";
            presentacio.iniciSessio(); // ens falta condicio per accedir només a la Sessio Iniciada si el inici és correcte
            if (presentacio.sessioIniciada){

                menuSessioIniciada();
            }
        }
        else if (entrada == "2") {

            //std::cout << "\nHas escollit l'opcio " + entrada + ": Registrar usuari. \n\n";
            presentacio.procesarRegistreUsuari(); 
        }
        else if (entrada == "3") {

            std::cout << "\nHas escollit l'opcio " + entrada + ": Consultes. \n\n";
            consultes();
        }
        else if (entrada == "4"){

            std::cout << "\nHas escollit l'opcio " + entrada + ": Sortir. \n\n";
            continua_programa = false;
        }
        else {

            std::cout << "\nNo existeix l'opcio escollida, torna a intentar-ho. \n\n";
        }
        if (continua_programa) {

           menuPrincipalUsuariSenseIniciSessio();
        }
    }
}