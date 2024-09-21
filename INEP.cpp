// INEP.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

void procesarRegistreUsuari() {

    std::cout << "1. Registre usuari \n";
    std::cout << "2. Gestio continguts \n";
    std::cout << "3. Modifica usuari \n";
    std::cout << "4. Esborra usuari \n"; 
    std::cout << "5. Tornar \n";
    
    std::string entrada2;

    std::cout << "Escriu un nombre:";
    std::cin >> entrada2;
    std::cout << "Has escollit el nombre " + entrada2 + "\n";

    if ( )
}

void procesarGestioContinguts() {

}
void procesarConsultes() {

}

int main()
{
    std::cout << "1. Gestio usuaris \n";
    std::cout << "2. Gestio continguts \n";
    std::cout << "3. Consultes \n";
    std::cout << "4. Sortir \n";

    std::string entrada;

    std::cout << "Escriu un nombre:";
    std::cin >> entrada;
    std::cout << "Has escollit el nombre " + entrada + "\n";

    if (entrada == "1") {

        std::cout << "Has escollit l'opcio Gestio usuaris \n";
        procesarRegistreUsuari();
    }
    else if (entrada == "2") {

        std::cout << "Has escollit l'opcio Gestio continguts \n";
        procesarGestioContinguts();
    }
    else if (entrada == "3") {

        std::cout << "Has escollit l'opcio Consultes \n";
        void procesarConsultes();
    }
    else {

        std::cout << "Has escollit l'opcio Sortir \n";
    }
    //int select_num;
    //std::cin >> entrada;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
