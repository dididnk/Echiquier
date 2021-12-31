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
Piece::mouvementValide( Echiquier &e, int x, int y)
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
Roi::EchecTest( Echiquier &e)
{
    int ax  = (m_x - 1);
    int ay  = (m_y - 1);

	if(this->isWhite())
	{
		int isEchec= 0;
		for (int i = 0; i < LONGUEUR; i++)
		{
			for (int j = 0; j < LONGUEUR; j++)
			{
				if (e.getPiece(i, j)->isBlack())
				{
					if (e.getPiece(i, j)->getSrc() == PION_NOIR)
					{
						isEchec= PionNoirEchec(j, i, ax, ax);
					}
					if (e.getPiece(i, j)->getSrc() == TOUR_NOIR)
					{
						isEchec= TourNoirEchec(j, i, ax, ax);
					}
					if (e.getPiece(i, j)->getSrc() == CHEVAL_NOIR)
					{
						isEchec= ChevalNoirEchec(j, i, ax, ax);
					}
					if (e.getPiece(i, j)->getSrc() == FOU_NOIR)
					{
						isEchec= FouNoirEchec(j, i, ax, ax);
					}
					if (e.getPiece(i, j)->getSrc() == REINE_NOIR)
					{
						isEchec= ReineNoirEchec(j, i, ax, ax);
					}
					if (e.getPiece(i, j)->getSrc() == ROI_NOIR)
					{
						isEchec =RoiNoirEchec(j, i, ax, ax);
					}
					if (isEchec== 1)
					{
						//	std::cout << "da" << "\n";
						return 0;
					}
				}
			}
		}
	}

	if(this->isBlack())
    {
        int isEchec= 0;
        for (int i = 0; i < LONGUEUR; i++)
        {
            for (int j = 0; j < LONGUEUR; j++)
            {
                if(e.getPiece(i, j)->isWhite())
                {
                    if (e.getPiece(i, j)->getSrc() == PION_BLANC)
                    {
                        isEchec = PionBlancEchec(j, i, ax, ax);
                    }
                    if (e.getPiece(i, j)->getSrc() == TOUR_BLANC)
                    {
                        isEchec = TourBlancEchec(j, i, ax, ax);
                    }
                    if (e.getPiece(i, j)->getSrc() == CHEVAL_BLANC)
                    {
                        isEchec = ChevalBlancEchec(j, i, ax, ax);
                    }
                    if (e.getPiece(i, j)->getSrc() == FOU_BLANC)
                    {
                        isEchec = FouBlancEchec(j, i, ax, ax);
                    }
                    if (e.getPiece(i, j)->getSrc() == REINE_BLANC)
                    {
                        isEchec = ReineBlancEchec(j, i, ax, ax);
                    }
                    if (e.getPiece(i, j)->getSrc() == ROI_BLANC)
                    {
                        isEchec = RoiBlancEchec(j, i, ax, ax);
                    }
                    if (isEchec== 1)
                    {
                        return 0;
                    }
                }
            }
        }
    }
    return true;
}
bool
Roi::mouvementValide( Echiquier &e, int x, int y)
{
    int ax  = (m_x - 1);
    int ay  = (m_y - 1);

    if(this->isWhite())
	{
		if (ax - 1 >= 0 && ay - 1 >= 0 && y == ay - 1 && x == ax - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
		{
			int isEchec = EchecTest(ax - 1, ay - 1);
			if (isEchec == 1)
			{
				return 1;  // Haut gauche
			}
		}
		if (ay - 1 >= 0 && x == ax && y == ay - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
		{
			int isEchec = EchecTest(ax, ay - 1);
			if (isEchec == 1)
			{
				return 1; // Côté Haut
			}
		}
		if (ay - 1 >= 0 && ax + 1 < LONGUEUR && x == ax + 1 && y == ay - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
		{
			int isEchec = EchecTest(ax + 1, ay - 1);
			if (isEchec == 1)
			{
				return 1; // Haut droit
			}
		}
		if (ax + 1 < LONGUEUR && y == ay && x == ax + 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
		{
			int isEchec = EchecTest(ax + 1, ay);
			if (isEchec == 1)
			{
				return 1; // droit
			}
		}
		if (ax + 1 < LONGUEUR && ay + 1 < LONGUEUR && y == ay + 1 && x == ax + 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
		{
			int isEchec = EchecTest(ax + 1, ay + 1);
			if (isEchec == 1)
			{
				return 1; // droit bas
			}
		}
		if (ay + 1 < LONGUEUR && y == ay + 1 && x == ax && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
		{
			int isEchec = EchecTest(ax, ay + 1);
			if (isEchec == 1)
			{
				return 1; // bas
			}
		}
		if (ax - 1 >= 0 && ay + 1 < LONGUEUR && x == ax - 1 && y == ay + 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
		{
			int isEchec = EchecTest(ax - 1, ay + 1);
			if (isEchec == 1)
			{
				return 1; // gauche bas
			}
		}
		if (ax - 1 >= 0 && y == ay && x == ax - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
		{
			int isEchec = EchecTest(ax - 1, ay);
			if (isEchec == 1)
			{
				return 1; // gauche
			}
		}
		// Tourner à Droit
		if (RoiBlancPremierMouv == 0 && mouvDroitTourBlanc == 0 && m_cases[7][5] == 0 && m_cases[7][6] == 0 && y==7 && x==6)
		{
			int isEchec = 1;
			isEchec = EchecTest(4, 7);
			if (isEchec == 1)
			{
				isEchec = EchecTest(5, 7);
				if (isEchec == 1)
				{
					isEchec = EchecTest(6, 7);
					if (isEchec == 1)
					{
						m_cases[7][7] = 0;
						m_cases[7][5] = TOUR_BLANC;
						RoiBlancPremierMouv = 1;
						mouvDroitTourBlanc = 1;
						return 1;
					}
				}
			}
		}
		// Tourner à Gauche
		if (RoiBlancPremierMouv == 0 && mouvDroitTourBlanc == 0 && m_cases[7][3] == 0 && m_cases[7][2] == 0 && m_cases[7][1] == 0 && y == 7 && x == 2)
		{
			int isEchec = 1;
			isEchec = EchecTest(4, 7);
			if (isEchec == 1)
			{
				isEchec = EchecTest(3, 7);
				if (isEchec == 1)
				{
					isEchec = EchecTest(2, 7);
					if (isEchec == 1)
					{
						isEchec = EchecTest(1, 7);
						if (isEchec == 1)
						{
							m_cases[7][0] = 0;
							m_cases[7][3] = TOUR_BLANC;
							RoiBlancPremierMouv = 1;
							mouvGaucheTourBlanc = 1;
							return 1;
						}
					}
				}
			}
		}
	}

    if(this->isBlack())
	{
		if (ax - 1 >= 0 && ay - 1 >= 0 && y == ay - 1 && x == ax - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
		{
			int isEchec = EchecTest(ax - 1, ay - 1);
			if (isEchec == 1)
			{
				return 1;  // Haut gauche
			}
		}
		if (ay - 1 >= 0 && x == ax && y == ay-1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
		{
			int isEchec = EchecTest(ax, ay-1);
			if (isEchec == 1)
			{
				return 1; // Côté Haut
			}
		}
		if (ay - 1 >= 0 && ax + 1 < LONGUEUR && x == ax + 1 && y == ay - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
		{
			int isEchec = EchecTest(ax+ 1, ay- 1);
			if (isEchec == 1)
			{
				return 1; // Haut droit
			}
		}
		if (ax + 1 < LONGUEUR && y == ay && x == ax+1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
		{
			int isEchec = EchecTest(ax+1, ay);
			if (isEchec == 1)
			{
				return 1; // droit
			}
		}
		if (ax + 1 < LONGUEUR && ay + 1 < LONGUEUR && y == ay + 1 && x == ax + 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
		{
			int isEchec = EchecTest(ax + 1, ay + 1);
			if (isEchec == 1)
			{
				return 1; // droit bas
			}
		}
		if (ay + 1 < LONGUEUR && y == ay+1 && x == ax && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
		{
			int isEchec = EchecTest(ax, ay+1);
			if (isEchec == 1)
			{
				return 1; // bas
			}
		}
		if (ax - 1 >=0 && ay + 1 <LONGUEUR && x == ax - 1 && y == ay + 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
		{
			int isEchec = EchecTest(ax-1, ay+ 1);
			if (isEchec == 1)
			{
				return 1; // gauche bas
			}
		}
		if (ax - 1 >= 0 && y == ay && x == ax-1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
		{
			int isEchec = EchecTest(ax-1, ay);
			if (isEchec == 1)
			{
				return 1; // gauche
			}
		}
		// Tourner à Droit
		if (mouvDroitTourNoir==0 && RoiNoirPremierMouv ==0 && m_cases[0][5]==0 && m_cases[0][6]==0 && y==0 && x==6)
		{
			int isEchec = EchecTest(4, 0);
			if (isEchec == 1)
			{
				isEchec = EchecTest(5, 0);
				if (isEchec == 1)
				{
					isEchec = EchecTest(6, 0);
					if (isEchec == 1)
					{
						RoiNoirPremierMouv = 1;
						mouvDroitTourNoir = 1;
						m_cases[0][7] = 0;
						m_cases[0][5] = TOUR_NOIR;
						return 1;
					}
				}
			}
		}
		if (mouvGaucheTourNoir == 0 && RoiNoirPremierMouv == 0 && m_cases[0][3] == 0 && m_cases[0][2] == 0 && m_cases[0][1] == 0 && y == 0 && x == 2)
		{
			int isEchec = EchecTest(4, 0);
			if (isEchec == 1)
			{
				isEchec = EchecTest(3, 0);
				if (isEchec == 1)
				{
					isEchec = EchecTest(2, 0);
					if (isEchec == 1)
					{
						isEchec = EchecTest(1, 0);
						if (isEchec == 1)
						{
							RoiNoirPremierMouv = 1;
							mouvGaucheTourNoir = 1;
							m_cases[0][0] = 0;
							m_cases[0][3] = TOUR_NOIR;
							return 1;
						}
					}
				}
			}
		}
	}
    return false;
}
bool
Roi::mouvementEchec( Echiquier &e, int x, int y)
{
    int ax  = (m_x - 1);
    int ay  = (m_y - 1);

	if(this->isWhite())
	{
		if (ax - 1 >= 0 && ay - 1 >= 0 && y == ay - 1 && x == ax - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
		{
			return 1;
		}
		if (ay - 1 >= 0 && x == ax && y == ay - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
		{
			return 1;
		}
		if (ay - 1 >= 0 && ax + 1 < LONGUEUR && x == ax + 1 && y == ay - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
		{
			return 1;
		}
		if (ax + 1 < LONGUEUR && y == ay && x == ax + 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
		{
			return 1;
		}
		if (ax + 1 < LONGUEUR && ay + 1 < LONGUEUR && y == ay + 1 && x == ax + 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
		{
			return 1;
		}
		if (ay + 1 < LONGUEUR && y == ay + 1 && x == ax && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
		{
			return 1;
		}
		if (ax - 1 >= 0 && ay + 1 < LONGUEUR && x == ax - 1 && y == ay + 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
		{
			return 1;
		}
		if (ax - 1 >= 0 && y == ay && x == ax - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
		{
			return 1;
		}
	}
	if(this->isBlack())
	{
		if (ax - 1 >= 0 && ay - 1 >= 0 && y == ay - 1 && x == ax - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
		{
			return 1;
		}
		if (ay - 1 >= 0 && x == ax && y == ay - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
		{
			return 1;
		}
		if (ay - 1 >= 0 && ax + 1 < LONGUEUR && x == ax + 1 && y == ay - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
		{
			return 1;
		}
		if (ax + 1 < LONGUEUR && y == ay && x == ax + 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
		{
			return 1;
		}
		if (ax + 1 < LONGUEUR && ay + 1 < LONGUEUR && y == ay + 1 && x == ax + 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
		{
			return 1;
		}
		if (ay + 1 < LONGUEUR && y == ay + 1 && x == ax && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
		{
			return 1;
		}
		if (ax - 1 >= 0 && ay + 1 < LONGUEUR && x == ax - 1 && y == ay + 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
		{
			return 1;
		}
		if (ax - 1 >= 0 && y == ay && x == ax - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
		{
			return 1;
		}
	}

    return false;
}
void
Roi::getPosition( Echiquier &e)
{
    int ax  = (m_x - 1);
    int ay  = (m_y - 1);

    if(this->isWhite())
    {
        for (int i = 0; i < LONGUEUR; i++)
        {
            for (int j = 0; j < LONGUEUR; j++)
            {
                if ( e.getPiece(i, j)->getSrc() == ROI_BLANC)
                {
                    ax  = j;
                    ay  = i;
                    break;
                }
            }
        }
    }
    if(this->isBlack())
    {
        for (int i = 0; i < LONGUEUR; i++)
        {
            for (int j = 0; j < LONGUEUR; j++)
            {
                if ( e.getPiece(i, j)->getSrc() == ROI_NOIR)
                {
                    ax  = j;
                    ay  = i;
                    break;
                }
            }
        }
    }
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
Reine::mouvementValide( Echiquier &e, int x, int y)
{
    int ax  = (m_x - 1);
    int ay  = (m_y - 1);

    if(this->isWhite())
    {
        for (int i = ax - 1; i >= 0; i--) // Côté gauche
        {
            if (nullptr == e.getPiece(ay, i) || e.getPiece(ay, i)->isBlack() && (x == i && y == ay))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(ay, i))
            {
                break;
            }
        }
        for (int i = ay - 1; i >= 0; i--) // Côté Haut
        {
            if (nullptr == e.getPiece(i, ax) || e.getPiece(i, ax)->isBlack() && (y == i && x == ax))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, ax))
            {
                break;
            }
        }
        for (int i = ax + 1; i < LONGUEUR; i++) // À droite
        {
            if (nullptr == e.getPiece(ay, i) || e.getPiece(ay, i)->isBlack() && (y == ay && x == i))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(ay, i))
            {
                break;
            }
        }
        for (int i = ay + 1; i < LONGUEUR; i++) // bas
        {
            if (nullptr == e.getPiece(i, ax) || e.getPiece(i, ax)->isBlack() && (y == i && x == ax))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, ax))
            {
                break;
            }
        }
        int j = ax - 1;
        for (int i = ay - 1; i >= 0; i--) // Côté gauche haut
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isBlack() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j--;
        }
        j = ax + 1;
        for (int i = ay - 1; i >= 0; i--) // À droite haut
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isBlack() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j++;
        }
        j = ax - 1;
        for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isBlack() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j--;
        }
        j = ax + 1;
        for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isBlack() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j++;
        }
        return 0;
    }

    if(this->isBlack())
    {
        for (int i = ax - 1; i >= 0; i--) // Côté gauche
        {
            if (nullptr == e.getPiece(ay, i) || e.getPiece(ay, i)->isWhite() && (x == i && y == ay))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(ay, i))
            {
                break;
            }
        }
        for (int i = ay - 1; i >= 0; i--) // Côté Haut
        {
            if (nullptr == e.getPiece(i, ax) || e.getPiece(i, ax)->isWhite() && (y == i && x == ax))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, ax))
            {
                break;
            }
        }
        for (int i = ax + 1; i < LONGUEUR; i++) // À droite
        {
            if (nullptr == e.getPiece(ay, i) || e.getPiece(ay, i)->isWhite() && (y == ay && x == i))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(ay, i))
            {
                break;
            }
        }
        for (int i = ay + 1; i < LONGUEUR; i++) // bas
        {
            if (nullptr == e.getPiece(i, ax) || e.getPiece(i, ax)->isWhite() && (y == i && x == ax))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, ax))
            {
                break;
            }
        }
        int j = ax - 1;
        for (int i = ay - 1; i >= 0; i--) // Côté gauche haut
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isWhite() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j--;
        }
        j = ax + 1;
        for (int i = ay - 1; i >= 0; i--) // À droite haut
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isWhite() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j++;
        }
        j = ax - 1;
        for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isWhite() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j--;
        }
        j = ax + 1;
        for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isWhite() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j++;
        }
        return 0;
    }
}
bool
Reine::mouvementEchec( Echiquier &e, int x, int y)
{
    int ax  = (m_x - 1);
    int ay  = (m_y - 1);

	if(this->isWhite())
	{
		for (int i = ax - 1; i >= 0; i--) // Côté gauche
		{
			if (nullptr == e.getPiece(ay, i) || e.getPiece(ay, i)->isBlack() && (x == i && y == ay))
			{
				return 1;
			}
			else if(nullptr == e.getPiece(ay, i))
			{
				break;
			}
		}
		for (int i = ay - 1; i >= 0; i--) // Côté Haut
		{
			if (nullptr == e.getPiece(i, ax) || e.getPiece(i, ax)->isBlack() && (y == i && x == ax))
			{
				return 1;
			}
			else if(nullptr == e.getPiece(i, ax))
			{
				break;
			}
		}
		for (int i = ax + 1; i < LONGUEUR; i++) // À droite
		{
			if (nullptr == e.getPiece(ay, i) || e.getPiece(ay, i)->isBlack() && (y == ay && x == i))
			{
				return 1;
			}
			else if (nullptr == e.getPiece(ay, i))
			{
				break;
			}
		}
		for (int i = ay + 1; i <LONGUEUR; i++) // bas
		{
			if (nullptr == e.getPiece(i, ax) || e.getPiece(i, ax)->isBlack() && (y == i && x == ax))
			{
				return 1;
			}
			else if(nullptr == e.getPiece(i, ax))
			{
				break;
			}
		}
		int j = ax - 1;
		for (int i = ay - 1; i >= 0; i--) // Côté gauche haut
		{
			if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isBlack() && (y == i && x == j))
			{
				return 1;
			}
			else if(nullptr != e.getPiece(i, j))
			{
				break;
			}
			j--;
		}
		j = ax + 1;
		for (int i = ay - 1; i >= 0; i--) // À droite haut
		{
			if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isBlack() && (y == i && x == j))
			{
				return 1;
			}
			else if (nullptr != e.getPiece(i, j))
			{
				break;
			}
			j++;
		}
		j = ax - 1;
		for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
		{
			if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isBlack() && (y == i && x == j))
			{
				return 1;
			}
			else if(nullptr != e.getPiece(i, j))
			{
				break;
			}
			j--;
		}
		j = ax + 1;
		for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
		{
			if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isBlack() && (y == i && x == j))
			{
				return 1;
			}
			else if(nullptr != e.getPiece(i, j))
			{
				break;
			}
			j++;
		}
	}

	if(this->isBlack())
	{
		for (int i = ax - 1; i >= 0; i--) // Côté gauche
		{
			if (nullptr == e.getPiece(ay, i) || e.getPiece(ay, i)->isWhite() && (x == i && y == ay))
			{
				return 1;
			}
			else if (nullptr == e.getPiece(ay, i))
			{
				break;
			}
		}
		for (int i = ay - 1; i >= 0; i--) // Côté Haut
		{
			if (nullptr == e.getPiece(i, ax) || e.getPiece(i, ax)->isWhite() && (y == i && x == ax))
			{
				return 1;
			}
			else if (nullptr == e.getPiece(i, ax))
			{
				break;
			}
		}
		for (int i = ax + 1; i < LONGUEUR; i++) // À droite
		{
			if (nullptr == e.getPiece(ay, i) || e.getPiece(ay, i)->isWhite() && (y == ay && x == i))
			{
				return 1;
			}
			else if (nullptr == e.getPiece(ay, i))
			{
				break;
			}
		}
		for (int i = ay + 1; i < LONGUEUR; i++) // bas
		{
			if (nullptr == e.getPiece(i, ax) || e.getPiece(i, ax)->isWhite() && (y == i && x == ax))
			{
				return 1;
			}
			else if (nullptr == e.getPiece(i, ax))
			{
				break;
			}
		}
		int j = ax - 1;
		for (int i = ay - 1; i >= 0; i--) // Côté gauche haut
		{
			if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isWhite() && (y == i && x == j))
			{
				return 1;
			}
			else if (nullptr != e.getPiece(i, j))
			{
				break;
			}
			j--;
		}
		j = ax + 1;
		for (int i = ay - 1; i >= 0; i--) // À droite haut
		{
			if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isWhite() && (y == i && x == j))
			{
				return 1;
			}
			else if (nullptr != e.getPiece(i, j))
			{
				break;
			}
			j++;
		}
		j = ax - 1;
		for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
		{
			if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isWhite() && (y == i && x == j))
			{
				return 1;
			}
			else if (nullptr != e.getPiece(i, j))
			{
				break;
			}
			j--;
		}
		j = ax + 1;
		for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
		{
			if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isWhite() && (y == i && x == j))
			{
				return 1;
			}
			else if (nullptr != e.getPiece(i, j))
			{
				break;
			}
			j++;
		}
	}
    return false;
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
Tour::mouvementValide( Echiquier &e, int x, int y)
{
    int ax  =   (this->m_x - 1);
    int ay  =   (this->m_y - 1);

    if(this->isWhite())
    {
        for (int i = ax - 1; i >= 0; i--) // Côté gauche
        {
            if ( e.getPiece(ay, i)->isBlack() || nullptr == e.getPiece(ay, i) && (x == 1 && y == ay) )
            {
                return 1;
            }
            else if (nullptr != e.getPiece(ay, i))
            {
                break;
            }
        }
        for (int i = ay - 1; i >= 0; i--) // Côté Haut
        {
            if (e.getPiece(i, ax)->isBlack() || nullptr == e.getPiece(i, ax) && (y == i && x == ax))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, ax) )
            {
                break;
            }
        }
        for (int i = ax + 1; i < LONGUEUR; i++) // À droite
        {
            if (e.getPiece(ay, i)->isBlack() || nullptr == e.getPiece(ay, i) && (y == ay && x == i))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(ay, i))
            {
                break;
            }
        }
        for (int i = ay + 1; i < LONGUEUR; i++) // bas
        {
            if (e.getPiece(i, ax)->isBlack() || nullptr == e.getPiece(i, ax) && (y == i && x == ax))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, ax))
            {
                break;
            }
        }
        return 0;
    }
    if(this->isBlack())
    {
        for (int i = ax - 1; i >= 0; i--) // Côté gauche
        {
            if (e.getPiece(ay, i)->isWhite() || nullptr == e.getPiece(ay, i) && (x == i && y == ay))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(ay, i))
            {
                break;
            }
        }
        for (int i = ay - 1; i >= 0; i--) // Côté Haut
        {
            if (e.getPiece(i, ax)->isWhite() || nullptr == e.getPiece(i, ax) && (y == i && x == ax))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, ax))            
            {
                break;
            }
        }
        for (int i = ax + 1; i < LONGUEUR; i++) // À droite
        {
            if (e.getPiece(ay, i)->isWhite() || nullptr == e.getPiece(ay, i) && (y == ay && x == i))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(ay, i))
            {
                break;
            }
        }
        for (int i = ay + 1; i < LONGUEUR; i++) // bas
        {
            if (e.getPiece(i, ay)->isWhite() || nullptr == e.getPiece(i, ay) && (y == i && x == ax))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, ax))
            {
                break;
            }
        }
        return 0;
    }
    return false;
}
bool
Tour::mouvementEchec(Echiquier &e, int x, int y)
{
    int ax  = (m_x - 1);
    int ay  = (m_y - 1);

    if(this->isWhite())
    {
        for (int i = ax - 1; i >= 0; i--) // Côté gauche
        {
            if (nullptr == e.getPiece(ay, i) || e.getPiece(ay, i)->isBlack() && (x== i && y == ay))
            {
                return 1;
            }
            else if(nullptr != e.getPiece(ay, i))
            {
                break;
            }
        }
        for (int i = ay - 1; i >= 0; i--) // Côté Haut
        {
            if (nullptr == e.getPiece(i, ax) || e.getPiece(i, ax)->isBlack() && (y == i && x == ax))
            {
                return 1;
            }
            else if(nullptr != e.getPiece(i, ax))
            {
                break;
            }
        }
        for (int i = ax + 1; i < LONGUEUR; i++) // À droite
        {
            if (nullptr == e.getPiece(ay, i) || e.getPiece(ay, i)->isBlack() && (y == ay && x == i))
            {
                return 1;
            }
            else if(nullptr != e.getPiece(ay, i))
            {
                break;
            }
        }
        for (int i = ay + 1; i <LONGUEUR; i++) // bas
        {
            if (nullptr == e.getPiece(i, ax) || e.getPiece(i, ax)->isBlack() && (y == i && x == ax))
            {
                return 1;
            }
            else if(nullptr != e.getPiece(i, ax))
            {
                break;
            }
        }
        return 0;
    }
    if(this->isBlack())
    {
        for (int i = ax - 1; i >= 0; i--) // Côté gauche
        {
            if (nullptr == e.getPiece(ay, i) || e.getPiece(ay, i)->isWhite() && (x == i && y == ay))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(ay, i))
            {
                break;
            }
        }
        for (int i = ay - 1; i >= 0; i--) // Côté Haut
        {
            if (nullptr == e.getPiece(i, ax) || e.getPiece(i, ax)->isWhite() && (y == i && x == ax))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, ax))
            {
                break;
            }
        }
        for (int i = ax + 1; i < LONGUEUR; i++) // À droite
        {
            if (nullptr == e.getPiece(ay, i) || e.getPiece(ay, i)->isWhite() && (y == ay && x == i))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(ay, i))
            {
                break;
            }
        }
        for (int i = ay + 1; i < LONGUEUR; i++) // bas
        {
            if (nullptr == e.getPiece(i, ax) || e.getPiece(i, ax)->isWhite() && (y == i && x == ax))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, ax))
            {
                break;
            }
        }
    }
    return 0;
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
Fou::mouvementValide( Echiquier &e, int x, int y)
{
    
    int ax  = (m_x - 1);
    int ay  = (m_y - 1);

    if(this->isWhite())
    {
        int j = ax - 1;
        for (int i = ay - 1; i >= 0; i--) // Côté gauche haut
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isBlack() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j--;
        }
        j = ax + 1;
        for (int i = ay - 1; i >= 0; i--) // À droite haut
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isBlack() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j++;
        }
        j = ax - 1;
        for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isBlack() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j--;
        }
        j = ax + 1;
        for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isBlack() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j++;
        }
    }

    if(this->isBlack())
    {
        int j = ax - 1;
        for (int i = ay - 1; i >= 0; i--) // Côté gauche haut
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isWhite() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j--;
        }
        j = ax + 1;
        for (int i = ay - 1; i >= 0; i--) // À droite haut
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isWhite() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j++;
        }
        j = ax - 1;
        for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isWhite() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j--;
        }
        j = ax + 1;
        for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isWhite() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j++;
        }
    }
    return false;
}
bool
Fou::mouvementEchec( Echiquier &e, int x, int y)
{
    int ax  = (m_x - 1);
    int ay  = (m_y - 1);
    
    if(this->isWhite())
    {
        int j = ax - 1;
        for (int i = ay - 1; i >= 0; i--) // Côté gauche haut
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isBlack() && (y == i && x == j))
            {
                return 1;
            }
            else if(nullptr != e.getPiece(i, j))
            {
                break;
            }
            j--;
        }
        j = ax + 1;
        for (int i = ay - 1; i >= 0; i--) // À droite haut
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isBlack() && (y == i && x == j))
            {
                return 1;
            }
            else if(nullptr != e.getPiece(i, j))
            {
                break;
            }
            j++;
        }
        j = ax - 1;
        for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isBlack() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j--;
        }
        j = ax + 1;
        for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isBlack() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j++;
        }
    }

    if(this->isBlack())
    {
        int j = ax - 1;
        for (int i = ay - 1; i >= 0; i--) // Côté gauche haut
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isWhite() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j--;
        }
        j = ax + 1;
        for (int i = ay - 1; i >= 0; i--) // À droite haut
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isWhite() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j++;
        }
        j = ax - 1;
        for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isWhite() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j--;
        }
        j = ax + 1;
        for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
        {
            if (nullptr == e.getPiece(i, j) || e.getPiece(i, j)->isWhite() && (y == i && x == j))
            {
                return 1;
            }
            else if (nullptr != e.getPiece(i, j))
            {
                break;
            }
            j++;
        }
    }
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
Cavalier::mouvementValide( Echiquier &e, int x, int y)
{
    int ax  = (m_x - 1);
    int ay  = (m_y - 1);
    
    if(this->isWhite())
    {
        if (ay - 2 >= 0 && ax - 1 >= 0 && y == ay - 2 && x == ax - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
        {
            return 1; // Haut gauche
        }
        if (ay - 2 >= 0 && ax + 1 <LONGUEUR && y == ay - 2 && x == ax + 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
        {
            return 1; // Haut droit
        }
        if (ay - 1 >= 0 && ax + 2 < LONGUEUR && y==ay-1 && x==ax+2 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
        {
            return 1; // droit 1
        }
        if (ay + 1 >= 0 && ax + 2 < LONGUEUR && y == ay + 1 && x == ax + 2 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
        {
            return 1; // droit 2
        }
        if (ay+2<LONGUEUR && ax+1<LONGUEUR && y==ay+2 && x==ax+1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
        {
            return 1; // bas 1
        }
        if (ay + 2 < LONGUEUR && ax - 1 >= 0 && y == ay + 2 && x == ax - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
        {
            return 1; // bas 2
        }
        if (ay+1<LONGUEUR && ax-2>=0 && y==ay+1 && x==ax-2 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack() )
        {
            return 1; // gauche 1
        }
        if (ay - 1 >= 0 && ax - 2 >= 0 && y == ay - 1 && x == ax - 2 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
        {
            return 1;
        }
        return 0;
    }

    //------------------------------------------Mouvement Cheval Noir----------------------------//

    if(this->isBlack())
    {
        if (ay - 2 >= 0 && ax - 1 >= 0 && y == ay - 2 && x == ax - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
        {
            return 1; // Haut gauche
        }
        if (ay - 2 >= 0 && ax + 1 < LONGUEUR && y == ay - 2 && x == ax + 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
        {
            return 1; // Haut droit
        }
        if (ay - 1 >= 0 && ax + 2 < LONGUEUR && y == ay - 1 && x == ax + 2 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
        {
            return 1; // droit 1
        }
        if (ay + 1 >= 0 && ax + 2 < LONGUEUR && y == ay + 1 && x == ax + 2 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
        {
            return 1; // droit 2
        }
        if (ay + 2 < LONGUEUR && ax + 1 < LONGUEUR && y == ay + 2 && x == ax + 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
        {
            return 1; // bas 1
        }
        if (ay + 2 < LONGUEUR && ax - 1 >= 0 && y == ay + 2 && x == ax - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
        {
            return 1; // bas 2
        }
        if (ay + 1 < LONGUEUR && ax - 2 >= 0 && y == ay + 1 && x == ax - 2 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
        {
            return 1; // gauche 1
        }
        if (ay - 1 >= 0 && ax - 2 >= 0 && y == ay - 1 && x == ax - 2 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
        {
            return 1;
        }
        return 0;
    }
}
bool
Cavalier::mouvementEchec( Echiquier &e, int x, int y)
{
    int ax  = (m_x - 1);
    int ay  = (m_y - 1);

    if(this->isWhite())
    {
        if (ay - 2 >= 0 && ax - 1 >= 0 && y == ay - 2 && x == ax - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
        {
            return 1; // Haut gauche
        }
        if (ay - 2 >= 0 && ax + 1 < LONGUEUR && y == ay - 2 && x == ax + 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
        {
            return 1; // Haut droit
        }
        if (ay - 1 >= 0 && ax + 2 < LONGUEUR && y == ay - 1 && x == ax + 2 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
        {
            return 1; // droit 1
        }
        if (ay + 1 >= 0 && ax + 2 < LONGUEUR && y == ay + 1 && x == ax + 2 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
        {
            return 1; // droit 2
        }
        if (ay + 2 < LONGUEUR && ax + 1 < LONGUEUR && y == ay + 2 && x == ax + 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
        {
            return 1; // bas 1
        }
        if (ay + 2 < LONGUEUR && ax - 1 >= 0 && y == ay + 2 && x == ax - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
        {
            return 1; // bas 2
        }
        if (ay + 1 < LONGUEUR && ax - 2 >= 0 && y == ay + 1 && x == ax - 2 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
        {
            return 1; // gauche 1
        }
        if (ay - 1 >= 0 && ax - 2 >= 0 && y == ay - 1 && x == ax - 2 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isBlack())
        {
            return 1;
        }
    }

    if(this->isBlack())
    {
        if (ay - 2 >= 0 && ax - 1 >= 0 && y == ay - 2 && x == ax - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
        {
            return 1; // Haut gauche
        }
        if (ay - 2 >= 0 && ax + 1 < LONGUEUR && y == ay - 2 && x == ax + 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
        {
            return 1; // Haut droit
        }
        if (ay - 1 >= 0 && ax + 2 < LONGUEUR && y == ay - 1 && x == ax + 2 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
        {
            return 1; // droit 1
        }
        if (ay + 1 >= 0 && ax + 2 < LONGUEUR && y == ay + 1 && x == ax + 2 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
        {
            return 1; // droit 2
        }
        if (ay + 2 < LONGUEUR && ax + 1 < LONGUEUR && y == ay + 2 && x == ax + 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
        {
            return 1; // bas 1
        }
        if (ay + 2 < LONGUEUR && ax - 1 >= 0 && y == ay + 2 && x == ax - 1 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
        {
            return 1; // bas 2
        }
        if (ay + 1 < LONGUEUR && ax - 2 >= 0 && y == ay + 1 && x == ax - 2 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
        {
            return 1; // gauche 1
        }
        if (ay - 1 >= 0 && ax - 2 >= 0 && y == ay - 1 && x == ax - 2 && nullptr == e.getPiece(y, x) || e.getPiece(y, x)->isWhite())
        {
            return 1;
        }
    }
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
Pion::mouvementValide( Echiquier &e, int x, int y)
{
    int ax  =   (this->m_x - 1);
    int ay  =   (this->m_y - 1);

    if (this->isWhite())
    {
        if (6 == ay)
        {
            if (( nullptr == e.getPiece(ay-1, x) && y == ay - 1 && x == ax ) ||
                ( nullptr == e.getPiece(ay-1, x) && nullptr == e.getPiece(ay-2, x) && y == ay-2 && x==ax))
            {
                return true;
            }            
        }
        else if( nullptr == e.getPiece(ay-1, x) && y == ay - 1 && x == ax )
        {
            return true;
        }
        if ( nullptr != e.getPiece(ay-1, x-1) )
        {
            if (y == ay - 1 && x == ax - 1)
            {
                return true;
            }
        }
        if ( nullptr != e.getPiece(ay-1, x+1) )
        {
            if (y == ay - 1 && x == ax + 1)
            {
                return true;
            }
        }
    }
    if(this->isWhite())
    {
        if( 1 == ay )
        {
            if (( nullptr == e.getPiece(ay+1, ax) && y == ay + 1 && x == ax ) || 
                ( nullptr == e.getPiece(ay+1, ax) && nullptr == e.getPiece(ay+2, ax) && y == ay + 2 && x == ax))
            {
                return true;
            }
        }
        else if (y == ay + 1 && x == ax && nullptr == e.getPiece(ay+1, ax))
        {
            return true;
        }
        if (e.getPiece(ay+1, ax-1)->isWhite())
        {
            if (y == ay + 1 && x == ax - 1)
            {
                return true;
            }
        }
        if (e.getPiece(ay+1, ax+1)->isWhite())
        {
            if (y == ay + 1 && x == ax + 1)
            {
                return true;
            }
        }
    }    
    return false;
}
bool
Pion::mouvementValide(Echiquier &e, int x, int y)
{
    int ax  = (m_x - 1);
    int ay  = (m_y - 1);
    
    if(this->isWhite())
    {
        if(nullptr == e.getPiece(ay-1, ax -1) || e.getPiece(ay-1, ax-1)->isBlack())
        {
            if (ay-1 == y && ax - 1 == x)
            {
                return 1;
            }
            if(nullptr == e.getPiece(ay-1, ax+1) || e.getPiece(ay-1, ax+1)->isBlack())
            {
                if (ay - 1 == y && ax + 1==x)
                {
                    return 1;
                }
            }
        }
    }
    if(this->isWhite())
    {
        if (nullptr == e.getPiece(ay+1, ax-1) || e.getPiece(ay+1, ax-1)->isWhite())
        {
            if (y == ay + 1 && x == ax - 1)
            {
                return 1;
            }
        }
        if (nullptr == e.getPiece(ay+1, ax+1) || e.getPiece(ay+1, ax+1)->isWhite())
        {
            if (y == ay + 1 && x == ax + 1)
            {
                return 1;
            }
        }
    }
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
     * @return false si aucune piece n'est sur cette case et un pointeur
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
     * @return false si aucune piece n'est sur cette case et le pointeur
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
 * @return false si aucune piece n'est sur cette case et un pointeur
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
 * @return false si aucune piece n'est sur cette case et le pointeur
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
			if (e.type == Event::MouseButtonPressed)
			{
				if (e.key.code == Mouse::Left)
				{
					//std::cout << "x=" << x << " y=" << y << "\n";
					//std::cout << "pos_x=" << pos.x << " pos_y=" << pos.y << "\n";
					//std::cout << "tableDeJeu[y][x]=" << tableDeJeu[y][x] << "\n";
					//std::cout << "\n";
					if (transformationBlanc == 1)
					{
						if (pos.y >= transforme_blanc.y * taille && pos.y <= (transforme_blanc.y + 1) * taille && pos.x >= transforme_blanc.x * taille && pos.x <= (transforme_blanc.x + 1) * taille)
						{
							int ax = pos.x % 100, ay = pos.y % 100;
							//std::cout << "pos.y=" << ay << "\n";
							//std::cout << "pos.x=" << ax << "\n";
							if (ax < 50 && ay < 50 && ax > 0 && ay > 0)
							{
								tableDeJeu[transforme_blanc.y][transforme_blanc.x] = TOUR_BLANC;
								transformationBlanc = 0;
							}
							if (ax > 50 && ax < 100 && ay < 50 && ay > 0)
							{
								tableDeJeu[transforme_blanc.y][transforme_blanc.x] = REINE_BLANC;
								transformationBlanc = 0;
							}
							if (ax > 50 && ax < 100 && ay>50 && ay < 100)
							{
								tableDeJeu[transforme_blanc.y][transforme_blanc.x] = CHEVAL_BLANC;
								transformationBlanc = 0;
							}
							if (ax < 50 && ax>0 && ay > 50 && y < 100)
							{
								tableDeJeu[transforme_blanc.y][transforme_blanc.x] = FOU_BLANC;
								transformationBlanc = 0;
							}
							if (transformationBlanc == 0)
							{
								getPosition();
								bool h = EchecTest(roi_noir.x, roi_noir.y);
								if (h == 0)
								{
									EchecNoir = 1;
								}
							}
						}
					}
					if (transformationNoir == 1)
					{
						if (pos.y >= transforme_noir.y * taille && pos.y <= (transforme_noir.y + 1) * taille && pos.x >= transforme_noir.x * taille && pos.x <= (transforme_noir.x + 1) * taille)
						{
							int ax = pos.x % 100, ay = pos.y % 100;
							//std::cout << "pos.y=" << ay << "\n";
							//std::cout << "pos.x=" << ax << "\n";
							if (ax < 50 && ay < 50 && ax > 0 && ay > 0)
							{
								tableDeJeu[transforme_noir.y][transforme_noir.x] = TOUR_NOIR;
								transformationNoir = 0;
							}
							if (ax > 50 && ax < 100 && ay < 50 && ay > 0)
							{
								tableDeJeu[transforme_noir.y][transforme_noir.x] = REINE_NOIR;
								transformationNoir = 0;
							}
							if (ax > 50 && ax < 100 && ay>50 && ay < 100)
							{
								tableDeJeu[transforme_noir.y][transforme_noir.x] = CHEVAL_NOIR;
								transformationNoir = 0;
							}
							if (ax < 50 && ax>0 && ay > 50 && y < 100)
							{
								tableDeJeu[transforme_noir.y][transforme_noir.x] = FOU_NOIR;
								transformationNoir = 0;
							}
							if (transformationNoir == 0)
							{
								getPosition();
								int h = EchecTest(roi_blanc.x, roi_blanc.y);
								if (h == 0)
								{
									EchecBlanc = 1;
								}
							}
						}
					}
					if (tableDeJeu[y][x] != 0)
					{
						dx = pos.x - x * 100;
						dy = pos.y - y * 100;
						if (tableDeJeu[y][x]  == PION_NOIR && mouvement ==1)
						{
							pasMouvPiece = PION_NOIR;
							Deplacement = imgPionNoir;
							tableDeJeu[y][x] = 0;
						}
						if (tableDeJeu[y][x] == PION_BLANC && mouvement ==0)
						{
							pasMouvPiece = PION_BLANC;
							Deplacement = imgPionBlanc;
							tableDeJeu[y][x] = 0;
						}
						if (tableDeJeu[y][x] == TOUR_NOIR && mouvement ==1)
						{
							pasMouvPiece = TOUR_NOIR;
							Deplacement = imgTourNoir;
							tableDeJeu[y][x] = 0;

						}
						if (tableDeJeu[y][x] == TOUR_BLANC && mouvement ==0)
						{
							pasMouvPiece = TOUR_BLANC;
							Deplacement = imgTourNoir;
							tableDeJeu[y][x] = 0;

						}
						if (tableDeJeu[y][x] == CHEVAL_BLANC && mouvement ==0)
						{
							pasMouvPiece = CHEVAL_BLANC;
							Deplacement = imgChevalBlanc;
							tableDeJeu[y][x] = 0;
						}
						if (tableDeJeu[y][x] == CHEVAL_NOIR && mouvement ==1)
						{
							pasMouvPiece = CHEVAL_NOIR;
							Deplacement = imgChevalNoir;
							tableDeJeu[y][x] = 0;
						}
						if (tableDeJeu[y][x] == FOU_NOIR && mouvement ==1)
						{
							pasMouvPiece = FOU_NOIR;
							Deplacement = imgFouNoir;
							tableDeJeu[y][x] = 0;
						}
						if (tableDeJeu[y][x] == FOU_BLANC && mouvement ==0)
						{
							pasMouvPiece = FOU_BLANC;
							Deplacement = imgFouBlanc;
							tableDeJeu[y][x] = 0;
						}
						if (tableDeJeu[y][x] == REINE_BLANC && mouvement ==0)
						{
							pasMouvPiece = REINE_BLANC;
							Deplacement = imgReineBlanc;
							tableDeJeu[y][x] = 0;
						}
						if (tableDeJeu[y][x] == REINE_NOIR && mouvement ==1)
						{
							pasMouvPiece = REINE_NOIR;
							Deplacement = imgReineNoir;
							tableDeJeu[y][x] = 0;
						}
						if (tableDeJeu[y][x] == ROI_NOIR && mouvement ==1)
						{
							pasMouvPiece = ROI_NOIR;
							Deplacement = imgRoiNoir;
							tableDeJeu[y][x] = 0;
						}
						if (tableDeJeu[y][x] == ROI_BLANC && mouvement ==0)
						{
							pasMouvPiece = ROI_BLANC;
							Deplacement = imgRoiBlanc;
							tableDeJeu[y][x] = 0;
						}
						if (tableDeJeu[y][x] == 0)
						{
							ca_bouge = 1;
							ancienne_Pos.x = x;
							ancienne_Pos.y = y;
						}
					}
				}
			}
			
			if (e.type == Event::MouseButtonReleased)
			{
				if (e.key.code == Mouse::Left)
				{
					int isEchec=2;
					if (pasMouvPiece == PION_BLANC && ca_bouge==1)
					{
						 isEchec = PionBlanc(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece  == PION_NOIR && ca_bouge == 1)
					{
						isEchec = PionNoir(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == TOUR_BLANC && ca_bouge == 1)
					{
						isEchec = TourBlanc(ancienne_Pos.x, ancienne_Pos.y, x, y);
						if (isEchec == 1 && mouvGaucheTourBlanc==0 && ancienne_Pos.y == 7 && ancienne_Pos.x == 0)
						{
							mouvGaucheTourBlanc = 1;
							//std::cout << mouvGaucheTourBlanc << "\n";
						}
						if (isEchec == 1 && mouvDroitTourBlanc==0 && ancienne_Pos.y == 7 && ancienne_Pos.x == 7)
						{
							mouvDroitTourBlanc = 1;
							//std::cout << mouvDroitTourBlanc << "\n";
						}
					}
					if (pasMouvPiece == TOUR_NOIR && ca_bouge == 1)
					{
						isEchec=TourNoir(ancienne_Pos.x, ancienne_Pos.y, x, y);
						if (isEchec == 1 && mouvDroitTourNoir == 0 && ancienne_Pos.y == 0 && ancienne_Pos.x == 7)
						{
							mouvDroitTourNoir = 1;
							//std::cout << mouvDroitTourNoir<< "\n";
						}
						if (isEchec == 1 && mouvGaucheTourNoir == 0 && ancienne_Pos.y == 0 && ancienne_Pos.x == 0)
						{
							mouvGaucheTourNoir = 1;
							//std::cout << mouvGaucheTourNoir << "\n";
						}
					}
					if (pasMouvPiece == FOU_BLANC && ca_bouge == 1)
					{
						isEchec = FouBlanc(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == FOU_NOIR && ca_bouge == 1)
					{
						isEchec= FouNoir(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == REINE_BLANC && ca_bouge == 1)
					{
						isEchec=ReineBlanc(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == REINE_NOIR && ca_bouge == 1)
					{
						isEchec=ReineNoir(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == CHEVAL_BLANC && ca_bouge == 1)
					{
						isEchec=ChevalBlanc(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == CHEVAL_NOIR && ca_bouge == 1)
					{
						isEchec = ChevalNoir(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == ROI_NOIR && ca_bouge == 1)
					{
						isEchec=RoiNoir(ancienne_Pos.x, ancienne_Pos.y, x, y);
						if (isEchec == 1 && RoiNoirPremierMouv == 0)
						{
							RoiNoirPremierMouv = 1;
						//	std::cout << imgRoiNoir << "\n";
						}
					}
					if (pasMouvPiece == ROI_BLANC && ca_bouge == 1)
					{
						isEchec=RoiBlanc(ancienne_Pos.x, ancienne_Pos.y, x, y);
						if (isEchec == 1 && RoiBlancPremierMouv == 0)
						{
							RoiBlancPremierMouv = 1;
							//std::cout << "primaDeplacementimgRoiBlanc=" << imgRoiBlanc << "\n";
						}
					}
					if (isEchec == 1)
					{
						int nr = tableDeJeu[y][x];
						tableDeJeu[y][x] = pasMouvPiece;
						if (y == 0 && pasMouvPiece == PION_BLANC)
						{
							transformationBlanc = 1;
							transforme_blanc.x = x;
							transforme_blanc.y = y;
							tableDeJeu[y][x] = 0;
						}
						if (y == 7 && pasMouvPiece  == PION_NOIR)
						{
							transformationNoir = 1;
							transforme_noir.x = x;
							transforme_noir.y = y;
							tableDeJeu[y][x] = 0;
						}
						if(mouvement ==0) // blanc a bougé et noir suit
						{
							if (EchecBlanc == 1)
							{
								getPosition();
								int s = EchecTest(roi_blanc.x, roi_blanc.y);
								if (s == 0)
								{
									tableDeJeu[ancienne_Pos.y][ancienne_Pos.x] = pasMouvPiece;
									tableDeJeu[y][x] = nr;
								}
								else
								{
									EchecBlanc = 0;
									getPosition();
									int Echec = EchecTest(roi_noir.x,roi_noir.y);
									if (Echec == 0)
									{
										EchecNoir = 1;
									}
									mouvement = 1;
								}
							}
							else
							{
								getPosition();
								int sa = EchecTest(roi_blanc.x, roi_blanc.y);
								if (sa == 0)
								{
									tableDeJeu[ancienne_Pos.y][ancienne_Pos.x] = pasMouvPiece;
									tableDeJeu[y][x] = nr;
								}
								else
								{
									getPosition();
									int Echec = EchecTest(roi_noir.x, roi_noir.y);
									if (Echec == 0)
									{
										EchecNoir = 1;
									}
									mouvement = 1;
								}
							}
						}
						else // noir a bougé et blanc a suivi
						{
							if (EchecNoir == 1)
							{
								getPosition();
								int s = EchecTest(roi_noir.x,roi_noir.y);
								if (s == 0)
								{
									tableDeJeu[ancienne_Pos.y][ancienne_Pos.x] = pasMouvPiece;
									tableDeJeu[y][x] = nr;
								}
								else
								{
									EchecNoir = 0;
									getPosition();
									int Echec = EchecTest(roi_blanc.x,roi_blanc.y);
									if (Echec == 0)
									{
										EchecBlanc = 1;
									}
									mouvement = 0;
								}
							}
							else
							{
								getPosition();
								int sa = EchecTest(roi_noir.x, roi_noir.y);
								if (sa == 0)
								{
									tableDeJeu[ancienne_Pos.y][ancienne_Pos.x] = pasMouvPiece;
									tableDeJeu[y][x] = nr;
								}
								else
								{
									getPosition();
									int Echec = EchecTest(roi_blanc.x, roi_blanc.y);
									if (Echec == 0)
									{
										EchecBlanc = 1;
									}
									mouvement = 0;
								}
							}
						}
					}
					else if(isEchec==0)
					{
						tableDeJeu[ancienne_Pos.y][ancienne_Pos.x] = pasMouvPiece;
					}
                   ca_bouge = 0;
				}
			}
		
		}

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
                            imgFouNoir.setPosition(x * taille, y * taille);
                            window.draw(imgFouNoir);  
                        }
                        if (p->getSrc() == REINE_NOIR)
                        {
                            imgReineNoir.setPosition(x * taille, y * taille);
                            window.draw(imgReineNoir);  
                        }
                        if (p->getSrc() == ROI_NOIR)
                        {
                            imgRoiNoir.setPosition(x * taille, y * taille);
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
                            imgTourBlanc.setPosition(x * taille, y * taille);
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
    Cavalier *cg  = new Cavalier( false, true );
    m_pieces[p++] = cg;
    Fou *fg       = new Fou( false, true );
    m_pieces[p++] = fg;
    Reine *q      = new Reine( false );
    m_pieces[p++] = q;
    Roi *r        = new Roi( false );
    m_pieces[p++] = r;
    Fou *fd       = new Fou( false, false );
    m_pieces[p++] = fd; 
    Cavalier *cd  = new Cavalier( false, false );
    m_pieces[p++] = cd;
    Tour *td      = new Tour( false, false );
    m_pieces[p++] = td;
    for ( int i = 1; i <= 8; i++ ) {
        Pion *ptr     = new Pion( false, i );
        m_pieces[p++] = ptr;
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
    //e.affiche(); // on test par un affichage R=>Tableau vide

    JoueurNoir JoueurNr; // on créer un joueur noir (avec pions noirs)
    JoueurBlanc JoueurBl; // on créer un joueur blanc (avec pions blancs)
    
    assert( JoueurNr.placerPieces( e ) ); // On place tous les pions noirs sur la table
    assert( JoueurBl.placerPieces( e ) ); // On place tous les pions blancs sur la table
    
    e.affiche(); // on test par un affichage R=>Tableau avec tous les pions   
    
    //Run();

	return EXIT_SUCCESS;
}