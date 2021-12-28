#include "Graphique.h"
#include <SFML/Graphics.hpp>
#include <assert.h>


#include <iostream>

using namespace sf;
using namespace std;



//################################################ PIECE.cxx ############################################

Piece::Piece()
{
    // ne fait rien => objet instancie mais non valide.
    // cout << "Constructeur Piece par defaut" << endl;
}

Piece::Piece( int x, int y, bool white )
{
    m_x     = x;
    m_y     = y;
    m_white = white;
    
    
    if(m_white == false)
    {
        this->img.loadFromFile(PION_NOIR);
    }
    else
    {
        this->img.loadFromFile(PION_BLANC); 
    }
    // cout << "Constructeur Piece special" << endl;
}

Piece::Piece( const Piece &autre )
{
    m_x     = autre.m_x;
    m_y     = autre.m_y;
    m_white = autre.m_white;

    if(m_white == false)
    {
        this->img.loadFromFile(PION_NOIR);
    }
    else
    {
        this->img.loadFromFile(PION_BLANC); 
    }
    // cout << "Constructeur Piece par copie" << endl;
}

Piece::~Piece()
{
    // // cout << "Destructeur Piece" << endl;
}

Piece &
Piece::operator=( const Piece &autre )
{
    m_x     = autre.m_x;
    m_y     = autre.m_y;
    m_white = autre.m_white;
    cout << "Affectation Piece" << endl;
    return *this;
}

void
Piece::init( int x, int y, bool white )
{
    m_x     = x;
    m_y     = y;
    m_white = white;
    if(m_white == false)
    {
        this->img.loadFromFile(PION_NOIR);
    }
    else
    {
        this->img.loadFromFile(PION_BLANC); 
    }
}

void
Piece::move( int x, int y )
{
    m_x = x;
    m_y = y;
}

int
Piece::x()
{
    return m_x;
}

int
Piece::y()
{
    return m_y;
}
Texture
Piece::getImage()
{
    return this->img;
}
bool
Piece::isWhite()
{
    return m_white;
}

bool
Piece::isBlack()
{
    return !m_white;
}

void
Piece::affiche()
{
    cout << "Piece: x=" << m_x << " y=" << m_y << " " << ( m_white ? "blanche" : "noire" ) << endl;
}

char
Piece::vue()
{
    return this->isWhite() ? 'B' : 'N';
}

/*
bool
Piece::mouvementValide( Echiquier &e, int x, int y )
{
    cout << "Mouvement Valide Piece" << endl;
    return true;  // cette methode deviendra abstraite
}
*/

Roi::Roi( bool white ) : Piece( 5, white ? 8 : 1, white )
{
    // cout << "Constructeur Roi" << endl;
    if(m_white == false)
    {
        this->img.loadFromFile(ROI_NOIR);
    }
    else
    {
        this->img.loadFromFile(ROI_BLANC); 
    }
}

Roi::~Roi()
{
    // cout << "Destructeur Roi" << endl;
}

bool
Roi::mouvementValide( Echiquier &e, int x, int y )
{
    cout << "Mouvement Valide Roi" << endl;
    return true;
}

char
Roi::vue()
{
    return m_white ? 'R' : 'r';
}
Texture
Roi::getImage()
{
    return this->img;
}

void
Roi::roque()
{
    cout << "Roque Roi" << endl;
}

Reine::Reine( bool white )
    : Piece( 4, white ? 8 : 1, white ), Fou( white, true ), Tour( white, true )
{
    if(m_white == false)
    {
        this->img.loadFromFile(REINE_NOIR);
    }
    else
    {
        this->img.loadFromFile(REINE_BLANC); 
    }
    // cout << "Constructeur Reine" << endl;
}

Reine::~Reine()
{
    // cout << "Destructeur Reine" << endl;
}

bool
Reine::mouvementValide( Echiquier &e, int x, int y )
{
    return Fou::mouvementValide( e, x, y ) || Tour::mouvementValide( e, x, y );
}

char
Reine::vue()
{
    return Fou::m_white ? 'Q' : 'q';
}

Texture
Reine::getImage()
{
    return this->img;
}

Tour::Tour( bool white, bool gauche ) : Piece( gauche ? 1 : 8, white ? 8 : 1, white )
{
    if(m_white == false)
    {
        this->img.loadFromFile(TOUR_NOIR);
    }
    else
    {
        this->img.loadFromFile(TOUR_NOIR); 
    }
    // cout << "Constructeur Tour" << endl;
}

Tour::~Tour()
{
    // cout << "Destructeur Tour" << endl;
}

bool
Tour::mouvementValide( Echiquier &e, int x, int y )
{
    cout << "Mouvement Valide Tour" << endl;
    return false;
}

char
Tour::vue()
{
    return m_white ? 'T' : 't';
}
Texture
Tour::getImage()
{
    return this->img;
}

Fou::Fou( bool white, bool gauche ) : Piece( gauche ? 3 : 6, white ? 8 : 1, white )
{
    if(m_white == false)
    {
        this->img.loadFromFile(FOU_NOIR);
    }
    else
    {
        this->img.loadFromFile(FOU_BLANC); 
    }
    // cout << "Constructeur Fou" << endl;
}

