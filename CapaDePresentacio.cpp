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
        sessioIniciada = true;
    }
    catch (const std::exception& e) {
        sessioIniciada = false;
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
        sessioIniciada = false;
        std::cout << "Sessio tancada correctament!" << std::endl;
    }
}

void CapaDePresentacio::procesarRegistreUsuari() {
    
    std::cout << "** Registra usuari **" << std::endl;

    std::string sobrenomU, nomU, contrasenyaU, correuU, dataNaixementU, modalitatU;
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
            std::cout << "Usuari registrat correctament!, per accedir al teu compte inicia sessio." << std::endl;
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

        if (res.nS == 1){
            std::cout << res.nS << " capitol visualitzat" << std::endl;
        }
        else {
            std::cout << res.nS << " capitols visualitzats" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void CapaDePresentacio::procesarModificarUsuari() {

    std::cout << "** Modifica Usuari **" << std::endl;

    try {
        CtrlModificaUsuari ctrlModifica;
        DTOUsuari usu;
        usu = ctrlModifica.consultarUsuari();

        std::cout << "Nom complet: " << usu.obteNom() << std::endl;
        std::cout << "Sobrenom: " << usu.obteSobrenom() << std::endl;
        std::cout << "Correu electronic: " << usu.obteCorreu() << std::endl;
        std::string dataNeix = usu.obteDataNeix();
        dataNeix = dataNeix.substr(0, 10);  // Obtener solo los primeros 10 caracteres (YYYY-MM-DD)
        std::cout << "Data naixement (AAAA-MM-DD): " << dataNeix << std::endl;
        std::cout << "Modalitat subscripcio: " << usu.obteModalitatSubscripcio() << std::endl;
        std::cout << std::endl;

        // ** Limpieza del buffer **
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::cout << std::endl;

        std::string nomU, contrasenyaU, correuU, dataNaixementU, modalitatU;
        std::cout << "Polsar enter als camps que NO es volen modificar i omplir la informacio que SI es vol modificar ..." << std::endl;
    
        std::cout << "Nom complet: ";
        std::getline(std::cin, nomU);  // Cambiar a getline
        std::cout << "Contrasenya: ";
        std::getline(std::cin, contrasenyaU);  // Cambiar a getline
        std::cout << "Correu electronic: ";
        std::getline(std::cin, correuU);  // Cambiar a getline
        std::cout << "Data naixement (YYYY-MM-DD): ";
        std::getline(std::cin, dataNaixementU);  // Cambiar a getline

        std::cout << "Modalitats de subscripcio disponibles " << std::endl;
        std::cout << " > 1. Completa" << std::endl;
        std::cout << " > 2. Cinefil" << std::endl;
        std::cout << " > 3. Infantil" << std::endl;

        std::string eleccio;
        std::cout << "Escriu el numero de la modalitat a canviar: ";
        std::getline(std::cin, eleccio);  // Cambiar a getline

        bool continua = true;
        if (eleccio == "1") {
            modalitatU = "Completa";
        }
        else if (eleccio == "2") {
            modalitatU = "Cinefil";
        }
        else if (eleccio == "3") {
            modalitatU = "Infantil";
        }
        else if (eleccio != ""){

            throw std::invalid_argument("Error: La modalitat escollida no es valida.");
        }
        ctrlModifica.modificaUsuari(nomU, contrasenyaU, correuU, dataNaixementU, modalitatU);

        std::cout << std::endl;
        std::cout << "** Dades Usuari Modificades **" << std::endl;

        PassarelaUsuari usuari;
        PetitFlix& petitF = PetitFlix::getInstance();
        usuari = petitF.obteUsuari();

        std::cout << "Nom complet: " << usuari.obteNom() << std::endl;
        std::cout << "Sobrenom: " << usuari.obteSobrenom() << std::endl;
        std::cout << "Correu electronic: " << usuari.obteCorreu() << std::endl;
        dataNeix = usuari.obteDataNaixement();
        dataNeix = dataNeix.substr(0, 10);  // Obtener solo los primeros 10 caracteres (YYYY-MM-DD)
        std::cout << "Data naixement (AAAA-MM-DD): " << dataNeix << std::endl;
        std::cout << "Modalitat subscripcio: " << usuari.obteModalitatSubs() << std::endl;
        std::cout << std::endl;

    }
    catch (const std::invalid_argument& e) {

        std::cout << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void CapaDePresentacio::procesarEsborraUsuari() {

    std::cout << "** Esborra Usuari **" << std::endl;
    std::cout << "Per confirmar l'esborrat s'ha d'entrar la contrasenya:";
    std::string contrasenya;
    std::cin >> contrasenya;

    try {
        TxEsborraUsuari TxEsborra (contrasenya);
        TxEsborra.executa();
        std::cout << "L'usuari s'ha esborrat correctament." << std::endl << std::endl;
        sessioIniciada = false;
    }
    catch (const std::exception& e) {

        sessioIniciada = true;
        std::cerr << "Error: " << e.what() << std::endl;
    }
}


void CapaDePresentacio::procesarConsultaVisualitzacions() {

    std::cout << "** Consulta Visualitzacions **" << std::endl;
    try {
        TxConsultaVisualitzacions txConsulta;
        txConsulta.executa();
        TxConsultaVisualitzacions::Resultat res;
        res = txConsulta.obteResultat();

        PassarelaUsuari usuari;
        PetitFlix& petitF = PetitFlix::getInstance();
        usuari = petitF.obteUsuari();

        //----------------------------- canviar

        std::cout << "Nom complet: " << usu.obteNom() << std::endl;
        std::cout << "Sobrenom: " << usu.obteSobrenom() << std::endl;
        std::cout << "Correu electronic: " << usu.obteCorreu() << std::endl;
        std::string dataNeix = usu.obteDataNeix();
    }
    catch (const std::exception& e) {

        sessioIniciada = true;
        std::cerr << "Error: " << e.what() << std::endl;
    }
}