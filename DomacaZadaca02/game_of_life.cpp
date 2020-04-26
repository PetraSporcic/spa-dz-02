#include "game_of_life.h"
#include <ctime>

bool game_of_life::slucajna_vrijednost()
{
	int n = rand() % 100 + 1;
	return n <= 25;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	if (_generacija[i][j] == true)
	{
		return true;
	}
	else return false;
}		

game_of_life::game_of_life()
{	
	srand(time(nullptr));

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
	
}

void game_of_life::sljedeca_generacija()
{
	int broj_susjeda = 0;
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			broj_susjeda = _generacija[i - 1][j - 1] + _generacija[i - 1][j] + _generacija[i - 1][j + 1] + _generacija[i][j - 1] 
				+ _generacija[i][j + 1] + _generacija[i + 1][j - 1] + _generacija[i + 1][j] + _generacija[i + 1][j + 1];

			if (broj_susjeda==2)
			{
				_sljedeca_generacija[i][j] = _generacija[i][j];
			}
			else if (broj_susjeda == 3)
			{
				_sljedeca_generacija[i][j] = true;
			}
			else if (broj_susjeda <2 || broj_susjeda>3)
			{
				_sljedeca_generacija[i][j] = false;
			}
		}
	}
	
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j]=_sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::iscrtaj()
{

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (celija_zauzeta(i,j) == true)
			{
				cout << "*";
			}
			else
			{
				cout << ".";
			}
		}
		cout << endl;
	}
}