Fou::~Fou()
{
    // cout << "Destructeur Fou" << endl;
}

bool
Fou::mouvementValide( Echiquier &e, int x, int y )
{
    cout << "Mouvement Valide Fou" << endl;
    return false;
}

char
Fou::vue()
{
    return m_white ? 'F' : 'f';
}

Texture
Fou::getImage()
{
    return this->img;
}

Cavalier::Cavalier( bool white, bool gauche ) : Piece( gauche ? 2 : 7, white ? 8 : 1, white )
{
    if(m_white == false)
    {
        this->img.loadFromFile(CHEVAL_NOIR);
    }
    else
    {
        this->img.loadFromFile(CHEVAL_BLANC); 
    }
    // cout << "Constructeur Cavalier" << endl;
}
Cavalier::~Cavalier()
{
    // cout << "Destructeur Cavalier" << endl;
}

bool
Cavalier::mouvementValide( Echiquier &e, int x, int y )
{
    cout << "Mouvement Valide Cavalier" << endl;
    return false;
}

char
Cavalier::vue()
{
    return m_white ? 'C' : 'c';
}

Texture
Cavalier::getImage()
{
    return this->img;
}

Pion::Pion( bool white, int x ) : Piece( x, white ? 7 : 2, white )
{
    if(m_white == false)
    {
        this->img.loadFromFile(PION_NOIR);
    }
    else
    {
        this->img.loadFromFile(PION_BLANC); 
    }
    // cout << "Constructeur Pion" << endl;
}

Pion::~Pion()
{
    // cout << "Destructeur Pion" << endl;
}

bool
Pion::mouvementValide( Echiquier &e, int x, int y )
{
    cout << "Mouvement Valide Pion" << endl;
    return false;
}

char
Pion::vue()
{
    return m_white ? 'P' : 'p';
}
Texture
Pion::getImage()
{
    return this->img;
}
//##############################"""""HEADER Echiquier"#######################################

/**
 * Declaration d'une classe modelisant une piece de jeu d'echec.
 */
class Echiquier
{
   private:
    /**
     * Les cases de l'echiquier
     */
    Piece *m_cases[LONGUEUR*LONGUEUR];

   public:
    /**
     * Constructeur par defaut.
     * Initialise a vide l'echiquier.
     */
    Echiquier();

    /**
     * Recupere la piece situee sur une case.
     *
     * @param x un entier entre 1 et 8
     * @param y un entier entre 1 et 8
     *
     * @return 0 si aucune piece n'est sur cette case et un pointeur
     * vers une piece sinon.
     */
    Piece *getPiece( int x, int y );

    /**
     * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
     *
     * @param p un pointeur vers une piece
     *
     * @return 'true' si le placement s'est bien passe, 'false' sinon
     * (case occupee, coordonnees invalides, piece vide )
     */
    bool placer( Piece *p );

    /**
     * Deplace une piece sur l'echiquier, des coordonnees specifiees
     * dans la piece aux coordonnees x,y.
     *
     * @param p un pointeur vers une piece
     * @param x un entier entre 1 et 8
     * @param y un entier entre 1 et 8
     *
     * @return 'true' si le placement s'est bien passe, 'false' sinon
     * (case occupee, coordonnees invalides, piece vide, piece pas
     * presente au bon endroit sur l'echiquier)
     */
    bool deplacer( Piece *p, int x, int y );

    /**
     * Enleve la piece situee sur une case (qui devient vide).
     *
     * @param x un entier entre 1 et 8
     * @param y un entier entre 1 et 8
     *
     * @return 0 si aucune piece n'est sur cette case et le pointeur
     * vers la piece enlevee sinon.
     */
    Piece *enleverPiece( int x, int y );

    /**
     * Affiche l'echiquier avec des # pour les cases noires et . pour
     * les blanches si elles sont vides, et avec B pour les pieces
     * blanches et N pour les pieces noires.
     */
    void affiche();
};

//################################################ ECHIQUIER.cxx ############################################


/**
 * Constructeur par defaut.
 * Initialise a vide l'echiquier.
 */
Echiquier::Echiquier()
{
    for ( int i = 0; i < 64; i++ )
        m_cases[i] = nullptr;
}

/**
 * Recupere la piece situee sur une case.
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 0 si aucune piece n'est sur cette case et un pointeur
 * vers une piece sinon.
 */
Piece *
Echiquier::getPiece( int x, int y )
{
    assert( x >= 1 && x <= 8 && y >= 1 && y <= 8 );
    return m_cases[( x - 1 ) + ( y - 1 ) * 8];
}

/**
 * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
 *
 * @param p un pointeur vers une piece
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide )
 */
bool
Echiquier::placer( Piece *p )
{
    if ( nullptr == p )
        return false;
    int x = p->x();
    int y = ( *p ).y();
    assert( x >= 1 && x <= 8 && y >= 1 && y <= 8 );
    assert( x >= 1 && x <= 8 && y >= 1 && y <= 8 );
    if ( nullptr != getPiece( x, y ) )
        return false;  // case non vide
    m_cases[( x - 1 ) + ( y - 1 ) * 8] = p;
    return true;
}

