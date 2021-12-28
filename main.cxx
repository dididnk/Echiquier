#include <SFML/Graphics.hpp>
#include <iostream>
#include "Jeu.h"


int main(int argc, char const *argv[])
{
    // Création de la fenêtre
    creationJeu run = creationJeu();
    run.lancer();
    return 0;
}

