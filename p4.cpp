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

#include "p4.hpp"

void menu()
{
	string tmp1;
	short int tmp = 0;
	P4 JEUX;
	Grid AIRE;
	//PlayerHuman playerInit;
	//playerInit.setTokenType('x');
	PlayerHuman player1;
	player1.setTokenType('x');
	PlayerHuman player2;
	player2.setTokenType('y');
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
		player1.setType(0);
		cout << "Entrez un nom pour le 2eme joueur :" << endl;
		cin >> tmp1;
		player2.setName(tmp1);
		player2.setType(1);
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
		JEUX.play(player1, &AIRE);
		JEUX.play(player2, &AIRE);
		}

		cout <<"partie terminée." << endl;
		system("pause");
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
	status = "ACTIVE";
}

Token::Token()
{
	number = 21;
	type = ' ';
}

bool Token::isEmpty()
{
	if(number <= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Token::setNumber(short int nb)
{
	number = nb;
}

void Token::setType(bool tpe)
{
	if(tpe == 0)
	{
		type = 'x';
	}
	else if (tpe == 1)
	{
		type = 'o';
	}
	else
	{
		cout << "Erreur, trop de joueurs" << endl;
	}
}

Grid::Grid(short int COL, short int LIN)
{
	colonnes = COL;
	lignes = LIN;
	int size = COL*LIN;
	grille.push_back (size);
}

Grid::Grid()
{
	colonnes = 1;
	lignes = 1;
	int size = colonnes*lignes;
	for(int i = 0; i < colonnes * lignes ; i++)
	{
		grille.push_back (' ');
	}

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
		grille.push_back (' ');
	}
}

bool Grid::gIsFull()
{
	int tmp = 0;
	for(int i = 0; i < grille.size(); i++)
	{
		if(grille[i] == 'x' || grille[i] == 'o')
		{
			tmp++;
		}
	}
	if(tmp == grille.size())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool Grid::cIsFull(short int COL)
{
	int tmp = 0;
	for(int i =  COL; i < grille.size(); i = i + colonnes)
	{
		if(grille[i] == 'x' || grille[i] == 'o')
		{
			tmp++;
		}
	}
	if(tmp == lignes)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
short int Grid::getElem(short int COL)
{
    	for(int i = 0; i < colonnes; i++)
    	{
    	if(grille[colonnes + COL] == ' ')
		{
			COL += colonnes;
			//getElem(COL + colonnes);
		}
		else
		{
			return COL;
		}
    	}

}

/*void Grid::getCol()
{

}

void Grid::getLin()
{

}*/

void P4::display(Grid *aire_de_jeu)
{
	int lineA = 0;
	system("CLS");
	for(int i = aire_de_jeu->lignes; i >= 1; i--)
	{
		cout << i <<"| ";
		for(int j = lineA * aire_de_jeu->colonnes; j < lineA * aire_de_jeu->colonnes + aire_de_jeu->colonnes; j++)
		{
			cout << aire_de_jeu->grille[j];
			cout << " ";
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
		cout << l + 1 <<" ";
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

void PlayerHuman::setType(bool tpe)
{
    playerType = tpe;
    if(playerType == 0)
    {
    	tokenType = 'x';
    }
    else
    {
    	tokenType = 'o';
    }
}

void PlayerHuman::setTokenType(char temp)
{
	tokenType = temp;
}

void P4::check()
{

}

void P4::play(PlayerHuman p, Grid *aire_de_jeu)
{
	short int colPlay = 0;
	cout << "entrez une colonne a jouer pour : " << p.playerName << endl;
	cin >> colPlay;
	cin.ignore();
	system("pause");
	cout << p.playerName << " joue la colonne: " << colPlay <<endl;
	short int tmp3 = aire_de_jeu->getElem( colPlay );
	if(aire_de_jeu->grille[tmp3] == ' ')
	{
		aire_de_jeu->grille[tmp3] = p.tokenType;
	}
	else
	{
		cout << "colonne pleine" << endl;
	}

	display(aire_de_jeu);

}

void P4::play(PlayerHuman p, Grid *aire_de_jeu, const short int init)
{
	aire_de_jeu->grille[init] = p.tokenType;
	display(aire_de_jeu);
}

