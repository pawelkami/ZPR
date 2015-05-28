#include "Game.hpp"

PGame Game::pInstance = nullptr;

PGame Game::getInstance()
{
	if(!pInstance)
	{
		pInstance = PGame(new Game());
	}

	return pInstance;
}

Game::Game()					/// inicjujemy tablice EMPTY'ami
{
	counter = 0;
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		board_.push_back( std::vector<std::string>() );
		for (int j = 0; j < BOARD_SIZE; ++j)
			board_[i].push_back(NONE);
	}
	x_ = 0;
	y_ = 0;
	which_ = CIRCLE; // nie EMPTY poniewaz gdybym dla pustej planszy wywolal condition to okazaloby sie, ze mamy zwyciestwo
}

Game::~Game() { }

GameResult Game::condition()		/// 0 nic, 1 remis, 2 wygrana
{
	GameResult result = STILL_PLAYING;
	//najpierw sprawdzamy czy w prostej pionowej lub poziomej mamy spelniony warunek zwyciestwa

	if(checkVertically() == VICTORY
		|| checkHorizontally() == VICTORY
		|| checkLeftDownRightUpper() == VICTORY
		|| checkLeftUpperRightDown() == VICTORY)
		return VICTORY;

	// sprawdzamy czy nie remis

	result = checkDraw();

	return result;
}

GameResult Game::checkVertically()
{
	int from_x = (x_ - 4 > 0 ? x_ - 4 : 0);		// jesli x_ - 5 jest ujemne to bedziemy sprawdzac od brzegu tablicy, czyli od 0
	int to_x = (x_ + 4 < BOARD_SIZE ? x_ + 4 : BOARD_SIZE - 1);		// analogicznie dla x_ - 5

	int from, to;
	GameResult result;

	for (int i = from_x; i <= (from_x + 4); i++)			// prosta pionowa
	{
		from = i;
		to = ((i+4) <= to_x ? i+4 : to_x);

		result = VICTORY;
		for (int j = from; j <= to; j++)
		{
			if (board_[j][y_] != which_)			// jesli w sprawdzanej piatce trafimy na inny znak niz dodany to niespelnione warunki
			{
				result = STILL_PLAYING;
				break;
			} // if
		} // for

		if (to == to_x || result == VICTORY) break;
	} // for

	return result;
}

GameResult Game::checkHorizontally()
{
	GameResult result;
	int from_y = (y_ - 4 > 0 ? y_ - 4 : 0);
	int to_y = (y_ + 4 < BOARD_SIZE ? y_ + 4 : BOARD_SIZE - 1);

	int from, to;

	for (int i = from_y; i <= (from_y + 4); i++)		// prosta pozioma
	{
		from = i;
		to = ((i + 4) <= to_y ? i + 4 : to_y);

		result = VICTORY;
		for (int j = from; j <= to; j++)
		{
			if (board_[x_][j] != which_)			// jesli w sprawdzanej piatce trafimy na inny znak niz dodany to niespelnione warunki
			{
				result = STILL_PLAYING;
				break;
			} // if
		} // for

		if (to == to_y || result == VICTORY) break;
	} // for

	return result;
}

GameResult Game::checkLeftUpperRightDown()
{
	GameResult result = STILL_PLAYING;
	int xfrom, yfrom, xto, yto;
	int i, j;

	int from_x = (x_ - 4 > 0 ? x_ - 4 : 0);
	int to_x = (x_ + 4 < BOARD_SIZE ? x_ + 4 : BOARD_SIZE - 1);
	int from_y = (y_ - 4 > 0 ? y_ - 4 : 0);
	int to_y = (y_ + 4 < BOARD_SIZE ? y_ + 4 : BOARD_SIZE - 1);

	// wspolrzedne skrajne dla nieregularnych przypadkow w rogach i przy krawedziach planszy

	// wpierw od lewego gornego rogu do prawego dolnego

	if ((x_ - from_x) != (y_ - from_y))
	{
		int dif = ((x_ - from_x) < (y_ - from_y) ? (x_ - from_x) : (y_ - from_y) );
		xfrom = x_ - dif;
		yfrom = y_ - dif;
	}
	else
	{
		xfrom = from_x;
		yfrom = from_y;
	}
	if ((to_x - x_) != (to_y - y_))
	{
		int dif = ((to_x - x_) < (to_y - y_) ? (to_x - x_) : (to_y - y_));
		xto = x_ + dif;
		yto = y_ + dif;
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

		result = VICTORY;
		for (i = xfrom, j = yfrom; i <= (xfrom + 4) && j <= (yfrom + 4); i++, j++)
		{
			if (board_[i][j] != which_)
			{
				result = STILL_PLAYING;
				break;
			} // if
		} // for
		if (result == VICTORY) break;
	} // for it

	return result;
}

