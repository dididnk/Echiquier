#include "Graphique.h"
#include <SFML/Graphics.hpp>
#include <assert.h>


#include <iostream>

using namespace sf;
using namespace std;



//===============================================================================================//
//                                 Test Mouvement Simple                                         //
//                                   [BLANC] + [Noir]                                            //
//===============================================================================================//

//------------------------------------------Mouvement Pièce Blanc----------------------------//

bool PionBlanc(int ax, int ay, int nx, int ny)
{
	if (ancienne_Pos.y == 6)
	{
		if ((ny == ay - 1 && nx == ax && tableDeJeu[ay-1][ax]==0)||
			  (ny==ay-2 && nx==ax && tableDeJeu[ay - 1][ax] == 0 && tableDeJeu[ay - 2][ax]==0))
		{
			return 1;
		}
	}
	else if(ny == ay - 1 && nx == ax && tableDeJeu[ay - 1][ax] == 0)
	{
		return 1;
	}
	if (tableDeJeu[ay - 1][ax - 1] > 0)
	{
		if (ny == ay - 1 && nx == ax - 1)
		{
			return 1;
		}
	}
	if (tableDeJeu[ay - 1][ax + 1] > 0)
	{
		if (ny == ay - 1 && nx == ax + 1)
		{
			return 1;
		}
	}
	return 0;
}

//------------------------------------------Mouvement Pièce Noir----------------------------//

bool PionNoir(int ax, int ay, int nx, int ny)
{
	if (ancienne_Pos.y == 1)
	{
		if ((ny == ay + 1 && nx == ax && tableDeJeu[ay+1][ax]==0) || 
			  (ny == ay + 2 && nx == ax && tableDeJeu[ay + 1][ax] == 0 && tableDeJeu[ay + 2][ax] == 0))
		{
			return 1;
		}
	}
	else if (ny == ay + 1 && nx == ax && tableDeJeu[ay + 1][ax] == 0)
	{
		return 1;
	}
	if (tableDeJeu[ay + 1][ax - 1] < 0)
	{
		if (ny == ay + 1 && nx == ax - 1)
		{
			return 1;
		}
	}
	if (tableDeJeu[ay + 1][ax + 1] < 0)
	{
		if (ny == ay + 1 && nx == ax + 1)
		{
			return 1;
		}
	}
	return 0;
}

//------------------------------------------Mouvement Tour Blanc----------------------------//

