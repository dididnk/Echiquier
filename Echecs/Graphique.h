#if !defined Graphique_h
#define Graphique_h

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



#endif