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
		short int number = 21; //Correspond au nombre de jetons disponible en début de jeu 
		char type = ' '; //Correspond au type de jeton ( ' ', 'x', 'o'), dépendant du numéro du joueur, par défaut, ' ')
	public :
		Token();
		void playtoken(int COL);
		void isEmpty();
};

class Grid
{
	private :
		short int colonnes;
		short int lignes;
		vector<char> grille;
	public :
		Grid(short int colonnes = 7, short int lignes = 6);
		void raz();
		void refresh();
		void isFull(int COL);
};

class P4
{
	private :

	public :
		P4();
		void start();
		void quit();
		void display();
};


class Player 
{
	private :
	bool type;
	token 
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
}
