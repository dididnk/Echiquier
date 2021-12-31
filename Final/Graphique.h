#if !defined Graphique_h
#define Graphique_h

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
using namespace sf; 


#define LONGUEUR 8

// Ces constantes servent à detecter les pions du tableau 
// Pour le remplir dans le tableau de POO de prof
#define TABLEAU "images/Tableau.png"
#define PION_BLANC "images/PieceBlanc.png"
#define PION_NOIR "images/PieceNoir.png"
#define TOUR_BLANC "images/TourBlanc.png"
#define TOUR_NOIR "images/TourNoir.png"
#define CHEVAL_BLANC "images/ChevalBlanc.png"
#define CHEVAL_NOIR "images/ChevalNoir.png"
#define FOU_BLANC "images/FouBlanc.png"
#define FOU_NOIR "images/FouNoir.png"
#define REINE_BLANC "images/ReineBlanc.png"
#define REINE_NOIR "images/ReineNoir.png"
#define ROI_BLANC "images/RoiBlanc.png"
#define ROI_NOIR "images/RoiNoir.png"
// cas particulier
#define TRANFORMATION_BLANC "images/TransformerBlanc.png"
#define TRANFORMATION_NOIR "images/TransformerNoir.png"

// Structure pour stocker les positions
struct position
{
    int x, y;
}ancienne_Pos, roi_blanc, roi_noir, transforme_blanc, transforme_noir;


int  taille = 100, ca_bouge = 0, x, y;

// Le tableau sert à detecter l'emplacement correcte des pions 
// Pour le remplir dans le tableau de POO de le prof
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

//----------------------------------------------------------------
void Run();


//##############################"""""HEADER PIECE"#######################################

//#include "Echiquier.h"
class Echiquier;  // pb de reference croisee

/**
 * Declaration d'une classe modelisant une piece de jeu d'echec.
 */
class Piece
{
   protected:
    int  m_x;
    int  m_y;
    bool m_white;
    String src;
   public:
    virtual ~Piece();
    Piece();
    Piece( int x, int y, bool white );
    Piece( const Piece &autre );
    Piece &      operator=( const Piece &autre );
    void         init( int x, int y, bool white );
    void         move( int x, int y );
    int          x();
    int          y();
    String       getSrc();
    bool         isWhite();
    bool         isBlack();
    void         affiche();
    virtual char vue();
    virtual bool mouvementValide( Echiquier &e, int x, int y) = 0;
    virtual bool mouvementEchec( Echiquier &e, int x, int y ) = 0;
};

class Roi : public Piece
{
   public:
    Roi( bool white );
    ~Roi();
    char vue();
    bool mouvementValide( Echiquier &e, int x, int y);
    void roque();
    String getSrc();
    bool mouvementEchec( Echiquier &e, int x, int y );
    bool EchecTest( Echiquier &e);
    void getPosition( Echiquier &e);
};

class Tour : virtual public Piece
{
   public:
    Tour( bool white, bool gauche );
    ~Tour();
    char vue();
    bool mouvementValide( Echiquier &e, int x, int y);
    String getSrc();
    bool mouvementEchec( Echiquier &e, int x, int y );
};

class Fou : virtual public Piece
{
   public:
    Fou( bool white, bool gauche );
    ~Fou();
    char vue();
    bool mouvementValide( Echiquier &e, int x, int y);
    String getSrc();
    bool mouvementEchec( Echiquier &e, int x, int y );
};

class Cavalier : public Piece
{
   public:
    Cavalier( bool white, bool gauche );
    ~Cavalier();
    char vue();
    bool mouvementValide( Echiquier &e, int x, int y);
    String getSrc();
    bool mouvementEchec( Echiquier &e, int x, int y );
};

class Reine : public Fou, public Tour
{
   public:
    Reine( bool white );
    ~Reine();
    char vue();
    bool mouvementValide( Echiquier &e, int x, int y);
    String getSrc();
    bool mouvementEchec( Echiquier &e, int x, int y );
};

class Pion : public Piece
{
   public:
    Pion( bool white, int x );
    ~Pion();
    char vue();
    bool mouvementValide( Echiquier &e, int x, int y);
    String getSrc();
    bool mouvementEchec( Echiquier &e, int x, int y );
};

//##############################"""""HEADER JOUEUR"#######################################

class Joueur
{
   protected:
    Piece *m_pieces[16];

   public:
    Joueur();
    virtual ~Joueur();
    //Joueur( bool white );
    void         affiche();
    virtual bool isWhite() = 0;
    bool         placerPieces( Echiquier &e );
    /* bool placerPieces( Echiquier * e ); */
};

class JoueurBlanc : public Joueur
{
   public:
    JoueurBlanc();
    bool isWhite();
};

class JoueurNoir : public Joueur
{
   public:
    JoueurNoir();
    bool isWhite();
};


#endif