bool TourBlanc(int ax, int ay, int nx, int ny)
{
	for (int i = ax-1; i >= 0; i--) // Côté gauche
	{
		if (tableDeJeu[ay][i] >= 0 && (nx == i && ny == ay))
		{
			return 1;
		}
		else if (tableDeJeu[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay - 1; i >= 0; i--) // Côté Haut
	{
		if (tableDeJeu[i][ax] >= 0 && (ny == i && nx == ax))
		{
			return 1;
		}
		else if (tableDeJeu[i][ax] != 0 )
		{
			break;
		}
	}
	for (int i = ax + 1; i < LONGUEUR; i++) // À droite
	{
		if (tableDeJeu[ay][i]>=0 && (ny == ay && nx == i))
		{
			return 1;
		}
		else if (tableDeJeu[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay + 1; i < LONGUEUR; i++) // bas
	{
		if (tableDeJeu[i][ax]>=0 && (ny == i && nx == ax))
		{
			return 1;
		}
		else if (tableDeJeu[i][ax] != 0)
		{
			break;
		}
	}
	return 0;
}

//------------------------------------------Mouvement Tour Noir----------------------------//

bool TourNoir(int ax, int ay, int nx, int ny)
{
	for (int i = ax - 1; i >= 0; i--) // Côté gauche
	{
		if (tableDeJeu[ay][i] <= 0 && (nx == i && ny == ay))
		{
			return 1;
		}
		else if (tableDeJeu[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay - 1; i >= 0; i--) // Côté Haut
	{
		if (tableDeJeu[i][ax] <= 0 && (ny == i && nx == ax))
		{
			return 1;
		}
		else if (tableDeJeu[i][ax] != 0)
		{
			break;
		}
	}
	for (int i = ax + 1; i < LONGUEUR; i++) // À droite
	{
		if (tableDeJeu[ay][i] <= 0 && (ny == ay && nx == i))
		{
			return 1;
		}
		else if (tableDeJeu[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay + 1; i < LONGUEUR; i++) // bas
	{
		if (tableDeJeu[i][ax] <= 0 && (ny == i && nx == ax))
		{
			return 1;
		}
		else if (tableDeJeu[i][ax] != 0)
		{
			break;
		}
	}
	return 0;
}

//------------------------------------------Mouvement Fou Blanc----------------------------//

bool FouBlanc(int ax, int ay, int nx, int ny)
{
	int j = ax - 1;
	for (int i = ay - 1; i >= 0; i--) // Côté gauche haut
	{
		if (tableDeJeu[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay - 1; i >= 0; i--) // À droite haut
	{
		if (tableDeJeu[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ax - 1;
	for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
	{
		if (tableDeJeu[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
	{
		if (tableDeJeu[i][j] >= 0 && (ny == i && nx == j))
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

//------------------------------------------Mouvement Tour Noir----------------------------//

bool FouNoir(int ax, int ay, int nx, int ny)
{
	int j = ax - 1;
	for (int i = ay - 1; i >= 0; i--) // Côté gauche haut
	{
		if (tableDeJeu[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay - 1; i >= 0; i--) // À droite haut
	{
		if (tableDeJeu[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ax - 1;
	for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
	{
		if (tableDeJeu[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
	{
		if (tableDeJeu[i][j] <= 0 && (ny == i && nx == j))
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

bool ReineBlanc(int ax, int ay, int nx, int ny)
{
	for (int i = ax - 1; i >= 0; i--) // Côté gauche
	{
		if (tableDeJeu[ay][i] >= 0 && (nx == i && ny == ay))
		{
			return 1;
		}
		else if (tableDeJeu[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay - 1; i >= 0; i--) // Côté Haut
	{
		if (tableDeJeu[i][ax] >= 0 && (ny == i && nx == ax))
		{
			return 1;
		}
		else if (tableDeJeu[i][ax] != 0)
		{
			break;
		}
	}
	for (int i = ax + 1; i < LONGUEUR; i++) // À droite
	{
		if (tableDeJeu[ay][i] >= 0 && (ny == ay && nx == i))
		{
			return 1;
		}
		else if (tableDeJeu[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay + 1; i < LONGUEUR; i++) // bas
	{
		if (tableDeJeu[i][ax] >= 0 && (ny == i && nx == ax))
		{
			return 1;
		}
		else if (tableDeJeu[i][ax] != 0)
		{
			break;
		}
	}
	int j = ax - 1;
	for (int i = ay - 1; i >= 0; i--) // Côté gauche haut
	{
		if (tableDeJeu[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay - 1; i >= 0; i--) // À droite haut
	{
		if (tableDeJeu[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ax - 1;
	for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
	{
		if (tableDeJeu[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
	{
		if (tableDeJeu[i][j] >= 0 && (ny == i && nx == j))
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

//------------------------------------------Mouvement Tour Noir----------------------------//

bool ReineNoir(int ax, int ay, int nx, int ny)
{
	for (int i = ax - 1; i >= 0; i--) // Côté gauche
	{
		if (tableDeJeu[ay][i] <= 0 && (nx == i && ny == ay))
		{
			return 1;
		}
		else if (tableDeJeu[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay - 1; i >= 0; i--) // Côté Haut
	{
		if (tableDeJeu[i][ax] <= 0 && (ny == i && nx == ax))
		{
			return 1;
		}
		else if (tableDeJeu[i][ax] != 0)
		{
			break;
		}
	}
	for (int i = ax + 1; i < LONGUEUR; i++) // À droite
	{
		if (tableDeJeu[ay][i] <= 0 && (ny == ay && nx == i))
		{
			return 1;
		}
		else if (tableDeJeu[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay + 1; i < LONGUEUR; i++) // bas
	{
		if (tableDeJeu[i][ax] <= 0 && (ny == i && nx == ax))
		{
			return 1;
		}
		else if (tableDeJeu[i][ax] != 0)
		{
			break;
		}
	}
	int j = ax - 1;
	for (int i = ay - 1; i >= 0; i--) // Côté gauche haut
	{
		if (tableDeJeu[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay - 1; i >= 0; i--) // À droite haut
	{
		if (tableDeJeu[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ax - 1;
	for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
	{
		if (tableDeJeu[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
	{
		if (tableDeJeu[i][j] <= 0 && (ny == i && nx == j))
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

bool ChevalBlanc(int ax, int ay, int nx, int ny)
{
	if (ay - 2 >= 0 && ax - 1 >= 0 && ny == ay - 2 && nx == ax - 1 && tableDeJeu[ny][nx] >= 0)
	{
		return 1; // Haut gauche
	}
	if (ay - 2 >= 0 && ax + 1 <LONGUEUR && ny == ay - 2 && nx == ax + 1 && tableDeJeu[ny][nx] >= 0)
	{
		return 1; // Haut droit
	}
	if (ay - 1 >= 0 && ax + 2 < LONGUEUR && ny==ay-1 && nx==ax+2 && tableDeJeu[ny][nx]>=0)
	{
		return 1; // droit 1
	}
	if (ay + 1 >= 0 && ax + 2 < LONGUEUR && ny == ay + 1 && nx == ax + 2 && tableDeJeu[ny][nx] >= 0)
	{
		return 1; // droit 2
	}
	if (ay+2<LONGUEUR && ax+1<LONGUEUR && ny==ay+2 && nx==ax+1 && tableDeJeu[ny][nx]>=0)
	{
		return 1; // bas 1
	}
	if (ay + 2 < LONGUEUR && ax - 1 >= 0 && ny == ay + 2 && nx == ax - 1 && tableDeJeu[ny][nx] >= 0)
	{
		return 1; // bas 2
	}
	if (ay+1<LONGUEUR && ax-2>=0 && ny==ay+1 && nx==ax-2 && tableDeJeu[ny][nx]>=0 )
	{
		return 1; // gauche 1
	}
	if (ay - 1 >= 0 && ax - 2 >= 0 && ny == ay - 1 && nx == ax - 2 && tableDeJeu[ny][nx] >= 0)
	{
		return 1;
	}
	return 0;
}

//------------------------------------------Mouvement Cheval Noir----------------------------//

bool ChevalNoir(int ax, int ay, int nx, int ny)
{
	if (ay - 2 >= 0 && ax - 1 >= 0 && ny == ay - 2 && nx == ax - 1 && tableDeJeu[ny][nx] <= 0)
	{
		return 1; // Haut gauche
	}
	if (ay - 2 >= 0 && ax + 1 < LONGUEUR && ny == ay - 2 && nx == ax + 1 && tableDeJeu[ny][nx] <= 0)
	{
		return 1; // Haut droit
	}
	if (ay - 1 >= 0 && ax + 2 < LONGUEUR && ny == ay - 1 && nx == ax + 2 && tableDeJeu[ny][nx] <= 0)
	{
		return 1; // droit 1
	}
	if (ay + 1 >= 0 && ax + 2 < LONGUEUR && ny == ay + 1 && nx == ax + 2 && tableDeJeu[ny][nx] <= 0)
	{
		return 1; // droit 2
	}
	if (ay + 2 < LONGUEUR && ax + 1 < LONGUEUR && ny == ay + 2 && nx == ax + 1 && tableDeJeu[ny][nx] <= 0)
	{
		return 1; // bas 1
	}
	if (ay + 2 < LONGUEUR && ax - 1 >= 0 && ny == ay + 2 && nx == ax - 1 && tableDeJeu[ny][nx] <= 0)
	{
		return 1; // bas 2
	}
	if (ay + 1 < LONGUEUR && ax - 2 >= 0 && ny == ay + 1 && nx == ax - 2 && tableDeJeu[ny][nx] <= 0)
	{
		return 1; // gauche 1
	}
	if (ay - 1 >= 0 && ax - 2 >= 0 && ny == ay - 1 && nx == ax - 2 && tableDeJeu[ny][nx] <= 0)
	{
		return 1;
	}
	return 0;
}

//===============================================================================================//
//                                 Test Mouvement Echec et match                               //
//                                             [BLANC]                                           //
//===============================================================================================//

//------------------------------------------Mouvement Piece Blanc Echec----------------------------//

bool PionBlancEchec(int posx, int posy, int roiX, int roiY)
{
	if (tableDeJeu[posy - 1][posx - 1] >= 0)
	{
		if (posy-1 == roiY && posx - 1 == roiX)
		{
			return 1;
		}
	}
	if (tableDeJeu[posy - 1][posx + 1] >= 0)
	{
		if (posy - 1 == roiY && posx + 1==roiX)
		{
			return 1;
		}
	}
	return 0;
}

//------------------------------------------Mouvement Tour Blanc Echec----------------------------//

bool TourBlancEchec(int ax, int ay, int roiX, int roiY)
{
	for (int i = ax - 1; i >= 0; i--) // Côté gauche
	{
		if (tableDeJeu[ay][i] >= 0 && (roiX== i && roiY == ay))
		{
			return 1;
		}
		else if(tableDeJeu[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay - 1; i >= 0; i--) // Côté Haut
	{
		if (tableDeJeu[i][ax] >= 0 && (roiY == i && roiX == ax))
		{
			return 1;
		}
		else if(tableDeJeu[i][ax] != 0)
		{
			break;
		}
	}
	for (int i = ax + 1; i < LONGUEUR; i++) // À droite
	{
		if (tableDeJeu[ay][i] >= 0 && (roiY == ay && roiX == i))
		{
			return 1;
		}
		else if(tableDeJeu[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay + 1; i <LONGUEUR; i++) // bas
	{
		if (tableDeJeu[i][ax] >= 0 && (roiY == i && roiX == ax))
		{
			return 1;
		}
		else if(tableDeJeu[i][ax] != 0)
		{
			break;
		}
	}
	return 0;
}

//------------------------------------------Mouvement Fou Blanc Echec----------------------------//

bool FouBlancEchec(int ax, int ay, int roiX, int roiY)
{
	int j = ax - 1;
	for (int i = ay - 1; i >= 0; i--) // Côté gauche haut
	{
		if (tableDeJeu[i][j] >= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if(tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay - 1; i >= 0; i--) // À droite haut
	{
		if (tableDeJeu[i][j] >= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if(tableDeJeu[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ax - 1;
	for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
	{
		if (tableDeJeu[i][j] >= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
	{
		if (tableDeJeu[i][j] >= 0 && (roiY == i && roiX == j))
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

//------------------------------------------Mouvement Reine Blanc Echec----------------------------//

bool ReineBlancEchec(int ax, int ay, int roiX, int roiY)
{
	for (int i = ax - 1; i >= 0; i--) // Côté gauche
	{
		if (tableDeJeu[ay][i] >= 0 && (roiX == i && roiY == ay))
		{
			return 1;
		}
		else if(tableDeJeu[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay - 1; i >= 0; i--) // Côté Haut
	{
		if (tableDeJeu[i][ax] >= 0 && (roiY == i && roiX == ax))
		{
			return 1;
		}
		else if(tableDeJeu[i][ax] != 0)
		{
			break;
		}
	}
	for (int i = ax + 1; i < LONGUEUR; i++) // À droite
	{
		if (tableDeJeu[ay][i] >= 0 && (roiY == ay && roiX == i))
		{
			return 1;
		}
		else if (tableDeJeu[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay + 1; i <LONGUEUR; i++) // bas
	{
		if (tableDeJeu[i][ax] >= 0 && (roiY == i && roiX == ax))
		{
			return 1;
		}
		else if(tableDeJeu[i][ax] != 0)
		{
			break;
		}
	}
	int j = ax - 1;
	for (int i = ay - 1; i >= 0; i--) // Côté gauche haut
	{
		if (tableDeJeu[i][j] >= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if(tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay - 1; i >= 0; i--) // À droite haut
	{
		if (tableDeJeu[i][j] >= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ax - 1;
	for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
	{
		if (tableDeJeu[i][j] >= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if(tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
	{
		if (tableDeJeu[i][j] >= 0 && (roiY == i && roiX == j))
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

//------------------------------------------Mouvement Cheval Blanc Echec----------------------------//

bool ChevalBlancEchec(int ax, int ay, int roiX, int roiY)
{
	if (ay - 2 >= 0 && ax - 1 >= 0 && roiY == ay - 2 && roiX == ax - 1 && tableDeJeu[roiY][roiX] >= 0)
	{
		return 1; // Haut gauche
	}
	if (ay - 2 >= 0 && ax + 1 < LONGUEUR && roiY == ay - 2 && roiX == ax + 1 && tableDeJeu[roiY][roiX] >= 0)
	{
		return 1; // Haut droit
	}
	if (ay - 1 >= 0 && ax + 2 < LONGUEUR && roiY == ay - 1 && roiX == ax + 2 && tableDeJeu[roiY][roiX] >= 0)
	{
		return 1; // droit 1
	}
	if (ay + 1 >= 0 && ax + 2 < LONGUEUR && roiY == ay + 1 && roiX == ax + 2 && tableDeJeu[roiY][roiX] >= 0)
	{
		return 1; // droit 2
	}
	if (ay + 2 < LONGUEUR && ax + 1 < LONGUEUR && roiY == ay + 2 && roiX == ax + 1 && tableDeJeu[roiY][roiX] >= 0)
	{
		return 1; // bas 1
	}
	if (ay + 2 < LONGUEUR && ax - 1 >= 0 && roiY == ay + 2 && roiX == ax - 1 && tableDeJeu[roiY][roiX] >= 0)
	{
		return 1; // bas 2
	}
	if (ay + 1 < LONGUEUR && ax - 2 >= 0 && roiY == ay + 1 && roiX == ax - 2 && tableDeJeu[roiY][roiX] >= 0)
	{
		return 1; // gauche 1
	}
	if (ay - 1 >= 0 && ax - 2 >= 0 && roiY == ay - 1 && roiX == ax - 2 && tableDeJeu[roiY][roiX] >= 0)
	{
		return 1;
	}
	return 0;
}

//------------------------------------------Mouvement Roi Blanc Echec----------------------------//

bool RoiBlancEchec(int ax, int ay, int roiX, int roiY)
{
	if (ax - 1 >= 0 && ay - 1 >= 0 && roiY == ay - 1 && roiX == ax - 1 && tableDeJeu[roiY][roiX] <= 0)
	{
		return 1;
	}
	if (ay - 1 >= 0 && roiX == ax && roiY == ay - 1 && tableDeJeu[roiY][roiX] <= 0)
	{
		return 1;
	}
	if (ay - 1 >= 0 && ax + 1 < LONGUEUR && roiX == ax + 1 && roiY == ay - 1 && tableDeJeu[roiY][roiX] <= 0)
	{
		return 1;
	}
	if (ax + 1 < LONGUEUR && roiY == ay && roiX == ax + 1 && tableDeJeu[roiY][roiX] <= 0)
	{
		return 1;
	}
	if (ax + 1 < LONGUEUR && ay + 1 < LONGUEUR && roiY == ay + 1 && roiX == ax + 1 && tableDeJeu[roiY][roiX] <= 0)
	{
		return 1;
	}
	if (ay + 1 < LONGUEUR && roiY == ay + 1 && roiX == ax && tableDeJeu[roiY][roiX] <= 0)
	{
		return 1;
	}
	if (ax - 1 >= 0 && ay + 1 < LONGUEUR && roiX == ax - 1 && roiY == ay + 1 && tableDeJeu[roiY][roiX] <= 0)
	{
		return 1;
	}
	if (ax - 1 >= 0 && roiY == ay && roiX == ax - 1 && tableDeJeu[roiY][roiX] <= 0)
	{
		return 1;
	}
	return 0;
}

//===============================================================================================//
//                                 Test Mouvement Echec et match                               //
//                                              [NOIR]                                           //
//===============================================================================================//

//------------------------------------------Mouvement Piece Noir Echec--------------------------//

bool PionNoirEchec(int ax, int ay, int roiX, int roiY)
{
	if (tableDeJeu[ay + 1][ax - 1] <= 0)
	{
		if (roiY == ay + 1 && roiX == ax - 1)
		{
			return 1;
		}
	}
	if (tableDeJeu[ay + 1][ax + 1] <= 0)
	{
		if (roiY == ay + 1 && roiX == ax + 1)
		{
			return 1;
		}
	}
	return 0;
}

//------------------------------------------Mouvement Tour Noir Echec--------------------------//

bool TourNoirEchec(int ax, int ay, int roiX, int roiY)
{
	for (int i = ax - 1; i >= 0; i--) // Côté gauche
	{
		if (tableDeJeu[ay][i] <= 0 && (roiX == i && roiY == ay))
		{
			return 1;
		}
		else if (tableDeJeu[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay - 1; i >= 0; i--) // Côté Haut
	{
		if (tableDeJeu[i][ax] <= 0 && (roiY == i && roiX == ax))
		{
			return 1;
		}
		else if (tableDeJeu[i][ax] != 0)
		{
			break;
		}
	}
	for (int i = ax + 1; i < LONGUEUR; i++) // À droite
	{
		if (tableDeJeu[ay][i] <= 0 && (roiY == ay && roiX == i))
		{
			return 1;
		}
		else if (tableDeJeu[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay + 1; i < LONGUEUR; i++) // bas
	{
		if (tableDeJeu[i][ax] <= 0 && (roiY == i && roiX == ax))
		{
			return 1;
		}
		else if (tableDeJeu[i][ax] != 0)
		{
			break;
		}
	}
	return 0;
}

//------------------------------------------Mouvement Fou Noir Echec--------------------------//

bool FouNoirEchec(int ax, int ay, int roiX, int roiY)
{
	int j = ax - 1;
	for (int i = ay - 1; i >= 0; i--) // Côté gauche haut
	{
		if (tableDeJeu[i][j] <= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay - 1; i >= 0; i--) // À droite haut
	{
		if (tableDeJeu[i][j] <= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ax - 1;
	for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
	{
		if (tableDeJeu[i][j] <= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
	{
		if (tableDeJeu[i][j] <= 0 && (roiY == i && roiX == j))
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

//------------------------------------------Mouvement Reine Noir Echec--------------------------//

bool ReineNoirEchec(int ax, int ay, int roiX, int roiY)
{
	for (int i = ax - 1; i >= 0; i--) // Côté gauche
	{
		if (tableDeJeu[ay][i] <= 0 && (roiX == i && roiY == ay))
		{
			return 1;
		}
		else if (tableDeJeu[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay - 1; i >= 0; i--) // Côté Haut
	{
		if (tableDeJeu[i][ax] <= 0 && (roiY == i && roiX == ax))
		{
			return 1;
		}
		else if (tableDeJeu[i][ax] != 0)
		{
			break;
		}
	}
	for (int i = ax + 1; i < LONGUEUR; i++) // À droite
	{
		if (tableDeJeu[ay][i] <= 0 && (roiY == ay && roiX == i))
		{
			return 1;
		}
		else if (tableDeJeu[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay + 1; i < LONGUEUR; i++) // bas
	{
		if (tableDeJeu[i][ax] <= 0 && (roiY == i && roiX == ax))
		{
			return 1;
		}
		else if (tableDeJeu[i][ax] != 0)
		{
			break;
		}
	}
	int j = ax - 1;
	for (int i = ay - 1; i >= 0; i--) // Côté gauche haut
	{
		if (tableDeJeu[i][j] <= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay - 1; i >= 0; i--) // À droite haut
	{
		if (tableDeJeu[i][j] <= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ax - 1;
	for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
	{
		if (tableDeJeu[i][j] <= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if (tableDeJeu[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
	{
		if (tableDeJeu[i][j] <= 0 && (roiY == i && roiX == j))
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

//------------------------------------------Mouvement Cheval Noir Echec--------------------------//

bool ChevalNoirEchec(int ax, int ay, int roiX, int roiY)
{
	if (ay - 2 >= 0 && ax - 1 >= 0 && roiY == ay - 2 && roiX == ax - 1 && tableDeJeu[roiY][roiX] <= 0)
	{
		return 1; // Haut gauche
	}
	if (ay - 2 >= 0 && ax + 1 < LONGUEUR && roiY == ay - 2 && roiX == ax + 1 && tableDeJeu[roiY][roiX] <= 0)
	{
		return 1; // Haut droit
	}
	if (ay - 1 >= 0 && ax + 2 < LONGUEUR && roiY == ay - 1 && roiX == ax + 2 && tableDeJeu[roiY][roiX] <= 0)
	{
		return 1; // droit 1
	}
	if (ay + 1 >= 0 && ax + 2 < LONGUEUR && roiY == ay + 1 && roiX == ax + 2 && tableDeJeu[roiY][roiX] <= 0)
	{
		return 1; // droit 2
	}
	if (ay + 2 < LONGUEUR && ax + 1 < LONGUEUR && roiY == ay + 2 && roiX == ax + 1 && tableDeJeu[roiY][roiX] <= 0)
	{
		return 1; // bas 1
	}
	if (ay + 2 < LONGUEUR && ax - 1 >= 0 && roiY == ay + 2 && roiX == ax - 1 && tableDeJeu[roiY][roiX] <= 0)
	{
		return 1; // bas 2
	}
	if (ay + 1 < LONGUEUR && ax - 2 >= 0 && roiY == ay + 1 && roiX == ax - 2 && tableDeJeu[roiY][roiX] <= 0)
	{
		return 1; // gauche 1
	}
	if (ay - 1 >= 0 && ax - 2 >= 0 && roiY == ay - 1 && roiX == ax - 2 && tableDeJeu[roiY][roiX] <= 0)
	{
		return 1;
	}
	return 0;
}

//------------------------------------------Mouvement Roi Noir Echec--------------------------//

bool RoiNoirEchec(int ax, int ay, int roiX, int roiY)
{
	if (ax - 1 >= 0 && ay - 1 >= 0 && roiY == ay - 1 && roiX == ax - 1 && tableDeJeu[roiY][roiX] >= 0)
	{
		return 1;
	}
	if (ay - 1 >= 0 && roiX == ax && roiY == ay - 1 && tableDeJeu[roiY][roiX] >= 0)
	{
		return 1;
	}
	if (ay - 1 >= 0 && ax + 1 < LONGUEUR && roiX == ax + 1 && roiY == ay - 1 && tableDeJeu[roiY][roiX] >= 0)
	{
		return 1;
	}
	if (ax + 1 < LONGUEUR && roiY == ay && roiX == ax + 1 && tableDeJeu[roiY][roiX] >= 0)
	{
		return 1;
	}
	if (ax + 1 < LONGUEUR && ay + 1 < LONGUEUR && roiY == ay + 1 && roiX == ax + 1 && tableDeJeu[roiY][roiX] >= 0)
	{
		return 1;
	}
	if (ay + 1 < LONGUEUR && roiY == ay + 1 && roiX == ax && tableDeJeu[roiY][roiX] >= 0)
	{
		return 1;
	}
	if (ax - 1 >= 0 && ay + 1 < LONGUEUR && roiX == ax - 1 && roiY == ay + 1 && tableDeJeu[roiY][roiX] >= 0)
	{
		return 1;
	}
	if (ax - 1 >= 0 && roiY == ay && roiX == ax - 1 && tableDeJeu[roiY][roiX] >= 0)
	{
		return 1;
	}
	return 0;
}

//===============================================================================================//
//                Test Mouvement Checking Echec et match plus Deplacement "Roi"                //
//                                          [Noir]                                              //
//===============================================================================================//

//------------------------Mouvement Noir Checking Echec et match Roi----------------------------//

bool RoiNoirEchecTest(int posRoiX, int posRoiY)
{
	int ok = 0;
	for (int i = 0; i < LONGUEUR; i++)
	{
		for (int j = 0; j < LONGUEUR; j++)
		{
			if (tableDeJeu[i][j] < 0)
			{
				if (tableDeJeu[i][j] == PION_BLANC)
				{
					ok=PionBlancEchec(j, i, posRoiX, posRoiY);
				}
				if (tableDeJeu[i][j] == TOUR_BLANC)
				{
					ok=TourBlancEchec(j, i, posRoiX, posRoiY);
				}
				if (tableDeJeu[i][j] == CHEVAL_BLANC)
				{
					ok=ChevalBlancEchec(j, i, posRoiX, posRoiY);
				}
				if (tableDeJeu[i][j] == FOU_BLANC)
				{
					ok=FouBlancEchec(j, i, posRoiX, posRoiY);
				}
				if (tableDeJeu[i][j] == REINE_BLANC)
				{
					ok=ReineBlancEchec(j, i, posRoiX, posRoiY);
				}
				if (tableDeJeu[i][j] == ROI_BLANC)
				{
					ok=RoiBlancEchec(j, i, posRoiX, posRoiY);
				}
				if (ok == 1)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

//-----------------------------------Mouvement Roi Noir----------------------------------------//

bool RoiNoir(int ax, int ay, int nx, int ny)
{
	if (ax - 1 >= 0 && ay - 1 >= 0 && ny == ay - 1 && nx == ax - 1 && tableDeJeu[ny][nx] <= 0)
	{
		int ok = RoiNoirEchecTest(ax - 1, ay - 1);
		if (ok == 1)
		{
			return 1;  // Haut gauche
		}
	}
	if (ay - 1 >= 0 && nx == ax && ny == ay-1 && tableDeJeu[ny][nx] <= 0)
	{
		int ok = RoiNoirEchecTest(ax, ay-1);
		if (ok == 1)
		{
			return 1; // Côté Haut
		}
	}
	if (ay - 1 >= 0 && ax + 1 < LONGUEUR && nx == ax + 1 && ny == ay - 1 && tableDeJeu[ny][nx] <= 0)
	{
		int ok = RoiNoirEchecTest(ax+ 1, ay- 1);
		if (ok == 1)
		{
			return 1; // Haut droit
		}
	}
	if (ax + 1 < LONGUEUR && ny == ay && nx == ax+1 && tableDeJeu[ny][nx] <= 0)
	{
		int ok = RoiNoirEchecTest(ax+1, ay);
		if (ok == 1)
		{
			return 1; // droit
		}
	}
	if (ax + 1 < LONGUEUR && ay + 1 < LONGUEUR && ny == ay + 1 && nx == ax + 1 && tableDeJeu[ny][nx] <= 0)
	{
		int ok = RoiNoirEchecTest(ax + 1, ay + 1);
		if (ok == 1)
		{
			return 1; // droit bas
		}
	}
	if (ay + 1 < LONGUEUR && ny == ay+1 && nx == ax && tableDeJeu[ny][nx] <= 0)
	{
		int ok = RoiNoirEchecTest(ax, ay+1);
		if (ok == 1)
		{
			return 1; // bas
		}
	}
	if (ax - 1 >=0 && ay + 1 <LONGUEUR && nx == ax - 1 && ny == ay + 1 && tableDeJeu[ny][nx] <= 0)
	{
		int ok = RoiNoirEchecTest(ax-1, ay+ 1);
		if (ok == 1)
		{
			return 1; // gauche bas
		}
	}
	if (ax - 1 >= 0 && ny == ay && nx == ax-1 && tableDeJeu[ny][nx] <= 0)
	{
		int ok = RoiNoirEchecTest(ax-1, ay);
		if (ok == 1)
		{
			return 1; // gauche
		}
	}
	// Tourner à Droit
	if (mouvDroitTourNoir==0 && RoiNoirPremierMouv ==0 && tableDeJeu[0][5]==0 && tableDeJeu[0][6]==0 && ny==0 && nx==6)
	{
		int ok = RoiNoirEchecTest(4, 0);
		if (ok == 1)
		{
			ok = RoiNoirEchecTest(5, 0);
			if (ok == 1)
			{
				ok = RoiNoirEchecTest(6, 0);
				if (ok == 1)
				{
					RoiNoirPremierMouv = 1;
					mouvDroitTourNoir = 1;
					tableDeJeu[0][7] = 0;
					tableDeJeu[0][5] = TOUR_NOIR;
					return 1;
				}
			}
		}
	}
	if (mouvGaucheTourNoir == 0 && RoiNoirPremierMouv == 0 && tableDeJeu[0][3] == 0 && tableDeJeu[0][2] == 0 && tableDeJeu[0][1] == 0 && ny == 0 && nx == 2)
	{
		int ok = RoiNoirEchecTest(4, 0);
		if (ok == 1)
		{
			ok = RoiNoirEchecTest(3, 0);
			if (ok == 1)
			{
				ok = RoiNoirEchecTest(2, 0);
				if (ok == 1)
				{
					ok = RoiNoirEchecTest(1, 0);
					if (ok == 1)
					{
						RoiNoirPremierMouv = 1;
						mouvGaucheTourNoir = 1;
						tableDeJeu[0][0] = 0;
						tableDeJeu[0][3] = TOUR_NOIR;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

//===============================================================================================//
//                Test Mouvement Checking Echec et match plus Deplacement "Roi"                //
//                                          [Blanc]                                              //
//===============================================================================================//

//------------------------Mouvement Blanc Testing Echec et match Roi----------------------------//

bool RoiBlancEchecTest(int posRoiX, int posRoiY)
{
	int ok = 0;
	for (int i = 0; i < LONGUEUR; i++)
	{
		for (int j = 0; j < LONGUEUR; j++)
		{
			if (tableDeJeu[i][j] > 0)
			{
				if (tableDeJeu[i][j]  == PION_NOIR)
				{
					ok = PionNoirEchec(j, i, posRoiX, posRoiY);
				}
				if (tableDeJeu[i][j] == TOUR_NOIR)
				{
					ok = TourNoirEchec(j, i, posRoiX, posRoiY);
				}
				if (tableDeJeu[i][j] == CHEVAL_NOIR)
				{
					ok = ChevalNoirEchec(j, i, posRoiX, posRoiY);
				}
				if (tableDeJeu[i][j] == FOU_NOIR)
				{
					ok = FouNoirEchec(j, i, posRoiX, posRoiY);
				}
				if (tableDeJeu[i][j] == REINE_NOIR)
				{
					ok = ReineNoirEchec(j, i, posRoiX, posRoiY);
				}
				if (tableDeJeu[i][j] == ROI_NOIR)
				{
					ok=RoiNoirEchec(j, i, posRoiX, posRoiY);
				}
				if (ok == 1)
				{
					//	std::cout << "da" << "\n";
					return 0;
				}
			}
		}
	}
	return 1;
}

//-----------------------------------Mouvement Roi Blanc----------------------------------------//

bool RoiBlanc(int ax, int ay, int nx, int ny)
{
	if (ax - 1 >= 0 && ay - 1 >= 0 && ny == ay - 1 && nx == ax - 1 && tableDeJeu[ny][nx] >= 0)
	{
		int ok = RoiBlancEchecTest(ax - 1, ay - 1);
		if (ok == 1)
		{
			return 1;  // Haut gauche
		}
	}
	if (ay - 1 >= 0 && nx == ax && ny == ay - 1 && tableDeJeu[ny][nx] >= 0)
	{
		int ok = RoiBlancEchecTest(ax, ay - 1);
		if (ok == 1)
		{
			return 1; // Côté Haut
		}
	}
	if (ay - 1 >= 0 && ax + 1 < LONGUEUR && nx == ax + 1 && ny == ay - 1 && tableDeJeu[ny][nx] >= 0)
	{
		int ok = RoiBlancEchecTest(ax + 1, ay - 1);
		if (ok == 1)
		{
			return 1; // Haut droit
		}
	}
	if (ax + 1 < LONGUEUR && ny == ay && nx == ax + 1 && tableDeJeu[ny][nx] >= 0)
	{
		int ok = RoiBlancEchecTest(ax + 1, ay);
		if (ok == 1)
		{
			return 1; // droit
		}
	}
	if (ax + 1 < LONGUEUR && ay + 1 < LONGUEUR && ny == ay + 1 && nx == ax + 1 && tableDeJeu[ny][nx] >= 0)
	{
		int ok = RoiBlancEchecTest(ax + 1, ay + 1);
		if (ok == 1)
		{
			return 1; // droit bas
		}
	}
	if (ay + 1 < LONGUEUR && ny == ay + 1 && nx == ax && tableDeJeu[ny][nx] >= 0)
	{
		int ok = RoiBlancEchecTest(ax, ay + 1);
		if (ok == 1)
		{
			return 1; // bas
		}
	}
	if (ax - 1 >= 0 && ay + 1 < LONGUEUR && nx == ax - 1 && ny == ay + 1 && tableDeJeu[ny][nx] >= 0)
	{
		int ok = RoiBlancEchecTest(ax - 1, ay + 1);
		if (ok == 1)
		{
			return 1; // gauche bas
		}
	}
	if (ax - 1 >= 0 && ny == ay && nx == ax - 1 && tableDeJeu[ny][nx] >= 0)
	{
		int ok = RoiBlancEchecTest(ax - 1, ay);
		if (ok == 1)
		{
			return 1; // gauche
		}
	}
	// Tourner à Droit
	if (RoiBlancPremierMouv == 0 && mouvDroitTourBlanc == 0 && tableDeJeu[7][5] == 0 && tableDeJeu[7][6] == 0 && ny==7 && nx==6)
	{
		int ok = 1;
		ok = RoiBlancEchecTest(4, 7);
		if (ok == 1)
		{
			ok = RoiBlancEchecTest(5, 7);
			if (ok == 1)
			{
				ok = RoiBlancEchecTest(6, 7);
				if (ok == 1)
				{
					tableDeJeu[7][7] = 0;
					tableDeJeu[7][5] = TOUR_BLANC;
					RoiBlancPremierMouv = 1;
					mouvDroitTourBlanc = 1;
					return 1;
				}
			}
		}
	}
	// Tourner à Gauche
	if (RoiBlancPremierMouv == 0 && mouvDroitTourBlanc == 0 && tableDeJeu[7][3] == 0 && tableDeJeu[7][2] == 0 && tableDeJeu[7][1] == 0 && ny == 7 && nx == 2)
	{
		int ok = 1;
		ok = RoiBlancEchecTest(4, 7);
		if (ok == 1)
		{
			ok = RoiBlancEchecTest(3, 7);
			if (ok == 1)
			{
				ok = RoiBlancEchecTest(2, 7);
				if (ok == 1)
				{
					ok = RoiBlancEchecTest(1, 7);
					if (ok == 1)
					{
						tableDeJeu[7][0] = 0;
						tableDeJeu[7][3] = TOUR_BLANC;
						RoiBlancPremierMouv = 1;
						mouvGaucheTourBlanc = 1;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

//===============================================================================================//
//                  Test Mouvement Particulier de Deplacement de la reine                        //
//                                        [Blanc]  + [Noir]                                      //
//===============================================================================================//

//------------------------------------------Mouvement ROI Blanc Position----------------------------//

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

//------------------------------------------Mouvement ROI Noir Position----------------------------//

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

Roi::Roi( bool white ) : Piece( 5, white ? 1 : 8, white )
{
    // cout << "Constructeur Roi" << endl;
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

// Roi::setImg(String chemin)
// {
//    // importation des images
//     t1.loadFromFile("images/Tableau.png");
//     t2.loadFromFile("images/PieceNoir.png");
//     t3.loadFromFile("images/PieceBlanc.png");
//     t4.loadFromFile("images/TourNoir.png");
//     t5.loadFromFile("images/TourBlanc.png");
//     t6.loadFromFile("images/ChevalBlanc.png");
//     t7.loadFromFile("images/ChevalNoir.png");
//     t8.loadFromFile("images/FouNoir.png");
//     t9.loadFromFile("images/FouBlanc.png");
//     t10.loadFromFile("images/ReineBlanc.png");
//     t11.loadFromFile("images/ReineNoir.png");
//     t12.loadFromFile("images/RoiNoir.png");
//     t13.loadFromFile("images/RoiBlanc.png");
//     t14.loadFromFile("images/TransformerBlanc.png");
//     t15.loadFromFile("images/TransformerNoir.png");

// 	// Afficher les images
// 	Sprite imgTableau(t1);
// 	Sprite imgPionNoir(t2);
// 	Sprite imgPionBlanc(t3);
// 	Sprite imgTourNoir(t4);
// 	Sprite imgTourBlanc(t5);
// 	Sprite imgChevalBlanc(t6);
// 	Sprite imgChevalNoir(t7);
// 	Sprite imgFouNoir(t8);
// 	Sprite imgFouBlanc(t9);
// 	Sprite imgReineBlanc(t10);
// 	Sprite imgReineNoir(t11);
// 	Sprite imgRoiNoir(t12);
// 	Sprite imgRoiBlanc(t13);
// 	Sprite Deplacement;
// 	Sprite BlancTransformation(t14);
// 	Sprite NoirTransformation(t15); 
// }
void
Roi::roque()
{
    cout << "Roque Roi" << endl;
}

Reine::Reine( bool white )
    : Piece( 4, white ? 1 : 8, white ), Fou( white, true ), Tour( white, true )
{
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

Tour::Tour( bool white, bool gauche ) : Piece( gauche ? 1 : 8, white ? 1 : 8, white )
{
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

Fou::Fou( bool white, bool gauche ) : Piece( gauche ? 3 : 6, white ? 1 : 8, white )
{
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

Cavalier::Cavalier( bool white, bool gauche ) : Piece( gauche ? 2 : 7, white ? 1 : 8, white )
{
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

Pion::Pion( bool white, int x ) : Piece( x, white ? 2 : 7, white )
{
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
        
        for (int i = 0; i < LONGUEUR; i++)
        {
            for (int j = 0; j < LONGUEUR; j++)
            {
                // On place les piions noirs en premiers
                if ((j == 0 && i == 0) || (j == 0 && i == 7))
                {
                    imgTourNoir.setPosition(i * taille, j * taille);
                    bool tst = imgChevalNoir.getTexture() == imgChevalNoir.getTexture();
                    cout << tst << endl;
                    window.draw(imgTourNoir);
                }
                if ((j == 0 && i == 1) || (j == 0 && i == 6))
                {
                    imgChevalNoir.setPosition(i * taille, j * taille);
                    window.draw(imgChevalNoir);
                }
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
    // for ( int i = 0; i < 16; i++ )
    //     delete m_pieces[i];
    // cout << "Destructeur Joueur" << endl;
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

    // for (int i = 0; i < LONGUEUR; i++)
    // {
    //     for (int j = 0; j < LONGUEUR; j++)
    //     {
    //         m_pieces[i][j]->affiche();
    //     }
    // }    
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
    for ( int i = 1; i <= 8; i++ ) {
        Pion *ptr     = new Pion( true, i );
        m_pieces[p++] = ptr;
    }
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
JoueurBlanc::isWhite()
{
    return true;
}

bool
JoueurNoir::isWhite()
{
    return false;
}

//################################################ PROG ############################################

int main(int argc, char const *argv[])
{

	Echiquier e; // on créer la table de jeu
    e.affiche(); // on test par un affichage

    JoueurNoir JoueurNr; // on créer un joueur noir (avec pions noires)

    //assert( JoueurNr.placerPieces( e ) ); // On place toutes les pions noirs sur la table
    //cout << JoueurNr.placerPieces( e ) << endl;
    e.affiche();
    Sprite imgPionNoir(t2);
    string txt = "images/PieceNoir.png";
    if(t2.loadFromFile(txt))
        cout << "OK" << endl;
    //Run();

	return EXIT_SUCCESS;
}