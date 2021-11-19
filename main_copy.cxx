#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>


#define LONGUEUR 7
#define PIECE_BLANC 1
#define PIECE_NOIR -1
#define TOUR_BLANC 2
#define TOUR_NOIR -2
#define CHEVAL_BLANC 3
#define CHEVAL_NOIR -3
#define FOU_NOIR 4
#define FOU_BLANC -4
#define REINE_BLANC 5
#define REINE_NOIR -5
#define ROI_BLANC 6
#define ROI_NOIR -6
#define MaxSize 8
#define BLANC 1
#define NOIR 0
#define ZONE_VIDE 0

using namespace sf; 

// Structure pour stocker les positions
struct poistion
{
    int x, y;
}ancienne_Pos, roi_blanc, roi_noir, transforme_blanc, transforme_noir;

int taille = 100, ca_bouge = 0;

int tableDeJeu[MaxSize][MaxSize]=
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

int mouvement = 0; // 1 -> Mouvement Blanc 0 -> Mouvement Noir

int testBlanc = 0, testNoir = 0;

int transformationBlanc = 0, transformationNoir = 0;

int main(int argc, char const *argv[])
{
    int largeurJeu = 800, hauteurJeu = 800;
    String auteur = "Echiquier Emmanuel NGBAME";

    RenderWindow window(VideoMode(largeurJeu, hauteurJeu), auteur);
    Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
    
    // importation des images
    t1.loadFromFile("images/Tableau.png");
    t2.loadFromFile("images/PieceNoir.png");
    t3.loadFromFile("images/PieceBlanc.png");
    t4.loadFromFile("images/TourNoir.png");
    t5.loadFromFile("images/TourBlanc.png");
    t6.loadFromFile("images/ChevalBlanc.png");
    t7.loadFromFile("images/ChevalNoir.png");
    // t8.loadFromFile("images/BoutiqueNoir.png");
    // t9.loadFromFile("images/BoutiqueBlanc.png");
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
    // Sprite BoutiqueNoir(t8);
	// Sprite BoutiqueBlanc(t9);
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

    // lancement du programme
    while (window.isOpen())
    {
        Vector2i pos = Mouse::getPosition(window); // detecter le mouvement de la souris
        int x = pos.x / taille;
        int y = pos.y / taille;
        Event e; // événement

        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
                window.close();
            }
            window.clear();
        }
        window.clear();
        window.draw(Tableau);

        // On detecte le mouvement 
        if (e.type == Event::MouseButtonPressed)
        {
            // On traite cas par cas selon le mouvement choisi
            if (e.key.code == Mouse::Left)
            {
                // Transformation

                //
                if(tableDeJeu[y][x] != NOIR)
                {
                    dx = pos.x - (x * taille);
                    dy = pos.y - (y * taille);
                    
                    if(tableDeJeu[y][x] == PIECE_BLANC && mouvement == BLANC) // Si mouvement pion piece BLANC
                    {
                        pasMouvPiece        = PIECE_BLANC; // Alors pion piece BLANC ne bouge pas
                        MouveImages         = PieceBlanc; // Le mouvement va au pion piece blanc
                        tableDeJeu[y][x]    = ZONE_VIDE;  // Initialiser la case vide
                    }
                    if(tableDeJeu[y][x] == PIECE_NOIR && mouvement == NOIR) // Si mouvement pion piece NOIR
                    {
                        pasMouvPiece        = PIECE_NOIR; // Alors pion piece NOIR ne bouge pas
                        MouveImages         = PieceNoir; // Le mouvement va au pion piece NOIR
                        tableDeJeu[y][x]    = ZONE_VIDE;  // Initialiser la case vide
                    }
                    if(tableDeJeu[y][x] == CHEVAL_NOIR && mouvement == NOIR) // Si mouvement pion cheval Noir
                    {
                        pasMouvPiece        = CHEVAL_NOIR; // Alors pion cheval noir ne bouge pas
                        MouveImages         = ChevalNoir; // Le mouvement va au pion cheval blanc
                        tableDeJeu[y][x]    = ZONE_VIDE;  // Initialiser la case vide
                    }
                    if(tableDeJeu[y][x] == CHEVAL_BLANC && mouvement == BLANC) // Si mouvement pion cheval BLANC
                    {
                        pasMouvPiece        = CHEVAL_BLANC; // Alors pion cheval BLANC ne bouge pas
                        MouveImages         = ChevalBlanc; // Le mouvement va au pion cheval blanc
                        tableDeJeu[y][x]    = ZONE_VIDE;  // Initialiser la case vide
                    }
                    if(tableDeJeu[y][x] == TOUR_BLANC && mouvement == BLANC) // Si mouvement pion tour BLANC
                    {
                        pasMouvPiece        = TOUR_BLANC; // Alors pion tour BLANC ne bouge pas
                        MouveImages         = TourBlanc; // Le mouvement va au pion tour blanc
                        tableDeJeu[y][x]    = ZONE_VIDE;  // Initialiser la case vide
                    }
                    if(tableDeJeu[y][x] == TOUR_NOIR && mouvement == NOIR) // Si mouvement pion tour NOIR
                    {
                        pasMouvPiece        = TOUR_NOIR; // Alors pion tour NOIR ne bouge pas
                        MouveImages         = TourNoir; // Le mouvement va au pion tour NOIR
                        tableDeJeu[y][x]    = ZONE_VIDE;  // Initialiser la case vide
                    }
                    if(tableDeJeu[y][x] == FOU_BLANC && mouvement == BLANC) // Si mouvement pion boutique NOIR
                    {
                        pasMouvPiece        = FOU_BLANC; // Alors pion boutique NOIR ne bouge pas
                        MouveImages         = FouBlanc; // Le mouvement va au pion Fou NOIR
                        tableDeJeu[y][x]    = ZONE_VIDE;  // Initialiser la case vide
                    }
                    if(tableDeJeu[y][x] == FOU_NOIR && mouvement == NOIR) // Si mouvement pion Fou NOIR
                    {
                        pasMouvPiece        = FOU_NOIR; // Alors pion Fou NOIR ne bouge pas
                        MouveImages         = FouNoir; // Le mouvement va au pion Fou NOIR
                        tableDeJeu[y][x]    = ZONE_VIDE;  // Initialiser la case vide
                    }
                    if(tableDeJeu[y][x] == REINE_BLANC && mouvement == BLANC) // Si mouvement pion REINE BLANC
                    {
                        pasMouvPiece        = REINE_BLANC; // Alors pion REINE BLANC ne bouge pas
                        MouveImages         = ReineBlanc; // Le mouvement va au pion REINE BLANC
                        tableDeJeu[y][x]    = ZONE_VIDE;  // Initialiser la case vide
                    }
                    if(tableDeJeu[y][x] == REINE_NOIR && mouvement == NOIR) // Si mouvement pion REINE NOIR
                    {
                        pasMouvPiece        = REINE_NOIR; // Alors pion REINE NOIR ne bouge pas
                        MouveImages         = ReineNoir; // Le mouvement va au pion REINE NOIR
                        tableDeJeu[y][x]    = ZONE_VIDE;  // Initialiser la case vide
                    }
                    if(tableDeJeu[y][x] == ROI_BLANC && mouvement == BLANC) // Si mouvement pion ROI BLANC
                    {
                        pasMouvPiece        = ROI_BLANC; // Alors pion ROI BLANC ne bouge pas
                        MouveImages         = RoiBlanc; // Le mouvement va au pion ROI BLANC
                        tableDeJeu[y][x]    = ZONE_VIDE;  // Initialiser la case vide
                    }
                    if(tableDeJeu[y][x] == ROI_NOIR && mouvement == NOIR) // Si mouvement pion ROI NOIR
                    {
                        pasMouvPiece        = ROI_NOIR; // Alors pion ROI NOIR ne bouge pas
                        MouveImages         = RoiNoir; // Le mouvement va au pion ROI NOIR
                        tableDeJeu[y][x]    = ZONE_VIDE;  // Initialiser la case vide
                    }
                    if (tableDeJeu[y][x] == ZONE_VIDE)
                    {
                        ca_bouge        = BLANC;
                        ancienne_Pos.x  = x;
                        ancienne_Pos.y  = y;
                    }                      
                }
            }
        }
        if (e.type == Event::MouseButtonReleased)
        {
            if (e.key.code == Mouse::Left)
            {
                int ok;
                // Mouvement de pièce

                //

            }
        }
    
        if (transformationBlanc == BLANC)
        {
            BlancTransformation.setPosition(transforme_blanc.x * taille, transforme_blanc.y * taille);
            window.draw(BlancTransformation);
        }
        if (transformationNoir == NOIR)
        {
            NoirTransformation.setPosition(transforme_noir.x * taille, transforme_noir.y * taille);
            window.draw(NoirTransformation);
        }
        if (ca_bouge == BLANC)
        {
            MouveImages.setPosition(pos.x - dx, pos.y - dy);
            window.draw(deplacement);
        }
        // On dessine la table de jeu
        for (int i = 0; i < LONGUEUR; i++)
        {
            for (int j = 0; j < LONGUEUR; j++)
            {
                if (tableDeJeu[i][j] != NOIR)
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

