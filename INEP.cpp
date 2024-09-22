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

}
void procesarModificaUsuari() {

}
void procesarEsborraUsuari() {

}

//principal 1
void gestioUsuari() {

    std::cout << "1. Registre usuari \n";
    std::cout << "2. Consulta usuari \n";
    std::cout << "3. Modifica usuari \n";
    std::cout << "4. Esborra usuari \n"; 
    std::cout << "5. Tornar \n";
    
    std::string entrada2;

    std::cout << "Escriu un nombre:";
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
    }
}

void procesarGestioPelicules(){
}
void procesarGestioSeries(){
}

//principal 2
void gestioContinguts() {

    std::cout << "1. Gestio pel.licules \n";
    std::cout << "2. Gestio series \n";
    std::cout << "3. Tornar \n";

    std::string entrada2;

    std::cout << "Escriu un nombre:";
    std::cin >> entrada2;
    std::cout << "Has escollit el nombre " + entrada2 + "\n";

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
    }
}

void procesarConsultaPerQualificacioDeEdat(){}
void procesarUltimesNovetats(){}
void procesarProximesEstrenes(){}

//pricipal 3
void consultes() {

    std::cout << "1. Consulta per qualificacio de edat \n";
    std::cout << "2. Ultimes novetats \n";
    std::cout << "3. Proximes estrenes \n";
    std::cout << "4. Tornar \n";

    std::string entrada2;

    std::cout << "Escriu un nombre:";
    std::cin >> entrada2;

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
    }
}

int main()
{
    std::string entrada;
    menuPrincipal();

    while (std::cin >> entrada){
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
            // bool para sortir 
        }
        menuPrincipal();
    }
}

