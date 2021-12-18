#if !defined Graphique_h
#define Graphique_h

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf; 

#define LONGUEUR 8
#define PION_BLANC -1
#define PION_NOIR 1
#define TOUR_BLANC -2
#define TOUR_NOIR 2
#define CHEVAL_BLANC -3
#define CHEVAL_NOIR 3
#define FOU_BLANC -4
#define FOU_NOIR 4
#define REINE_BLANC -5
#define REINE_NOIR 5
#define ROI_BLANC -6
#define ROI_NOIR 6


// Structure pour stocker les positions
struct position
{
    int x, y;
}ancienne_Pos, roi_blanc, roi_noir, transforme_blanc, transforme_noir;


int  taille = 100, ca_bouge = 0, x, y;

int tableDeJeu[LONGUEUR][LONGUEUR] =
{ 2, 3, 4, 5, 6, 4, 3, 2,
  1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
 -1,-1,-1,-1,-1,-1,-1,-1,
 -2,-3,-4,-5,-6,-4,-3,-2,
};

int mouvDroitTourBlanc = 0, mouvGaucheTourBlanc = 0, RoiBlancPremierMouv = 0;
int mouvDroitTourNoir = 0, mouvGaucheTourNoir = 0, RoiNoirPremierMouv = 0;

int mouvement = 0; // 0 -> Mouvement Blanc 1 -> Mouvement Noir

int EchecBlanc = 0, EchecNoir = 0;

int transformationBlanc = 0, transformationNoir = 0;

// fênetre de jeu
RenderWindow window(VideoMode(800, 800), "Ehiquier by Emmanuel NGBAME");
Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;

//-----------------------------------------------------------
bool PionBlanc(int ax, int ay, int nx, int ny);
bool PionNoir(int ax, int ay, int nx, int ny);
bool TourBlanc(int ax, int ay, int nx, int ny);
bool TourNoir(int ax, int ay, int nx, int ny);
bool FouBlanc(int ax, int ay, int nx, int ny);
bool FouNoir(int ax, int ay, int nx, int ny);
bool ReineBlanc(int ax, int ay, int nx, int ny);
bool ReineNoir(int ax, int ay, int nx, int ny);
bool ChevalBlanc(int ax, int ay, int nx, int ny);
bool ChevalNoir(int ax, int ay, int nx, int ny);
bool RoiNoir(int ax, int ay, int nx, int ny);
bool RoiBlanc(int ax, int ay, int nx, int ny);

//-------------------------------------------------------------
bool PionBlancEchec(int posx, int posy, int roiX, int roiY);
bool TourBlancEchec(int ax, int ay, int roiX, int roiY);
bool FouBlancEchec(int ax, int ay, int roiX, int roiY);
bool ReineBlancEchec(int ax, int ay, int roiX, int roiY);
bool ChevalBlancEchec(int ax, int ay, int roiX, int roiY);
bool RoiBlancEchec(int ax, int ay, int roiX, int roiY);
bool PionNoirEchec(int ax, int ay, int roiX, int roiY);
bool TourNoirEchec(int ax, int ay, int roiX, int roiY);
bool FouNoirEchec(int ax, int ay, int roiX, int roiY);
bool ReineNoirEchec(int ax, int ay, int roiX, int roiY);
bool ChevalNoirEchec(int ax, int ay, int roiX, int roiY);
bool RoiNoirEchec(int ax, int ay, int roiX, int roiY);

//---------------------------------------------------------------

bool RoiNoirEchecTest(int posRoiX, int posRoiY);
bool RoiBlancEchecTest(int posRoiX, int posRoiY);

//----------------------------------------------------------------
void posRoiBlanc();
void posRoiNoir();

//---------------------------------------------------------------
void Run();


#endif