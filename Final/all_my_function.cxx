/*
bool
Piece::mouvementValide( Echiquier &e, int x, int y )
{
    cout << "Mouvement Valide Piece" << endl;
    return true;  // cette methode deviendra abstraite
}
*/
//===============================================================================================//
//                                 Test Mouvement Simple                                         //
//                                   [BLANC] + [Noir]                                            //
//===============================================================================================//

//------------------------------------------Mouvement Pièce Blanc----------------------------//

bool PionBlanc(int ax, int ay, int nx, int ny)
{
	if (ancienne_Pos.y == 6)
	{
		if ((ny == ay - 1 && nx == ax && m_cases[ay-1][ax]==0)||
			  (ny==ay-2 && nx==ax && m_cases[ay - 1][ax] == 0 && m_cases[ay - 2][ax]==0))
		{
			return 1;
		}
	}
	else if(ny == ay - 1 && nx == ax && m_cases[ay - 1][ax] == 0)
	{
		return 1;
	}
	if (m_cases[ay - 1][ax - 1] > 0)
	{
		if (ny == ay - 1 && nx == ax - 1)
		{
			return 1;
		}
	}
	if (m_cases[ay - 1][ax + 1] > 0)
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
		if ((ny == ay + 1 && nx == ax && m_cases[ay+1][ax]==0) || 
			  (ny == ay + 2 && nx == ax && m_cases[ay + 1][ax] == 0 && m_cases[ay + 2][ax] == 0))
		{
			return 1;
		}
	}
	else if (ny == ay + 1 && nx == ax && m_cases[ay + 1][ax] == 0)
	{
		return 1;
	}
	if (m_cases[ay + 1][ax - 1] < 0)
	{
		if (ny == ay + 1 && nx == ax - 1)
		{
			return 1;
		}
	}
	if (m_cases[ay + 1][ax + 1] < 0)
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
		if (m_cases[ay][i] >= 0 && (nx == i && ny == ay))
		{
			return 1;
		}
		else if (m_cases[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay - 1; i >= 0; i--) // Côté Haut
	{
		if (m_cases[i][ax] >= 0 && (ny == i && nx == ax))
		{
			return 1;
		}
		else if (m_cases[i][ax] != 0 )
		{
			break;
		}
	}
	for (int i = ax + 1; i < LONGUEUR; i++) // À droite
	{
		if (m_cases[ay][i]>=0 && (ny == ay && nx == i))
		{
			return 1;
		}
		else if (m_cases[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay + 1; i < LONGUEUR; i++) // bas
	{
		if (m_cases[i][ax]>=0 && (ny == i && nx == ax))
		{
			return 1;
		}
		else if (m_cases[i][ax] != 0)
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
		if (m_cases[ay][i] <= 0 && (nx == i && ny == ay))
		{
			return 1;
		}
		else if (m_cases[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay - 1; i >= 0; i--) // Côté Haut
	{
		if (m_cases[i][ax] <= 0 && (ny == i && nx == ax))
		{
			return 1;
		}
		else if (m_cases[i][ax] != 0)
		{
			break;
		}
	}
	for (int i = ax + 1; i < LONGUEUR; i++) // À droite
	{
		if (m_cases[ay][i] <= 0 && (ny == ay && nx == i))
		{
			return 1;
		}
		else if (m_cases[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay + 1; i < LONGUEUR; i++) // bas
	{
		if (m_cases[i][ax] <= 0 && (ny == i && nx == ax))
		{
			return 1;
		}
		else if (m_cases[i][ax] != 0)
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
		if (m_cases[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay - 1; i >= 0; i--) // À droite haut
	{
		if (m_cases[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ax - 1;
	for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
	{
		if (m_cases[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
	{
		if (m_cases[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
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
		if (m_cases[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay - 1; i >= 0; i--) // À droite haut
	{
		if (m_cases[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ax - 1;
	for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
	{
		if (m_cases[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
	{
		if (m_cases[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
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
		if (m_cases[ay][i] >= 0 && (nx == i && ny == ay))
		{
			return 1;
		}
		else if (m_cases[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay - 1; i >= 0; i--) // Côté Haut
	{
		if (m_cases[i][ax] >= 0 && (ny == i && nx == ax))
		{
			return 1;
		}
		else if (m_cases[i][ax] != 0)
		{
			break;
		}
	}
	for (int i = ax + 1; i < LONGUEUR; i++) // À droite
	{
		if (m_cases[ay][i] >= 0 && (ny == ay && nx == i))
		{
			return 1;
		}
		else if (m_cases[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay + 1; i < LONGUEUR; i++) // bas
	{
		if (m_cases[i][ax] >= 0 && (ny == i && nx == ax))
		{
			return 1;
		}
		else if (m_cases[i][ax] != 0)
		{
			break;
		}
	}
	int j = ax - 1;
	for (int i = ay - 1; i >= 0; i--) // Côté gauche haut
	{
		if (m_cases[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay - 1; i >= 0; i--) // À droite haut
	{
		if (m_cases[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ax - 1;
	for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
	{
		if (m_cases[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
	{
		if (m_cases[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
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
		if (m_cases[ay][i] <= 0 && (nx == i && ny == ay))
		{
			return 1;
		}
		else if (m_cases[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay - 1; i >= 0; i--) // Côté Haut
	{
		if (m_cases[i][ax] <= 0 && (ny == i && nx == ax))
		{
			return 1;
		}
		else if (m_cases[i][ax] != 0)
		{
			break;
		}
	}
	for (int i = ax + 1; i < LONGUEUR; i++) // À droite
	{
		if (m_cases[ay][i] <= 0 && (ny == ay && nx == i))
		{
			return 1;
		}
		else if (m_cases[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay + 1; i < LONGUEUR; i++) // bas
	{
		if (m_cases[i][ax] <= 0 && (ny == i && nx == ax))
		{
			return 1;
		}
		else if (m_cases[i][ax] != 0)
		{
			break;
		}
	}
	int j = ax - 1;
	for (int i = ay - 1; i >= 0; i--) // Côté gauche haut
	{
		if (m_cases[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay - 1; i >= 0; i--) // À droite haut
	{
		if (m_cases[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ax - 1;
	for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
	{
		if (m_cases[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
	{
		if (m_cases[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
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
	if (ay - 2 >= 0 && ax - 1 >= 0 && ny == ay - 2 && nx == ax - 1 && m_cases[ny][nx] >= 0)
	{
		return 1; // Haut gauche
	}
	if (ay - 2 >= 0 && ax + 1 <LONGUEUR && ny == ay - 2 && nx == ax + 1 && m_cases[ny][nx] >= 0)
	{
		return 1; // Haut droit
	}
	if (ay - 1 >= 0 && ax + 2 < LONGUEUR && ny==ay-1 && nx==ax+2 && m_cases[ny][nx]>=0)
	{
		return 1; // droit 1
	}
	if (ay + 1 >= 0 && ax + 2 < LONGUEUR && ny == ay + 1 && nx == ax + 2 && m_cases[ny][nx] >= 0)
	{
		return 1; // droit 2
	}
	if (ay+2<LONGUEUR && ax+1<LONGUEUR && ny==ay+2 && nx==ax+1 && m_cases[ny][nx]>=0)
	{
		return 1; // bas 1
	}
	if (ay + 2 < LONGUEUR && ax - 1 >= 0 && ny == ay + 2 && nx == ax - 1 && m_cases[ny][nx] >= 0)
	{
		return 1; // bas 2
	}
	if (ay+1<LONGUEUR && ax-2>=0 && ny==ay+1 && nx==ax-2 && m_cases[ny][nx]>=0 )
	{
		return 1; // gauche 1
	}
	if (ay - 1 >= 0 && ax - 2 >= 0 && ny == ay - 1 && nx == ax - 2 && m_cases[ny][nx] >= 0)
	{
		return 1;
	}
	return 0;
}

//------------------------------------------Mouvement Cheval Noir----------------------------//

bool ChevalNoir(int ax, int ay, int nx, int ny)
{
	if (ay - 2 >= 0 && ax - 1 >= 0 && ny == ay - 2 && nx == ax - 1 && m_cases[ny][nx] <= 0)
	{
		return 1; // Haut gauche
	}
	if (ay - 2 >= 0 && ax + 1 < LONGUEUR && ny == ay - 2 && nx == ax + 1 && m_cases[ny][nx] <= 0)
	{
		return 1; // Haut droit
	}
	if (ay - 1 >= 0 && ax + 2 < LONGUEUR && ny == ay - 1 && nx == ax + 2 && m_cases[ny][nx] <= 0)
	{
		return 1; // droit 1
	}
	if (ay + 1 >= 0 && ax + 2 < LONGUEUR && ny == ay + 1 && nx == ax + 2 && m_cases[ny][nx] <= 0)
	{
		return 1; // droit 2
	}
	if (ay + 2 < LONGUEUR && ax + 1 < LONGUEUR && ny == ay + 2 && nx == ax + 1 && m_cases[ny][nx] <= 0)
	{
		return 1; // bas 1
	}
	if (ay + 2 < LONGUEUR && ax - 1 >= 0 && ny == ay + 2 && nx == ax - 1 && m_cases[ny][nx] <= 0)
	{
		return 1; // bas 2
	}
	if (ay + 1 < LONGUEUR && ax - 2 >= 0 && ny == ay + 1 && nx == ax - 2 && m_cases[ny][nx] <= 0)
	{
		return 1; // gauche 1
	}
	if (ay - 1 >= 0 && ax - 2 >= 0 && ny == ay - 1 && nx == ax - 2 && m_cases[ny][nx] <= 0)
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
	if (m_cases[posy - 1][posx - 1] >= 0)
	{
		if (posy-1 == roiY && posx - 1 == roiX)
		{
			return 1;
		}
	}
	if (m_cases[posy - 1][posx + 1] >= 0)
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
		if (m_cases[ay][i] >= 0 && (roiX== i && roiY == ay))
		{
			return 1;
		}
		else if(m_cases[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay - 1; i >= 0; i--) // Côté Haut
	{
		if (m_cases[i][ax] >= 0 && (roiY == i && roiX == ax))
		{
			return 1;
		}
		else if(m_cases[i][ax] != 0)
		{
			break;
		}
	}
	for (int i = ax + 1; i < LONGUEUR; i++) // À droite
	{
		if (m_cases[ay][i] >= 0 && (roiY == ay && roiX == i))
		{
			return 1;
		}
		else if(m_cases[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay + 1; i <LONGUEUR; i++) // bas
	{
		if (m_cases[i][ax] >= 0 && (roiY == i && roiX == ax))
		{
			return 1;
		}
		else if(m_cases[i][ax] != 0)
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
		if (m_cases[i][j] >= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if(m_cases[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay - 1; i >= 0; i--) // À droite haut
	{
		if (m_cases[i][j] >= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if(m_cases[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ax - 1;
	for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
	{
		if (m_cases[i][j] >= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
	{
		if (m_cases[i][j] >= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
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
		if (m_cases[ay][i] >= 0 && (roiX == i && roiY == ay))
		{
			return 1;
		}
		else if(m_cases[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay - 1; i >= 0; i--) // Côté Haut
	{
		if (m_cases[i][ax] >= 0 && (roiY == i && roiX == ax))
		{
			return 1;
		}
		else if(m_cases[i][ax] != 0)
		{
			break;
		}
	}
	for (int i = ax + 1; i < LONGUEUR; i++) // À droite
	{
		if (m_cases[ay][i] >= 0 && (roiY == ay && roiX == i))
		{
			return 1;
		}
		else if (m_cases[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay + 1; i <LONGUEUR; i++) // bas
	{
		if (m_cases[i][ax] >= 0 && (roiY == i && roiX == ax))
		{
			return 1;
		}
		else if(m_cases[i][ax] != 0)
		{
			break;
		}
	}
	int j = ax - 1;
	for (int i = ay - 1; i >= 0; i--) // Côté gauche haut
	{
		if (m_cases[i][j] >= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if(m_cases[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay - 1; i >= 0; i--) // À droite haut
	{
		if (m_cases[i][j] >= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ax - 1;
	for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
	{
		if (m_cases[i][j] >= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if(m_cases[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
	{
		if (m_cases[i][j] >= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if(m_cases[i][j] != 0)
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
	if (ay - 2 >= 0 && ax - 1 >= 0 && roiY == ay - 2 && roiX == ax - 1 && m_cases[roiY][roiX] >= 0)
	{
		return 1; // Haut gauche
	}
	if (ay - 2 >= 0 && ax + 1 < LONGUEUR && roiY == ay - 2 && roiX == ax + 1 && m_cases[roiY][roiX] >= 0)
	{
		return 1; // Haut droit
	}
	if (ay - 1 >= 0 && ax + 2 < LONGUEUR && roiY == ay - 1 && roiX == ax + 2 && m_cases[roiY][roiX] >= 0)
	{
		return 1; // droit 1
	}
	if (ay + 1 >= 0 && ax + 2 < LONGUEUR && roiY == ay + 1 && roiX == ax + 2 && m_cases[roiY][roiX] >= 0)
	{
		return 1; // droit 2
	}
	if (ay + 2 < LONGUEUR && ax + 1 < LONGUEUR && roiY == ay + 2 && roiX == ax + 1 && m_cases[roiY][roiX] >= 0)
	{
		return 1; // bas 1
	}
	if (ay + 2 < LONGUEUR && ax - 1 >= 0 && roiY == ay + 2 && roiX == ax - 1 && m_cases[roiY][roiX] >= 0)
	{
		return 1; // bas 2
	}
	if (ay + 1 < LONGUEUR && ax - 2 >= 0 && roiY == ay + 1 && roiX == ax - 2 && m_cases[roiY][roiX] >= 0)
	{
		return 1; // gauche 1
	}
	if (ay - 1 >= 0 && ax - 2 >= 0 && roiY == ay - 1 && roiX == ax - 2 && m_cases[roiY][roiX] >= 0)
	{
		return 1;
	}
	return 0;
}

//------------------------------------------Mouvement Roi Blanc Echec----------------------------//

bool RoiBlancEchec(int ax, int ay, int roiX, int roiY)
{
	if (ax - 1 >= 0 && ay - 1 >= 0 && roiY == ay - 1 && roiX == ax - 1 && m_cases[roiY][roiX] <= 0)
	{
		return 1;
	}
	if (ay - 1 >= 0 && roiX == ax && roiY == ay - 1 && m_cases[roiY][roiX] <= 0)
	{
		return 1;
	}
	if (ay - 1 >= 0 && ax + 1 < LONGUEUR && roiX == ax + 1 && roiY == ay - 1 && m_cases[roiY][roiX] <= 0)
	{
		return 1;
	}
	if (ax + 1 < LONGUEUR && roiY == ay && roiX == ax + 1 && m_cases[roiY][roiX] <= 0)
	{
		return 1;
	}
	if (ax + 1 < LONGUEUR && ay + 1 < LONGUEUR && roiY == ay + 1 && roiX == ax + 1 && m_cases[roiY][roiX] <= 0)
	{
		return 1;
	}
	if (ay + 1 < LONGUEUR && roiY == ay + 1 && roiX == ax && m_cases[roiY][roiX] <= 0)
	{
		return 1;
	}
	if (ax - 1 >= 0 && ay + 1 < LONGUEUR && roiX == ax - 1 && roiY == ay + 1 && m_cases[roiY][roiX] <= 0)
	{
		return 1;
	}
	if (ax - 1 >= 0 && roiY == ay && roiX == ax - 1 && m_cases[roiY][roiX] <= 0)
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
	if (m_cases[ay + 1][ax - 1] <= 0)
	{
		if (roiY == ay + 1 && roiX == ax - 1)
		{
			return 1;
		}
	}
	if (m_cases[ay + 1][ax + 1] <= 0)
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
		if (m_cases[ay][i] <= 0 && (roiX == i && roiY == ay))
		{
			return 1;
		}
		else if (m_cases[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay - 1; i >= 0; i--) // Côté Haut
	{
		if (m_cases[i][ax] <= 0 && (roiY == i && roiX == ax))
		{
			return 1;
		}
		else if (m_cases[i][ax] != 0)
		{
			break;
		}
	}
	for (int i = ax + 1; i < LONGUEUR; i++) // À droite
	{
		if (m_cases[ay][i] <= 0 && (roiY == ay && roiX == i))
		{
			return 1;
		}
		else if (m_cases[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay + 1; i < LONGUEUR; i++) // bas
	{
		if (m_cases[i][ax] <= 0 && (roiY == i && roiX == ax))
		{
			return 1;
		}
		else if (m_cases[i][ax] != 0)
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
		if (m_cases[i][j] <= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay - 1; i >= 0; i--) // À droite haut
	{
		if (m_cases[i][j] <= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ax - 1;
	for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
	{
		if (m_cases[i][j] <= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
	{
		if (m_cases[i][j] <= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
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
		if (m_cases[ay][i] <= 0 && (roiX == i && roiY == ay))
		{
			return 1;
		}
		else if (m_cases[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay - 1; i >= 0; i--) // Côté Haut
	{
		if (m_cases[i][ax] <= 0 && (roiY == i && roiX == ax))
		{
			return 1;
		}
		else if (m_cases[i][ax] != 0)
		{
			break;
		}
	}
	for (int i = ax + 1; i < LONGUEUR; i++) // À droite
	{
		if (m_cases[ay][i] <= 0 && (roiY == ay && roiX == i))
		{
			return 1;
		}
		else if (m_cases[ay][i] != 0)
		{
			break;
		}
	}
	for (int i = ay + 1; i < LONGUEUR; i++) // bas
	{
		if (m_cases[i][ax] <= 0 && (roiY == i && roiX == ax))
		{
			return 1;
		}
		else if (m_cases[i][ax] != 0)
		{
			break;
		}
	}
	int j = ax - 1;
	for (int i = ay - 1; i >= 0; i--) // Côté gauche haut
	{
		if (m_cases[i][j] <= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay - 1; i >= 0; i--) // À droite haut
	{
		if (m_cases[i][j] <= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ax - 1;
	for (int i = ay + 1; i < LONGUEUR; i++) // Côté gauche bas
	{
		if (m_cases[i][j] <= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ax + 1;
	for (int i = ay + 1; i < LONGUEUR; i++)  // À droite bas
	{
		if (m_cases[i][j] <= 0 && (roiY == i && roiX == j))
		{
			return 1;
		}
		else if (m_cases[i][j] != 0)
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
	if (ay - 2 >= 0 && ax - 1 >= 0 && roiY == ay - 2 && roiX == ax - 1 && m_cases[roiY][roiX] <= 0)
	{
		return 1; // Haut gauche
	}
	if (ay - 2 >= 0 && ax + 1 < LONGUEUR && roiY == ay - 2 && roiX == ax + 1 && m_cases[roiY][roiX] <= 0)
	{
		return 1; // Haut droit
	}
	if (ay - 1 >= 0 && ax + 2 < LONGUEUR && roiY == ay - 1 && roiX == ax + 2 && m_cases[roiY][roiX] <= 0)
	{
		return 1; // droit 1
	}
	if (ay + 1 >= 0 && ax + 2 < LONGUEUR && roiY == ay + 1 && roiX == ax + 2 && m_cases[roiY][roiX] <= 0)
	{
		return 1; // droit 2
	}
	if (ay + 2 < LONGUEUR && ax + 1 < LONGUEUR && roiY == ay + 2 && roiX == ax + 1 && m_cases[roiY][roiX] <= 0)
	{
		return 1; // bas 1
	}
	if (ay + 2 < LONGUEUR && ax - 1 >= 0 && roiY == ay + 2 && roiX == ax - 1 && m_cases[roiY][roiX] <= 0)
	{
		return 1; // bas 2
	}
	if (ay + 1 < LONGUEUR && ax - 2 >= 0 && roiY == ay + 1 && roiX == ax - 2 && m_cases[roiY][roiX] <= 0)
	{
		return 1; // gauche 1
	}
	if (ay - 1 >= 0 && ax - 2 >= 0 && roiY == ay - 1 && roiX == ax - 2 && m_cases[roiY][roiX] <= 0)
	{
		return 1;
	}
	return 0;
}

//------------------------------------------Mouvement Roi Noir Echec--------------------------//

bool RoiNoirEchec(int ax, int ay, int roiX, int roiY)
{
	if (ax - 1 >= 0 && ay - 1 >= 0 && roiY == ay - 1 && roiX == ax - 1 && m_cases[roiY][roiX] >= 0)
	{
		return 1;
	}
	if (ay - 1 >= 0 && roiX == ax && roiY == ay - 1 && m_cases[roiY][roiX] >= 0)
	{
		return 1;
	}
	if (ay - 1 >= 0 && ax + 1 < LONGUEUR && roiX == ax + 1 && roiY == ay - 1 && m_cases[roiY][roiX] >= 0)
	{
		return 1;
	}
	if (ax + 1 < LONGUEUR && roiY == ay && roiX == ax + 1 && m_cases[roiY][roiX] >= 0)
	{
		return 1;
	}
	if (ax + 1 < LONGUEUR && ay + 1 < LONGUEUR && roiY == ay + 1 && roiX == ax + 1 && m_cases[roiY][roiX] >= 0)
	{
		return 1;
	}
	if (ay + 1 < LONGUEUR && roiY == ay + 1 && roiX == ax && m_cases[roiY][roiX] >= 0)
	{
		return 1;
	}
	if (ax - 1 >= 0 && ay + 1 < LONGUEUR && roiX == ax - 1 && roiY == ay + 1 && m_cases[roiY][roiX] >= 0)
	{
		return 1;
	}
	if (ax - 1 >= 0 && roiY == ay && roiX == ax - 1 && m_cases[roiY][roiX] >= 0)
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
			if (m_cases[i][j] < 0)
			{
				if (m_cases[i][j] == PION_BLANC)
				{
					ok=PionBlancEchec(j, i, posRoiX, posRoiY);
				}
				if (m_cases[i][j] == TOUR_BLANC)
				{
					ok=TourBlancEchec(j, i, posRoiX, posRoiY);
				}
				if (m_cases[i][j] == CHEVAL_BLANC)
				{
					ok=ChevalBlancEchec(j, i, posRoiX, posRoiY);
				}
				if (m_cases[i][j] == FOU_BLANC)
				{
					ok=FouBlancEchec(j, i, posRoiX, posRoiY);
				}
				if (m_cases[i][j] == REINE_BLANC)
				{
					ok=ReineBlancEchec(j, i, posRoiX, posRoiY);
				}
				if (m_cases[i][j] == ROI_BLANC)
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
	if (ax - 1 >= 0 && ay - 1 >= 0 && ny == ay - 1 && nx == ax - 1 && m_cases[ny][nx] <= 0)
	{
		int ok = RoiNoirEchecTest(ax - 1, ay - 1);
		if (ok == 1)
		{
			return 1;  // Haut gauche
		}
	}
	if (ay - 1 >= 0 && nx == ax && ny == ay-1 && m_cases[ny][nx] <= 0)
	{
		int ok = RoiNoirEchecTest(ax, ay-1);
		if (ok == 1)
		{
			return 1; // Côté Haut
		}
	}
	if (ay - 1 >= 0 && ax + 1 < LONGUEUR && nx == ax + 1 && ny == ay - 1 && m_cases[ny][nx] <= 0)
	{
		int ok = RoiNoirEchecTest(ax+ 1, ay- 1);
		if (ok == 1)
		{
			return 1; // Haut droit
		}
	}
	if (ax + 1 < LONGUEUR && ny == ay && nx == ax+1 && m_cases[ny][nx] <= 0)
	{
		int ok = RoiNoirEchecTest(ax+1, ay);
		if (ok == 1)
		{
			return 1; // droit
		}
	}
	if (ax + 1 < LONGUEUR && ay + 1 < LONGUEUR && ny == ay + 1 && nx == ax + 1 && m_cases[ny][nx] <= 0)
	{
		int ok = RoiNoirEchecTest(ax + 1, ay + 1);
		if (ok == 1)
		{
			return 1; // droit bas
		}
	}
	if (ay + 1 < LONGUEUR && ny == ay+1 && nx == ax && m_cases[ny][nx] <= 0)
	{
		int ok = RoiNoirEchecTest(ax, ay+1);
		if (ok == 1)
		{
			return 1; // bas
		}
	}
	if (ax - 1 >=0 && ay + 1 <LONGUEUR && nx == ax - 1 && ny == ay + 1 && m_cases[ny][nx] <= 0)
	{
		int ok = RoiNoirEchecTest(ax-1, ay+ 1);
		if (ok == 1)
		{
			return 1; // gauche bas
		}
	}
	if (ax - 1 >= 0 && ny == ay && nx == ax-1 && m_cases[ny][nx] <= 0)
	{
		int ok = RoiNoirEchecTest(ax-1, ay);
		if (ok == 1)
		{
			return 1; // gauche
		}
	}
	// Tourner à Droit
	if (mouvDroitTourNoir==0 && RoiNoirPremierMouv ==0 && m_cases[0][5]==0 && m_cases[0][6]==0 && ny==0 && nx==6)
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
					m_cases[0][7] = 0;
					m_cases[0][5] = TOUR_NOIR;
					return 1;
				}
			}
		}
	}
	if (mouvGaucheTourNoir == 0 && RoiNoirPremierMouv == 0 && m_cases[0][3] == 0 && m_cases[0][2] == 0 && m_cases[0][1] == 0 && ny == 0 && nx == 2)
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
						m_cases[0][0] = 0;
						m_cases[0][3] = TOUR_NOIR;
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
			if (m_cases[i][j] > 0)
			{
				if (m_cases[i][j]  == PION_NOIR)
				{
					ok = PionNoirEchec(j, i, posRoiX, posRoiY);
				}
				if (m_cases[i][j] == TOUR_NOIR)
				{
					ok = TourNoirEchec(j, i, posRoiX, posRoiY);
				}
				if (m_cases[i][j] == CHEVAL_NOIR)
				{
					ok = ChevalNoirEchec(j, i, posRoiX, posRoiY);
				}
				if (m_cases[i][j] == FOU_NOIR)
				{
					ok = FouNoirEchec(j, i, posRoiX, posRoiY);
				}
				if (m_cases[i][j] == REINE_NOIR)
				{
					ok = ReineNoirEchec(j, i, posRoiX, posRoiY);
				}
				if (m_cases[i][j] == ROI_NOIR)
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
	if (ax - 1 >= 0 && ay - 1 >= 0 && ny == ay - 1 && nx == ax - 1 && m_cases[ny][nx] >= 0)
	{
		int ok = RoiBlancEchecTest(ax - 1, ay - 1);
		if (ok == 1)
		{
			return 1;  // Haut gauche
		}
	}
	if (ay - 1 >= 0 && nx == ax && ny == ay - 1 && m_cases[ny][nx] >= 0)
	{
		int ok = RoiBlancEchecTest(ax, ay - 1);
		if (ok == 1)
		{
			return 1; // Côté Haut
		}
	}
	if (ay - 1 >= 0 && ax + 1 < LONGUEUR && nx == ax + 1 && ny == ay - 1 && m_cases[ny][nx] >= 0)
	{
		int ok = RoiBlancEchecTest(ax + 1, ay - 1);
		if (ok == 1)
		{
			return 1; // Haut droit
		}
	}
	if (ax + 1 < LONGUEUR && ny == ay && nx == ax + 1 && m_cases[ny][nx] >= 0)
	{
		int ok = RoiBlancEchecTest(ax + 1, ay);
		if (ok == 1)
		{
			return 1; // droit
		}
	}
	if (ax + 1 < LONGUEUR && ay + 1 < LONGUEUR && ny == ay + 1 && nx == ax + 1 && m_cases[ny][nx] >= 0)
	{
		int ok = RoiBlancEchecTest(ax + 1, ay + 1);
		if (ok == 1)
		{
			return 1; // droit bas
		}
	}
	if (ay + 1 < LONGUEUR && ny == ay + 1 && nx == ax && m_cases[ny][nx] >= 0)
	{
		int ok = RoiBlancEchecTest(ax, ay + 1);
		if (ok == 1)
		{
			return 1; // bas
		}
	}
	if (ax - 1 >= 0 && ay + 1 < LONGUEUR && nx == ax - 1 && ny == ay + 1 && m_cases[ny][nx] >= 0)
	{
		int ok = RoiBlancEchecTest(ax - 1, ay + 1);
		if (ok == 1)
		{
			return 1; // gauche bas
		}
	}
	if (ax - 1 >= 0 && ny == ay && nx == ax - 1 && m_cases[ny][nx] >= 0)
	{
		int ok = RoiBlancEchecTest(ax - 1, ay);
		if (ok == 1)
		{
			return 1; // gauche
		}
	}
	// Tourner à Droit
	if (RoiBlancPremierMouv == 0 && mouvDroitTourBlanc == 0 && m_cases[7][5] == 0 && m_cases[7][6] == 0 && ny==7 && nx==6)
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
	if (RoiBlancPremierMouv == 0 && mouvDroitTourBlanc == 0 && m_cases[7][3] == 0 && m_cases[7][2] == 0 && m_cases[7][1] == 0 && ny == 7 && nx == 2)
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
			if (m_cases[i][j] == ROI_BLANC)
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
			if (m_cases[i][j] == ROI_NOIR)
			{
				roi_noir.y = i;
				roi_noir.x = j;
				break;
			}
		}
	}
}


