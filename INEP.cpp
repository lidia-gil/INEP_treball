// INEP.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

//menu principal
void menuPrincipal() {

    std::cout << "1. Gestio usuaris \n";
    std::cout << "2. Gestio continguts \n";
    std::cout << "3. Consultes \n";
    std::cout << "4. Sortir \n";
    std::cout << "Escriu un nombre:";
}
//submenus
void subMenuPrincipal1() {

    std::cout << "1. Registre usuari \n";
    std::cout << "2. Consulta usuari \n";
    std::cout << "3. Modifica usuari \n";
    std::cout << "4. Esborra usuari \n";
    std::cout << "5. Tornar \n";
    std::cout << "Escriu un nombre:";
}
void subMenuPrincipal2() {

    std::cout << "1. Gestio pel.licules \n";
    std::cout << "2. Gestio series \n";
    std::cout << "3. Tornar \n";
    std::cout << "Escriu un nombre:";
}
void subMenuPrincipal3() {

    std::cout << "1. Consulta per qualificacio de edat \n";
    std::cout << "2. Ultimes novetats \n";
    std::cout << "3. Proximes estrenes \n";
    std::cout << "4. Tornar \n";
    std::cout << "Escriu un nombre:";
}

//subfuncions1
void procesarRegistreUsuari() {

    std::string nom;
    std::string cognom;
    std::string sobrenom;
    std::cout << "Escriure nom: ";
    std::cin >> nom;
    std::cout << "Escriure congnom: ";
    std::cin >> cognom;
    std::cout << "Escriure sobrenom: ";
    std::cin >> sobrenom;
    if (nom == " " or cognom == " " or sobrenom == " ") {
        std::cout << "Error al registrar usuari \n";
    }
    else {
        std::cout << "El registre de el usuari " + nom + " " + cognom + " ( " + sobrenom + " ) s,ha processat correctament. \n";
    }
}
void procesarConsultaUsuari() {

    std::string nom;
    std::string cognom;
    std::string sobrenom;
    std::cout << "Escriure nom: ";
    std::cin >> nom;
    std::cout << "Escriure congnom: ";
    std::cin >> cognom;
    std::cout << "Escriure sobrenom: ";
    std::cin >> sobrenom;
    if (nom == " " or cognom == " " or sobrenom == " ") {
        std::cout << "Aquest usuari no esta registrat \n";
    }
    else {
        std::cout << "El usuari " + nom + " " + cognom + " ( " + sobrenom + " ) esta registrat. \n";
    }
}
void procesarModificaUsuari() {

    std::string nom;
    std::string cognom;
    std::string sobrenom;
    std::string apartat;
    std::cout << "Escriure nom: ";
    std::cin >> nom;
    std::cout << "Escriure congnom: ";
    std::cin >> cognom;
    std::cout << "Escriure sobrenom: ";
    std::cin >> sobrenom;
    std::cout << "Quin dels apartats anterior vols modificar 1,2 o 3 ?";
    std::cin >> apartat;
    if (apartat == "1") {
        
        std::cout << "Escriure nom: ";
        std::cin >> nom;
        std::cout << "El usuari " + nom + " " + cognom + " ( " + sobrenom + " ) s,ha modificat correctament. \n";
    }
    else if (apartat == "2") {

        std::cout << "Escriure cognom: ";
        std::cin >> cognom;
        std::cout << "El usuari " + nom + " " + cognom + " ( " + sobrenom + " ) s,ha modificat correctament. \n";
    }
    else if (apartat == "3") {

        std::cout << "Escriure sobrenom: ";
        std::cin >> sobrenom;
        std::cout << "El usuari " + nom + " " + cognom + " ( " + sobrenom + " ) s,ha modificat correctament. \n";
    }
    else {

        std::cout << "Apartat no trobat. \n";
    }
}
void procesarEsborraUsuari() {
 
    std::string nom;
    std::string cognom;
    std::string sobrenom;
    std::cout << "Escriure nom: ";
    std::cin >> nom;
    std::cout << "Escriure congnom: ";
    std::cin >> cognom;
    std::cout << "Escriure sobrenom: ";
    std::cin >> sobrenom;
    if (nom == " " or cognom == " " or sobrenom == " ") {
        std::cout << "Error al esborrar usuari \n";
    }
    else {
        std::cout << "El usuari " + nom + " " + cognom + " ( " + sobrenom + " ) s,ha esborrat correctament. \n";
    }
}

