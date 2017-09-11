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

using namespace std;

class Token
{
	private :
		short int number = 21; //Correspond au nombre de jetons disponible en début de jeu*
		char type = ' '; //Correspond au type de jeton ( ' ', 'x', 'o'), dépendant du numéro du joueur, par défaut, ' ')*
	public :
		Token();
		bool isEmpty(); //vérifie que le nombre de jetons n'est pas nul == le joueur peut continuer à jouer*
		void setNumber(short int nb);
		void setType(bool tpe);
};

class Grid
{
	private :
		short int colonnes = 7; //définit le nombre de colonnes, par défaut 7
		short int lignes = 6; //définit le nombre de lignes, par défaut 6
		vector<char> grille; //Gère tous les emplacments de l'aire de jeu, et évite de passer par un tableau dynamique
	public :
		Grid(short int COL, short int LIN); //Constructeur, avec les éléments par defauts nombre de ligne et colonne
		void raz(); //Fonction de remise à zéro de l'aire de jeu
		bool gIsFull(); //Vérifie si l'aire de jeu est pleine
		bool cIsFull(short int COL);
		short int getSize();
};

class P4
{
	private :

	public :
		P4();
		void start();
		void quit();
		void display();//Permet de rafraichir l'affichage
};


class Player
{
	private :
	public :
		Player(bool type);
		virtual void play();
};

class PlayerHuman : public Player
{
	private :

	short int tokenNumber;

	public :
		PlayerHuman();
};
