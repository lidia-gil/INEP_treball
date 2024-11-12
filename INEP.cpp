#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <iostream>
#include <string>

class ConnexioBD {
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;

public:
    // Constructor: estableix la connexió
    ConnexioBD() {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep02", "rai2Laavaey6ph");
        con->setSchema("inep02");
    }

    // Destructor: tanca la connexió
    ~ConnexioBD() {
        if (con) con->close();
    }

    // Mètode per a consultes (SELECT)
    sql::ResultSet* executarConsulta(const std::string& consultaSQL) {
        sql::Statement* stmt = con->createStatement();
        return stmt->executeQuery(consultaSQL);
    }

    // Mètode per a comandes (INSERT, UPDATE, DELETE)
    void executarComanda(const std::string& comandaSQL) {
        sql::Statement* stmt = con->createStatement();
        stmt->executeUpdate(comandaSQL);
    }
};

// Modifiquem les funcions existents per utilitzar la classe ConnexioBD


//menu principal
void menuPrincipal() {

    std::cout << "Menu inicial \n";
    std::cout << "1. Gestio usuaris \n";
    std::cout << "2. Gestio continguts \n";
    std::cout << "3. Consultes \n";
    std::cout << "4. Sortir \n\n";
    std::cout << "Escull una opcio: ";
}
//submenus
void subMenuPrincipal1() {

    std::cout << "Menu Gestio Usuaris \n";
    std::cout << "1. Registre usuari \n";
    std::cout << "2. Consulta usuari \n";
    std::cout << "3. Modifica usuari \n";
    std::cout << "4. Esborra usuari \n";
    std::cout << "5. Consulta usuaris \n";
    std::cout << "6. Tornar \n\n";
    std::cout << "Escull una opcio: ";
}
void subMenuPrincipal2() {

    std::cout << "Menu Gestio Continguts \n";
    std::cout << "1. Gestio pel.licules \n";
    std::cout << "2. Gestio series \n";
    std::cout << "3. Tornar \n\n";
    std::cout << "Escull una opcio: ";
}
void subMenuPrincipal3() {

    std::cout << "Menu Consultes \n";
    std::cout << "1. Consulta per qualificacio de edat \n";
    std::cout << "2. Ultimes novetats \n";
    std::cout << "3. Proximes estrenes \n";
    std::cout << "4. Tornar \n\n";
    std::cout << "Escull una opcio: ";
}


//subfuncions1
void procesarRegistreUsuari() {
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
}

void procesarConsultaUsuari() {
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
}

void procesarModificaUsuari() {
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
}

