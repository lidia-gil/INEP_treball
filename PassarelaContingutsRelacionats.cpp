#include "PassarelaContingutsRelacionats.h"
PassarelaContingutsRelacionats::PassarelaContingutsRelacionats(){

    titolContingutX = "";
    titolContingutY = "";
}
PassarelaContingutsRelacionats::PassarelaContingutsRelacionats(std::string titolContingutA, std::string titolContingutB){

    titolContingutX = titolContingutA;
    titolContingutY = titolContingutB;
}

std::string PassarelaContingutsRelacionats::obteTitolContingutX(){

    return titolContingutX;
}
std::string PassarelaContingutsRelacionats::obteTitolContingutY(){

    return titolContingutY;
}

void PassarelaContingutsRelacionats::posaTitolContingutX(std::string titolContingutA){

    titolContingutX = titolContingutA;
}
void PassarelaContingutsRelacionats::posaTitolContingutY(std::string titolContingutB){

    titolContingutY = titolContingutB;
}

void PassarelaContingutsRelacionats::insereix(){

    ConnexioBD con;

    std::string query = "INSERT INTO relacionat (titol_x, titol_y) VALUES('" + titolContingutX +  "' , '" + titolContingutY + "')";
    con.executarComanda(query);
}
void PassarelaContingutsRelacionats::esborra(){

    ConnexioBD con;
    std::string query = "DELETE FROM relacionat WHERE titol_x = '" + titolContingutX + "' AND titol_y = '" + titolContingutY + "'";
    con.executarComanda(query);
}