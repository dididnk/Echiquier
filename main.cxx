#include <SFML/Graphics.hpp>
#include <iostream>

#define LONGUEUR 8
#define PIECE_BLANC 1
#define PIECE_NOIR -1
#define TOUR_BLANC 2
#define TOUR_NOIR -2
#define CHEVAL_BLANC 3
#define CHEVAL_NOIR -3
#define FOU_BLANC 4
#define FOU_NOIR -4
#define REINE_BLANC 5
#define REINE_NOIR -5
#define ROI_BLANC 6
#define ROI_NOIR -6

using namespace sf; 

// Structure pour stocker les positions
struct poistion
{
    int x, y;
}ancienne_Pos, roi_blanc, roi_noir, transforme_blanc, transforme_noir;

int taille = 100, ca_bouge = 0;

int tableDeJeu[LONGUEUR][LONGUEUR]=
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

int mouvement = 0, x, y; // 0 -> Mouvement Blanc 1 -> Mouvement Noir

int testBlanc = 0, testNoir = 0;

int transformationBlanc = 0, transformationNoir = 0;


//===============================================================================================//
//                                 Test Mouvement Simple                                         //
//                                   [BLANC] + [Noir]                                            //
//===============================================================================================//

//------------------------------------------Mouvement Pièce Blanc----------------------------//

int PieceB(int ancienX, int ancienY, int nouveauX, int nouveauY)
{
    if (ancienne_Pos.y == 6)
    {
        if ( ( nouveauY == ancienY - 1 && nouveauX == ancienX && tableDeJeu[ancienY - 1][ancienX] == 0 ) ||
             ( nouveauY == ancienY - 2 && nouveauX == ancienX && tableDeJeu[ancienY - 1][ancienX] == 0 && tableDeJeu[ancienY - 2][ancienX] == 0 ))
        {
            return 1;
		}
    }    
	else if ( nouveauY == ancienY - 1 && nouveauX == ancienX && tableDeJeu[ancienY - 1][ancienX] == 0 )
    {
        return 1;
    }
	if ( (tableDeJeu[ancienY - 1][ancienX - 1] > 0) && ( nouveauY == ancienY - 1 && nouveauX == ancienX -1 ))
	{
		return 1;
	}
	if ( (tableDeJeu[ancienY -1][ancienX + 1] > 0) && ( nouveauY == ancienY - 1 && nouveauX == nouveauX + 1))
	{
		return 1; 
	}
    return 0;
}

//------------------------------------------Mouvement Pièce Noir----------------------------//

int PieceN(int ancienX, int ancienY, int nouveauX, int nouveauY)
{
    if (ancienne_Pos.y == 1)
    {
        if ( ( nouveauY == ancienY + 1 && nouveauX == ancienX && tableDeJeu[ancienY + 1][ancienX] == 0 ) ||
             ( nouveauY == ancienY + 2 && nouveauX == ancienX && tableDeJeu[ancienY + 1][ancienX] == 0 && tableDeJeu[ancienY + 2][ancienX] == 0 ))
        {
            return 1;
        }
	}
	else if ( nouveauY == ancienY + 1 && nouveauX == ancienX && tableDeJeu[ancienY + 1][ancienX] == 0 )
		{
			return 1;
		}
	
	if ( (tableDeJeu[ancienY + 1][ancienX - 1] < 0) && ( nouveauY == ancienY + 1 && nouveauX == ancienX - 1 ))
	{
		return 1;
	}
	if ( (tableDeJeu[ancienY +1][ancienX + 1] < 0) && ( nouveauY == ancienY + 1 && nouveauX == nouveauX + 1))
	{
		return 1; 
	} 
    return 0;
}

//------------------------------------------Mouvement Tour Blanc----------------------------//

int TourB(int ancienX, int ancienY, int nouveauX, int nouveauY)
{
    for (int i = ancienX - 1; i >= 0; i--) // Côté gauche
    {
        if ( tableDeJeu[ancienY][i] >= 0 && ( nouveauX == i && nouveauY == ancienY ) )
        {
            return 1;
        }
        else if ( tableDeJeu[ancienY][i] != 0)
        {
            break;
        }      
    }
    for (int i = ancienY - 1; i >= 0; i--) // Côté Haut
    {
        if ( tableDeJeu[i][ancienX] >= 0 && ( nouveauX == ancienX && nouveauY == i ) )
        {
            return 1;
        }
        else if ( tableDeJeu[i][ancienX] != 0)
        {
            break;
        }      
    }
    for (int i = ancienX + 1; i < LONGUEUR; i++) // À droite
    {
        if ( (tableDeJeu[ancienY][i] >= 0) && (nouveauY == ancienY && nouveauX == i) )
        {
            return 1;
        }
        else if ( tableDeJeu[ancienY][i] != 0)
        {
            break;
        }
    }
    for (int i = ancienY + 1; i < LONGUEUR; i++) // bas
    {
        if ( (tableDeJeu[i][ancienX] >= 0) && (nouveauY == i && nouveauX == ancienX) )
        {
            return 1;
        }
        else if ( tableDeJeu[i][ancienX] != 0)
        {
            break;
        }
    }    
    return 0;
}

//------------------------------------------Mouvement Tour Blanc----------------------------//

int TourN(int ancienX, int ancienY, int nouveauX, int nouveauY)
{
    for (int i = ancienX - 1; i >= 0; i--) // Côté gauche
    {
        if ( tableDeJeu[ancienY][i] <= 0 && ( nouveauX == i && nouveauY == ancienY ) )
        {
            return 1;
        }
        else if ( tableDeJeu[ancienY][i] != 0)
        {
            break;
        }      
    }
    for (int i = ancienY - 1; i >= 0; i--) // Côté Haut
    {
        if ( tableDeJeu[i][ancienX] <= 0 && ( nouveauX == ancienX && nouveauY == i ) )
        {
            return 1;
        }
        else if ( tableDeJeu[i][ancienX] != 0)
        {
            break;
        }      
    }
    for (int i = ancienX + 1; i < LONGUEUR; i++) // À droite
    {
        if ( (tableDeJeu[ancienY][i] <= 0) && (nouveauY == ancienY && nouveauX ==i) )
        {
            return 1;
        }
        else if ( tableDeJeu[ancienY][i] != 0)
        {
            break;
        }
    }
    for (int i = ancienY + 1; i < LONGUEUR; i++) // En bas
    {
        if ( (tableDeJeu[i][ancienX] <= 0) && (nouveauY == i && nouveauX == ancienX) )
        {
            return 1;
        }
        else if ( tableDeJeu[i][ancienX] != 0)
        {
            break;
        }
    }    
    return 0;
}

//------------------------------------------Mouvement Fou Blanc----------------------------//

int FouB(int ancienX, int ancienY, int nouveauX, int nouveauY)
{
    int j = ancienX - 1;
    for (int i = ancienY - 1; i >= 0; i--) //en haut à gauche
    {
        if ((tableDeJeu[i][j] >= 0) && (nouveauY == i && nouveauX == j))
        {
            return 1;
        }
        else if ( tableDeJeu[i][j] != 0)
        {
            break;
        }
        j--;
    }
    j = ancienX + 1;
    for (int i = ancienY - 1; i >= 0; i--) // en haut à droite
    {
        if ((tableDeJeu[i][j] >= 0) && (nouveauY == i && nouveauX == j))
        {
            return 1;
        }
        else if ( tableDeJeu[i][j] != 0)
        {
            break;
        }
        j++;
    }
    j = ancienX - 1;
    for (int i = ancienY + 1; i < LONGUEUR; i++) // en bas à gauche
    {
        if ((tableDeJeu[i][j] >= 0) && (nouveauY == i && nouveauX == j))
        {
            return 1;
        }
        else if ( tableDeJeu[i][j] != 0)
        {
            break;
        }
        j--;
    }
    j = ancienX + 1;
    for (int i = ancienY + 1; i < LONGUEUR; i++) // en bas à droite
    {
        if ((tableDeJeu[i][j] >= 0) && (nouveauY == i && nouveauX == j))
        {
            return 1;
        }
        else if ( tableDeJeu[i][j] != 0)
        {
            break;
        }
        j++;
    }
    return 0;
}

//------------------------------------------Mouvement Fou Blanc----------------------------//