//principal 1
void gestioUsuari() {

    std::string entrada2;
    subMenuPrincipal1();
    bool continua = true;

    while (continua and std::cin >> entrada2) {

        if (entrada2 == "1") {

            std::cout << "Has escollit l'opcio " + entrada2 + ". Registre usuari \n";
            procesarRegistreUsuari();
        }
        else if (entrada2 == "2") {
            procesarConsultaUsuari();
        }
        else if (entrada2 == "3") {
            procesarModificaUsuari();
        }
        else if (entrada2 == "4") {
            procesarEsborraUsuari();
        }
        else {
            std::cout << "Has escollit l'opcio " + entrada2 + ". Tornar \n";
            continua = false;
        }
        if (continua) {
            subMenuPrincipal1();
        }
    }
}

//subfuncions2
void procesarGestioPelicules(){

    std::string nom_peli;
    std::cout << "Escriu el nom de la pel.licula que busques: ";
    std::cin >> nom_peli;
    if (nom_peli == " ") {
        std::cout << "No s,ha trobat la pel.licula que busques. \n";
    }
    else {
        std::cout << "La pel.licula " + nom_peli + " s,ha trobat. \n";
    }
}
void procesarGestioSeries(){

    std::string nom_serie;
    std::cout << "Escriu el nom de la serie que busques: ";
    std::cin >> nom_serie;
    if (nom_serie == " ") {
        std::cout << "No s,ha trobat la serie que busques. \n";
    }
    else {
        std::cout << "La serie " + nom_serie + " s,ha trobat. \n";
    }
}

//principal 2
void gestioContinguts() {

    std::string entrada2;
    subMenuPrincipal2();
    bool continua = true;

    while (continua and std::cin >> entrada2) {
        if (entrada2 == "1") {

            std::cout << "Has escollit l'opcio " + entrada2 + ". Gestio pel.licules \n";
            procesarGestioPelicules();
        }
        else if (entrada2 == "2") {

            std::cout << "Has escollit l'opcio " + entrada2 + ". Gestio series \n";
            procesarGestioSeries();
        }
        else {

            std::cout << "Has escollit l'opcio " + entrada2 + ". Tornar \n";
            continua = false;
            //procesarTornar();
        }
        if (continua) {
            subMenuPrincipal2();
        }
    }
}

//subfuncions3
void procesarConsultaPerQualificacioDeEdat(){
       
    int edat;
    std::cout << "Escriure la teva edat actual: ";
    std::cin >> edat;

    if (edat > 0 and edat <= 12) {
        std::cout << "Mostrant apartat infantil. \n \n";
    }
    else if (edat > 12 and edat < 18) {
    
        std::cout << "Mostrant apartat juvenil. \n \n";
    }
    else {

        std::cout << "Mostrant apartat adult. \n \n";
    }
}
void procesarUltimesNovetats(){

    std::cout << "Mostrant les ultimes novetats. \n\n";
}
void procesarProximesEstrenes(){

    std::cout << "Mostrant les proximes estrenes. \n\n";
}

//pricipal 3
void consultes() {

    std::string entrada2;
    subMenuPrincipal3();
    bool continua = true;

    while (continua and std::cin >> entrada2) {

        if (entrada2 == "1") {

            procesarConsultaPerQualificacioDeEdat();
        }
        else if (entrada2 == "2") {

            procesarUltimesNovetats();
        }
        else if (entrada2 == "3") {

            procesarProximesEstrenes();
        }
        else {

            std::cout << "Has escollit l'opcio " + entrada2 + ". Tornar \n";
            continua = false;
        }
        if (continua) {
            subMenuPrincipal3();
        }
    }
}

int main()
{
    menuPrincipal();
    bool continua_programa = true;
    std::string entrada;

    while (continua_programa and std::cin >> entrada){
        if (entrada == "1") {

            std::cout << "Has escollit l'opcio " + entrada + ". Gestio usuaris \n";
            gestioUsuari();
        }
        else if (entrada == "2") {

            std::cout << "Has escollit l'opcio " + entrada + ". Gestio continguts \n";
            gestioContinguts();
        }
        else if (entrada == "3") {

            std::cout << "Has escollit l'opcio " + entrada + ". Consultes \n";
            consultes();
        }
        else {

            std::cout << "Has escollit l'opcio " + entrada + ". Sortir \n";
            continua_programa = false;
            // bool para sortir 
        }
        if (continua_programa) {
            menuPrincipal();
        }
    }
}

