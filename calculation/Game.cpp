#include "Game.hpp"

Game::Game() : oPlayer(), xPlayer(), mtx()					/// inicjujemy tablice EMPTY'ami
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		board_.push_back( std::vector<std::string>() );
		for (int j = 0; j < BOARD_SIZE; ++j)
			board_[i].push_back(NONE);
	}
	x_ = -1;
	y_ = -1;
	which_ = NONE;
	state_ = STILL_PLAYING;
	hasChanged = false;
}

Game::~Game() { }

GameResult Game::condition()		/// 0 nic, 1 remis, 2 wygrana
{
	if(!hasChanged)
		return state_;
	if(which_ == NONE)
		return state_ = STILL_PLAYING;

	//najpierw sprawdzamy czy w prostej pionowej lub poziomej mamy spelniony warunek zwyciestwa
	if(checkVertically() == VICTORY
		|| checkHorizontally() == VICTORY
		|| checkLeftDownRightUpper() == VICTORY
		|| checkLeftUpperRightDown() == VICTORY)
	{
			return state_ = VICTORY;
	}

	// sprawdzamy czy nie remis

	return state_ = checkDraw();
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

void Game::setPoint(int a, int b, Sign w)
{
	std::lock_guard<std::mutex> lock(mtx);
	x_ = a;
	y_ = b;
	which_ = w;
	board_[x_][y_] = w;
}

void Game::setBoard(Board board)
{
	std::lock_guard<std::mutex> lock(mtx);
	board_ = board;
}

void Game::setBoard(Sign sign)
{
	std::lock_guard<std::mutex> lock(mtx);
	for(auto& board : board_)
	{
		for(auto& field : board)
		{
			field = sign;
		}
	}
}

void Game::reset()
{
	//std::lock_guard<std::mutex> lock(mtx);        //zablokowało mi serwer

	if( getReseted() == true )
		return;

  setReseted(true);
  state_ = STILL_PLAYING;
	setBoard(NONE);
	x_ = -1;
  y_ = -1;
	which_ = "";
	hasChanged = false;
}


void Game::displayBoard()
{
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

Sign Game::addPlayer(int id, std::string name)
{
	std::lock_guard<std::mutex> lock(mtx);

	if (oPlayer.id == -1)
	{
		oPlayer.id = id;
		oPlayer.name = name;
		return CIRCLE;
	}
	else if(xPlayer.id == -1)
	{
		xPlayer.id = id;
		xPlayer.name = name;
		return CROSS;
	}
	else
		return NONE;	/// nie brakowało graczy, więc nowy nie został dodany
									/// możemy też zamienić to na rzucanie wyjątkiem
}

Move Game::getLastMove()
{
	std::lock_guard<std::mutex> lock(mtx);
	return Move(x_, y_, which_);
}

void Game::makeMove(int id, int x, int y)
{
	if(oPlayer.id == id || xPlayer.id == id)
	{
		hasChanged = true;
		setReseted(false);
		if(oPlayer.id == id)
			setPoint(x, y, CIRCLE);
		else
			setPoint(x, y, CROSS);
	}
}

std::string Game::getOpponentsName(int id)
{
	if(oPlayer.id == id)
		return xPlayer.name;
	else if(xPlayer.id == id)
		return oPlayer.name;
	else
		return "";
}

bool Game::hasPlayer(int id)
{
	return (xPlayer.id == id || oPlayer.id == id);
}

bool Game::isFull()
{
	return xPlayer.id != -1;		/// gra nie jest pełna, jeśli nie ma w niej drugiego gracza
}

GameList::GameList() : list(), mtx()
{
	firstUnusedID = 0;
}

GameList::~GameList() {}

PGameList GameList::pInstance = nullptr;

PGameList GameList::getInstance()
{
	if(!pInstance)
	{
		pInstance = PGameList(new GameList());
	}

	return pInstance;
}

int GameList::getNewID()
{
	std::lock_guard<std::mutex> lock(mtx);
	int ret = firstUnusedID;
	firstUnusedID = (firstUnusedID + 1) % 100000;
	return ret;
}

Sign GameList::addPlayer(int id, std::string name)
{
	std::lock_guard<std::mutex> lock(mtx);
	for(Game& game : list)
	{
		if(!game.isFull())
		{
			return game.addPlayer(id, name);
		}
	}

	list.emplace_back();			/// dodanie nowej gry
	                          /// nie możemu tu tak po prostu użyć push_back, bo mutex nie ma konstruktora kopiującego
	return list.back().addPlayer(id, name);
}

std::string GameList::getOpponentsName(int id)
{
	for(Game& game : list)
	{
		if(game.hasPlayer(id))
			return game.getOpponentsName(id);
	}
	return "";
}

Move GameList::getLastMove(int id)
{
	for(Game& game : list)
	{
		if(game.hasPlayer(id))
			return game.getLastMove();
	}
	return Move();
}

void GameList::makeMove(int id, int x, int y)
{
	for(Game& game : list)
	{
		if(game.hasPlayer(id))
		{
			game.makeMove(id, x ,y);
			break;
		}
	}
}

GameResult GameList::getResult(int id)
{
	for(Game& game : list)
	{
		if(game.hasPlayer(id))
			return game.condition();
	}
	return STILL_PLAYING;
}

void GameList::resetGame(int id)
{
	for(Game& game : list)
	{
		if(game.hasPlayer(id))
		{
			game.reset();
			break;
		}
	}
}
