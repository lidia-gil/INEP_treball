#include "TxTancaSessio.h"

TxTancaSessio::TxTancaSessio() { }


void TxTancaSessio::executa() {

    PetitFlix& petitFlix = PetitFlix::getInstance();
    petitFlix.tancaSessio();
}

