#include "TxConsultaVisualitzacions.h"
TxConsultaVisualitzacions::TxConsultaVisualitzacions(){ }

void TxConsultaVisualitzacions::executa(){
    
    PassarelaUsuari usuari;
    PetitFlix& petitF = PetitFlix::getInstance();
    usuari = petitF.obteUsuari();

    std::string sobrenomU;
    sobrenomU = usuari.obteSobrenom();

    CercadoraVisualitzaPel visualitzacionsPel;
    std::vector<PassarelaVisualitzaPel> vec_Pelicules;
    vec_Pelicules = visualitzacionsPel.cercaVisualitzacions(sobrenomU);
    int midaVecPel = vec_Pelicules.size();
    result.vec_Pel.resize(midaVecPel);

    std::string titolP, dataVisualitzacioP, descripcioP, qualificacioEdatP; //declarem les variables per fer els DTOContingutMesVisualitzacioPel
    int numVisualitzacionsP;
    for (int i = 0; i < midaVecPel; i++) {
                                                            //info que treiem de les visualitzacions
        titolP = vec_Pelicules[i].obteTitolPelicula();
        dataVisualitzacioP = vec_Pelicules[i].obteData();
        numVisualitzacionsP = vec_Pelicules[i].obteNumVisualitzacions();
                                
        PassarelaContingut contingut;
        CercadoraContingut cerca_contingut;
        contingut = cerca_contingut.cercaPerTitol(titolP);
                                                            // info que treiem del contingut
        descripcioP = contingut.obteDescripcio();
        qualificacioEdatP = contingut.obteQualificacioEdat();
        
        // li fiquem tota la info al vector de dto
        DTOContingutMesVisualitzacioPel dto(dataVisualitzacioP, titolP, descripcioP, qualificacioEdatP, numVisualitzacionsP);
        result.vec_Pel[i] = dto;
    }

    CercadoraVisualitzaCapitol visualitzacionsCapitol;
    std::vector<PassarelaVisualitzaCapitol> vec_Capitols;
    vec_Capitols = visualitzacionsCapitol.cercaVisualitzacions(sobrenomU);
    int midaVecCap = vec_Capitols.size();
    result.vec_Cap.resize(midaVecCap);

    std::string  titolC, dataVisualitzacioC, qualificacioEdatC; //declarem les variables per fer els DTOContingutMesVisualitzacioCap
    int numTemporada,numCapitol, numVisualitzacionsC;

    for (int i = 0; i < midaVecPel; i++) {
        //info que treiem de les visualitzacions
        titolC = vec_Capitols[i].obteTitolSerie();
        dataVisualitzacioC = vec_Capitols[i].obteData();
        numVisualitzacionsC = vec_Capitols[i].obteNumVisualitzacions();
        numTemporada = vec_Capitols[i].obteNumTemporada();
        numCapitol = vec_Capitols[i].obteNumCapitol();

        PassarelaContingut contingut;
        CercadoraContingut cerca_contingut;
        contingut = cerca_contingut.cercaPerTitol(titolC);
        // info que treiem del contingut
        qualificacioEdatC = contingut.obteQualificacioEdat();

        // li fiquem tota la info al vector de dto
        DTOContingutMesVisualitzacioCap dto(dataVisualitzacioC, titolC, numTemporada, numCapitol, qualificacioEdatC, numVisualitzacionsC);
        result.vec_Cap[i] = dto;
    }
}

TxConsultaVisualitzacions::Resultat TxConsultaVisualitzacions::obteResultat() {

    return result;
}