/**
 * Deplace une piece sur l'echiquier, des coordonnees specifiees
 * dans la piece aux coordonnees x,y.
 *
 * @param p un pointeur vers une piece
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide, piece pas
 * presente au bon endroit sur l'echiquier)
 */
bool
Echiquier::deplacer( Piece *p, int x, int y )
{
    return false;
}

/**
 * Enleve la piece situee sur une case (qui devient vide).
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 0 si aucune piece n'est sur cette case et le pointeur
 * vers la piece enlevee sinon.
 */
Piece *
Echiquier::enleverPiece( int x, int y )
{
    assert( x >= 1 && x <= 8 && y >= 1 && y <= 8 );
    Piece *ptr                         = m_cases[( x - 1 ) + ( y - 1 ) * 8];
    m_cases[( x - 1 ) + ( y - 1 ) * 8] = nullptr;
    return ptr;
}

/**
 * Affiche l'echiquier avec des # pour les cases noires et . pour
 * les blanches si elles sont vides, et avec B pour les pieces
 * blanches et N pour les pieces noires.
 */
void
Echiquier::affiche()
{
    // cout << endl << "  12345678" << endl;
    // for ( int y = 1; y <= 8; ++y ) {
    //     cout << y << " ";
    //     for ( int x = 1; x <= 8; ++x ) {
    //         char   c;
    //         Piece *p = getPiece( x, y );
    //         if ( nullptr == p )
    //             c = ( ( x + y ) % 2 ) == 0 ? '#' : '.';
    //         else
    //             c = p->vue();  // p->isWhite() ? 'B' : 'N';
    //         cout << c;
    //     }
    //     cout << " " << y << endl;
    // }
    // cout << "  12345678" << endl;
    // importation des images

    t1.loadFromFile(TABLEAU);
    t2.loadFromFile(PION_NOIR);
    t3.loadFromFile(PION_BLANC);
    t4.loadFromFile(TOUR_NOIR);
    t5.loadFromFile(TOUR_NOIR);
    t6.loadFromFile(CHEVAL_BLANC);
    t7.loadFromFile(CHEVAL_NOIR);
    t8.loadFromFile(FOU_NOIR);
    t9.loadFromFile(FOU_BLANC);
    t10.loadFromFile(REINE_BLANC);
    t11.loadFromFile(REINE_NOIR);
    t12.loadFromFile(ROI_NOIR);
    t13.loadFromFile(ROI_BLANC);
    t14.loadFromFile(TRANFORMATION_BLANC);
    t15.loadFromFile(TRANFORMATION_NOIR);

	// Afficher les images
	Sprite imgTableau(t1);
	Sprite imgPionNoir(t2);
    Sprite imgPionBlanc(t3);
	Sprite imgTourNoir(t4);
	Sprite imgTourBlanc(t5);
	Sprite imgChevalBlanc(t6);
	Sprite imgChevalNoir(t7);
	Sprite imgFouNoir(t8);
	Sprite imgFouBlanc(t9);
	Sprite imgReineBlanc(t10);
	Sprite imgReineNoir(t11);
	Sprite imgRoiNoir(t12);
	Sprite imgRoiBlanc(t13);
	Sprite BlancTransformation(t14);
	Sprite NoirTransformation(t15);

    // Importation d'image
    tab_jeux.loadFromFile(TABLEAU);
    tranformation_blanc.loadFromFile(TRANFORMATION_BLANC);
    tranformation_noir.loadFromFile(TRANFORMATION_NOIR);

    // Afficher les images
	// Sprite imgTableau(tab_jeux);
	Sprite Deplacement;
	// Sprite BlancTransformation(tranformation_blanc);
	// Sprite NoirTransformation(tranformation_noir);

	float dx = 0, dy = 0;
	int pasMouvPiece = 0;

	while (window.isOpen())
	{
		Vector2i pos = Mouse::getPosition(window);
		x = pos.x / taille;
		y = pos.y / taille;
		Event e;

		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			window.clear();

			// if (e.type == Event::MouseButtonPressed)
			// {
			// 	if (e.key.code == Mouse::Left)
			// 	{
			// 		//std::cout << "x=" << x << " y=" << y << "\n";
			// 		//std::cout << "pos_x=" << pos.x << " pos_y=" << pos.y << "\n";
			// 		//std::cout << "tableDeJeu[y][x]=" << tableDeJeu[y][x] << "\n";
			// 		//std::cout << "\n";
			// 		if (transformationBlanc == 1)
			// 		{
			// 			if (pos.y >= transforme_blanc.y * taille && pos.y <= (transforme_blanc.y + 1) * taille && pos.x >= transforme_blanc.x * taille && pos.x <= (transforme_blanc.x + 1) * taille)
			// 			{
			// 				int posX = pos.x % 100, posY = pos.y % 100;
			// 				//std::cout << "pos.y=" << posY << "\n";
			// 				//std::cout << "pos.x=" << posX << "\n";
			// 				if (posX < 50 && posY < 50 && posX > 0 && posY > 0)
			// 				{
			// 					tableDeJeu[transforme_blanc.y][transforme_blanc.x] = TOUR_BLANC;
			// 					transformationBlanc = 0;
			// 				}
			// 				if (posX > 50 && posX < 100 && posY < 50 && posY > 0)
			// 				{
			// 					tableDeJeu[transforme_blanc.y][transforme_blanc.x] = REINE_BLANC;
			// 					transformationBlanc = 0;
			// 				}
			// 				if (posX > 50 && posX < 100 && posY>50 && posY < 100)
			// 				{
			// 					tableDeJeu[transforme_blanc.y][transforme_blanc.x] = CHEVAL_BLANC;
			// 					transformationBlanc = 0;
			// 				}
			// 				if (posX < 50 && posX>0 && posY > 50 && y < 100)
			// 				{
			// 					tableDeJeu[transforme_blanc.y][transforme_blanc.x] = FOU_BLANC;
			// 					transformationBlanc = 0;
			// 				}
			// 				if (transformationBlanc == 0)
			// 				{
			// 					posRoiNoir();
			// 					bool h = RoiNoirEchecTest(roi_noir.x, roi_noir.y);
			// 					if (h == 0)
			// 					{
			// 						EchecNoir = 1;
			// 					}
			// 				}
			// 			}
			// 		}
			// 		if (transformationNoir == 1)
			// 		{
			// 			if (pos.y >= transforme_noir.y * taille && pos.y <= (transforme_noir.y + 1) * taille && pos.x >= transforme_noir.x * taille && pos.x <= (transforme_noir.x + 1) * taille)
			// 			{
			// 				int posX = pos.x % 100, posY = pos.y % 100;
			// 				//std::cout << "pos.y=" << posY << "\n";
			// 				//std::cout << "pos.x=" << posX << "\n";
			// 				if (posX < 50 && posY < 50 && posX > 0 && posY > 0)
			// 				{
			// 					tableDeJeu[transforme_noir.y][transforme_noir.x] = TOUR_NOIR;
			// 					transformationNoir = 0;
			// 				}
			// 				if (posX > 50 && posX < 100 && posY < 50 && posY > 0)
			// 				{
			// 					tableDeJeu[transforme_noir.y][transforme_noir.x] = REINE_NOIR;
			// 					transformationNoir = 0;
			// 				}
			// 				if (posX > 50 && posX < 100 && posY>50 && posY < 100)
			// 				{
			// 					tableDeJeu[transforme_noir.y][transforme_noir.x] = CHEVAL_NOIR;
			// 					transformationNoir = 0;
			// 				}
			// 				if (posX < 50 && posX>0 && posY > 50 && y < 100)
			// 				{
			// 					tableDeJeu[transforme_noir.y][transforme_noir.x] = FOU_NOIR;
			// 					transformationNoir = 0;
			// 				}
			// 				if (transformationNoir == 0)
			// 				{
			// 					posRoiBlanc();
			// 					int h = RoiBlancEchecTest(roi_blanc.x, roi_blanc.y);
			// 					if (h == 0)
			// 					{
			// 						EchecBlanc = 1;
			// 					}
			// 				}
			// 			}
			// 		}
			// 		if (tableDeJeu[y][x] != 0)
			// 		{
			// 			dx = pos.x - x * 100;
			// 			dy = pos.y - y * 100;
			// 			if (tableDeJeu[y][x]  == PION_NOIR && mouvement ==1)
			// 			{
			// 				pasMouvPiece = PION_NOIR;
			// 				Deplacement = imgPionNoir;
			// 				tableDeJeu[y][x] = 0;
			// 			}
			// 			if (tableDeJeu[y][x] == PION_BLANC && mouvement ==0)
			// 			{
			// 				pasMouvPiece = PION_BLANC;
			// 				Deplacement = imgPionBlanc;
			// 				tableDeJeu[y][x] = 0;
			// 			}
			// 			if (tableDeJeu[y][x] == TOUR_NOIR && mouvement ==1)
			// 			{
			// 				pasMouvPiece = TOUR_NOIR;
			// 				Deplacement = imgTourNoir;
			// 				tableDeJeu[y][x] = 0;

			// 			}
			// 			if (tableDeJeu[y][x] == TOUR_BLANC && mouvement ==0)
			// 			{
			// 				pasMouvPiece = TOUR_BLANC;
			// 				Deplacement = imgTourNoir;
			// 				tableDeJeu[y][x] = 0;

			// 			}
			// 			if (tableDeJeu[y][x] == CHEVAL_BLANC && mouvement ==0)
			// 			{
			// 				pasMouvPiece = CHEVAL_BLANC;
			// 				Deplacement = imgChevalBlanc;
			// 				tableDeJeu[y][x] = 0;
			// 			}
			// 			if (tableDeJeu[y][x] == CHEVAL_NOIR && mouvement ==1)
			// 			{
			// 				pasMouvPiece = CHEVAL_NOIR;
			// 				Deplacement = imgChevalNoir;
			// 				tableDeJeu[y][x] = 0;
			// 			}
			// 			if (tableDeJeu[y][x] == FOU_NOIR && mouvement ==1)
			// 			{
			// 				pasMouvPiece = FOU_NOIR;
			// 				Deplacement = imgFouNoir;
			// 				tableDeJeu[y][x] = 0;
			// 			}
			// 			if (tableDeJeu[y][x] == FOU_BLANC && mouvement ==0)
			// 			{
			// 				pasMouvPiece = FOU_BLANC;
			// 				Deplacement = imgFouBlanc;
			// 				tableDeJeu[y][x] = 0;
			// 			}
			// 			if (tableDeJeu[y][x] == REINE_BLANC && mouvement ==0)
			// 			{
			// 				pasMouvPiece = REINE_BLANC;
			// 				Deplacement = imgReineBlanc;
			// 				tableDeJeu[y][x] = 0;
			// 			}
			// 			if (tableDeJeu[y][x] == REINE_NOIR && mouvement ==1)
			// 			{
			// 				pasMouvPiece = REINE_NOIR;
			// 				Deplacement = imgReineNoir;
			// 				tableDeJeu[y][x] = 0;
			// 			}
			// 			if (tableDeJeu[y][x] == ROI_NOIR && mouvement ==1)
			// 			{
			// 				pasMouvPiece = ROI_NOIR;
			// 				Deplacement = imgRoiNoir;
			// 				tableDeJeu[y][x] = 0;
			// 			}
			// 			if (tableDeJeu[y][x] == ROI_BLANC && mouvement ==0)
			// 			{
			// 				pasMouvPiece = ROI_BLANC;
			// 				Deplacement = imgRoiBlanc;
			// 				tableDeJeu[y][x] = 0;
			// 			}
			// 			if (tableDeJeu[y][x] == 0)
			// 			{
			// 				ca_bouge = 1;
			// 				ancienne_Pos.x = x;
			// 				ancienne_Pos.y = y;
			// 			}
			// 		}
			// 	}
			// }
			
			// if (e.type == Event::MouseButtonReleased)
			// {
			// 	if (e.key.code == Mouse::Left)
			// 	{
			// 		int ok=2;
			// 		if (pasMouvPiece == PION_BLANC && ca_bouge==1)
			// 		{
			// 			 ok = PionBlanc(ancienne_Pos.x, ancienne_Pos.y, x, y);
			// 		}
			// 		if (pasMouvPiece  == PION_NOIR && ca_bouge == 1)
			// 		{
			// 			ok = PionNoir(ancienne_Pos.x, ancienne_Pos.y, x, y);
			// 		}
			// 		if (pasMouvPiece == TOUR_BLANC && ca_bouge == 1)
			// 		{
			// 			ok = TourBlanc(ancienne_Pos.x, ancienne_Pos.y, x, y);
			// 			if (ok == 1 && mouvGaucheTourBlanc==0 && ancienne_Pos.y == 7 && ancienne_Pos.x == 0)
			// 			{
			// 				mouvGaucheTourBlanc = 1;
			// 				//std::cout << mouvGaucheTourBlanc << "\n";
			// 			}
			// 			if (ok == 1 && mouvDroitTourBlanc==0 && ancienne_Pos.y == 7 && ancienne_Pos.x == 7)
			// 			{
			// 				mouvDroitTourBlanc = 1;
			// 				//std::cout << mouvDroitTourBlanc << "\n";
			// 			}
			// 		}
			// 		if (pasMouvPiece == TOUR_NOIR && ca_bouge == 1)
			// 		{
			// 			ok=TourNoir(ancienne_Pos.x, ancienne_Pos.y, x, y);
			// 			if (ok == 1 && mouvDroitTourNoir == 0 && ancienne_Pos.y == 0 && ancienne_Pos.x == 7)
			// 			{
			// 				mouvDroitTourNoir = 1;
			// 				//std::cout << mouvDroitTourNoir<< "\n";
			// 			}
			// 			if (ok == 1 && mouvGaucheTourNoir == 0 && ancienne_Pos.y == 0 && ancienne_Pos.x == 0)
			// 			{
			// 				mouvGaucheTourNoir = 1;
			// 				//std::cout << mouvGaucheTourNoir << "\n";
			// 			}
			// 		}
			// 		if (pasMouvPiece == FOU_BLANC && ca_bouge == 1)
			// 		{
			// 			ok = FouBlanc(ancienne_Pos.x, ancienne_Pos.y, x, y);
			// 		}
			// 		if (pasMouvPiece == FOU_NOIR && ca_bouge == 1)
			// 		{
			// 			ok= FouNoir(ancienne_Pos.x, ancienne_Pos.y, x, y);
			// 		}
			// 		if (pasMouvPiece == REINE_BLANC && ca_bouge == 1)
			// 		{
			// 			ok=ReineBlanc(ancienne_Pos.x, ancienne_Pos.y, x, y);
			// 		}
			// 		if (pasMouvPiece == REINE_NOIR && ca_bouge == 1)
			// 		{
			// 			ok=ReineNoir(ancienne_Pos.x, ancienne_Pos.y, x, y);
			// 		}
			// 		if (pasMouvPiece == CHEVAL_BLANC && ca_bouge == 1)
			// 		{
			// 			ok=ChevalBlanc(ancienne_Pos.x, ancienne_Pos.y, x, y);
			// 		}
			// 		if (pasMouvPiece == CHEVAL_NOIR && ca_bouge == 1)
			// 		{
			// 			ok = ChevalNoir(ancienne_Pos.x, ancienne_Pos.y, x, y);
			// 		}
			// 		if (pasMouvPiece == ROI_NOIR && ca_bouge == 1)
			// 		{
			// 			ok=RoiNoir(ancienne_Pos.x, ancienne_Pos.y, x, y);
			// 			if (ok == 1 && RoiNoirPremierMouv == 0)
			// 			{
			// 				RoiNoirPremierMouv = 1;
			// 			//	std::cout << imgRoiNoir << "\n";
			// 			}
			// 		}
			// 		if (pasMouvPiece == ROI_BLANC && ca_bouge == 1)
			// 		{
			// 			ok=RoiBlanc(ancienne_Pos.x, ancienne_Pos.y, x, y);
			// 			if (ok == 1 && RoiBlancPremierMouv == 0)
			// 			{
			// 				RoiBlancPremierMouv = 1;
			// 				//std::cout << "primaDeplacementimgRoiBlanc=" << imgRoiBlanc << "\n";
			// 			}
			// 		}
			// 		if (ok == 1)
			// 		{
			// 			int nr = tableDeJeu[y][x];
			// 			tableDeJeu[y][x] = pasMouvPiece;
			// 			if (y == 0 && pasMouvPiece == PION_BLANC)
			// 			{
			// 				transformationBlanc = 1;
			// 				transforme_blanc.x = x;
			// 				transforme_blanc.y = y;
			// 				tableDeJeu[y][x] = 0;
			// 			}
			// 			if (y == 7 && pasMouvPiece  == PION_NOIR)
			// 			{
			// 				transformationNoir = 1;
			// 				transforme_noir.x = x;
			// 				transforme_noir.y = y;
			// 				tableDeJeu[y][x] = 0;
			// 			}                        
			// 			if(mouvement == 0) // blanc a bougé et noir suit
			// 			{
			// 				if (EchecBlanc == 1)
			// 				{
			// 					posRoiBlanc();
			// 					int s = RoiBlancEchecTest(roi_blanc.x, roi_blanc.y);
			// 					if (s == 0)
			// 					{
			// 						tableDeJeu[ancienne_Pos.y][ancienne_Pos.x] = pasMouvPiece;
			// 						tableDeJeu[y][x] = nr;
			// 					}
			// 					else
			// 					{
			// 						EchecBlanc = 0;
			// 						posRoiNoir();
			// 						int Echec = RoiNoirEchecTest(roi_noir.x,roi_noir.y);
			// 						if (Echec == 0)
			// 						{
			// 							EchecNoir = 1;
			// 						}
			// 						mouvement = 1;
			// 					}
			// 				}
			// 				else
			// 				{
			// 					posRoiBlanc();
			// 					int sa = RoiBlancEchecTest(roi_blanc.x, roi_blanc.y);
			// 					if (sa == 0)
			// 					{
			// 						tableDeJeu[ancienne_Pos.y][ancienne_Pos.x] = pasMouvPiece;
			// 						tableDeJeu[y][x] = nr;
			// 					}
			// 					else
			// 					{
			// 						posRoiNoir();
			// 						int Echec = RoiNoirEchecTest(roi_noir.x, roi_noir.y);
			// 						if (Echec == 0)
			// 						{
			// 							EchecNoir = 1;
			// 						}
			// 						mouvement = 1;
			// 					}
			// 				}
			// 			}
			// 			else // noir a bougé et blanc a suivi
			// 			{
			// 				if (EchecNoir == 1)
			// 				{
			// 					posRoiNoir();
			// 					int s = RoiNoirEchecTest(roi_noir.x,roi_noir.y);
			// 					if (s == 0)
			// 					{
			// 						tableDeJeu[ancienne_Pos.y][ancienne_Pos.x] = pasMouvPiece;
			// 						tableDeJeu[y][x] = nr;
			// 					}
			// 					else
			// 					{
			// 						EchecNoir = 0;
			// 						posRoiBlanc();
			// 						int Echec = RoiBlancEchecTest(roi_blanc.x,roi_blanc.y);
			// 						if (Echec == 0)
			// 						{
			// 							EchecBlanc = 1;
			// 						}
			// 						mouvement = 0;
			// 					}
			// 				}
			// 				else
			// 				{
			// 					posRoiNoir();
			// 					int sa = RoiNoirEchecTest(roi_noir.x, roi_noir.y);
			// 					if (sa == 0)
			// 					{
			// 						tableDeJeu[ancienne_Pos.y][ancienne_Pos.x] = pasMouvPiece;
			// 						tableDeJeu[y][x] = nr;
			// 					}
			// 					else
			// 					{
			// 						posRoiBlanc();
			// 						int Echec = RoiBlancEchecTest(roi_blanc.x, roi_blanc.y);
			// 						if (Echec == 0)
			// 						{
			// 							EchecBlanc = 1;
			// 						}
			// 						mouvement = 0;
			// 					}
			// 				}
			// 			}             
                    
                    
            //         }
			// 		else if(ok==0)
			// 		{
			// 			tableDeJeu[ancienne_Pos.y][ancienne_Pos.x] = pasMouvPiece;
			// 		}
            //        ca_bouge = 0;
			// 	}
			// }
		
		}
        // Afficher les images
        /*
        Sprite imgTableau(t1);
        Sprite imgPionNoir(t2);
        Sprite imgPionBlanc(t3);
        Sprite imgTourNoir(t4);
        Sprite imgTourBlanc(t5);
        Sprite imgChevalBlanc(t6);
        Sprite imgChevalNoir(t7);
        Sprite imgFouNoir(t8);
        Sprite imgFouBlanc(t9);
        Sprite imgReineBlanc(t10);
        Sprite imgReineNoir(t11);
        Sprite imgRoiNoir(t12);
        Sprite imgRoiBlanc(t13);
        Sprite Deplacement;
        Sprite BlancTransformation(t14);
        Sprite NoirTransformation(t15);
        
        */

		// Affichage
		window.clear();
		window.draw(imgTableau);
		        
		// Cas particulier de Dame

		if (transformationBlanc == 1)
		{
			BlancTransformation.setPosition(transforme_blanc.x* taille, transforme_blanc.y* taille);
			window.draw(BlancTransformation);
		}
		if (transformationNoir == 1)
		{
			NoirTransformation.setPosition(transforme_noir.x* taille, transforme_noir.y* taille);
			window.draw(NoirTransformation);
		}
		if (ca_bouge == 1)
		{
			Deplacement.setPosition(pos.x-dx, pos.y-dy);
			window.draw(Deplacement);
		}

		// Cas normal
		// On dessine la table de jeu  
        //hear_we_go      
        
        int cpt = 0;
        for (int i = 0; i < LONGUEUR; i++)
        {
            for (int j = 0; j < LONGUEUR; j++)
            {
                // On place les piions noirs en premiers
                // On récupère le pion dans ImagePiece
                
                Pion* pn    = new Pion(false, i+1);
                Tour* tng    = new Tour(false, true);
                Pion* pb    = new Pion(true, i+1);
                // //Pion(false, i+1);
                // m_cases[ 9 ] = nullptr;
                // m_cases[ 9 ] = pn;

                //Piece* p = m_cases[ (j - 1) + (i - 1) * 8 ];

                //if (m_cases[ (j - 1) + (i - 1) * 8 ]->getImage().loadFromFile(PION_NOIR))
                if(pn->getImage().loadFromFile(TOUR_NOIR))
                {
                    imgTourNoir.setPosition(j * taille, 0 * taille);
                    window.draw(imgTourNoir);
                }
                if(pn->getImage().loadFromFile(PION_NOIR))
                {
                    imgPionNoir.setPosition(j * taille, 1 * taille);
                    window.draw(imgPionNoir);
                }
                // if (m_cases[ 49 ]->getImage().loadFromFile(PION_BLANC))
                // {
                //     imgPionBlanc.setPosition(j * taille, 6 * taille);
                //     window.draw(imgPionBlanc);
                // }
                // if ((j == 0 && i == 1) || (j == 0 && i == 6))
                // {
                //     imgChevalNoir.setPosition(i * taille, j * taille);
                //     window.draw(imgChevalNoir);
                // }
                /*
                if ((j == 0 && i == 2) || (j == 0 && i == 5))
                {
                    imgFouNoir.setPosition(i * taille, j * taille);
                    window.draw(imgFouNoir);
                }
                if (j == 0 && i == 3)
                {
                    imgReineNoir.setPosition(i * taille, j * taille);
                    window.draw(imgReineNoir);
                }
                if (j == 0 && i == 4)
                {
                    imgRoiNoir.setPosition(i * taille, j * taille);
                    window.draw(imgRoiNoir);
                }
                if ((j == 1 && i < 8))
                {
                    imgPionNoir.setPosition(i * taille, j * taille);
                    window.draw(imgPionNoir);
                }
                */   
                // En suite on place les pions blancs          
            }
        }

        window.display();
	}    
}


