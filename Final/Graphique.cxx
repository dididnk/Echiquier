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
    // cout << "Constructeur Piece special" << endl;
}

Piece::Piece( const Piece &autre )
{
    m_x     = autre.m_x;
    m_y     = autre.m_y;
    m_white = autre.m_white;
    // cout << "Constructeur Piece par copie" << endl;
}

Piece::~Piece()
{
    // // cout << "Destructeur Piece" << endl;
}

Piece &
Piece::operator=(const Piece &autre )
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
String
Piece::getSrc()
{
    return this->src;
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
        this->src = ROI_NOIR;
    }
    else
    {
        this->src = ROI_BLANC; 
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
String
Roi::getSrc()
{
    return this->src;
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
        this->src  = REINE_NOIR;
    }
    else
    {
        this->src  = REINE_BLANC; 
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

String
Reine::getSrc()
{
    return this->src;
}

Tour::Tour( bool white, bool gauche ) : Piece( gauche ? 1 : 8, white ? 8 : 1, white )
{
    if(m_white == false)
    {
        this->src  = TOUR_NOIR;
    }
    else
    {
        this->src  = TOUR_BLANC; 
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
String
Tour::getSrc()
{
    return this->src;
}

Fou::Fou( bool white, bool gauche ) : Piece( gauche ? 3 : 6, white ? 8 : 1, white )
{
    if(m_white == false)
    {
        this->src  = FOU_NOIR;
    }
    else
    {
        this->src  = FOU_BLANC; 
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

String
Fou::getSrc()
{
    return this->src;
}

Cavalier::Cavalier( bool white, bool gauche ) : Piece( gauche ? 2 : 7, white ? 8 : 1, white )
{
    if(m_white == false)
    {
        this->src  = CHEVAL_NOIR;
    }
    else
    {
        this->src  = CHEVAL_BLANC; 
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

String
Cavalier::getSrc()
{
    return this->src;
}

Pion::Pion( bool white, int x ) : Piece( x, white ? 7 : 2, white )
{
    if(m_white == false)
    {
        this->src  = PION_NOIR;
    }
    else
    {
        this->src  = PION_BLANC; 
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
String
Pion::getSrc()
{
    return this->src;
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
    // importation des images
    t1.loadFromFile(TABLEAU);
    t2.loadFromFile(PION_NOIR);
    t3.loadFromFile(PION_BLANC);
    t4.loadFromFile(TOUR_NOIR);
    t5.loadFromFile(TOUR_BLANC);
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

	// Affectation des images
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
	Sprite Deplacement;

	float dx = 0, dy = 0;
	Piece* pasMouvPiece;

	while (window.isOpen())
	{
		Vector2i pos = Mouse::getPosition(window);
		x = pos.x / taille;
		y = pos.y / taille;  

        // Variables temporaires pour la lisibilité du code
        int index   = (x - 1) + (y - 1) * 8;
        Piece* p    = m_cases[ index ];
		Event e;

		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			window.clear();
        }
		// Affichage
		window.clear();
		window.draw(imgTableau);

        // while (window.pollEvent(e))
        // {
        //     /* code */
        // }
        
		// Cas normal
		// On dessine la table de jeu   
        for (int i = 1; i <= LONGUEUR; i++)
        {
            for (int j = 1; j <= LONGUEUR; j++)
            {
                // Variables temporaires pour la lisibilité du code
                int index   = (i - 1) + (j - 1) * 8;
                Piece* p    = m_cases[ index ];

                if (p != nullptr)
                {                    
                    int x       = p->x()-1;
                    int y       = p->y()-1;

                    // Pions noir
                    if (p->isBlack())
                    { 
                        if (p->getSrc() == TOUR_NOIR)
                        {
                            imgTourNoir.setPosition(x * taille, y * taille);
                            window.draw(imgTourNoir);  
                        }
                        if (p->getSrc() == CHEVAL_NOIR)
                        {
                            imgChevalNoir.setPosition(x * taille, y * taille);
                            window.draw(imgChevalNoir);  
                        }
                        if (p->getSrc() == FOU_NOIR)
                        {
                            imgFouNoir.setPosition(x * taille, 0 * taille);
                            window.draw(imgFouNoir);  
                        }
                        if (p->getSrc() == REINE_NOIR)
                        {
                            imgReineNoir.setPosition(x * taille, 0 * taille);
                            window.draw(imgReineNoir);  
                        }
                        if (p->getSrc() == ROI_NOIR)
                        {
                            imgRoiNoir.setPosition(x * taille, 0 * taille);
                            window.draw(imgRoiNoir); 
                        }                        
                        if (p->getSrc() == PION_NOIR)
                        {
                            imgPionNoir.setPosition(x * taille, y * taille);
                            window.draw(imgPionNoir); 
                        } 
                    }
                    // Pions blanc
                    if (p->isWhite())
                    { 
                        if (p->getSrc() == TOUR_BLANC)
                        {
                            imgTourBlanc.setPosition(x * taille, 7 * taille);
                            window.draw(imgTourBlanc);  
                        }
                        if (p->getSrc() == CHEVAL_BLANC)
                        {
                            imgChevalBlanc.setPosition(x * taille, y * taille);
                            window.draw(imgChevalBlanc);  
                        }
                        if (p->getSrc() == FOU_BLANC)
                        {
                            imgFouBlanc.setPosition(x * taille, y * taille);
                            window.draw(imgFouBlanc);  
                        }
                        if (p->getSrc() == REINE_BLANC)
                        {
                            imgReineBlanc.setPosition(x * taille, y * taille);
                            window.draw(imgReineBlanc);  
                        }
                        if (p->getSrc() == ROI_BLANC)
                        {
                            imgRoiBlanc.setPosition(x * taille, y * taille);
                            window.draw(imgRoiBlanc); 
                        }                        
                        if (p->getSrc() == PION_BLANC)
                        {
                            imgPionBlanc.setPosition(x * taille, y * taille);
                            window.draw(imgPionBlanc);  
                        } 
                    }
                
                }         
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

class test
{
    public:
        String src;
    public:
        test();
        ~test();
};

test::test()
{
    src = PION_BLANC;
}

test::~test()
{
}

int main(int argc, char const *argv[])
{
	Echiquier e; // on créer la table de jeu
    //e.affiche(); // on test par un affichage R=>Tableau vide

    JoueurNoir JoueurNr; // on créer un joueur noir (avec pions noirs)
    JoueurBlanc JoueurBl; // on créer un joueur blanc (avec pions blancs)
    
    assert( JoueurNr.placerPieces( e ) ); // On place tous les pions noirs sur la table
    assert( JoueurBl.placerPieces( e ) ); // On place tous les pions blancs sur la table
    
    e.affiche(); // on test par un affichage R=>Tableau avec tous les pions   
    
    //Run();

	return EXIT_SUCCESS;
}