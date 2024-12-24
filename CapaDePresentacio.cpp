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
        std::cout << "Sessio iniciada correctament!" << std::endl << std::endl;
        sessioIniciada = true;
    }
    catch (const std::exception& e) {
        sessioIniciada = false;
        std::cout << "Error: Hi ha hagut un error amb el sobrenom o la contrasenya." << std::endl  << std::endl; // NO e.what(), ja que el missatge no ha de dir que ha fallat per seguretat
    }
}

void CapaDePresentacio::tancarSessio() {
    std::string resposta;
    std::cout << "** Tancar Sessio **" << std::endl;
    std::cout << "Vols tancar la sessio (S/N): ";
    std::cin >> resposta; 

    if (resposta == "S"){
        TxTancaSessio tx;
        tx.executa();
        sessioIniciada = false;
        std::cout << "Sessio tancada correctament!" << std::endl << std::endl;
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
            std::cout << "Usuari registrat correctament!, per accedir al teu compte inicia sessio." << std::endl << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Error: "  << e.what() << std::endl << std::endl;
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
    std::cout << "Per confirmar l'esborrat s'ha d'entrar la contrasenya: ";
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
        std::cout << std::endl;
        std::cout << "** Visualitzacions Pel.licules **" << std::endl;
        std::cout << "*********************************" << std::endl;
        
        TxConsultaVisualitzacions txConsulta;
        txConsulta.executa();
        
        TxConsultaVisualitzacions::Resultat res;
        res = txConsulta.obteResultat();

        int midaVecPel = res.vec_Pel.size();
        
        std::string titolP, dataVisualitzacioP, descripcioP, qualificacioEdatP;
        int numVisualitzacionsP;
        if (midaVecPel == 0){
            std::cout << "No s'ha visualitzat cap pelicula." <<std::endl;
        }
        else {
            for (int i = 0; i < midaVecPel; i++) {

            dataVisualitzacioP = res.vec_Pel[i].obteDataVisualitzacio();
            titolP = res.vec_Pel[i].obteTitol();
            descripcioP = res.vec_Pel[i].obteDescripcio();
            qualificacioEdatP = res.vec_Pel[i].obteQualificacioEdat();
            numVisualitzacionsP = res.vec_Pel[i].obteVisualitzacions();
            
            std::cout << " - " << dataVisualitzacioP << ": " << titolP << "; " << descripcioP << "; " << qualificacioEdatP << "; nombre de visualitzacions: " << numVisualitzacionsP << std::endl;
            }
        }

        std::cout << std::endl;
        std::cout << "** Visualitzacions Series **" << std::endl;
        std::cout << "****************************" << std::endl;

        int midaVecCap = res.vec_Cap.size();

        std::string titolS, dataVisualitzacioC, qualificacioEdatC;
        int numTemporada, numCapitol, numVisualitzacionsC;
        if (midaVecCap == 0){
            std::cout << "No s'ha visualitzat cap capitol." <<std::endl;
        }
        else {
            for (int i = 0; i < midaVecCap; i++) {

                dataVisualitzacioC = res.vec_Cap[i].obteDataVisualitzacio();
                titolS = res.vec_Cap[i].obteTitol();
                numTemporada = res.vec_Cap[i].obteNumTemporada();
                numCapitol = res.vec_Cap[i].obteNumCapitol();
                qualificacioEdatC = res.vec_Cap[i].obteQualificacioEdat();
                numVisualitzacionsC = res.vec_Cap[i].obteVisualitzacions();

                std::cout << " - " << dataVisualitzacioC << ": " << titolS << "; " << qualificacioEdatC << "; temporada " << numTemporada << ", capitol " << numCapitol  << "; nombre de visualitzacions: " << numVisualitzacionsC << std::endl;
            }
        }
    }
    catch (const std::exception& e) {

        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void CapaDePresentacio::procesarVisualitzarPel() {

    std::cout << "** Visualitzar Pel.licula **" << std::endl;
    try {
        std::string titol;
        std::cout << "Nom pel.licula: ";
        std::cin >> titol;

        ////// data i hora actual
        auto ara = std::chrono::system_clock::now();
        std::time_t tempsActual = std::chrono::system_clock::to_time_t(ara);
        std::tm tempsFinal = *std::localtime(&tempsActual);
        // Formatear directamente en un std::ostringstream
        std::ostringstream stream;
        stream << std::put_time(&tempsFinal, "%Y-%m-%d %H:%M:%S");
        std::string dataHora = stream.str();


        CtrlVisualitzarPel ctrlVisualitza;
      
        std::string descripcio, qualificacioEdat, dataEstrena, duracio;
        DTOContingutPelicula dto;

        dto = ctrlVisualitza.consultaInfoPeli(titol,dataHora);

        descripcio = dto.obteDescripcio();
        qualificacioEdat = dto.obteQualificacioEdat();
        dataEstrena = dto.obteDataEstrena();
        duracio = dto.obteDuracio();
       
        std::cout << std::endl;
        std::cout << "Informacio pel.licula ..." << std::endl << std::endl;
        std::cout << "Nom pel.licula: " << titol << std::endl;
        std::cout << "Descripcio: " << descripcio << std::endl;
        std::cout << "Qualificacio edat: " << qualificacioEdat << std::endl;
        std::cout << "Data estrena: " << dataEstrena.substr(0, 10) << std::endl; // Obtenir només els 10 primers chars (YYYY-MM-DD)
        std::cout << "Duracio: " << duracio << std::endl;
        std::cout << "Vols continuar amb la visualitzacio (S/N): ";
        std::string resposta;
        std::cin >> resposta;
        std::cout << std::endl << std::endl;
        if (resposta == "S") {

            //---------------------------------------------------

            ctrlVisualitza.registrarVisualitzacions(titol, dataHora);

            //------------------------------------------------------------

            std::cout << "Visualitzacio registrada: " << dataHora << std::endl;

            std::vector< DTOContingutPelicula> vecDTOContingutPeli;
            vecDTOContingutPeli = ctrlVisualitza.pelisRelacionades(titol);

            int midaVecDto = vecDTOContingutPeli.size();

            std::string titolP, descripcio, qualificacioEdat, dataEstrena, duracio;
            if (midaVecDto == 0) {

                std::cout << "No hi ha pel.licules relacionades." << std::endl;
            }
            else {
                std::cout << "Pel.licules relacionades: " << std::endl;
                for (int i = 0; i < midaVecDto; i++) {

                    titolP = vecDTOContingutPeli[i].obteTitol();
                    descripcio = vecDTOContingutPeli[i].obteDescripcio();
                    qualificacioEdat = vecDTOContingutPeli[i].obteQualificacioEdat();
                    dataEstrena = vecDTOContingutPeli[i].obteDataEstrena();
                    duracio = vecDTOContingutPeli[i].obteDuracio();

                    std::cout << " - " << titolP << "; " << descripcio << "; " << qualificacioEdat << "; " << duracio << " min; " << dataEstrena.substr(0, 10) << std::endl;
                }
            }
        }
    }
    catch (const std::exception& e) {

        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void CapaDePresentacio::procesarVisualitzarCapitol() {

    std::cout << "** Visualitzar Capitol **" << std::endl;
    try {
        std::string titolS;
        std::cout << "Nom de la serie: ";
        std::cin >> titolS;

        CtrlVisualitzarCapitol CtrlCap;
        int numTemps;
        numTemps = CtrlCap.consultaNumeroTemporades(titolS);
        int temporadaEscollida = 1;
        if (numTemps > 1) {
            std::cout << "La serie te " << std::to_string(numTemps) << " temporades." << std::endl;
            std::cout << "Escull una temporada: ";
            std::cin >> temporadaEscollida;
            std::cout << std::endl;
        }
        std::vector<DTOCapitol> capitols;//CANVIAR
        capitols = CtrlCap.consultaCapitols(titolS, temporadaEscollida);
        
        int midaCapitols = capitols.size();
        if (midaCapitols > 1){

            std::cout << "LLista capitols:"<<std::endl;
        }
        if (midaCapitols == 1){

            std::cout << "Capitol:" << std::endl;
        }

        std::string titolC, dataEstrena, dataVisualitzacio;
        int numCapitol;
        for (int i = 0; i < midaCapitols; i++ ) {
  
            dataEstrena = capitols[i].obteDataPublicacio();
            dataVisualitzacio = capitols[i].obteDataVisualitzacio();
            titolC = capitols[i].obteTitol();
            numCapitol = capitols[i].obteNumCapitol();

            std::cout << std::to_string(numCapitol) << ". " << titolC << "; " << dataEstrena.substr(0, 10) << "; ";
            if (dataVisualitzacio == "") {

                std::cout << "no visualitzat" << std::endl;
            }
            else {

                std::cout << "visualitzat el " << dataVisualitzacio.substr(0, 10) << std::endl;
            }
        }
        std::cout << std::endl;
        std::cout << "Numero de capitol a visualitzar: ";
        int capitol;
        std::cin >> capitol;
        std::cout << "Vols continuar amb la visualitzacio (S/N):";
        std::string llegueix;
        std::cin >> llegueix;
        if (llegueix == "S") {

            ////// data i hora actual
            auto ara = std::chrono::system_clock::now();
            std::time_t tempsActual = std::chrono::system_clock::to_time_t(ara);
            std::tm tempsFinal = *std::localtime(&tempsActual);
            std::ostringstream stream;
            stream << std::put_time(&tempsFinal, "%Y-%m-%d %H:%M:%S");
            std::string dataHora = stream.str();


            CtrlCap.registrarVisualitzacio(titolS, temporadaEscollida, capitol, dataHora);
            std::cout << "Visualitzacio registrada: " << dataHora << std::endl;
        }
        
    }
    catch (const std::exception& e) {

        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void CapaDePresentacio::procesarProperesEstrenes() {

    std::cout << "** Properes estrenes **" << std::endl;
    try {
        ////// data i hora actual
        auto ara = std::chrono::system_clock::now();
        std::time_t tempsActual = std::chrono::system_clock::to_time_t(ara);
        std::tm tempsFinal = *std::localtime(&tempsActual);
        std::ostringstream stream;
        stream << std::put_time(&tempsFinal, "%Y-%m-%d %H:%M:%S");
        std::string dataHoraActual = stream.str();

        std::string modalitatConsultada;

        if (sessioIniciada) {   // aixo que ho faci el tx
            // aprofitar el DTO
            modalitatConsultada = ".";
                // usuari ha registrat sessio la modalitat sub és la de l'usuari
                //-cinefil -> només pelis
                //-completa -> tot
                //-infantil -> tot però limitat per rang d'edat

        }
        else {

            std::cout << std::endl;
            std::cout << "Modalitats Disponibles ... " << std::endl;
            std::cout << " > 1. Completa" << std::endl;
            std::cout << " > 2. Cinefil" << std::endl;
            std::cout << " > 3. Infantil" << std::endl;
            
            std::string eleccio;
            std::cout << "Escull la modalitat que vols consultar: ";
            std::cin >> eleccio;
            if (eleccio == "1") {
                
                modalitatConsultada = "Completa";
            }
            else if (eleccio == "2") {

                modalitatConsultada = "Cinefil";
            }
            else if (eleccio == "3") {

                modalitatConsultada = "Infantil";
            }
            else if (eleccio != ""){    

                throw std::invalid_argument("Error: La modalitat escollida no es valida.");
            }
            // usuari no ha inciat sessio li preguntem quina modalitat vol consultar 
        }
        TxProperesEstrenes tx(modalitatConsultada,dataHoraActual);
        tx.executa();
        std::vector <DTOEstrenes> properesEstrenes;
        properesEstrenes = tx.obteResultat();

        std::string dataEstrena, text, titol, qualificacioEdat, duracio, duracioOnumTemp;
        int numCap;
        int mida = properesEstrenes.size();

        std::cout << std::endl;
        if ( mida == 0 ) {

            std::cout << "No hi ha properes estrenes." << std::endl;
        }
        else {

            // Ordenar manualmente el vector por dataEstrena (Bubble Sort)
            for (int i = 0; i < mida - 1; ++i) {
                for (int j = 0; j < mida - i - 1; ++j) {
                    if (properesEstrenes[j].obteData() > properesEstrenes[j + 1].obteData()) {
                        // Intercambiar posiciones
                        DTOEstrenes temp = properesEstrenes[j];
                        properesEstrenes[j] = properesEstrenes[j + 1];
                        properesEstrenes[j + 1] = temp;
                    }
                }
            }

            for (int i = 0; i < mida; i++) {

                duracioOnumTemp = properesEstrenes[i].obteDuracioOnumTemp();
                dataEstrena = properesEstrenes[i].obteData();
                titol = properesEstrenes[i].obteTitol();
                qualificacioEdat = properesEstrenes[i].obteQualificacioEdat();
                numCap = properesEstrenes[i].obteNumCap();
                if (numCap == 0) {

                    std::cout << i + 1 << ".- " << dataEstrena.substr(0, 10) << " [Pel.licula]: " << titol << "; " << qualificacioEdat << "; " << duracioOnumTemp << "h." << std::endl;
                }
                else {

                    std::cout << i + 1 << ".- " << dataEstrena.substr(0, 10) << " [Serie]: " << titol << "; " << qualificacioEdat << "; Temporada " << duracioOnumTemp << " Capitol " << numCap << "." << std::endl;
                }
            }
            std::cout << std::endl;
        }
    }
    catch (const std::exception& e) {

        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void CapaDePresentacio::procesarUltimesNovetats() {

    std::cout << "** NOVETATS **" << std::endl;
    try {

        //Hora actual
        auto ara = std::chrono::system_clock::now();
        std::time_t tempsActual = std::chrono::system_clock::to_time_t(ara);
        std::tm tempsFinal = *std::localtime(&tempsActual);
        std::ostringstream stream;
        stream << std::put_time(&tempsFinal, "%Y-%m-%d %H:%M:%S");
        std::string dataHoraActual = stream.str();

        std::string modalitatConsultada;

        if (sessioIniciada) {

            modalitatConsultada = ".";
        }
        else {

            std::cout << std::endl;
            std::cout << "Modalitats Disponibles ... " << std::endl;
            std::cout << " > 1. Completa" << std::endl;
            std::cout << " > 2. Cinefil" << std::endl;
            std::cout << " > 3. Infantil" << std::endl;
            
            std::string eleccio;
            std::cout << "Escull la modalitat que vols consultar: ";
            std::cin >> eleccio;
            if (eleccio == "1") {
                
                modalitatConsultada = "Completa";
            }
            else if (eleccio == "2") {

                modalitatConsultada = "Cinefil";
            }
            else if (eleccio == "3") {

                modalitatConsultada = "Infantil";
            }
            else if (eleccio != ""){    

                throw std::invalid_argument("Error: La modalitat escollida no es valida.");
            }
            // usuari no ha inciat sessio li preguntem quina modalitat vol consultar 
        }
        TxUltimesNovetats tx (modalitatConsultada, dataHoraActual);
        tx.executa();
        std::vector<DTOEstrenes> ultimesNovetats;
        ultimesNovetats = tx.obteResultat();

        std::string dataEstrena, text, titol, qualificacioEdat, duracio, duracioOnumTemp;
        int numCap;
        int mida = ultimesNovetats.size();

        std::cout << std::endl;
        if ( mida == 0 ) {

            std::cout << "No hi ha cap contingut estrenat." << std::endl;
        }
        else {
            bool primeraSerie = true;
            bool primeraPelicula = true;
            int j = 1;
            for (int i = 0; i < mida; i++) {

                duracioOnumTemp = ultimesNovetats[i].obteDuracioOnumTemp();
                dataEstrena = ultimesNovetats[i].obteData();
                titol = ultimesNovetats[i].obteTitol();
                qualificacioEdat = ultimesNovetats[i].obteQualificacioEdat();
                numCap = ultimesNovetats[i].obteNumCap();
                if (numCap == 0) {
                    if (primeraPelicula){
                        
                        primeraPelicula = false;
                        std::cout << "** Novetats pel.licules **" << std::endl;
                        std::cout << "**************************" << std::endl;
                    }
                    std::cout << i + 1 << ".- " << dataEstrena.substr(0, 10) << ": "<< titol << "; " << qualificacioEdat << "; " << duracioOnumTemp << "h." << std::endl;
                }
                else {
                    if (primeraSerie){

                        primeraSerie = false;
                        std::cout << std::endl;
                        std::cout << "** Novetats series **" << std::endl;
                        std::cout << "*********************" << std::endl;
                    }
                    std::cout << j << ".- " << dataEstrena.substr(0, 10) << ": "<< titol << "; " << qualificacioEdat << "; Temporada " << duracioOnumTemp << " Capitol " << numCap << "." << std::endl;
                    j++;
                }
            }
            std::cout << std::endl;
        }
    }
    catch (const std::exception& e) {

        std::cerr << "Error: " << e.what() << std::endl;
    }
}