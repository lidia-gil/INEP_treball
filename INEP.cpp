#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <iostream>
#include <string>
#include "CapaDePresentacio.h"


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


//menu gestio usuari
void menuGestioUsuari() {

    std::string entrada2;
    subMenuGestioUsuari();
    bool continua = true;
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();

    while (continua and std::cin >> entrada2) {

        if (entrada2 == "1") {

            presentacio.procesarConsultaUsuari(); 
            continua = false;
        }
        else if (entrada2 == "2") {

            presentacio.procesarModificarUsuari(); 
            continua = false;
        }
        else if (entrada2 == "3") {

            presentacio.procesarEsborraUsuari();
            continua = false;
        }
        else if (entrada2 == "4") {

            std::cout << "\nHas escollit l'opcio " + entrada2 + ": Tornar. \n\n";
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

//menu visualitzar
void menuVisualitzar() {

    std::string entrada2;
    subMenuVisualitzar();
    bool continua = true;
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    while (continua and std::cin >> entrada2) {

        if (entrada2 == "1") {

            presentacio.procesarVisualitzarPel();
            continua = false;
        }
        else if (entrada2 == "2") {

            presentacio.procesarVisualitzarCapitol();
            continua = false;
        }
        else if (entrada2 == "3") {

            presentacio.procesarConsultaVisualitzacions();
            continua = false;
        }
        else if (entrada2 == "4") {

            std::cout << "\nHas escollit l'opcio " + entrada2 + ": Tornar. \n\n";
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

//menu consultes
void consultes() {

    std::string entrada2;
    subMenuConsultes();
    bool continua = true;
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();

    while (continua and std::cin >> entrada2) {

        if (entrada2 == "1") {

            presentacio.procesarProperesEstrenes();
            continua = false;
        }
        else if (entrada2 == "2") {

            presentacio.procesarUltimesNovetats();
            continua = false;
        }
        else if (entrada2 == "3") {

            presentacio.procesarPeliculesMesVistes();
            continua = false;
        }
        else if (entrada2 == "4") {

            std::cout << "\nHas escollit l'opcio " + entrada2 + ": Tornar. \n\n";
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

            std::cout << "\nHas escollit l'opcio " + entrada + ": Consultes. \n\n";
            consultes();
        }
        else if (entrada == "4") {

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

//menu sense sessio iniciada
void menuSenseSessioIniciada(){

    menuPrincipalUsuariSenseIniciSessio();
    bool continua_programa = true;
    std::string entrada;

    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    while (continua_programa and std::cin >> entrada) {

        presentacio.sessioIniciada = false;
        if (entrada == "1") {

            presentacio.iniciSessio();
            if (presentacio.sessioIniciada) {

                menuSessioIniciada();
            }
        }
        else if (entrada == "2") {

            presentacio.procesarRegistreUsuari();
        }
        else if (entrada == "3") {

            std::cout << "\nHas escollit l'opcio " + entrada + ": Consultes. \n\n";
            consultes();
        }
        else if (entrada == "4") {

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

int main()
{
    std::string name, user, password, host, port;
    std::cout << "Dades necessaries per generar la connexio amb la base de dades: " << std::endl;
    std::cout << "dbname= ";
    std::cin >> name;
    std::cout << "user= ";
    std::cin >> user;
    std::cout << "password= ";
    std::cin >> password;
    std::cout << "hostaddr= ";
    std::cin >> host;
    std::cout << "port= ";
    std::cin >> port;
    std::cout << std::endl;
    
    ConnexioBD& connexio = ConnexioBD::getInstance();
    connexio.inicialitzar_atributs(name, user, password, host, port);

    menuSenseSessioIniciada();
}