void procesarEsborraUsuari() {
    std::cout << "Escriu el sobrenom d'un usuari" << std::endl;
    std::string sobrenom_usuari;
    std::cin >> sobrenom_usuari;

    try {
        ConnexioBD connexio;
        std::string sql = "DELETE FROM usuari WHERE sobrenom = '" + sobrenom_usuari + "'";
        connexio.executarComanda(sql);
        std::cout << "S'ha eliminat la fila amb el sobrenom especificat." << std::endl << std::endl;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void procesarConsultaUsuaris() {
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
}


//principal 1
void gestioUsuari() {

    std::string entrada2;
    subMenuPrincipal1();
    bool continua = true;

    while (continua and std::cin >> entrada2) {

        std::cout << "\n";
        if (entrada2 == "1") {

            std::cout << "Has escollit l'opcio " + entrada2 + ": Registre usuari. \n\n";
            procesarRegistreUsuari();
        }
        else if (entrada2 == "2") {

            std::cout << "Has escollit l'opcio " + entrada2 + ": Consulta usuari. \n\n";
            procesarConsultaUsuari();
        }
        else if (entrada2 == "3") {

            std::cout << "Has escollit l'opcio " + entrada2 + ": Modifica usuari. \n\n";
            procesarModificaUsuari();
        }
        else if (entrada2 == "4") {

            std::cout << "Has escollit l'opcio " + entrada2 + ": Esborra usuari. \n\n";
            procesarEsborraUsuari();
        }
        else if (entrada2 == "5") {

            std::cout << "Has escollit l'opcio " + entrada2 + ": Consulta usuaris. \n\n";
            procesarConsultaUsuaris();
        }
        else if (entrada2 == "6") {

            std::cout << "Has escollit l'opcio " + entrada2 + ": Tornar. \n\n";
            continua = false;
        }
        else {

            std::cout << "No existeix l'opcio escollida, torna a intentar-ho. \n\n";
        }
        if (continua) {
            subMenuPrincipal1();
        }
    }
}

//subfuncions2
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
}
void procesarGestioSeries() {

    std::string nom_serie;
    std::cout << "Escriu el nom de la serie que busques: ";
    std::cin >> nom_serie;
    if (nom_serie == " ") {
        std::cout << "No s,ha trobat la serie que busques. \n\n";
    }
    else {
        std::cout << "La serie " + nom_serie + " s,ha trobat. \n\n";
    }
}

//principal 2
void gestioContinguts() {

    std::string entrada2;
    subMenuPrincipal2();
    bool continua = true;

    while (continua and std::cin >> entrada2) {

        std::cout << "\n";
        if (entrada2 == "1") {

            std::cout << "Has escollit l'opcio " + entrada2 + ": Gestio pel.licules. \n\n";
            procesarGestioPelicules();
        }
        else if (entrada2 == "2") {

            std::cout << "Has escollit l'opcio " + entrada2 + ": Gestio series. \n\n";
            procesarGestioSeries();
        }
        else if (entrada2 == "3") {

            std::cout << "Has escollit l'opcio " + entrada2 + ": Tornar. \n\n";
            continua = false;
        }
        else {

            std::cout << "No existeix l'opcio escollida, torna a intentar-ho. \n\n";
        }
        if (continua) {
            subMenuPrincipal2();
        }
    }
}

//subfuncions3
void procesarConsultaPerQualificacioDeEdat() {

    int edat;
    std::cout << "Escriure la teva edat actual: ";
    std::cin >> edat;

    if (edat > 0 and edat <= 12) {

        std::cout << "\nMostrant apartat infantil. \n \n";
    }
    else if (edat > 12 and edat < 18) {

        std::cout << "\nMostrant apartat juvenil. \n \n";
    }
    else {

        std::cout << "\nMostrant apartat adult. \n \n";
    }
    std::cout << " ...\n \n";
}
void procesarUltimesNovetats() {

    std::cout << "Mostrant les ultimes novetats. \n\n ... \n\n";
}
void procesarProximesEstrenes() {

    std::cout << "Mostrant les proximes estrenes. \n\n ... \n\n";
}

//pricipal 3
void consultes() {

    std::string entrada2;
    subMenuPrincipal3();
    bool continua = true;

    while (continua and std::cin >> entrada2) {

        std::cout << "\n";
        if (entrada2 == "1") {

            std::cout << "Has escollit l'opcio " + entrada2 + ": Consulta per qualificaio de edat. \n\n";
            procesarConsultaPerQualificacioDeEdat();
        }
        else if (entrada2 == "2") {

            std::cout << "Has escollit l'opcio " + entrada2 + ": Ultimes novetats. \n\n";
            procesarUltimesNovetats();
        }
        else if (entrada2 == "3") {

            std::cout << "Has escollit l'opcio " + entrada2 + ": Proximes estrenes. \n\n";
            procesarProximesEstrenes();
        }
        else if (entrada2 == "4") {

            std::cout << "Has escollit l'opcio " + entrada2 + ": Tornar. \n\n";
            continua = false;
        }
        else {

            std::cout << "No existeix l'opcio escollida, torna a intentar-ho. \n\n";
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

    while (continua_programa and std::cin >> entrada) {

        if (entrada == "1") {

            std::cout << "\nHas escollit l'opcio " + entrada + ": Gestio Usuaris. \n\n";
            gestioUsuari();
        }
        else if (entrada == "2") {

            std::cout << "\nHas escollit l'opcio " + entrada + ": Gestio Continguts. \n\n";
            gestioContinguts();
        }
        else if (entrada == "3") {

            std::cout << "\nHas escollit l'opcio " + entrada + ": Consultes. \n\n";
            consultes();
        }
        else {

            std::cout << "\nHas escollit l'opcio " + entrada + ": Sortir. \n\n";
            continua_programa = false;
        }
        if (continua_programa) {

            menuPrincipal();
        }
    }
}

