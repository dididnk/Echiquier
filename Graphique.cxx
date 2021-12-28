#include "Graphique.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf; 

RenderWindow window(VideoMode(800, 800), "Ehiquier by Emmanuel NGBAME");
Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;



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

void Run()
{
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
								bool h = RoiNoirEchecTest(roi_noir.x, roi_noir.y);
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
								int h = RoiBlancEchecTest(roi_blanc.x, roi_blanc.y);
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
					int ok=2;
					if (pasMouvPiece == PION_BLANC && ca_bouge==1)
					{
						 ok = PionBlanc(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece  == PION_NOIR && ca_bouge == 1)
					{
						ok = PionNoir(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == TOUR_BLANC && ca_bouge == 1)
					{
						ok = TourBlanc(ancienne_Pos.x, ancienne_Pos.y, x, y);
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
						ok=TourNoir(ancienne_Pos.x, ancienne_Pos.y, x, y);
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
						ok = FouBlanc(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == FOU_NOIR && ca_bouge == 1)
					{
						ok= FouNoir(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == REINE_BLANC && ca_bouge == 1)
					{
						ok=ReineBlanc(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == REINE_NOIR && ca_bouge == 1)
					{
						ok=ReineNoir(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == CHEVAL_BLANC && ca_bouge == 1)
					{
						ok=ChevalBlanc(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == CHEVAL_NOIR && ca_bouge == 1)
					{
						ok = ChevalNoir(ancienne_Pos.x, ancienne_Pos.y, x, y);
					}
					if (pasMouvPiece == ROI_NOIR && ca_bouge == 1)
					{
						ok=RoiNoir(ancienne_Pos.x, ancienne_Pos.y, x, y);
						if (ok == 1 && RoiNoirPremierMouv == 0)
						{
							RoiNoirPremierMouv = 1;
						//	std::cout << imgRoiNoir << "\n";
						}
					}
					if (pasMouvPiece == ROI_BLANC && ca_bouge == 1)
					{
						ok=RoiBlanc(ancienne_Pos.x, ancienne_Pos.y, x, y);
						if (ok == 1 && RoiBlancPremierMouv == 0)
						{
							RoiBlancPremierMouv = 1;
							//std::cout << "primaDeplacementimgRoiBlanc=" << imgRoiBlanc << "\n";
						}
					}
					if (ok == 1)
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
								posRoiBlanc();
								int s = RoiBlancEchecTest(roi_blanc.x, roi_blanc.y);
								if (s == 0)
								{
									tableDeJeu[ancienne_Pos.y][ancienne_Pos.x] = pasMouvPiece;
									tableDeJeu[y][x] = nr;
								}
								else
								{
									EchecBlanc = 0;
									posRoiNoir();
									int Echec = RoiNoirEchecTest(roi_noir.x,roi_noir.y);
									if (Echec == 0)
									{
										EchecNoir = 1;
									}
									mouvement = 1;
								}
							}
							else
							{
								posRoiBlanc();
								int sa = RoiBlancEchecTest(roi_blanc.x, roi_blanc.y);
								if (sa == 0)
								{
									tableDeJeu[ancienne_Pos.y][ancienne_Pos.x] = pasMouvPiece;
									tableDeJeu[y][x] = nr;
								}
								else
								{
									posRoiNoir();
									int Echec = RoiNoirEchecTest(roi_noir.x, roi_noir.y);
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
								posRoiNoir();
								int s = RoiNoirEchecTest(roi_noir.x,roi_noir.y);
								if (s == 0)
								{
									tableDeJeu[ancienne_Pos.y][ancienne_Pos.x] = pasMouvPiece;
									tableDeJeu[y][x] = nr;
								}
								else
								{
									EchecNoir = 0;
									posRoiBlanc();
									int Echec = RoiBlancEchecTest(roi_blanc.x,roi_blanc.y);
									if (Echec == 0)
									{
										EchecBlanc = 1;
									}
									mouvement = 0;
								}
							}
							else
							{
								posRoiNoir();
								int sa = RoiNoirEchecTest(roi_noir.x, roi_noir.y);
								if (sa == 0)
								{
									tableDeJeu[ancienne_Pos.y][ancienne_Pos.x] = pasMouvPiece;
									tableDeJeu[y][x] = nr;
								}
								else
								{
									posRoiBlanc();
									int Echec = RoiBlancEchecTest(roi_blanc.x, roi_blanc.y);
									if (Echec == 0)
									{
										EchecBlanc = 1;
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
				if (tableDeJeu[i][j] != 0)
				{
					if (tableDeJeu[i][j]  == PION_NOIR)
					{
						imgPionNoir.setPosition(j * taille, i * taille);
						window.draw(imgPionNoir);
					}
					if (tableDeJeu[i][j] == PION_BLANC)
					{
						imgPionBlanc.setPosition(j * taille, i * taille);
						window.draw(imgPionBlanc);
					}
					if (tableDeJeu[i][j] == TOUR_NOIR)
					{
						imgTourNoir.setPosition(j * taille, i * taille);
						window.draw(imgTourNoir);

					}
					if (tableDeJeu[i][j] == TOUR_BLANC)
					{
						imgTourBlanc.setPosition(j * taille, i * taille);
						window.draw(imgTourBlanc);

					}
					if (tableDeJeu[i][j] == CHEVAL_BLANC)
					{
						imgChevalBlanc.setPosition(j * taille, i * taille);
						window.draw(imgChevalBlanc);
					}
					if (tableDeJeu[i][j] == CHEVAL_NOIR)
					{
						imgChevalNoir.setPosition(j * taille, i * taille);
						window.draw(imgChevalNoir);
					}
					if (tableDeJeu[i][j] == FOU_NOIR)
					{
						imgFouNoir.setPosition(j * taille, i * taille);
						window.draw(imgFouNoir);
					}
					if (tableDeJeu[i][j] == FOU_BLANC)
					{
						imgFouBlanc.setPosition(j * taille, i * taille);
						window.draw(imgFouBlanc);
					}
					if (tableDeJeu[i][j] == REINE_BLANC)
					{
						imgReineBlanc.setPosition(j * taille, i * taille);
						window.draw(imgReineBlanc);
					}
					if (tableDeJeu[i][j] == REINE_NOIR)
					{
						imgReineNoir.setPosition(j * taille, i * taille);
						window.draw(imgReineNoir);
					}
					if (tableDeJeu[i][j] == ROI_NOIR)
					{
						imgRoiNoir.setPosition(j * taille, i * taille);
						window.draw(imgRoiNoir);
					}
					if (tableDeJeu[i][j] == ROI_BLANC)
					{
						imgRoiBlanc.setPosition(j * taille, i * taille);
						window.draw(imgRoiBlanc);
					}
				}
			}
		}
		window.display();
	}
}