/**
	Metoda sprawdzajaca warunek zwyciestwa po skosie od lewego dolnego rogu do prawego gornego.
*/
GameResult Game::checkLeftDownRightUpper()
{
	GameResult result = STILL_PLAYING;
	int xfrom, yfrom, xto, yto;

	int from_x = (x_ - 4 > 0 ? x_ - 4 : 0);
	int to_x = (x_ + 4 < BOARD_SIZE ? x_ + 4 : BOARD_SIZE - 1);

	int from_y = (y_ - 4 > 0 ? y_ - 4 : 0);
	int to_y = (y_ + 4 < BOARD_SIZE ? y_ + 4 : BOARD_SIZE - 1);

	if ((x_ - from_x) != (to_y - y_))
	{
		int dif = ((x_ - from_x) < (to_y - y_) ? (x_ - from_x) : (to_y - y_));
		xfrom = x_ - dif;
		yto = y_ + dif;
	}
	else
	{
		xfrom = from_x;
		yto = to_y;
	}
	if ((to_x - x_) != (y_ - from_y))
	{
		int dif = ((to_x - x_) < (y_ - from_y) ? (to_x - x_) : (y_ - from_y));
		xto = x_ + dif;
		yfrom = y_ - dif;
	}
	else
	{
		xto = to_x;
		yfrom = from_y;
	}

	for (int it = 0; it < 5; it++)
	{
		xfrom += it;
		yto -= it;
		if (xfrom + 4 > xto || yto - 4 < yfrom) break;

		result = VICTORY;
		for (int i = xfrom, j = yto; i <= (xfrom + 4) && j >= (yto - 4); i++, j--)
		{
			if (board_[i][j] != which_)
			{
				result = STILL_PLAYING;
				break;
			} // if
		} // for
		if (result == VICTORY) break;
	} // for it

	return result;
}

GameResult Game::checkDraw()
{
	GameResult result = DRAW;

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (board_[i][j] == NONE)
			{
				result = STILL_PLAYING;
				break;
			} // if
		} // for
		if (result == STILL_PLAYING) break;
	} // for

	return result;
}

void Game::get_point(int a, int b, Sign w)
{
	x_ = a;
	y_ = b;
	which_ = w;
	board_[x_][y_] = w;
}

void Game::setBoard(Board board)
{
	board_ = board;
}

void Game::setBoard(Sign sign)
{
	for(auto& row : board_)
	{
		for(auto& col : board)
		{
			col = sign;
		}
	}
}

void Game::resetGame()
{
	setBoard(NONE);
	counter = 0;
}

Sign Game::getSign()
{
	if(counter == 0)
	{
		counter++;
		return CIRCLE;
	}
	else if (counter == 1)
	{
		counter++;
		return CROSS;
	}
	return NONE;
}

void Game::displayBoard()
{
	std::cout << counter << std::endl;
	for(auto row : board_)
	{
		for(auto col : row)
		{
			if( col == NONE )
				std::cout << "_";
			else
				std::cout << col;
		}
		std::cout << std::endl;
	}
}

void Game::setPlayerName(std::string name)
{
	std::cout << name << std::endl;
	if (counter == 1)
	{
		name1 = name;
	}
	else if (counter == 2)
	{
		name2 = name;
	}
}

std::string Game::getPlayerName(int i)
{
	std::cout << "name1: " << name1 << " name2: " << name2 << std::endl;
	return ( i == 1 ? name1 : name2 );
}