int FouN(int ancienX, int ancienY, int nouveauX, int nouveauY)
{
    int j = ancienX - 1;
    for (int i = ancienY - 1; i >= 0; i--) // en haut gauche
    {
        if ((tableDeJeu[i][j] <= 0) && (nouveauY == i && nouveauX == j))
        {
            return 1;
        }
        else if ( tableDeJeu[i][j] != 0)
        {
            break;
        }
        j--;
    }
    j = ancienX + 1;
    for (int i = ancienY - 1; i >= 0; i--) // en haut droit
    {
        if ((tableDeJeu[i][j] <= 0) && (nouveauY == i && nouveauX == j))
        {
            return 1;
        }
        else if ( tableDeJeu[i][j] != 0)
        {
            break;
        }
        j++;
    }
    j = ancienX - 1;
    for (int i = ancienY + 1; i < LONGUEUR; i++) // en bas gauche
    {
        if ((tableDeJeu[i][j] <= 0) && (nouveauY == i && nouveauX == j))
        {
            return 1;
        }
        else if ( tableDeJeu[i][j] != 0)
        {
            break;
        }
        j--;
    }
    j = ancienX + 1;
    for (int i = ancienY + 1; i < LONGUEUR; i++) // en bas droit
    {
        if ((tableDeJeu[i][j] <= 0) && (nouveauY == i && nouveauX == j))
        {
            return 1;
        }
        else if ( tableDeJeu[i][j] != 0)
        {
            break;
        }
        j--;
    }
    return 0;
}

//------------------------------------------Mouvement Reine Blanc----------------------------//

