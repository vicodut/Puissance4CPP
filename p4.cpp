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

void Grid::raz()
{
	for(int i = 0; i <= grille.size() - 1; i++)
	{
		grille[i] = ' ';
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
