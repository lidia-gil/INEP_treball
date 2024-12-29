#include "CtrlVisualitzarCapitol.h"


CtrlVisualitzarCapitol::CtrlVisualitzarCapitol(){
            
}

int CtrlVisualitzarCapitol::consultaNumeroTemporades(std::string titolS){

    PassarelaTemporada temp;
    CercadoraTemporada cercaTemp;
    temp = cercaTemp.cercaPerTitol(titolS);
    int tempMax;
    tempMax = temp.obteNumTemporada();
    return tempMax;
}

std::vector<DTOCapitol> CtrlVisualitzarCapitol::consultaCapitols(std::string titolS, int numTemp){

    std::vector<DTOCapitol> result;

    std::vector<PassarelaCapitol> vecCap;
    CercadoraCapitol cercaCap;
    vecCap = cercaCap.cercaPerTitoliTemporada(titolS, numTemp);

    PassarelaUsuari usuari;
	PetitFlix& petitF = PetitFlix::getInstance();
	usuari = petitF.obteUsuari();
	std::string sobrenomU;
	sobrenomU = usuari.obteSobrenom();

    std::vector<PassarelaVisualitzaCapitol> vecCapVisualitzats;
    CercadoraVisualitzaCapitol visualitzaCap;
    vecCapVisualitzats = visualitzaCap.cercaVisualitzacions(sobrenomU);

    visualitzaCap.cercaVisualitzacions(sobrenomU);
    
    std::string titolC, dataEstrena;
    int numTemporada, numCap;
    for (int i=0; i < vecCap.size(); i++){

        numTemporada = vecCap[i].obteNumTemporada();
        numCap = vecCap[i].obteNumCapitol();
        titolC = vecCap[i].obteTitolCapitol();
        dataEstrena = vecCap[i].obteData();

        std::string dataVisualitzacio = "";
        bool trobat = false;
        int j = 0;
        while ( j < vecCapVisualitzats.size() and not trobat){

            if (titolS != vecCapVisualitzats[j].obteTitolSerie()){

                trobat = false;
            }
            else if (numTemporada != vecCapVisualitzats[j].obteNumTemporada()) {

                trobat = false;
            }
            else if (numCap != vecCapVisualitzats[j].obteNumCapitol()){

                trobat = false;
            }
            else {

                dataVisualitzacio = vecCapVisualitzats[j].obteData();
            }
            j++;
        }

        DTOCapitol dtoCap(numCap, titolC, dataEstrena, dataVisualitzacio); // sino s'ha visualitzat dataVisualitzacio retornara ""
        result.push_back(dtoCap);
    }

    //PER A CADA UN, MIRAR SI S'HA VISUALITZAT. + FER DTO
    return result;
}

void CtrlVisualitzarCapitol::registrarVisualitzacio(std::string titolS, int numTemp, int numCap, std::string dataHora) {

    std::vector <PassarelaVisualitzaCapitol> visualitzaCap;
    CercadoraVisualitzaCapitol cercaCap;

    PassarelaUsuari usuari;
    PetitFlix& petitF = PetitFlix::getInstance();
    usuari = petitF.obteUsuari();

    std::string sobrenomU;
    sobrenomU = usuari.obteSobrenom();

    // comparació data Naixement del Usuari amb la qualificació d'edat de la pel.licula 
    //----------------------------------------------------

    CercadoraCapitol cercaCapitol;
    PassarelaCapitol cap;
    cap = cercaCapitol.cercaCapitol(titolS,numTemp,numCap);
    std::string dataEstrena;
    dataEstrena = cap.obteData();
    if (dataEstrena > dataHora){

        throw std::runtime_error("El capitol encara no s'ha estrenat. S'estrenara el '" + dataEstrena.substr(0, 10) + "'.");
    }


    PassarelaContingut cont;
    CercadoraContingut cercaCont;
    cont = cercaCont.cercaPerTitol(titolS);

    std::string qualificacioEdat = cont.obteQualificacioEdat();
    if (qualificacioEdat != "TP"){

        std::string modalitatSub = usuari.obteModalitatSubs();
		if (modalitatSub == "Infantil"){

            throw std::runtime_error("L'usuari loguejat no pot veure el capitol, degut a que la seva modalitat de subscripcio es infantil.");
        }
        else if  (modalitatSub == "Cinefil"){

            throw std::runtime_error("No pots veure el capitol, la teva modalitat de subscripcio es cinefil i per tant no pots veure series.");
        }
        std::string edat;
        int i = 0;
        while (qualificacioEdat[i] != '+') {

            edat += qualificacioEdat[i];
            i++;
        }

        std::string dataNaixement = usuari.obteDataNaixement();

        //Calculem l'edat de l'usuari a partir de la data de neixament i la data actual:
        int edatUsuari = 0;
        if (dataNaixement.substr(0, 4) <= dataHora.substr(0, 4)) { // Comparar anys
            edatUsuari = std::stoi(dataHora.substr(0, 4)) - std::stoi(dataNaixement.substr(0, 4));

            // Verificar si ja ha complert anys aquest any
            if (dataNaixement.substr(5, 2) > dataHora.substr(5, 2) ||  // Si el mes no ha arribat
                (dataNaixement.substr(5, 2) == dataHora.substr(5, 2) && dataNaixement.substr(8, 2) > dataHora.substr(8, 2))) { // Si el dia no ha arribat
                edatUsuari--;
            }
        }

        if (std::stoi(edat) > edatUsuari) {

            throw std::runtime_error("L'usuari loguejat no pot veure el capitol. Edat de l'usuari: '" + std::to_string(edatUsuari) + "' Edat necessaria: '" + edat + "'");
        }
    }

    //-----------------------------------------------------


    visualitzaCap = cercaCap.cercaVisualitzacions(sobrenomU);

    bool trobat = false;
    std::string titolC;
    int numTemporada, numCapitol;

    int i = 0;
    while ((not trobat) and (i < visualitzaCap.size())) {
        bool continua = true;
        titolC = visualitzaCap[i].obteTitolSerie();
        numTemporada = visualitzaCap[i].obteNumTemporada();
        numCapitol = visualitzaCap[i].obteNumCapitol();

        if (titolC != titolS) {
            continua = false;
        }
        if (continua and (numTemporada != numTemp)){
            continua = false;
        }
        if (continua and (numCapitol == numCap)) {
            trobat = true;
        }
         ++i;
    }
    i--;
    if (trobat) {

        int visualitzacions = visualitzaCap[i].obteNumVisualitzacions();
        visualitzacions +=1;
        visualitzaCap[i].posaNumVisualitzacions(visualitzacions);
        visualitzaCap[i].posaData(dataHora);
        visualitzaCap[i].modifica();
    }
    else {

        PassarelaVisualitzaCapitol cap(sobrenomU, titolS, 1, numTemp, numCap, dataHora);
        cap.insereix();
    }
}