int ReineB(int ancienX, int ancienY, int nouveauX, int nouveauY)
{
	for (int i = ancienX - 1; i >= 0; i--) // à gauche
	{
		if (tableDeJeu[ancienY][i] >= 0 && (nouveauX == i && nouveauY == ancienY))
		{
			return 1;
		}
		else if (tableDeJeu[ancienY][i] != 0)
		{
			break;
		}
	}
	for (int i = ancienY - 1; i >= 0; i--) // en haut
	{
		if (tableDeJeu[i][ancienX] >= 0 && (nouveauY == i && nouveauX == ancienX))
		{
			return 1;
		}
		else if (tableDeJeu[i][ancienX] != 0)
		{
			break;
		}
	}
	for (int i = ancienX + 1; i < LONGUEUR; i++) // à droite
	{
		if (tableDeJeu[ancienY][i] >= 0 && (nouveauY == ancienY && nouveauX == i))
		{
			return 1;
		}
		else if (tableDeJeu[ancienY][i] != 0)
		{
			break;
		}
	}
	for (int i = ancienY + 1; i < LONGUEUR; i++) // bas
	{
		if (tableDeJeu[i][ancienX] >= 0 && (nouveauY == i && nouveauX == ancienX))
		{
			return 1;
		}
		else if (tableDeJeu[i][ancienX] != 0)
		{
			break;
		}
	}
	int j = ancienX - 1;
	for (int i = ancienY - 1; i >= 0; i--) // en Haut gauche
	{
		if (tableDeJeu[i][j] >= 0 && (nouveauY == i && nouveauX == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ancienX + 1;
	for (int i = ancienY - 1; i >= 0; i--) // en Haut droite
	{
		if (tableDeJeu[i][j] >= 0 && (nouveauY == i && nouveauX == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ancienX - 1;
	for (int i = ancienY + 1; i < LONGUEUR; i++) // en bas gauche
	{
		if (tableDeJeu[i][j] >= 0 && (nouveauY == i && nouveauX == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ancienX + 1;
	for (int i = ancienY + 1; i < LONGUEUR; i++)  // en bas roite
	{
		if (tableDeJeu[i][j] >= 0 && (nouveauY == i && nouveauX == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

//------------------------------------------Mouvement Reine Blanc----------------------------//

int ReineN(int ancienX, int ancienY, int nouveauX, int nouveauY)
{
	for (int i = ancienX - 1; i >= 0; i--) // à gauche
	{
		if (tableDeJeu[ancienY][i] <= 0 && (nouveauX == i && nouveauY == ancienY))
		{
			return 1;
		}
		else if (tableDeJeu[ancienY][i] != 0)
		{
			break;
		}
	}
	for (int i = ancienY - 1; i >= 0; i--) // haut
	{
		if (tableDeJeu[i][ancienX] <= 0 && (nouveauY == i && nouveauX == ancienX))
		{
			return 1;
		}
		else if (tableDeJeu[i][ancienX] != 0)
		{
			break;
		}
	}
	for (int i = ancienX + 1; i < LONGUEUR; i++) // à droite
	{
		if (tableDeJeu[ancienY][i] <= 0 && (nouveauY == ancienY && nouveauX == i))
		{
			return 1;
		}
		else if (tableDeJeu[ancienY][i] != 0)
		{
			break;
		}
	}
	for (int i = ancienY + 1; i < LONGUEUR; i++) // en bas
	{
		if (tableDeJeu[i][ancienX] <= 0 && (nouveauY == i && nouveauX == ancienX))
		{
			return 1;
		}
		else if (tableDeJeu[i][ancienX] != 0)
		{
			break;
		}
	}
	int j = ancienX - 1;
	for (int i = ancienY - 1; i >= 0; i--) // en haut gauche
	{
		if (tableDeJeu[i][j] <= 0 && (nouveauY == i && nouveauX == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ancienX + 1;
	for (int i = ancienY - 1; i >= 0; i--) // en Haut droite
	{
		if (tableDeJeu[i][j] <= 0 && (nouveauY == i && nouveauX == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ancienX - 1;
	for (int i = ancienY + 1; i < LONGUEUR; i++) // en bas gauche
	{
		if (tableDeJeu[i][j] <= 0 && (nouveauY == i && nouveauX == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ancienX + 1;
	for (int i = ancienY + 1; i < LONGUEUR; i++)  // en bas droite
	{
		if (tableDeJeu[i][j] <= 0 && (nouveauY == i && nouveauX == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

//------------------------------------------Mouvement Cheval Blanc----------------------------//

int ChevalB(int ancienX, int ancienY, int nouveauX, int nouveauY)
{
	if (ancienY - 2 >= 0 && ancienX - 1 >= 0 && nouveauY == ancienY - 2 && nouveauX == ancienX - 1 && tableDeJeu[nouveauY][nouveauX] >= 0)
	{
		return 1; // Haut gauche
	}
	if (ancienY - 2 >= 0 && ancienX + 1 < LONGUEUR && nouveauY == ancienY - 2 && nouveauX == ancienX + 1 && tableDeJeu[nouveauY][nouveauX] >= 0)
	{
		return 1; // Haut droite
	}
	if (ancienY - 1 >= 0 && ancienX + 2 < LONGUEUR && nouveauY==ancienY-1 && nouveauX==ancienX+2 && tableDeJeu[nouveauY][nouveauX]>=0)
	{
		return 1; // droite 1
	}
	if (ancienY + 1 >= 0 && ancienX + 2 < LONGUEUR && nouveauY == ancienY + 1 && nouveauX == ancienX + 2 && tableDeJeu[nouveauY][nouveauX] >= 0)
	{
		return 1; // droite 2
	}
	if (ancienY + 2 < LONGUEUR && ancienX + 1 < LONGUEUR && nouveauY==ancienY+2 && nouveauX==ancienX+1 && tableDeJeu[nouveauY][nouveauX]>=0)
	{
		return 1; // bas 1
	}
	if (ancienY + 2 < LONGUEUR && ancienX - 1 >= 0 && nouveauY == ancienY + 2 && nouveauX == ancienX - 1 && tableDeJeu[nouveauY][nouveauX] >= 0)
	{
		return 1; //bas 2
	}
	if (ancienY + 1 < LONGUEUR && ancienX-2>=0 && nouveauY==ancienY+1 && nouveauX==ancienX-2 && tableDeJeu[nouveauY][nouveauX]>=0 )
	{
		return 1; // gauche 1
	}
	if (ancienY - 1 >= 0 && ancienX - 2 >= 0 && nouveauY == ancienY - 1 && nouveauX == ancienX - 2 && tableDeJeu[nouveauY][nouveauX] >= 0)
	{
		return 1;
	}
	return 0;
}

//------------------------------------------Mouvement Cheval Blanc----------------------------//

int ChevalN(int ancienX, int ancienY, int nouveauX, int nouveauY)
{
	if (ancienY - 2 >= 0 && ancienX - 1 >= 0 && nouveauY == ancienY - 2 && nouveauX == ancienX - 1 && tableDeJeu[nouveauY][nouveauX] <= 0)
	{
		return 1; // Haut gauche
	}
	if (ancienY - 2 >= 0 && ancienX + 1 < LONGUEUR && nouveauY == ancienY - 2 && nouveauX == ancienX + 1 && tableDeJeu[nouveauY][nouveauX] <= 0)
	{
		return 1; // Haut droite
	}
	if (ancienY - 1 >= 0 && ancienX + 2 < LONGUEUR && nouveauY == ancienY - 1 && nouveauX == ancienX + 2 && tableDeJeu[nouveauY][nouveauX] <= 0)
	{
		return 1; // droite 1
	}
	if (ancienY + 1 >= 0 && ancienX + 2 < LONGUEUR && nouveauY == ancienY + 1 && nouveauX == ancienX + 2 && tableDeJeu[nouveauY][nouveauX] <= 0)
	{
		return 1; // droite 2
	}
	if (ancienY + 2 < LONGUEUR && ancienX + 1 < LONGUEUR && nouveauY == ancienY + 2 && nouveauX == ancienX + 1 && tableDeJeu[nouveauY][nouveauX] <= 0)
	{
		return 1; // bas 1
	}
	if (ancienY + 2 < LONGUEUR && ancienX - 1 >= 0 && nouveauY == ancienY + 2 && nouveauX == ancienX - 1 && tableDeJeu[nouveauY][nouveauX] <= 0)
	{
		return 1; //bas 2
	}
	if (ancienY + 1 < LONGUEUR && ancienX - 2 >= 0 && nouveauY == ancienY + 1 && nouveauX == ancienX - 2 && tableDeJeu[nouveauY][nouveauX] <= 0)
	{
		return 1; // gauche 1
	}
	if (ancienY - 1 >= 0 && ancienX - 2 >= 0 && nouveauY == ancienY - 1 && nouveauX == ancienX - 2 && tableDeJeu[nouveauY][nouveauX] <= 0)
	{
		return 1;
	}
	return 0;
}

//===============================================================================================//
//                                 Test Mouvement Echeque et match                               //
//                                             [BLANC]                                           //
//===============================================================================================//

//------------------------------------------Mouvement Piece Blanc Echec----------------------------//

int PieceBEchec(int pos_x, int pos_y, int roi_x, int roi_y)
{
	if (tableDeJeu[pos_y - 1][pos_x - 1] >= 0)
	{
		if (pos_y - 1 == roi_y && pos_x - 1 == roi_x)
		{
			return 1;
		}
	}
	if (tableDeJeu[pos_y - 1][pos_x + 1] >= 0)
	{
		if (pos_y - 1 == roi_y && pos_x + 1==roi_x)
		{
			return 1;
		}
	}
	return 0;
}

//------------------------------------------Mouvement Tour Blanc Echec----------------------------//

int TourBEchec(int ancienX, int ancienY, int roi_x, int roi_y)
{
	for (int i = ancienX - 1; i >= 0; i--) // À gauche
	{
		if (tableDeJeu[ancienY][i] >= 0 && (roi_x== i && roi_y == ancienY))
		{
			return 1;
		}
		else if(tableDeJeu[ancienY][i] != 0)
		{
			break;
		}
	}
	for (int i = ancienY - 1; i >= 0; i--) // haut
	{
		if (tableDeJeu[i][ancienX] >= 0 && (roi_y == i && roi_x == ancienX))
		{
			return 1;
		}
		else if(tableDeJeu[i][ancienX] != 0)
		{
			break;
		}
	}
	for (int i = ancienX + 1; i < LONGUEUR; i++) // À droite
	{
		if (tableDeJeu[ancienY][i] >= 0 && (roi_y == ancienY && roi_x == i))
		{
			return 1;
		}
		else if(tableDeJeu[ancienY][i] != 0)
		{
			break;
		}
	}
	for (int i = ancienY + 1; i <LONGUEUR; i++) // bas
	{
		if (tableDeJeu[i][ancienX] >= 0 && (roi_y == i && roi_x == ancienX))
		{
			return 1;
		}
		else if(tableDeJeu[i][ancienX] != 0)
		{
			break;
		}
	}
	return 0;
}

//------------------------------------------Mouvement Fou Blanc Echec----------------------------//

int FouBEchec(int ancienX, int ancienY, int roi_x, int roi_y)
{
	int j = ancienX - 1;
	for (int i = ancienY - 1; i >= 0; i--) // À gauche haut
	{
		if (tableDeJeu[i][j] >= 0 && (roi_y == i && roi_x == j))
		{
			return 1;
		}
		else if(tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ancienX + 1;
	for (int i = ancienY - 1; i >= 0; i--) // en haut à droite
	{
		if (tableDeJeu[i][j] >= 0 && (roi_y == i && roi_x == j))
		{
			return 1;
		}
		else if(tableDeJeu[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ancienX - 1;
	for (int i = ancienY + 1; i <= 7; i++) // en bas à gauche
	{
		if (tableDeJeu[i][j] >= 0 && (roi_y == i && roi_x == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ancienX + 1;
	for (int i = ancienY + 1; i <= 7; i++)  // en bas à droite
	{
		if (tableDeJeu[i][j] >= 0 && (roi_y == i && roi_x == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

//------------------------------------------Mouvement Reine Blanc Echec---------------------------//

int ReineBEchec(int ancienX, int ancienY, int roi_x, int roi_y)
{
	for (int i = ancienX - 1; i >= 0; i--) // À gauche
	{
		if (tableDeJeu[ancienY][i] >= 0 && (roi_x == i && roi_y == ancienY))
		{
			return 1;
		}
		else if(tableDeJeu[ancienY][i] != 0)
		{
			break;
		}
	}
	for (int i = ancienY - 1; i >= 0; i--) // haut
	{
		if (tableDeJeu[i][ancienX] >= 0 && (roi_y == i && roi_x == ancienX))
		{
			return 1;
		}
		else if(tableDeJeu[i][ancienX] != 0)
		{
			break;
		}
	}
	for (int i = ancienX + 1; i < LONGUEUR; i++) // À droite
	{
		if (tableDeJeu[ancienY][i] >= 0 && (roi_y == ancienY && roi_x == i))
		{
			return 1;
		}
		else if (tableDeJeu[ancienY][i] != 0)
		{
			break;
		}
	}
	for (int i = ancienY + 1; i <LONGUEUR; i++) // bas
	{
		if (tableDeJeu[i][ancienX] >= 0 && (roi_y == i && roi_x == ancienX))
		{
			return 1;
		}
		else if(tableDeJeu[i][ancienX] != 0)
		{
			break;
		}
	}
	int j = ancienX - 1;
	for (int i = ancienY - 1; i >= 0; i--) // À gauche haut
	{
		if (tableDeJeu[i][j] >= 0 && (roi_y == i && roi_x == j))
		{
			return 1;
		}
		else if(tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ancienX + 1;
	for (int i = ancienY - 1; i >= 0; i--) // en haut à droite
	{
		if (tableDeJeu[i][j] >= 0 && (roi_y == i && roi_x == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ancienX - 1;
	for (int i = ancienY + 1; i <= 7; i++) // en bas à gauche
	{
		if (tableDeJeu[i][j] >= 0 && (roi_y == i && roi_x == j))
		{
			return 1;
		}
		else if(tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ancienX + 1;
	for (int i = ancienY + 1; i < LONGUEUR; i++)  // en bas à droite
	{
		if (tableDeJeu[i][j] >= 0 && (roi_y == i && roi_x == j))
		{
			return 1;
		}
		else if(tableDeJeu[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

//------------------------------------------Mouvement Cheval Blanc Echec--------------------------//

int ChevalBEchec(int ancienX, int ancienY, int roi_x, int roi_y)
{
	if (ancienY - 2 >= 0 && ancienX - 1 >= 0 && roi_y == ancienY - 2 && roi_x == ancienX - 1 && tableDeJeu[roi_y][roi_x] >= 0)
	{
		return 1; // gauche haut
	}
	if (ancienY - 2 >= 0 && ancienX + 1 < LONGUEUR && roi_y == ancienY - 2 && roi_x == ancienX + 1 && tableDeJeu[roi_y][roi_x] >= 0)
	{
		return 1; // droit haut
	}
	if (ancienY - 1 >= 0 && ancienX + 2 < LONGUEUR && roi_y == ancienY - 1 && roi_x == ancienX + 2 && tableDeJeu[roi_y][roi_x] >= 0)
	{
		return 1; // droit 1
	}
	if (ancienY + 1 >= 0 && ancienX + 2 < LONGUEUR && roi_y == ancienY + 1 && roi_x == ancienX + 2 && tableDeJeu[roi_y][roi_x] >= 0)
	{
		return 1; // droit 2
	}
	if (ancienY + 2 < LONGUEUR && ancienX + 1 < LONGUEUR && roi_y == ancienY + 2 && roi_x == ancienX + 1 && tableDeJeu[roi_y][roi_x] >= 0)
	{
		return 1; // bas 1
	}
	if (ancienY + 2 < LONGUEUR && ancienX - 1 >= 0 && roi_y == ancienY + 2 && roi_x == ancienX - 1 && tableDeJeu[roi_y][roi_x] >= 0)
	{
		return 1; //bas 2
	}
	if (ancienY + 1 < LONGUEUR && ancienX - 2 >= 0 && roi_y == ancienY + 1 && roi_x == ancienX - 2 && tableDeJeu[roi_y][roi_x] >= 0)
	{
		return 1; // gauche 1
	}
	if (ancienY - 1 >= 0 && ancienX - 2 >= 0 && roi_y == ancienY - 1 && roi_x == ancienX - 2 && tableDeJeu[roi_y][roi_x] >= 0)
	{
		return 1;
	}
	return 0;
}

//------------------------------------------Mouvement ROI Blanc Echec----------------------------//

int RoiBEchec(int ancienX, int ancienY, int roi_x, int roi_y)
{
	if (ancienX - 1 >= 0 && ancienY - 1 >= 0 && roi_y == ancienY - 1 && roi_x == ancienX - 1 && tableDeJeu[roi_y][roi_x] <= 0)
	{
		return 1;
	}
	if (ancienY - 1 >= 0 && roi_x == ancienX && roi_y == ancienY - 1 && tableDeJeu[roi_y][roi_x] <= 0)
	{
		return 1;
	}
	if (ancienY - 1 >= 0 && ancienX + 1 < LONGUEUR && roi_x == ancienX + 1 && roi_y == ancienY - 1 && tableDeJeu[roi_y][roi_x] <= 0)
	{
		return 1;
	}
	if (ancienX + 1 < LONGUEUR && roi_y == ancienY && roi_x == ancienX + 1 && tableDeJeu[roi_y][roi_x] <= 0)
	{
		return 1;
	}
	if (ancienX + 1 < LONGUEUR && ancienY + 1 < LONGUEUR && roi_y == ancienY + 1 && roi_x == ancienX + 1 && tableDeJeu[roi_y][roi_x] <= 0)
	{
		return 1;
	}
	if (ancienY + 1 < LONGUEUR && roi_y == ancienY + 1 && roi_x == ancienX && tableDeJeu[roi_y][roi_x] <= 0)
	{
		return 1;
	}
	if (ancienX - 1 >= 0 && ancienY + 1 < LONGUEUR && roi_x == ancienX - 1 && roi_y == ancienY + 1 && tableDeJeu[roi_y][roi_x] <= 0)
	{
		return 1;
	}
	if (ancienX - 1 >= 0 && roi_y == ancienY && roi_x == ancienX - 1 && tableDeJeu[roi_y][roi_x] <= 0)
	{
		return 1;
	}
	return 0;
}

//===============================================================================================//
//                                 Test Mouvement Echeque et match                               //
//                                              [NOIR]                                           //
//===============================================================================================//

//------------------------------------------Mouvement Piece Noir Echec----------------------------//

int PieceNEchec(int ancienX, int ancienY, int roi_x, int roi_y)
{
	if (tableDeJeu[ancienY + 1][ancienX - 1] <= 0)
	{
		if (roi_y == ancienY + 1 && roi_x == ancienX - 1)
		{
			return 1;
		}
	}
	if (tableDeJeu[ancienY + 1][ancienX + 1] <= 0)
	{
		if (roi_y == ancienY + 1 && roi_x == ancienX + 1)
		{
			return 1;
		}
	}
	return 0;
}

//------------------------------------------Mouvement Tour Noir Echec----------------------------//

int TourNEchec(int ancienX, int ancienY, int roi_x, int roi_y)
{
	for (int i = ancienX - 1; i >= 0; i--) // À gauche
	{
		if (tableDeJeu[ancienY][i] <= 0 && (roi_x == i && roi_y == ancienY))
		{
			return 1;
		}
		else if (tableDeJeu[ancienY][i] != 0)
		{
			break;
		}
	}
	for (int i = ancienY - 1; i >= 0; i--) // haut
	{
		if (tableDeJeu[i][ancienX] <= 0 && (roi_y == i && roi_x == ancienX))
		{
			return 1;
		}
		else if (tableDeJeu[i][ancienX] != 0)
		{
			break;
		}
	}
	for (int i = ancienX + 1; i < LONGUEUR; i++) // À droite
	{
		if (tableDeJeu[ancienY][i] <= 0 && (roi_y == ancienY && roi_x == i))
		{
			return 1;
		}
		else if (tableDeJeu[ancienY][i] != 0)
		{
			break;
		}
	}
	for (int i = ancienY + 1; i < LONGUEUR; i++) // bas
	{
		if (tableDeJeu[i][ancienX] <= 0 && (roi_y == i && roi_x == ancienX))
		{
			return 1;
		}
		else if (tableDeJeu[i][ancienX] != 0)
		{
			break;
		}
	}
	return 0;
}

//------------------------------------------Mouvement ROI Noir Echec----------------------------//

int FouNEchec(int ancienX, int ancienY, int roi_x, int roi_y)
{
	int j = ancienX - 1;
	for (int i = ancienY - 1; i >= 0; i--) // À gauche haut
	{
		if (tableDeJeu[i][j] <= 0 && (roi_y == i && roi_x == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ancienX + 1;
	for (int i = ancienY - 1; i >= 0; i--) // en haut à droite
	{
		if (tableDeJeu[i][j] <= 0 && (roi_y == i && roi_x == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ancienX - 1;
	for (int i = ancienY + 1; i <= 7; i++) // en bas à gauche
	{
		if (tableDeJeu[i][j] <= 0 && (roi_y == i && roi_x == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ancienX + 1;
	for (int i = ancienY + 1; i <= 7; i++)  // en bas à droite
	{
		if (tableDeJeu[i][j] <= 0 && (roi_y == i && roi_x == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

//------------------------------------------Mouvement Reine Noir Echec----------------------------//

int ReineNEchec(int ancienX, int ancienY, int roi_x, int roi_y)
{
	for (int i = ancienX - 1; i >= 0; i--) // À gauche
	{
		if (tableDeJeu[ancienY][i] <= 0 && (roi_x == i && roi_y == ancienY))
		{
			return 1;
		}
		else if (tableDeJeu[ancienY][i] != 0)
		{
			break;
		}
	}
	for (int i = ancienY - 1; i >= 0; i--) // haut
	{
		if (tableDeJeu[i][ancienX] <= 0 && (roi_y == i && roi_x == ancienX))
		{
			return 1;
		}
		else if (tableDeJeu[i][ancienX] != 0)
		{
			break;
		}
	}
	for (int i = ancienX + 1; i < LONGUEUR; i++) // À droite
	{
		if (tableDeJeu[ancienY][i] <= 0 && (roi_y == ancienY && roi_x == i))
		{
			return 1;
		}
		else if (tableDeJeu[ancienY][i] != 0)
		{
			break;
		}
	}
	for (int i = ancienY + 1; i < LONGUEUR; i++) // bas
	{
		if (tableDeJeu[i][ancienX] <= 0 && (roi_y == i && roi_x == ancienX))
		{
			return 1;
		}
		else if (tableDeJeu[i][ancienX] != 0)
		{
			break;
		}
	}
	int j = ancienX - 1;
	for (int i = ancienY - 1; i >= 0; i--) // À gauche haut
	{
		if (tableDeJeu[i][j] <= 0 && (roi_y == i && roi_x == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ancienX + 1;
	for (int i = ancienY - 1; i >= 0; i--) // en haut à droite
	{
		if (tableDeJeu[i][j] <= 0 && (roi_y == i && roi_x == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ancienX - 1;
	for (int i = ancienY + 1; i <= 7; i++) // en bas à gauche
	{
		if (tableDeJeu[i][j] <= 0 && (roi_y == i && roi_x == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ancienX + 1;
	for (int i = ancienY + 1; i < LONGUEUR; i++)  // en bas à droite
	{
		if (tableDeJeu[i][j] <= 0 && (roi_y == i && roi_x == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

//------------------------------------------Mouvement ROI Blanc Echec----------------------------//

int ChevalNEchec(int ancienX, int ancienY, int roi_x, int roi_y)
{
	if (ancienY - 2 >= 0 && ancienX - 1 >= 0 && roi_y == ancienY - 2 && roi_x == ancienX - 1 && tableDeJeu[roi_y][roi_x] <= 0)
	{
		return 1; // gauche haut
	}
	if (ancienY - 2 >= 0 && ancienX + 1 < LONGUEUR && roi_y == ancienY - 2 && roi_x == ancienX + 1 && tableDeJeu[roi_y][roi_x] <= 0)
	{
		return 1; // droit haut
	}
	if (ancienY - 1 >= 0 && ancienX + 2 < LONGUEUR && roi_y == ancienY - 1 && roi_x == ancienX + 2 && tableDeJeu[roi_y][roi_x] <= 0)
	{
		return 1; // droit 1
	}
	if (ancienY + 1 >= 0 && ancienX + 2 < LONGUEUR && roi_y == ancienY + 1 && roi_x == ancienX + 2 && tableDeJeu[roi_y][roi_x] <= 0)
	{
		return 1; // droit 2
	}
	if (ancienY + 2 < LONGUEUR && ancienX + 1 < LONGUEUR && roi_y == ancienY + 2 && roi_x == ancienX + 1 && tableDeJeu[roi_y][roi_x] <= 0)
	{
		return 1; // bas 1
	}
	if (ancienY + 2 < LONGUEUR && ancienX - 1 >= 0 && roi_y == ancienY + 2 && roi_x == ancienX - 1 && tableDeJeu[roi_y][roi_x] <= 0)
	{
		return 1; //bas 2
	}
	if (ancienY + 1 < LONGUEUR && ancienX - 2 >= 0 && roi_y == ancienY + 1 && roi_x == ancienX - 2 && tableDeJeu[roi_y][roi_x] <= 0)
	{
		return 1; // gauche 1
	}
	if (ancienY - 1 >= 0 && ancienX - 2 >= 0 && roi_y == ancienY - 1 && roi_x == ancienX - 2 && tableDeJeu[roi_y][roi_x] <= 0)
	{
		return 1;
	}
	return 0;
}

//------------------------------------------Mouvement ROI Noir Echec----------------------------//

int RoiNEchec(int ancienX, int ancienY, int roi_x, int roi_y)
{
	if (ancienX - 1 >= 0 && ancienY - 1 >= 0 && roi_y == ancienY - 1 && roi_x == ancienX - 1 && tableDeJeu[roi_y][roi_x] >= 0)
	{
		return 1;
	}
	if (ancienY - 1 >= 0 && roi_x == ancienX && roi_y == ancienY - 1 && tableDeJeu[roi_y][roi_x] >= 0)
	{
		return 1;
	}
	if (ancienY - 1 >= 0 && ancienX + 1 < LONGUEUR && roi_x == ancienX + 1 && roi_y == ancienY - 1 && tableDeJeu[roi_y][roi_x] >= 0)
	{
		return 1;
	}
	if (ancienX + 1 < LONGUEUR && roi_y == ancienY && roi_x == ancienX + 1 && tableDeJeu[roi_y][roi_x] >= 0)
	{
		return 1;
	}
	if (ancienX + 1 < LONGUEUR && ancienY + 1 < LONGUEUR && roi_y == ancienY + 1 && roi_x == ancienX + 1 && tableDeJeu[roi_y][roi_x] >= 0)
	{
		return 1;
	}
	if (ancienY + 1 < LONGUEUR && roi_y == ancienY + 1 && roi_x == ancienX && tableDeJeu[roi_y][roi_x] >= 0)
	{
		return 1;
	}
	if (ancienX - 1 >= 0 && ancienY + 1 < LONGUEUR && roi_x == ancienX - 1 && roi_y == ancienY + 1 && tableDeJeu[roi_y][roi_x] >= 0)
	{
		return 1;
	}
	if (ancienX - 1 >= 0 && roi_y == ancienY && roi_x == ancienX - 1 && tableDeJeu[roi_y][roi_x] >= 0)
	{
		return 1;
	}
	return 0;
}

//===============================================================================================//
//                Test Mouvement Checking Echeque et match plus Deplacement "Roi"                //
//                                          [Blanc]                                              //
//===============================================================================================//

//------------------------Mouvement Blanc Checking Echec et match Roi----------------------------//

int RoiBEchecTest(int posRoiX, int posRoiY)
{
	int ok = 0;
	for (int i = 0; i < LONGUEUR; i++)
	{
		for (int j = 0; j < LONGUEUR; j++)
		{
			if (tableDeJeu[i][j] > 0)
			{
				if (tableDeJeu[i][j] == PIECE_NOIR)
				{
					ok = PieceNEchec(j, i, posRoiX, posRoiY);
				}
				if (tableDeJeu[i][j] == TOUR_NOIR)
				{
					ok = TourNEchec(j, i, posRoiX, posRoiY);
				}
				if (tableDeJeu[i][j] == TOUR_NOIR)
				{
					ok = TourNEchec(j, i, posRoiX, posRoiY);
				}
				if (tableDeJeu[i][j] == FOU_NOIR)
				{
					ok = FouNEchec(j, i, posRoiX, posRoiY);
				}
				if (tableDeJeu[i][j] == REINE_NOIR)
				{
					ok = ReineNEchec(j, i, posRoiX, posRoiY);
				}
				if (tableDeJeu[i][j] == ROI_NOIR)
				{
					ok = RoiNEchec(j, i, posRoiX, posRoiY);
				}
				if (ok == 1)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

//-----------------------------------Mouvement Roi Blanc----------------------------------------//

int RoiB(int ancienX, int ancienY, int nouveauX, int nouveauY)
{
	if (ancienX - 1 >= 0 && ancienY - 1 >= 0 && nouveauY == ancienY - 1 && nouveauX == ancienX - 1 && tableDeJeu[nouveauY][nouveauX] >= 0)
	{
		int ok = RoiBEchecTest(ancienX - 1, ancienY - 1);
		if (ok == 1)
		{
			return 0;  // Gauche haut
		}
	}
	if (ancienY - 1 >= 0 && nouveauX == ancienX && nouveauY == ancienY - 1 && tableDeJeu[nouveauY][nouveauX] >= 0)
	{
		int ok = RoiBEchecTest(ancienX, ancienY - 1);
		if (ok == 1)
		{
			return 0; // haut
		}
	}
	if (ancienY - 1 >= 0 && ancienX + 1 < LONGUEUR && nouveauX == ancienX + 1 && nouveauY == ancienY - 1 && tableDeJeu[nouveauY][nouveauX] >= 0)
	{
		int ok = RoiBEchecTest(ancienX + 1, ancienY - 1);
		if (ok == 1)
		{
			return 0; // Droit haut
		}
	}
	if (ancienX + 1 < LONGUEUR && nouveauY == ancienY && nouveauX == ancienX + 1 && tableDeJeu[nouveauY][nouveauX] >= 0)
	{
		int ok = RoiBEchecTest(ancienX + 1, ancienY);
		if (ok == 1)
		{
			return 0; // Droit
		}
	}
	if (ancienX + 1 < LONGUEUR && ancienY + 1 < LONGUEUR && nouveauY == ancienY + 1 && nouveauX == ancienX + 1 && tableDeJeu[nouveauY][nouveauX] >= 0)
	{
		int ok = RoiBEchecTest(ancienX + 1, ancienY + 1);
		if (ok == 1)
		{
			return 0; // Droit bas
		}
	}
	if (ancienY + 1 < LONGUEUR && nouveauY == ancienY + 1 && nouveauX == ancienX && tableDeJeu[nouveauY][nouveauX] >= 0)
	{
		int ok = RoiBEchecTest(ancienX, ancienY + 1);
		if (ok == 1)
		{
			return 0; // bas
		}
	}
	if (ancienX - 1 >= 0 && ancienY + 1 < LONGUEUR && nouveauX == ancienX - 1 && nouveauY == ancienY + 1 && tableDeJeu[nouveauY][nouveauX] >= 0)
	{
		int ok = RoiBEchecTest(ancienX - 1, ancienY + 1);
		if (ok == 1)
		{
			return 0; // Gauche bas
		}
	}
	if (ancienX - 1 >= 0 && nouveauY == ancienY && nouveauX == ancienX - 1 && tableDeJeu[nouveauY][nouveauX] >= 0)
	{
		int ok = RoiBEchecTest(ancienX - 1, ancienY);
		if (ok == 1)
		{
			return 0; // Gauche
		}
	}
	// Tourner à Droit
	if (RoiBlancPremierMouv == 0 && mouvDroitTourBlanc == 0 && tableDeJeu[7][5] == 0 && tableDeJeu[7][6] == 0 && nouveauY==7 && nouveauX==6)
	{
		int ok = 1;
		ok = RoiBEchecTest(4, 7);
		if (ok == 1)
		{
			ok = RoiBEchecTest(5, 7);
			if (ok == 1)
			{
				ok = RoiBEchecTest(6, 7);
				if (ok == 1)
				{
					tableDeJeu[7][7] = 0;
					tableDeJeu[7][5] = TOUR_BLANC;
					RoiBlancPremierMouv = 1;
					mouvDroitTourBlanc = 1;
					return 0;
				}
			}
		}
	}
	// Tourner à Gauche
	if (RoiBlancPremierMouv == 0 && mouvDroitTourBlanc == 0 && tableDeJeu[7][3] == 0 && tableDeJeu[7][2] == 0 && tableDeJeu[7][1] == 0 && nouveauY == 7 && nouveauX == 2)
	{
		int ok = 1;
		ok = RoiBEchecTest(4, 7);
		if (ok == 1)
		{
			ok = RoiBEchecTest(3, 7);
			if (ok == 1)
			{
				ok = RoiBEchecTest(2, 7);
				if (ok == 1)
				{
					ok = RoiBEchecTest(1, 7);
					if (ok == 1)
					{
						tableDeJeu[7][0] = 0;
						tableDeJeu[7][3] = TOUR_BLANC;
						RoiBlancPremierMouv = 1;
						mouvGaucheTourBlanc = 1;
						return 0;
					}
				}
			}
		}
	}
	return 1;
}


//===============================================================================================//
//                Test Mouvement Checking Echeque et match plus Deplacement Roi                  //
//                                          [Noir]                                               //
//===============================================================================================//

//------------------------Mouvement Noir Checking Echec et match Roi----------------------------//

int RoiNEchecTest(int posRoiX, int posRoiY)
{
	int ok = 0;
	for (int i = 0; i < LONGUEUR; i++)
	{
		for (int j = 0; j < LONGUEUR; j++)
		{
			if (tableDeJeu[i][j] < 0)
			{
				if (tableDeJeu[i][j] == PIECE_BLANC)
				{
					ok=PieceBEchec(j, i, posRoiX, posRoiY);
				}
				if (tableDeJeu[i][j] == TOUR_BLANC)
				{
					ok=TourBEchec(j, i, posRoiX, posRoiY);
				}
				if (tableDeJeu[i][j] == CHEVAL_BLANC)
				{
					ok=ChevalBEchec(j, i, posRoiX, posRoiY);
				}
				if (tableDeJeu[i][j] == FOU_BLANC)
				{
					ok=FouBEchec(j, i, posRoiX, posRoiY);
				}
				if (tableDeJeu[i][j] == REINE_BLANC)
				{
					ok=ReineBEchec(j, i, posRoiX, posRoiY);
				}
				if (tableDeJeu[i][j] == ROI_BLANC)
				{
					ok=RoiBEchec(j, i, posRoiX, posRoiY);
				}
				if (ok == 1)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

//-----------------------------------Mouvement Roi Noir----------------------------------------//

int RoiN(int ancienX, int ancienY, int nouveauX, int nouveauY)
{
	if (ancienX - 1 >= 0 && ancienY - 1 >= 0 && nouveauY == ancienY - 1 && nouveauX == ancienX - 1 && tableDeJeu[nouveauY][nouveauX] <= 0)
	{
		int ok = RoiNEchecTest(ancienX - 1, ancienY - 1);
		if (ok == 1)
		{
			return 0;  // Gauche haut
		}
	}
	if (ancienY - 1 >= 0 && nouveauX == ancienX && nouveauY == ancienY-1 && tableDeJeu[nouveauY][nouveauX] <= 0)
	{
		int ok = RoiNEchecTest(ancienX, ancienY-1);
		if (ok == 1)
		{
			return 0; // haut
		}
	}
	if (ancienY - 1 >= 0 && ancienX + 1 < LONGUEUR && nouveauX == ancienX + 1 && nouveauY == ancienY - 1 && tableDeJeu[nouveauY][nouveauX] <= 0)
	{
		int ok = RoiNEchecTest(ancienX+ 1, ancienY- 1);
		if (ok == 1)
		{
			return 0; // Droit haut
		}
	}
	if (ancienX + 1 < LONGUEUR && nouveauY == ancienY && nouveauX == ancienX+1 && tableDeJeu[nouveauY][nouveauX] <= 0)
	{
		int ok = RoiNEchecTest(ancienX+1, ancienY);
		if (ok == 1)
		{
			return 0; // Droit
		}
	}
	if (ancienX + 1 < LONGUEUR && ancienY + 1 < LONGUEUR && nouveauY == ancienY + 1 && nouveauX == ancienX + 1 && tableDeJeu[nouveauY][nouveauX] <= 0)
	{
		int ok = RoiNEchecTest(ancienX + 1, ancienY + 1);
		if (ok == 1)
		{
			return 0; // Droit bas
		}
	}
	if (ancienY + 1 < LONGUEUR && nouveauY == ancienY+1 && nouveauX == ancienX && tableDeJeu[nouveauY][nouveauX] <= 0)
	{
		int ok = RoiNEchecTest(ancienX, ancienY+1);
		if (ok == 1)
		{
			return 0; // bas
		}
	}
	if (ancienX - 1 >=0 && ancienY + 1 <LONGUEUR && nouveauX == ancienX - 1 && nouveauY == ancienY + 1 && tableDeJeu[nouveauY][nouveauX] <= 0)
	{
		int ok = RoiNEchecTest(ancienX-1, ancienY+ 1);
		if (ok == 1)
		{
			return 0; // Gauche bas
		}
	}
	if (ancienX - 1 >= 0 && nouveauY == ancienY && nouveauX == ancienX-1 && tableDeJeu[nouveauY][nouveauX] <= 0)
	{
		int ok = RoiNEchecTest(ancienX-1, ancienY);
		if (ok == 1)
		{
			return 0; // Gauche
		}
	}
	// Tourner à Droit
	if (RoiBlancPremierMouv==0 && ROI_NOIR==0 && tableDeJeu[0][5]==0 && tableDeJeu[0][6]==0 && nouveauY==0 && nouveauX==6)
	{
		int ok = RoiNEchecTest(4, 0);
		if (ok == 1)
		{
			ok = RoiNEchecTest(5, 0);
			if (ok == 1)
			{
				ok = RoiNEchecTest(6, 0);
				if (ok == 1)
				{
					RoiNoirPremierMouv = 1;
					RoiBlancPremierMouv = 1;
					tableDeJeu[0][7] = 0;
					tableDeJeu[0][5] = TOUR_NOIR;
					return 0;
				}
			}
		}
	}
	if (RoiBlancPremierMouv == 0 && ROI_NOIR == 0 && tableDeJeu[0][3] == 0 && tableDeJeu[0][2] == 0 && tableDeJeu[0][1] == 0 && nouveauY == 0 && nouveauX == 2)
	{
		int ok = RoiNEchecTest(4, 0);
		if (ok == 1)
		{
			ok = RoiNEchecTest(3, 0);
			if (ok == 1)
			{
				ok = RoiNEchecTest(2, 0);
				if (ok == 1)
				{
					ok = RoiNEchecTest(1, 0);
					if (ok == 1)
					{
						RoiNoirPremierMouv = 1;
						RoiBlancPremierMouv = 1;
						tableDeJeu[0][0] = 0;
						tableDeJeu[0][3] = TOUR_NOIR;
						return 0;
					}
				}
			}
		}
	}
	return 1;
}

//===============================================================================================//
//                  Test Mouvement Particulier de Deplacement de la reine                        //
//                                        [Blanc]  + [Noir]                                      //
//===============================================================================================//

//------------------------------------------Mouvement ROI Blanc Echec----------------------------//

void posRoiBlanc()
{
	for (int i = 0; i < LONGUEUR; i++)
	{
		for (int j = 0; j < LONGUEUR; j++)
		{
			if (tableDeJeu[i][j] == ROI_BLANC)
			{
				roi_blanc.x = j;
				roi_blanc.y = i;
				break;
			}
		}
	}
}

//------------------------------------------Mouvement ROI Noir Echec----------------------------//

void posRoiNoir()
{
	for (int i = 0; i < LONGUEUR; i++)
	{
		for (int j = 0; j < LONGUEUR; j++)
		{
			if (tableDeJeu[i][j] == ROI_NOIR)
			{
				roi_noir.y = i;
				roi_noir.x = j;
				break;
			}
		}
	}
}

//===============================================================================================//
//                                   Fonction principale                                         //
//===============================================================================================//

int main(int argc, char const *argv[])
{
    RenderWindow window(VideoMode(800, 800), "Ehiquier by Emmanuel NGBAME");

    Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
    
    // importation des images
    t1.loadFromFile("images/Tableau.png");
    t2.loadFromFile("images/PieceNoir.png");
    t3.loadFromFile("images/PieceBlanc.png");
    t4.loadFromFile("images/TourNoir.png");
    t5.loadFromFile("images/TourBlanc.png");
    t6.loadFromFile("images/ChevalBlanc.png");
    t7.loadFromFile("images/ChevalNoir.png");
    t8.loadFromFile("images/FouNoir.png");
    t9.loadFromFile("images/FouBlanc.png");
    t10.loadFromFile("images/ReineBlanc.png");
    t11.loadFromFile("images/ReineNoir.png");
    t12.loadFromFile("images/RoiNoir.png");
    t13.loadFromFile("images/RoiBlanc.png");
    t14.loadFromFile("images/TransformerBlanc.png");
    t15.loadFromFile("images/TransformerNoir.png");


    // Afficher les images
    Sprite Tableau(t1);
	Sprite PieceNoir(t2);
	Sprite PieceBlanc(t3);
	Sprite TourNoir(t4);
	Sprite TourBlanc(t5);
	Sprite ChevalBlanc(t6);
	Sprite ChevalNoir(t7);
	Sprite FouNoir(t8);
	Sprite FouBlanc(t9);
	Sprite ReineBlanc(t10);
	Sprite ReineNoir(t11);
	Sprite RoiNoir(t12);
	Sprite RoiBlanc(t13);
	Sprite deplacement;
	Sprite BlancTransformation(t14);
	Sprite NoirTransformation(t15);
    Sprite MouveImages;

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

			//On detecte le mouvement CLICK sur un pion
			if (e.type == Event::MouseButtonPressed)
			{
    			if (e.key.code == Mouse::Left)
				{
					//std::cout << "x=" << x << " y=" << y << "\n";
					//std::cout << "pos_x=" << pos.x << " pos_y=" << pos.y << "\n";
					//std::cout << "tableDeJeu[y][x]=" << tableDeJeu[y][x] << "\n";
					//std::cout << "\n";
					if (transformationBlanc	== 1)
					{
						if (pos.y >= transforme_blanc.y * taille && pos.y <= (transforme_blanc.y + 1) * taille && pos.x >= transforme_blanc.x * taille && pos.x <= (transforme_blanc.x + 1) * taille)
						{
							int posX = pos.x % 100, posY = pos.y % 100;
							//std::cout << "pos.y=" << posY << "\n";
							//std::cout << "pos.x=" << posX << "\n";
							if (posX < 50 && posY < 50 && posX > 0 && posY > 0)
							{
								tableDeJeu[transforme_blanc.y][transforme_blanc.x] = TOUR_BLANC;
								transformationBlanc = 0;
							}
							if (posX > 50 && posX < 100 && posY < 50 && posY > 0)
							{
								tableDeJeu[transforme_blanc.y][transforme_blanc.x] = REINE_BLANC;
								transformationBlanc = 0;
							}
							if (posX > 50 && posX < 100 && posY>50 && posY < 100)
							{
								tableDeJeu[transforme_blanc.y][transforme_blanc.x] = CHEVAL_BLANC;
								transformationBlanc = 0;
							}
							if (posX < 50 && posX>0 && posY > 50 && y < 100)
							{
								tableDeJeu[transforme_blanc.y][transforme_blanc.x] = FOU_BLANC;
								transformationBlanc = 0;
							}
							if (transformationBlanc == 0)
							{
								posRoiNoir();
								int h = RoiNEchecTest(roi_noir.x, roi_noir.y);
								if (h == 0)
								{
									testNoir = 1;
								}
							}
						}
					}
					if (transformationNoir	== 1)
					{
						if (pos.y >= transforme_noir.y * taille && pos.y <= (transforme_noir.y + 1) * taille && pos.x >= transforme_noir.x * taille && pos.x <= (transforme_noir.x + 1) * taille)
						{
							int posX = pos.x % 100, posY = pos.y % 100;
							//std::cout << "pos.y=" << posY << "\n";
							//std::cout << "pos.x=" << posX << "\n";
							if (posX < 50 && posY < 50 && posX > 0 && posY > 0)
							{
								tableDeJeu[transforme_noir.y][transforme_noir.x] = TOUR_NOIR;
								transformationNoir = 0;
							}
							if (posX > 50 && posX < 100 && posY < 50 && posY > 0)
							{
								tableDeJeu[transforme_noir.y][transforme_noir.x] = REINE_NOIR;
								transformationNoir = 0;
							}
							if (posX > 50 && posX < 100 && posY>50 && posY < 100)
							{
								tableDeJeu[transforme_noir.y][transforme_noir.x] = CHEVAL_NOIR;
								transformationNoir = 0;
							}
							if (posX < 50 && posX>0 && posY > 50 && y < 100)
							{
								tableDeJeu[transforme_noir.y][transforme_noir.x] = FOU_NOIR;
								transformationNoir = 0;
							}
							if (transformationNoir == 0)
							{
								posRoiBlanc();
								int h = RoiBEchecTest(roi_blanc.x, roi_blanc.y);
								if (h == 0)
								{
									testBlanc = 1;
								}
							}
						}
					}
					// On traite cas par cas selon le mouvement choisi
					if (e.key.code == Mouse::Left)
					{
						// Transformation
						//
						if(tableDeJeu[y][x] != 0)
						{
							dx = pos.x - (x * taille);
							dy = pos.y - (y * taille);
						
							if(tableDeJeu[y][x] == PIECE_BLANC && mouvement == 1) // Si mouvement pion piece BLANC
							{
								pasMouvPiece        = PIECE_BLANC; // Alors pion piece BLANC ne bouge pas
								MouveImages         = PieceBlanc; // Le mouvement va au pion piece blanc
								tableDeJeu[y][x]    = 0;  // Initialiser la case vide
							}
							if(tableDeJeu[y][x] == PIECE_NOIR && mouvement == 0) // Si mouvement pion piece NOIR
							{
								pasMouvPiece        = PIECE_NOIR; // Alors pion piece NOIR ne bouge pas
								MouveImages         = PieceNoir; // Le mouvement va au pion piece NOIR
								tableDeJeu[y][x]    = 0;  // Initialiser la case vide
							}
							if(tableDeJeu[y][x] == CHEVAL_NOIR && mouvement == 0) // Si mouvement pion cheval Noir
							{
								pasMouvPiece        = CHEVAL_NOIR; // Alors pion cheval noir ne bouge pas
								MouveImages         = ChevalNoir; // Le mouvement va au pion cheval blanc
								tableDeJeu[y][x]    = 0;  // Initialiser la case vide
							}
							if(tableDeJeu[y][x] == CHEVAL_BLANC && mouvement == 1) // Si mouvement pion cheval BLANC
							{
								pasMouvPiece        = CHEVAL_BLANC; // Alors pion cheval BLANC ne bouge pas
								MouveImages         = ChevalBlanc; // Le mouvement va au pion cheval blanc
								tableDeJeu[y][x]    = 0;  // Initialiser la case vide
							}
							if(tableDeJeu[y][x] == TOUR_BLANC && mouvement == 1) // Si mouvement pion tour BLANC
							{
								pasMouvPiece        = TOUR_BLANC; // Alors pion tour BLANC ne bouge pas
								MouveImages         = TourBlanc; // Le mouvement va au pion tour blanc
								tableDeJeu[y][x]    = 0;  // Initialiser la case vide
							}
							if(tableDeJeu[y][x] == TOUR_NOIR && mouvement == 0) // Si mouvement pion tour NOIR
							{
								pasMouvPiece        = TOUR_NOIR; // Alors pion tour NOIR ne bouge pas
								MouveImages         = TourNoir; // Le mouvement va au pion tour NOIR
								tableDeJeu[y][x]    = 0;  // Initialiser la case vide
							}
							if(tableDeJeu[y][x] == FOU_BLANC && mouvement == 1) // Si mouvement pion boutique NOIR
							{
								pasMouvPiece        = FOU_BLANC; // Alors pion boutique NOIR ne bouge pas
								MouveImages         = FouBlanc; // Le mouvement va au pion Fou NOIR
								tableDeJeu[y][x]    = 0;  // Initialiser la case vide
							}
							if(tableDeJeu[y][x] == FOU_NOIR && mouvement == 0) // Si mouvement pion Fou NOIR
							{
								pasMouvPiece        = FOU_NOIR; // Alors pion Fou NOIR ne bouge pas
								MouveImages         = FouNoir; // Le mouvement va au pion Fou NOIR
								tableDeJeu[y][x]    = 0;  // Initialiser la case vide
							}
							if(tableDeJeu[y][x] == REINE_BLANC && mouvement == 1) // Si mouvement pion REINE BLANC
							{
								pasMouvPiece        = REINE_BLANC; // Alors pion REINE BLANC ne bouge pas
								MouveImages         = ReineBlanc; // Le mouvement va au pion REINE BLANC
								tableDeJeu[y][x]    = 0;  // Initialiser la case vide
							}
							if(tableDeJeu[y][x] == REINE_NOIR && mouvement == 0) // Si mouvement pion REINE NOIR
							{
								pasMouvPiece        = REINE_NOIR; // Alors pion REINE NOIR ne bouge pas
								MouveImages         = ReineNoir; // Le mouvement va au pion REINE NOIR
								tableDeJeu[y][x]    = 0;  // Initialiser la case vide
							}
							if(tableDeJeu[y][x] == ROI_BLANC && mouvement == 1) // Si mouvement pion ROI BLANC
							{
								pasMouvPiece        = ROI_BLANC; // Alors pion ROI BLANC ne bouge pas
								MouveImages         = RoiBlanc; // Le mouvement va au pion ROI BLANC
								tableDeJeu[y][x]    = 0;  // Initialiser la case vide
							}
							if(tableDeJeu[y][x] == ROI_NOIR && mouvement == 0) // Si mouvement pion ROI NOIR
							{
								pasMouvPiece        = ROI_NOIR; // Alors pion ROI NOIR ne bouge pas
								MouveImages         = RoiNoir; // Le mouvement va au pion ROI NOIR
								tableDeJeu[y][x]    = 0;  // Initialiser la case vide
							}
							if (tableDeJeu[y][x] == 0)
							{
								ca_bouge        = 1;
								ancienne_Pos.x  = x;
								ancienne_Pos.y  = y;
							}                      
						}
					}	
				}
			}
			
			//On detecte le mouvement DECLICK sur un pion			
			if (e.type == Event::MouseButtonReleased)
			{
				if (e.key.code == Mouse::Left)
				{
					int ok=2;
					if (pasMouvPiece == PIECE_BLANC && ca_bouge==1)
					{
							ok = PieceB(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == PIECE_NOIR && ca_bouge == 1)
					{
						ok = PieceN(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == TOUR_BLANC && ca_bouge == 1)
					{
						ok = TourB(ancienne_Pos.x, ancienne_Pos.y, x, y);
						if (ok == 1 && mouvGaucheTourBlanc==0 && ancienne_Pos.y == 7 && ancienne_Pos.x == 0)
						{
							mouvGaucheTourBlanc = 1;
							//std::cout << mouvGaucheTourBlanc << "\n";
						}
						if (ok == 1 && mouvDroitTourBlanc==0 && ancienne_Pos.y == 7 && ancienne_Pos.x == 7)
						{
							mouvDroitTourBlanc = 1;
							//std::cout << mouvDroitTourBlanc << "\n";
						}
					}
					if (pasMouvPiece == TOUR_NOIR && ca_bouge == 1)
					{
						ok=TourN(ancienne_Pos.x, ancienne_Pos.y, x, y);
						if (ok == 1 && mouvDroitTourNoir == 0 && ancienne_Pos.y == 0 && ancienne_Pos.x == 7)
						{
							mouvDroitTourNoir = 1;
							//std::cout << mouvDroitTourNoir<< "\n";
						}
						if (ok == 1 && mouvGaucheTourNoir == 0 && ancienne_Pos.y == 0 && ancienne_Pos.x == 0)
						{
							mouvGaucheTourNoir = 1;
							//std::cout << mouvGaucheTourNoir << "\n";
						}
					}
					if (pasMouvPiece == FOU_BLANC && ca_bouge == 1)
					{
						ok = FouB(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == FOU_NOIR && ca_bouge == 1)
					{
						ok= FouN(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == REINE_BLANC && ca_bouge == 1)
					{
						ok=ReineB(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == REINE_NOIR && ca_bouge == 1)
					{
						ok=ReineN(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == CHEVAL_BLANC && ca_bouge == 1)
					{
						ok=ChevalB(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == CHEVAL_NOIR && ca_bouge == 1)
					{
						ok = ChevalN(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == ROI_NOIR && ca_bouge == 1)
					{
						ok=RoiN(ancienne_Pos.x, ancienne_Pos.y, x, y);
						if (ok == 1 && RoiNoirPremierMouv == 0)
						{
							RoiNoirPremierMouv = 1;
						//	std::cout << RoiNoirPremierMouv << "\n";
						}
					}
					if (pasMouvPiece == ROI_BLANC && ca_bouge == 1)
					{
						ok=RoiB(ancienne_Pos.x, ancienne_Pos.y, x, y);
						if (ok == 1 && RoiBlancPremierMouv == 0)
						{
							RoiBlancPremierMouv = 1;
							//std::cout << "RoiBlancPremierMouv=" << RoiBlancPremierMouv << "\n";
						}
					}
					if (ok == 1)
					{
						int nr = tableDeJeu[y][x];
						tableDeJeu[y][x] = pasMouvPiece;
						if (y == 0 && pasMouvPiece == PIECE_BLANC)
						{
							transformationBlanc = 1;
							transforme_blanc.x = x;
							transforme_blanc.y = y;
							tableDeJeu[y][x] = 0;
						}
						if (y == 7 && pasMouvPiece == PIECE_NOIR)
						{
							transformationNoir = 1;
							transforme_noir.x = x;
							transforme_noir.y = y;
							tableDeJeu[y][x] = 0;
						}
						if(mouvement==0) // blanc a bougé et noir suit
						{
							if (testBlanc == 1)
							{
								posRoiBlanc();
								int s = RoiBEchecTest(roi_blanc.x, roi_blanc.y);
								if (s == 0)
								{
									tableDeJeu[ancienne_Pos.y][ancienne_Pos.x] = pasMouvPiece;
									tableDeJeu[y][x] = nr;
								}
								else
								{
									testBlanc = 0;
									posRoiNoir();
									int sah = RoiNEchecTest(roi_noir.x,roi_noir.y);
									if (sah == 0)
									{
										testNoir = 1;
									}
									mouvement = 1;
								}
							}
							else
							{
								posRoiBlanc();
								int sa = RoiBEchecTest(roi_blanc.x, roi_blanc.y);
								if (sa == 0)
								{
									tableDeJeu[ancienne_Pos.y][ancienne_Pos.x] = pasMouvPiece;
									tableDeJeu[y][x] = nr;
								}
								else
								{
									posRoiNoir();
									int sah = RoiNEchecTest(roi_noir.x, roi_noir.y);
									if (sah == 0)
									{
										testNoir = 1;
									}
									mouvement = 1;
								}
							}
						}
						else // noir a bougé et blanc suit
						{
							if (testNoir == 1)
							{
								posRoiNoir();
								int s = RoiNEchecTest(roi_noir.x,roi_noir.y);
								if (s == 0)
								{
									tableDeJeu[ancienne_Pos.y][ancienne_Pos.x] = pasMouvPiece;
									tableDeJeu[y][x] = nr;
								}
								else
								{
									testNoir = 0;
									posRoiBlanc();
									int sah = RoiBEchecTest(roi_blanc.x,roi_blanc.y);
									if (sah == 0)
									{
										testBlanc = 1;
									}
									mouvement = 0;
								}
							}
							else
							{
								posRoiNoir();
								int sa = RoiNEchecTest(roi_noir.x, roi_noir.y);
								if (sa == 0)
								{
									tableDeJeu[ancienne_Pos.y][ancienne_Pos.x] = pasMouvPiece;
									tableDeJeu[y][x] = nr;
								}
								else
								{
									posRoiBlanc();
									int sah = RoiBEchecTest(roi_blanc.x, roi_blanc.y);
									if (sah == 0)
									{
										testBlanc = 1;
									}
									mouvement = 0;
								}
							}
						}
					}
					else if(ok==0)
					{
						tableDeJeu[ancienne_Pos.y][ancienne_Pos.x] = pasMouvPiece;
					}
					ca_bouge = 0;
				}
			}

		}
		// Affichage
		window.clear();
		window.draw(Tableau);
        //---------------------------------------------------------

        // Cas particulier de Dame
        if (transformationBlanc == 1)
        {
            BlancTransformation.setPosition(transforme_blanc.x * taille, transforme_blanc.y * taille);
            window.draw(BlancTransformation);
        }
		if (transformationNoir == 1)
        {
            NoirTransformation.setPosition(transforme_noir.x * taille, transforme_noir.y * taille);
            window.draw(NoirTransformation);
        }
        if (ca_bouge == 1)
        {
            deplacement.setPosition(pos.x - dx, pos.y - dy);
            window.draw(deplacement);
        }
        // Cas normal
		// On dessine la table de jeu
        for (int i = 0; i < LONGUEUR; i++)
        {
            for (int j = 0; j < LONGUEUR; j++)
            {
				if (tableDeJeu[i][j] != 0)
                {
                    if(tableDeJeu[i][j] == PIECE_BLANC) // Si mouvement pion piece BLANC
                    {
                        PieceBlanc.setPosition(j * taille, i * taille);
                        window.draw(PieceBlanc);
                    }
                    if(tableDeJeu[i][j] == PIECE_NOIR) // Si mouvement pion piece NOIR
                    {
                        PieceNoir.setPosition(j * taille, i * taille);
                        window.draw(PieceNoir);
                    }
                    if(tableDeJeu[i][j] == CHEVAL_NOIR) // Si mouvement pion cheval Noir
                    {
                        ChevalNoir.setPosition(j * taille, i * taille);
                        window.draw(ChevalNoir);
                    }
                    if(tableDeJeu[i][j] == CHEVAL_BLANC) // Si mouvement pion cheval BLANC
                    {
                        ChevalBlanc.setPosition(j * taille, i * taille);
                        window.draw(ChevalBlanc);
                    }
                    if(tableDeJeu[i][j] == TOUR_BLANC) // Si mouvement pion tour BLANC
                    {
                        TourBlanc.setPosition(j * taille, i * taille);
                        window.draw(TourBlanc);
                    }
                    if(tableDeJeu[i][j] == TOUR_NOIR) // Si mouvement pion tour NOIR
                    {
                        TourNoir.setPosition(j * taille, i * taille);
                        window.draw(TourNoir);
                    }
                    if(tableDeJeu[i][j] == FOU_BLANC) // Si mouvement pion Fou NOIR
                    {
                        FouBlanc.setPosition(j * taille, i * taille);
                        window.draw(FouBlanc);
                    }
                    if(tableDeJeu[i][j] == FOU_NOIR) // Si mouvement pion Fou NOIR
                    {
                        FouNoir.setPosition(j * taille, i * taille);
                        window.draw(FouNoir);
                    }
                    if(tableDeJeu[i][j] == REINE_BLANC) // Si mouvement pion REINE BLANC
                    {
                        ReineBlanc.setPosition(j * taille, i * taille);
                        window.draw(ReineBlanc);
                    }
                    if(tableDeJeu[i][j] == REINE_NOIR) // Si mouvement pion REINE NOIR
                    {
                        ReineNoir.setPosition(j * taille, i * taille);
                        window.draw(ReineNoir);
                    }
                    if(tableDeJeu[i][j] == ROI_BLANC) // Si mouvement pion ROI BLANC
                    {
                        RoiBlanc.setPosition(j * taille, i * taille);
                        window.draw(RoiBlanc);
                    }
                    if(tableDeJeu[i][j] == ROI_NOIR) // Si mouvement pion ROI NOIR
                    {
                        RoiNoir.setPosition(j * taille, i * taille);
                        window.draw(RoiNoir);
                    }
                }
            }
		}
		window.display();
	}
	return EXIT_SUCCESS;
}