//################################################ JOUEUR.cxx ############################################


Joueur::Joueur()
{
    // cout << "Constructeur Joueur par defaut" << endl;
}

Joueur::~Joueur()
{
    for ( int i = 0; i < 16; i++ )
        delete m_pieces[i];
    //cout << "Destructeur Joueur" << endl;
}

/*
Joueur::Joueur( bool white )
{
    int p   = 0;
    int y   = ( white ? 1 : 8 );
    for ( int x = 1; x <= 8; x++ ) {
        m_pieces[p].init( x, y, white );
        p++;
    }
    y = ( white ? 2 : 7 );
    for ( int x = 1; x <= 8; x++ )
        m_pieces[p++].init( x, y, white );
    assert( p == 16 );
    // cout << "Constructeur Joueur" << endl;
}
*/

void
Joueur::affiche()
{
    for ( int i = 0; i < 16; i++ )
        m_pieces[i]->affiche();    
}

bool
Joueur::placerPieces( Echiquier &e )
{
    for ( int i = 0; i < 16; i++ )
        if ( !e.placer( m_pieces[i] ) )
            return false; 
    return true;
}

/*
bool
Joueur::placerPieces( Echiquier * e )
{
    for ( int i = 0; i < 16; i++ )
        if ( !e->placer( &( m_pieces[i] ) ) )
            return false;
    return true;
}
*/

