/*
 *  File contains implemented methods of a Game class.
 */

#include "Game.hpp"

Game::Game() : oPlayer(), xPlayer(), mtx()					/// inicjujemy tablice EMPTY'ami
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		board_.push_back( std::vector<std::string>() );
		for (int j = 0; j < BOARD_SIZE; ++j)
			board_[i].push_back(NONE);
	}
	move_ = Move();
	state_ = STILL_PLAYING;
	hasChanged = false;
	reseted_ = 0;
}

Game::~Game() { }

GameResult Game::checkGame()
{
	if(!hasChanged)
		return state_;

	if(move_.sign_ == NONE)
		return state_ = STILL_PLAYING;

	if(checkVertically() == VICTORY
		|| checkHorizontally() == VICTORY
		|| checkLeftDownRightUpper() == VICTORY
		|| checkLeftUpperRightDown() == VICTORY)
	{
		move_.sign_ == CIRCLE ? oPlayer.incrementVictories() : xPlayer.incrementVictories();		// incrementing victory counter
		return state_ = VICTORY;
	}

	// checking for draw

	return state_ = checkDraw();
}

GameResult Game::checkVertically() const
{
	int from_x = (move_.x_ - 4 > 0 ? move_.x_ - 4 : 0);		// if x_ - 5 is negative then we will check from the border, from 0
	int to_x = (move_.x_ + 4 < BOARD_SIZE ? move_.x_ + 4 : BOARD_SIZE - 1);		// same as for x_ - 5

	int from, to;
	GameResult result;

	for (int i = from_x; i <= (from_x + 4); i++)			// vertical straight line
	{
		from = i;
		to = ((i+4) <= to_x ? i+4 : to_x);

		result = VICTORY;
		for (int j = from; j <= to; j++)
		{
			if (board_[j][move_.y_] != move_.sign_)			// if there is other sign than added lastly, interrupt
			{
				result = STILL_PLAYING;
				break;
			} // if
		} // for

		if (to == to_x || result == VICTORY) break;
	} // for

	return result;
}

GameResult Game::checkHorizontally() const
{
	GameResult result;
	int from_y = (move_.y_ - 4 > 0 ? move_.y_ - 4 : 0);
	int to_y = (move_.y_ + 4 < BOARD_SIZE ? move_.y_ + 4 : BOARD_SIZE - 1);

	int from, to;

	for (int i = from_y; i <= (from_y + 4); i++)		// horizontal straight line
	{
		from = i;
		to = ((i + 4) <= to_y ? i + 4 : to_y);

		result = VICTORY;
		for (int j = from; j <= to; j++)
		{
			if (board_[move_.x_][j] != move_.sign_)			// if there is other sign than added lastly, interrupt
			{
				result = STILL_PLAYING;
				break;
			} // if
		} // for

		if (to == to_y || result == VICTORY) break;
	} // for

	return result;
}

GameResult Game::checkLeftUpperRightDown() const
{
	GameResult result = STILL_PLAYING;
	int xfrom, yfrom, xto, yto;
	int i, j;

	// wspolrzedne skrajne dla nieregularnych przypadkow w rogach i przy krawedziach planszy
	int from_x = (move_.x_ - 4 > 0 ? move_.x_ - 4 : 0);
	int to_x = (move_.x_ + 4 < BOARD_SIZE ? move_.x_ + 4 : BOARD_SIZE - 1);
	int from_y = (move_.y_ - 4 > 0 ? move_.y_ - 4 : 0);
	int to_y = (move_.y_ + 4 < BOARD_SIZE ? move_.y_ + 4 : BOARD_SIZE - 1);


	if ((move_.x_ - from_x) != (move_.y_ - from_y))
	{
		int dif = ((move_.x_ - from_x) < (move_.y_ - from_y) ? (move_.x_ - from_x) : (move_.y_ - from_y) );
		xfrom = move_.x_ - dif;
		yfrom = move_.y_ - dif;
		from_x = xfrom;
		from_y = yfrom;
	}
	else
	{
		xfrom = from_x;
		yfrom = from_y;
	}
	if ((to_x - move_.x_) != (to_y - move_.y_))
	{
		int dif = ((to_x - move_.x_) < (to_y - move_.y_) ? (to_x - move_.x_) : (to_y - move_.y_));
		xto = move_.x_ + dif;
		yto = move_.y_ + dif;
		to_x = xto;
		to_y = yto;
	}
	else
	{
		xto = to_x;
		yto = to_y;
	}

	for (int it = 0; it < 5; it++)
	{
		xfrom = from_x + it;
		yfrom = from_y + it;

		if (xfrom + 4 > xto || yfrom + 4 > yto) break;

		result = VICTORY;
		for (i = xfrom, j = yfrom; i <= (xfrom + 4) && j <= (yfrom + 4); i++, j++)
		{
			if (board_[i][j] != move_.sign_)
			{
				result = STILL_PLAYING;
				break;
			} // if
		} // for
		if (result == VICTORY) break;
	} // for it

	return result;
}

