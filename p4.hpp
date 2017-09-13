/*
_____________________________________________________________________________________________________________________________________
|																																	|
|													Puissance 4 C++ Groupe    INFO3													|
|																																	|
|															Herbin Armelle															|
|															Laporte Nathan															|
|															Lefaure Antoine 														|
|															Loussaut Morgan															|
|																																	|
|																																	|
|																												ESME-Sudria 2017	|
|																												Ver 0.1A			|
-------------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

class Token
{
	private :
		short int number; //Correspond au nombre de jetons disponible en début de jeu*
		char type; //Correspond au type de jeton ( ' ', 'x', 'o'), dépendant du numéro du joueur, par défaut, ' ')*
	public :
		Token();
		bool isEmpty(); //vérifie que le nombre de jetons n'est pas nul == le joueur peut continuer à jouer*
		void setNumber(short int nb);
		void setType(bool tpe);
};

class Grid
{
	private :
		vector<char> grille; //Gère tous les emplacments de l'aire de jeu, et évite de passer par un tableau dynamique Besoin d'un accesseur pour le passer en private
		short int colonnes; //définit le nombre de colonnes, par défaut 7 Besoin d'un accesseur pour le passer en private
		short int lignes; //définit le nombre de lignes, par défaut 6 Besoin d'un accesseur pour le passer en private
		friend class P4;

	public :
		Grid();
		Grid(short int COL, short int LIN); //Constructeur, avec les éléments par defauts nombre de ligne et colonne
		bool gIsFull(); //Vérifie si l'aire de jeu est pleine
		bool cIsFull(short int COL);
		void setCol(int COL);
		void setLin(int LIN);
		void resize();
		short int getElem(short int COL);
		//void getCol();
		//void getLin();


};
class Player
{
	protected :
	bool playerType = 0;
	char tokenType;
	friend class P4;
	public :
        Player();
};

class PlayerHuman : public Player
{
	protected :
	string playerName;
	friend class P4;
	public :
	    PlayerHuman();
		void setName(string name);
		void setType(bool tpe);
		void setInactive();
		void setActive();
};

class P4
{
	private :
	string status;

	public :
		P4();
		void quit();
		void display(Grid aire_de_jeu);//Permet de rafraichir l'affichage
		void check();
		void play(PlayerHuman p1, PlayerHuman p2, PlayerHuman current, Grid *aire_de_jeu);
};