JoueurNoir::JoueurNoir()
{
    int p         = 0;
    Tour *tg      = new Tour( false, true );
    m_pieces[p++] = tg;
    //cout << ((tg->x() - 1 ) + (tg->y() - 1) *8) << endl;
    Cavalier *cg  = new Cavalier( false, true );
    m_pieces[p++] = cg;
    //cout << ((cg->x() - 1 ) + (cg->y() - 1) *8) << endl;
    Fou *fg       = new Fou( false, true );
    m_pieces[p++] = fg;
    //cout << ((fg->x() - 1 ) + (fg->y() - 1) *8) << endl;
    Reine *q      = new Reine( false );
    m_pieces[p++] = q;
    //cout << ((cg->x() - 1 ) + (cg->y() - 1) *8) << endl;
    Roi *r        = new Roi( false );
    m_pieces[p++] = r;
    //cout << ((r->x() - 1 ) + (r->y() - 1) *8) << endl; 
    Fou *fd       = new Fou( false, false );
    m_pieces[p++] = fd; 
    //cout << ((fd->x() - 1 ) + (fd->y() - 1) *8) << endl;   
    Cavalier *cd  = new Cavalier( false, false );
    m_pieces[p++] = cd;
    //cout << ((cd->x() - 1 ) + (cd->y() - 1) *8) << endl; 
    Tour *td      = new Tour( false, false );
    m_pieces[p++] = td;
    //cout << ((td->x() - 1 ) + (td->y() - 1) *8) << endl; 
    for ( int i = 1; i <= 8; i++ ) {
        Pion *ptr     = new Pion( false, i );
        m_pieces[p++] = ptr;
        // cout << "|" << ((ptr->x() - 1 ) + (ptr->y() - 1) *8)  << "|"<< endl; 
    }
    assert( 16 == p );
    // cout << "Constructeur JoueurNoir" << endl;
}

