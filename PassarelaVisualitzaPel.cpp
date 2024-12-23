#include "PassarelaVisualitzaPel.h"


PassarelaVisualitzaPel::PassarelaVisualitzaPel() { 

    sobrenom = "";
    titolPelicula = "";
    data = "";
    numVisualitzacions = 0;
}

PassarelaVisualitzaPel::PassarelaVisualitzaPel (std::string sobrenomU, std::string titolPeliculaV, std::string dataV, int numVisualitzacionsU) {
        
    sobrenom = sobrenomU;
    titolPelicula = titolPeliculaV;
    data = dataV;
    numVisualitzacions = numVisualitzacionsU;
}

std::string PassarelaVisualitzaPel::obteSobrenom(){
        
    return sobrenom;
}
std::string PassarelaVisualitzaPel::obteTitolPelicula(){

    return titolPelicula;
}
std::string PassarelaVisualitzaPel::obteData(){
        
    return data;
}
int PassarelaVisualitzaPel::obteNumVisualitzacions(){
        
    return numVisualitzacions;
}

void PassarelaVisualitzaPel::posaSobrenom(std::string sobrenomU){

    sobrenom = sobrenomU;
}

void PassarelaVisualitzaPel::posaTitolPelicula (std::string titolPeliculaV){

    titolPelicula = titolPeliculaV;
}
void PassarelaVisualitzaPel::posaData (std::string dataV){
        
    data = dataV;
}
void PassarelaVisualitzaPel::posaNumVisualitzacions (int numVisualitzacionsV){

    numVisualitzacions = numVisualitzacionsV;
}

    
void PassarelaVisualitzaPel::insereix(){
    
    ConnexioBD& con = ConnexioBD::getInstance();
    //ConnexioBD con;
    std::ostringstream numVisu;
    numVisu << numVisualitzacions;
    std::string query = "INSERT INTO visualitzacio_pelicula (sobrenom_usuari, titol_pelicula, data, num_visualitzacions) VALUES('" + sobrenom + "', '" + titolPelicula + "', '" + data + "' , '" + numVisu.str() + "')";
    con.executarComanda(query);
}

void PassarelaVisualitzaPel::modifica(){

    ConnexioBD& con = ConnexioBD::getInstance();
    //ConnexioBD con;
    
    std::ostringstream numVisu;
    numVisu << numVisualitzacions;

    std::string query = "UPDATE visualitzacio_pelicula SET data = '" + data + "', num_visualitzacions = '" + numVisu.str() + "' WHERE sobrenom_usuari = '" + sobrenom + "' AND titol_pelicula = '" + titolPelicula + "'";
    con.executarComanda(query);
}

   
void PassarelaVisualitzaPel::esborra() {

    ConnexioBD& con = ConnexioBD::getInstance();
    //ConnexioBD con;
        
    con.executarComanda("DELETE FROM visualitzacio_pelicula WHERE sobrenom_usuari = '" + sobrenom + "' AND titol_pelicula = '" + titolPelicula + "'");

}