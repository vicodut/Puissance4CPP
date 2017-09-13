/*
_____________________________________________________________________________________________________________________________________
|																																	|
|													Puissance 4 C++ Groupe 1  INFO3													|
|																																	|
|															Herbin Armelle															|
|															Laporte Nathan															|
|															Lefaure Antoine 														|
|															Loussaut Morgan															|
|																																	|
|																																	|
|																												ESME-Sudria 2017	|
|				 																								Ver 0.1A			|
-------------------------------------------------------------------------------------------------------------------------------------
*/

#include "p4.hpp"

void menu()
{
	string tmp1;
	short int tmp = 0;
	P4 JEUX;
	Grid AIRE;
	PlayerHuman player1;
	Token tokenp1;
	tokenp1.setType('x');
	PlayerHuman player2;
	Token tokenp2;
	tokenp2.setType('o');
	int comm = 0;
	cout << "Bienvenue dans le jeu puissance 4" << endl;
	cout << "Selectionnez une option : " << endl;
	cout << "1: Commencer une nouvelle partie." << endl << "2: Charger une partie." << endl << "3: Quitter." <<endl;
	cin >> comm;
	switch(comm)
	{
		case 1:

		cout << "Entrez un nom pour le 1er joueur :" << endl;
		cin >> tmp1;
		player1.setName(tmp1);
		cout << "Entrez un nom pour le 2eme joueur :" << endl;
		cin >> tmp1;
		player2.setName(tmp1);
		cout << "Entrez un nombre de colonnes :" << endl;
		cin >> tmp;
		AIRE.setCol(tmp);
		cout << "Entrez un nombre de lignes :" << endl;
		cin >> tmp;
		cin.get();
		AIRE.setLin(tmp);
		AIRE.resize();
		JEUX.display(&AIRE);
		while(!AIRE.gIsFull())
		{
		JEUX.play(player1, &AIRE, &tokenp1);
		JEUX.play(player2, &AIRE, &tokenp2);
		}

		cout <<"partie terminée." << endl;
        break;
		case 2:


			break;
		case 3:
			cout << "Merci, au revoir";
			break;
		default :
			menu();
	}
}

P4::P4()
{
}

Token::Token()
{

}


void Token::setType(char tpe)
{
	this->type = tpe;
}

char* Token::getType()
{
	return &(this->type);
}


Grid::Grid()
{

}
void Grid::setCol(int COL)
{
	colonnes = COL;
}
void Grid::setLin(int LIN)
{
	lignes = LIN;
}
void Grid::resize()
{
	for(int i = 0; i < lignes * colonnes; i++)
	{
		grille.push_back (nullptr);
	}
}

bool Grid::gIsFull()
{
	int tmp = 0;
	for(int i = 0; i < grille.size(); i++)
	{
		if(grille[i] == nullptr)
		{
			tmp++;
		}
	}
	if(tmp == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Grid::cIsFull(short int COL)
{
	int tmp = 0;
	for(int i =  COL; i < grille.size(); i = i + colonnes)
	{
		if(grille[i] == nullptr)
		{
			tmp++;
		}
	}
	if(tmp == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
short int Grid::getElem(short int COL)
{
    	for(int i = 0; i < colonnes; i++)
    	{
    	if(grille[colonnes + COL] == nullptr)
		{
			COL += colonnes;
		}
		else
		{
			return COL;
		}
    	}

}

void P4::display(Grid *aire_de_jeu)
{
	int lineA = 0;

	for(int i = aire_de_jeu->lignes; i >= 1; i--)
	{
		cout << i <<"| ";
		for(int j = lineA * aire_de_jeu->colonnes; j < lineA * aire_de_jeu->colonnes + aire_de_jeu->colonnes; j++)
		{
			char *type = aire_de_jeu->grille[j]->getType();
			if (type) {
				cout << *type;
			} else {
				cout << "  ";
			}
		}
		lineA++;
		cout << "|";
		cout << endl;
	}
	for(int k = 0; k < 2 * aire_de_jeu->colonnes + 3; k++)
	{
		cout << "-";
	}
	cout << endl << "   " ;
	for(int l = 0; l < aire_de_jeu->colonnes; l++)
	{
		cout << l <<" ";
	}
	cout << endl;
}
Player::Player()
{

}

PlayerHuman::PlayerHuman()
{

}


void PlayerHuman::setName(string name)
{
    playerName= name;
}


void P4::check()
{

}

void P4::play(PlayerHuman p, Grid *aire_de_jeu, Token * tkn)
{
	short int colPlay = 0;
	cout << "entrez une colonne a jouer pour : " << p.playerName << endl;
	cin >> colPlay;
	cin.ignore();


	cout << p.playerName << " joue la colonne: " << colPlay <<endl;
	short int tmp3 = aire_de_jeu->getElem(colPlay);
	//cout << tmp3 << end;
	if(aire_de_jeu->grille[tmp3] == nullptr)
	{
		aire_de_jeu->grille[tmp3] = tkn;
	}
	else
	{
		cout << "colonne pleine" << endl;
	}

	display(aire_de_jeu);

}
