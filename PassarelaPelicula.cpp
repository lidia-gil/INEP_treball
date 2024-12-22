#include "PassarelaPelicula.h"

PassarelaPelicula::PassarelaPelicula(){ }
//constructora
PassarelaPelicula::PassarelaPelicula(std::string titolP, std::string dataEstrenaP, std::string duracioP){

    titol = titolP;
    dataEstrena = dataEstrenaP;
    duracio = duracioP;
}

std::string PassarelaPelicula::obteTitol() {

    return titol;
}
std::string PassarelaPelicula::obteDataEstrena() {

    return dataEstrena;
}
std::string PassarelaPelicula::obteDuracio() {

    return duracio;
}

void PassarelaPelicula::posaTitol(std::string titolP) {

    titol = titolP;
}
void PassarelaPelicula::posaDataEstrena(std::string dataEstrenaP) {

    dataEstrena = dataEstrenaP;
}
void PassarelaPelicula::posaDuracio(std::string duracioP) {

    duracio = duracioP;
}


void PassarelaPelicula::insereix(){
    
    ConnexioBD con;

	std::string query = "INSERT INTO pelicula (titol, data_estrena, duracio) VALUES('" + titol + "', '" + dataEstrena +  "' , '" + duracio + "')";
	con.executarComanda(query);
}
void PassarelaPelicula::modifica(){

    ConnexioBD con;

    std::string query = "UPDATE pelicula SET data_estrena = '" + dataEstrena + "', duracio = '" + duracio + "' WHERE titol = '" + titol + "'";
    con.executarComanda(query);
}
void PassarelaPelicula::esborra() {

    ConnexioBD con;
	std::string query = "DELETE FROM pelicula WHERE titol = '" + titol + "'";
	con.executarComanda(query);
}