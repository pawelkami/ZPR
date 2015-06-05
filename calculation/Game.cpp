/*!
 *  @file   Game.cpp
 *  @brief File contains implemented methods of a Game class.
 */
#include "Project_declarations.hpp"
#include "Game.hpp"

Game::Game() : oPlayer_(), xPlayer_(), mtx_()
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		board_.push_back( std::vector<std::string>() );
		for (int j = 0; j < BOARD_SIZE; ++j)
			board_[i].push_back(NONE);
	}
	move_ = Move();
	state_ = STILL_PLAYING;
	hasChanged_ = false;
	reseted_ = 0;
	winPnt_.x1 = winPnt_.x2 = winPnt_.x3 = winPnt_.x4 = winPnt_.x5 = -1;
	winPnt_.y1 = winPnt_.y2 = winPnt_.y3 = winPnt_.y4 = winPnt_.y5 = -1;
}

Game::~Game() { }

GameResult Game::checkGame()
{
	if(!hasChanged_)
		return state_;

	if(move_.sign_ == NONE)
		return state_ = STILL_PLAYING;

	if(checkVertically() == VICTORY
		|| checkHorizontally() == VICTORY
		|| checkLeftDownRightUpper() == VICTORY
		|| checkLeftUpperRightDown() == VICTORY)
	{
		move_.sign_ == CIRCLE ? oPlayer_.incrementVictories() : xPlayer_.incrementVictories();		// incrementing victory counter
		return state_ = VICTORY;
	}

	// checking for draw

	return state_ = checkDraw();
}

GameResult Game::checkVertically() const
{
	int from_x = (move_.x_ - 4 > 0 ? move_.x_ - 4 : 0);		// if x_ - 5 is negative then we will check from the border, from 0
	int to_x = (move_.x_ + 4 < BOARD_SIZE ? move_.x_ + 4 : BOARD_SIZE - 1);		// same as for x_ - 5

	int from, to, j;
	GameResult result;

	for (int i = from_x; i <= (from_x + 4); i++)			// vertical straight line
	{
		from = i;
		to = ((i+4) <= to_x ? i+4 : to_x);

		result = VICTORY;
		for ( j = from; j <= to; j++)
		{
			if (board_[j][move_.y_] != move_.sign_)			// if there is other sign than added lastly, interrupt
			{
				result = STILL_PLAYING;
				break;
			} // if
		} // for

		if (to == to_x || result == VICTORY)
		{
			if(result == VICTORY)
			{
				winPnt_.x1 = j-5;
				winPnt_.x2 = j-4;
				winPnt_.x3 = j-3;
				winPnt_.x4 = j-2;
				winPnt_.x5 = j-1;
				winPnt_.y1 = winPnt_.y2 = winPnt_.y3 = winPnt_.y4 = winPnt_.y5 = move_.y_;
			}
			break;
		}
	} // for

	return result;
}

GameResult Game::checkHorizontally() const
{
	GameResult result;
	int from_y = (move_.y_ - 4 > 0 ? move_.y_ - 4 : 0);
	int to_y = (move_.y_ + 4 < BOARD_SIZE ? move_.y_ + 4 : BOARD_SIZE - 1);

	int from, to, j;

	for (int i = from_y; i <= (from_y + 4); i++)		// horizontal straight line
	{
		from = i;
		to = ((i + 4) <= to_y ? i + 4 : to_y);

		result = VICTORY;
		for ( j = from; j <= to; j++)
		{
			if (board_[move_.x_][j] != move_.sign_)			// if there is other sign than added lastly, interrupt
			{
				result = STILL_PLAYING;
				break;
			} // if
		} // for

		if (to == to_y || result == VICTORY)
		{
			if(result == VICTORY)
			{
				winPnt_.y1 = j-5;
				winPnt_.y2 = j-4;
				winPnt_.y3 = j-3;
				winPnt_.y4 = j-2;
				winPnt_.y5 = j-1;
				winPnt_.x1 = winPnt_.x2 = winPnt_.x3 = winPnt_.x4 = winPnt_.x5 = move_.x_;
			}
			break;
		}
	} // for

	return result;
}

GameResult Game::checkLeftUpperRightDown() const
{
	GameResult result = STILL_PLAYING;
	int xfrom, yfrom, xto, yto;
	int i, j;

	// extreme coordinates for irregular cases in the corners and borders
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
		if (result == VICTORY)
		{
			winPnt_.y1 = j-5;
			winPnt_.y2 = j-4;
			winPnt_.y3 = j-3;
			winPnt_.y4 = j-2;
			winPnt_.y5 = j-1;
			winPnt_.x1 = i-5;
			winPnt_.x2 = i-4;
			winPnt_.x3 = i-3;
			winPnt_.x4 = i-2;
			winPnt_.x5 = i-1;
			break;
		}
	} // for it

	return result;
}

