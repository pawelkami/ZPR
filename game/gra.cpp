#include "gra.h"

Game::Game()					/// inicjujemy tablice _null'ami
{
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 16; j++)
			board[i][j] = _null;
	x = 0;
	y = 0;
	which = circle; // nie _null poniewaz gdybym dla pustej planszy wywolal condition to okazaloby sie, ze mamy zwyciestwo
}

Game::~Game() { }

bool Game::condition()		/// x, y wspolrzednie, gdzie nowo dodany znak
{
	bool victory;
	int temp;
	int from_x = ((temp = x - 4) > 0 ? temp : 0);		// jesli x - 5 jest ujemne to bedziemy sprawdzac od brzegu tablicy, czyli od 0
	int to_x = ((temp = x + 4) < 16 ? temp : 15);		// analogicznie dla x - 5

	int from_y = ((temp = y - 4) > 0 ? temp : 0);
	int to_y = ((temp = y + 4) < 16 ? temp : 15);

	int from, to;
	//najpierw sprawdzamy czy w prostej pionowej lub poziomej mamy spelniony warunek zwyciestwa

	for (int i = from_x; i <= (from_x + 4); i++)			// prosta pionowa
	{
		from = i;
		to = ((i+4) <= to_x ? i+4 : to_x);

		victory = true;
		for (int j = from; j <= to; j++)
		{
			if (board[j][y] != which)			// jesli w sprawdzanej piatce trafimy na inny znak niz dodany to niespelnione warunki
			{
				victory = false;
				break;
			} // if
		} // for

		if (to == to_x || victory == true) break;
	} // for
	if (victory == true) return victory;


	for (int i = from_y; i <= (from_y + 4); i++)		// prosta pozioma
	{
		from = i;
		to = ((i + 4) <= to_y ? i + 4 : to_y);

		victory = true;
		for (int j = from; j <= to; j++)
		{
			if (board[x][j] != which)			// jesli w sprawdzanej piatce trafimy na inny znak niz dodany to niespelnione warunki
			{
				victory = false;
				break;
			} // if
		} // for

		if (to == to_y || victory == true) break;
	} // for
	if (victory == true) return victory;

	// teraz sprawdzamy warunki zwyciestwa dla przekatnych
	
	int xfrom, yfrom, xto, yto;
	int i, j;

	// wspolrzedne skrajne dla nieregularnych przypadkow w rogach i przy krawedziach planszy
	
	// wpierw od lewego gornego rogu do prawego dolnego

	if ((x - from_x) != (y - from_y))
	{
		int dif = ((x - from_x) < (y - from_y) ? (x - from_x) : (y - from_y) );
		xfrom = x - dif;
		yfrom = y - dif;
	}
	else
	{
		xfrom = from_x;
		yfrom = from_y;
	}
	if ((to_x - x) != (to_y - y))
	{
		int dif = ((to_x - x) < (to_y - y) ? (to_x - x) : (to_y - y));
		xto = x + dif;
		yto = y + dif;
	}
	else
	{
		xto = to_x;
		yto = to_y;
	}

	for (int it = 0; it < 5; it++)
	{
		xfrom += it;
		yfrom += it;
		if (xfrom + 4 > xto || yfrom + 4 > yto) break;

		victory = true;
		for (i = xfrom, j = yfrom; i <= (xfrom + 4) && j <= (yfrom + 4); i++, j++)
		{
			if (board[i][j] != which)
			{
				victory = false;
				break;
			} // if
		} // for
		if (victory == true) break;
	} // for it

	if (victory == true) return victory;
	
	// teraz sprawdzamy warunki zwyciestwa po skosie z lewego dolnego rogu do prawego gornego

	if ((x - from_x) != (to_y - y))
	{
		int dif = ((x - from_x) < (to_y - y) ? (x - from_x) : (to_y - y));
		xfrom = x - dif;
		yto = y + dif;
	}
	else
	{
		xfrom = from_x;
		yfrom = from_y;
	}
	if ((to_x - x) != (y - from_y))
	{
		int dif = ((to_x - x) < (y - from_y) ? (to_x - x) : (y - from_y));
		xto = x + dif;
		yfrom = y - dif;
	}
	else
	{
		xto = to_x;
		yto = to_y;
	}

	for (int it = 0; it < 5; it++)
	{
		xfrom += it;
		yto -= it;
		if (xfrom + 4 > xto || yto - 4 < yfrom) break;

		victory = true;
		for (i = xfrom, j = yto; i <= (xfrom + 4) && j >= (yto - 4); i++, j--)
		{
			if (board[i][j] != which)
			{
				victory = false;
				break;
			} // if
		} // for
		if (victory == true) break;
	} // for it

	if (victory == true) return victory;
	
	return victory;
}

void Game::get_point(int a, int b, _sign w)
{
	x = a;
	y = b;
	which = w;
	board[x][y] = w;
}