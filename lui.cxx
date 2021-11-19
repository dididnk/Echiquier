#include <SFML/Graphics.hpp>
#include <iostream>


#define LONGUEUR 8
#define PionNEGRU 1
#define PionALB -1
#define TurnNEGRU 2
#define TurnALB -2
#define CalALB -3
#define CalNEGRU 3
#define NebunNEGRU 4
#define NebunALB -4
#define ReginaALB -5
#define ReginaNEGRU 5
#define RegeNEGRU 6
#define RegeALB -6

using namespace sf;

struct poz
{
	int x, y;
}oldPoz, regeleAlb, regeleNegru, transformA, transformN;

int  size = 100, move = 0, x, y;
int board[8][8] =
{ 2, 3, 4, 5, 6, 4, 3, 2,
  1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
 -1,-1,-1,-1,-1,-1,-1,-1,
 -2,-3,-4,-5,-6,-4,-3,-2,};

int turnAlbDreapta = 0, turnAlbStanga = 0, regeAlb = 0;
int turnNegruDreapta = 0, turnNegruStanga = 0, regeNegru = 0;

int mutare = 0; // 0 muta albul, 1 muta negru

int sahAlb = 0, sahNegru = 0;

int transformareAlb = 0, transformareNegru = 0;

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

	
	Sprite tabla(t1);
	Sprite PionNegru(t2);
	Sprite PionAlb(t3);
	Sprite TurnNegru(t4);
	Sprite TurnAlb(t5);
	Sprite CalAlb(t6);
	Sprite CalNegru(t7);
	Sprite NebunNegru(t8);
	Sprite NebunAlb(t9);
	Sprite ReginaAlb(t10);
	Sprite ReginaNegru(t11);
	Sprite RegeNegru(t12);
	Sprite RegeAlb(t13);
	Sprite Mutare;
	Sprite TransformareALB(t14);
	Sprite TransformareNEGRU(t15);

	float dx = 0, dy = 0;
	int numarPiesaMutata = 0;

	while (window.isOpen())
	{
		Vector2i pos = Mouse::getPosition(window);
		 x = pos.x / size;
		 y = pos.y / size;
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			window.clear();
		}
		// afisare //
		window.clear();
		window.draw(tabla);
		if (transformareAlb == 1)
		{
			TransformareALB.setPosition(transformA.x* size, transformA.y* size);
			window.draw(TransformareALB);
		}
		if (transformareNegru == 1)
		{
			TransformareNEGRU.setPosition(transformN.x* size, transformN.y* size);
			window.draw(TransformareNEGRU);
		}
		if (move == 1)
		{
			Mutare.setPosition(pos.x-dx, pos.y-dy);
			window.draw(Mutare);
		}
		for (int i = 0; i < LONGUEUR; i++)
		{
			for (int j = 0; j < LONGUEUR; j++)
			{

				if (board[i][j] != 0)
				{
					if (board[i][j] == PionNEGRU)
					{
						PionNegru.setPosition(j * size, i * size);
						window.draw(PionNegru);
					}
					// if (board[i][j] == PionALB)
					// {
					// 	PionAlb.setPosition(j * size, i * size);
					// 	window.draw(PionAlb);
					// }
					// if (board[i][j] == TurnNEGRU)
					// {
					// 	TurnNegru.setPosition(j * size, i * size);
					// 	window.draw(TurnNegru);

					// }
					// if (board[i][j] == TurnALB)
					// {
					// 	TurnAlb.setPosition(j * size, i * size);
					// 	window.draw(TurnAlb);

					// }
					// if (board[i][j] == CalALB)
					// {
					// 	CalAlb.setPosition(j * size, i * size);
					// 	window.draw(CalAlb);
					// }
					// if (board[i][j] == CalNEGRU)
					// {
					// 	CalNegru.setPosition(j * size, i * size);
					// 	window.draw(CalNegru);
					// }
					// if (board[i][j] == NebunNEGRU)
					// {
					// 	NebunNegru.setPosition(j * size, i * size);
					// 	window.draw(NebunNegru);
					// }
					// if (board[i][j] == NebunALB)
					// {
					// 	NebunAlb.setPosition(j * size, i * size);
					// 	window.draw(NebunAlb);
					// }
					// if (board[i][j] == ReginaALB)
					// {
					// 	ReginaAlb.setPosition(j * size, i * size);
					// 	window.draw(ReginaAlb);
					// }
					// if (board[i][j] == ReginaNEGRU)
					// {
					// 	ReginaNegru.setPosition(j * size, i * size);
					// 	window.draw(ReginaNegru);
					// }
					// if (board[i][j] == RegeNEGRU)
					// {
					// 	RegeNegru.setPosition(j * size, i * size);
					// 	window.draw(RegeNegru);
					// }
					// if (board[i][j] == RegeALB)
					// {
					// 	RegeAlb.setPosition(j * size, i * size);
					// 	window.draw(RegeAlb);
					// }
				}
			}
		}
		window.display();
	}
		return 0;
}