JoueurBlanc::JoueurBlanc()
{

    int  p        = 0;
    Tour *tg      = new Tour( true, true );
    m_pieces[p++] = tg;
    Cavalier *cg  = new Cavalier( true, true );
    m_pieces[p++] = cg;
    Fou *fg       = new Fou( true, true );
    m_pieces[p++] = fg;
    Reine *q      = new Reine( true );
    m_pieces[p++] = q;
    Roi *r        = new Roi( true );
    m_pieces[p++] = r;
    
    Fou *fd       = new Fou( true, false );
    m_pieces[p++] = fd;
    Cavalier *cd  = new Cavalier( true, false );
    m_pieces[p++] = cd;
    Tour *td      = new Tour( true, false );
    m_pieces[p++] = td;
    for ( int i = 1; i <= 8; i++ ) {
        Pion *ptr     = new Pion( true, i );
        m_pieces[p++] = ptr;
    }
    assert( 16 == p );
    // cout << "Constructeur JoueurBlanc" << endl;
}    

/* methode virtual pure
bool Joueur::isWhite()
{
    return m_pieces[0].isWhite();
}
*/
bool
JoueurNoir::isWhite()
{
    return false;
}
bool
JoueurBlanc::isWhite()
{
    return true;
}



//################################################ PROG ############################################

int main(int argc, char const *argv[])
{

	Echiquier e; // on créer la table de jeu
    //e.affiche(); // on test par un affichage

    JoueurNoir JoueurNr; // on créer un joueur noir (avec pions noires)
    JoueurNr.placerPieces(e);
    //JoueurBlanc JoueurBl;
    
    //assert( JoueurNr.placerPieces( e ) ); // On place toutes les pions noirs sur la table
    //e.affiche();
    // assert( JoueurBl.placerPieces( e ) ); // On place toutes les pions noirs sur la table
    e.affiche();
    // JoueurNr.placerPieces( e );
    // if(JoueurNr.placerPieces( e ))
    //     cout << "ok noir" << endl;
    // JoueurBl.placerPieces( e );
    //cout << JoueurBl.placerPieces( e ) << endl;
    // for (int i = 0; i < 8; i++)
    // {
    //     for (int j = 0; j < 8; j++)
    //     {
    //         int index = (j - 1) + (i - 1) * 8;
    //         cout << index << endl;
    //     }
    // }    
    
    //Run();

	return EXIT_SUCCESS;
}