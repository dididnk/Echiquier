
#if !defined Jeu_H
#define Jeu_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>

#define LONGUEUR 7
#define PieceBLANC 1
#define PieceNOIR -1
#define TourBLANC 2
#define TourNOIR -2
#define ChevalBLANC 3
#define ChevalNOIR -3
#define ShopPieceNOIR 4
#define ShopPieceBLANC -4
#define ReineBLANC 5
#define ReineNOIR -5
#define RoiBLANC 6
#define RoiNOIR -6
#define MaxSize 8

using namespace sf;

// Structure pour stocker les positions
struct poistion
{
    int x, y;
}ancienne_Pos, roi_blanc, roi_noir, transforme_blanc, transforme_noir;

int taille = 100, ca_bouge;

int table[MaxSize][MaxSize]=
{
    -2, -3, -4, -5, -6, -4, -3, -2,
    -1, -1, -1, -1, -1, -1, -1, -1,
     0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0, 
     0,  0,  0,  0,  0,  0,  0,  0, 
     0,  0,  0,  0,  0,  0,  0,  0, 
     1,  1,  1,  1,  1,  1,  1,  1, 
     2,  3,  4,  5,  6,  4,  3,  2
};

int mouvDroitTourBlanc, mouvGaucheTourBlanc, RoiBlancPremierMouv;
int mouvDroitTourNoir, mouvGaucheTourNoir, RoiNoirPremierMouv;

int mouvement; // 1 -> Mouvement Blanc 0 -> Mouvement Noir

int testBlanc, testNoir;

int transformationBlanc, transformationNoir;

class creationJeu
{
    // Propriété
    protected:
        Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
        RenderWindow window(VideoMode(int, int), String);

    // Constructeur
    public:
        creationJeu();
        virtual ~creationJeu();

    // Fonctions
    void lancer();

    Sprite tabla(Texture t1);
	Sprite PionNegru(Texture t2);
	Sprite PionAlb(Texture t3);
	Sprite TurnNegru(Texture t4);
	Sprite TurnAlb(Texture t5);
	Sprite CalAlb(Texture t6);
	Sprite CalNegru(Texture t7);
	Sprite NebunNegru(Texture t8);
	Sprite NebunAlb(Texture t9);
	Sprite ReginaAlb(Texture t10);
	Sprite ReginaNegru(Texture t11);
	Sprite RegeNegru(Texture t12);
	Sprite RegeAlb(Texture t13);
	Sprite Mutare;
	Sprite TransformareALB(Texture t14);
	Sprite TransformareNEGRU(Texture t15);
};

#endif