GameResult Game::checkLeftDownRightUpper() const
{
	GameResult result = STILL_PLAYING;
	int xfrom, yfrom, xto, yto;

	int from_x = (move_.x_ - 4 > 0 ? move_.x_ - 4 : 0);
	int to_x = (move_.x_ + 4 < BOARD_SIZE ? move_.x_ + 4 : BOARD_SIZE - 1);

	int from_y = (move_.y_ - 4 > 0 ? move_.y_ - 4 : 0);
	int to_y = (move_.y_ + 4 < BOARD_SIZE ? move_.y_ + 4 : BOARD_SIZE - 1);

	if ((move_.x_ - from_x) != (to_y - move_.y_))
	{
		int dif = ((move_.x_ - from_x) < (to_y - move_.y_) ? (move_.x_ - from_x) : (to_y - move_.y_));
		xfrom = move_.x_ - dif;
		yto = move_.y_ + dif;
		from_x = xfrom;
		to_y = yto;
	}
	else
	{
		xfrom = from_x;
		yto = to_y;
	}
	if ((to_x - move_.x_) != (move_.y_ - from_y))
	{
		int dif = ((to_x - move_.x_) < (move_.y_ - from_y) ? (to_x - move_.x_) : (move_.y_ - from_y));
		xto = move_.x_ + dif;
		yfrom = move_.y_ - dif;
		to_x = xto;
		from_y = yfrom;
	}
	else
	{
		xto = to_x;
		yfrom = from_y;
	}

	for (int it = 0; it < 5; it++)
	{
		xfrom = from_x + it;
		yto = to_y - it;

		if (xfrom + 4 > xto || yto - 4 < yfrom) break;

		result = VICTORY;
		for (int i = xfrom, j = yto; i <= (xfrom + 4) && j >= (yto - 4); i++, j--)
		{
			if (board_[i][j] != move_.sign_)
			{
				result = STILL_PLAYING;
				break;
			} // if
		} // for
		if (result == VICTORY) break;
	} // for it

	return result;
}

GameResult Game::checkDraw() const
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

void Game::setPoint(const int& x, const int& y, const Sign& s)
{
	move_.setPoint(x, y, s);
	board_[move_.x_][move_.y_] = s;
}

void Game::setBoard(const Sign& sign)
{
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
	WriteLock lock(mtx);

	if( ++reseted_ == 2 )
	{
		state_ = STILL_PLAYING;
		setBoard(NONE);
		move_.setPoint(-1, -1, NONE);
		hasChanged = false;
	}
}

Sign Game::addPlayer(const int& id, const std::string& name)
{
	WriteLock lock(mtx);

	if (oPlayer.id == -1)
	{
		oPlayer.id = id;
		oPlayer.name = name;
		oPlayer.active = true;
		return CIRCLE;
	}
	else if(xPlayer.id == -1)
	{
		xPlayer.id = id;
		xPlayer.name = name;
		xPlayer.active = true;
		return CROSS;
	}
	else
		return NONE;	/// there wasn't empty place so new player wasn't added
}

Move Game::getLastMove() const
{
	ReadLock lock(mtx);
	return move_;
}

bool Game::makeMove(const int& id, const int& x, const int& y)
{
	WriteLock lock(mtx);

	if(oPlayer.id == id || xPlayer.id == id)
	{
		if( reseted_ == 2 )
			reseted_ = 0;
		else if(reseted_ == 1)
			return false;

		hasChanged = true;
		if(oPlayer.id == id)
			setPoint(x, y, CIRCLE);
		else
			setPoint(x, y, CROSS);

		return true;
	}
	return false;
}

std::string Game::getOpponentsName(const int& id) const
{
	ReadLock lock(mtx);
	if(oPlayer.id == id)
		return xPlayer.name;
	else if(xPlayer.id == id)
		return oPlayer.name;
	else
		return "";
}

bool Game::hasPlayer(const int& id) const
{
	ReadLock lock(mtx);
	return (xPlayer.id == id || oPlayer.id == id);
}

bool Game::isFull() const
{
	ReadLock lock(mtx);
	return xPlayer.id != -1;		/// game is not full if there is no second player
}

bool Game::setPlayerInactive(int id)
{
	WriteLock lock(mtx);
	if(oPlayer.id == id || xPlayer.id == id)
	{
		if(oPlayer.id == id)
			oPlayer.active = false;
		else
			xPlayer.active = false;
	}
	return false;
}

bool Game::isOpponentInactive(int id) const
{
	ReadLock lock(mtx);
	if((oPlayer.id == id && !xPlayer.active) || (xPlayer.id == id && !oPlayer.active))
		return true;
	else
		return false;
}