GameResult Game::checkLeftDownRightUpper() const
{
	GameResult result = STILL_PLAYING;
	int xfrom, yfrom, xto, yto, i, j;

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
		for ( i = xfrom, j = yto; i <= (xfrom + 4) && j >= (yto - 4); i++, j--)
		{
			if (board_[i][j] != move_.sign_)
			{
				result = STILL_PLAYING;
				break;
			} // if
		} // for
		if (result == VICTORY)
		{
			winPnt_.y1 = j+5;
			winPnt_.y2 = j+4;
			winPnt_.y3 = j+3;
			winPnt_.y4 = j+2;
			winPnt_.y5 = j+1;
			winPnt_.x1 = i-5;
			winPnt_.x2 = i-4;
			winPnt_.x3 = i-3;
			winPnt_.x4 = i-2;
			winPnt_.x5 = i-1;
			break;
		}
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
	WriteLock lock(mtx_);

	if( ++reseted_ == 2 )
	{
		state_ = STILL_PLAYING;
		setBoard(NONE);
		move_.setPoint(-1, -1, NONE);
		hasChanged_ = false;
		winPnt_.x1 = winPnt_.x2 = winPnt_.x3 = winPnt_.x4 = winPnt_.x5 = -1;
		winPnt_.y1 = winPnt_.y2 = winPnt_.y3 = winPnt_.y4 = winPnt_.y5 = -1;
	}
}

Sign Game::addPlayer(const int& id, const std::string& name)
{
	WriteLock lock(mtx_);

	if (oPlayer_.id_ == -1)
	{
		oPlayer_.id_ = id;
		oPlayer_.name_ = name;
		oPlayer_.active_ = true;
		return CIRCLE;
	}
	else if(xPlayer_.id_ == -1)
	{
		xPlayer_.id_ = id;
		xPlayer_.name_ = name;
		xPlayer_.active_ = true;
		return CROSS;
	}
	else
		return NONE;	/// there wasn't empty place so new player wasn't added
}

Move Game::getLastMove() const
{
	ReadLock lock(mtx_);
	return move_;
}

bool Game::makeMove(const int& id, const int& x, const int& y)
{
	WriteLock lock(mtx_);

	if(oPlayer_.id_ == id || xPlayer_.id_ == id)
	{
		if( reseted_ == 2 )
			reseted_ = 0;
		else if(reseted_ == 1)
			return false;

		hasChanged_ = true;
		if(oPlayer_.id_ == id)
			setPoint(x, y, CIRCLE);
		else
			setPoint(x, y, CROSS);

		return true;
	}
	return false;
}

std::string Game::getOpponentsName(const int& id) const
{
	ReadLock lock(mtx_);
	if(oPlayer_.id_ == id)
		return xPlayer_.name_;
	else if(xPlayer_.id_ == id)
		return oPlayer_.name_;
	else
		return "";
}

bool Game::hasPlayer(const int& id) const
{
	ReadLock lock(mtx_);
	return (xPlayer_.id_ == id || oPlayer_.id_ == id);
}

bool Game::isFull() const
{
	ReadLock lock(mtx_);
	return xPlayer_.id_ != -1;		/// game is not full if there is no second player
}

bool Game::isEmpty() const
{
	ReadLock lock(mtx_);
	return (oPlayer_.id_ == -1 || oPlayer_.active_ == false) && (xPlayer_.id_ == -1 || xPlayer_.active_ == false);
}

bool Game::setPlayerInactive(int id)
{
	WriteLock lock(mtx_);
	if(oPlayer_.id_ == id || xPlayer_.id_ == id)
	{
		if(oPlayer_.id_ == id)
			oPlayer_.active_ = false;
		else
			xPlayer_.active_ = false;
	}
	return false;
}

bool Game::isOpponentInactive(int id) const
{
	ReadLock lock(mtx_);
	if((oPlayer_.id_ == id && !xPlayer_.active_) || (xPlayer_.id_ == id && !oPlayer_.active_))
		return true;
	else
		return false;
}

WinnerPoints Game::getWinnerPoints() const
{
	ReadLock lock(mtx_);
	return winPnt_;
}
