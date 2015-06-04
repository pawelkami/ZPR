/*!
 *  @file   Game.hpp
 *  @brief Header file for Game class of Tic Tac Toe game.
 */

#ifndef GAME_HPP
#define GAME_HPP

#include <cstdlib>
#include <iostream>
#include <vector>
#include <list>
#include <shared_mutex>
#include "Player.hpp"
#include "Move.hpp"
#include "Project_declarations.hpp"
//#include <boost/thread/shared_mutex.hpp>

/*!
 * Enum representing the result of a Game.
 *
 */
enum GameResult { STILL_PLAYING, DRAW, VICTORY };

/*!
 *	\brief Struct representing coordinates of points which resulted in a VICTORY.
 */
struct WinnerPoints
{
	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
};


/*!
 *	\brief A class representing single Game.
 * It provides methods for checking the result of
 * a Game and setting it up.
 */
class Game
{
private:
	/*!
	 *	Method used for checking if there is a VICTORY Vertically.
	 *	@return Game result after checking
	 */
	GameResult checkVertically() const;

	/*!
		*	Method used for checking if there is a VICTORY Horizontally.
		*	@return Game result after checking
		*/
	GameResult checkHorizontally() const;

	/*!
 	 *	Method used for checking if there is a VICTORY from left down corner to right upper.
	 *	@return Game result after checking
	 */
	GameResult checkLeftDownRightUpper() const;

	/*!
	 *	Method used for checking if there is a VICTORY from left upper to right down.
	 *	@return Game result after checking
	 */
	GameResult checkLeftUpperRightDown() const;

	/*!
	 *	Method used for checking if there is a DRAW.
	 *	@return Game result after checking
	 */
	GameResult checkDraw() const;


	/*!
	 *	Method used for setting the latest move.
	 *	@param x x coordinate
	 * @param y y coordinate
	 * @param s Sign that made a move.
	 */
	void setPoint(const int& x, const int& y, const Sign& s);

	/*!
	 * Method fills board with sign passed as argument.
	 * @param sign Sign that will be used to fill the board.
	 *
	 */
	void setBoard(const Sign& sign);


	/*!
	 *	Object of a class Player, representing player with CIRCLE.
	 */
	Player oPlayer;

	/*!
	 *	Object of a class Player, representing player with CROSS.
	 */
	Player xPlayer;

	/*!
	 * Object of class Move representing last move that was done.
	 */
	Move move_;

	/*!
	 * Game board used for representing actual state of a game.
	 */
	Board board_;

	/**!
	  * Flag telling if a Game is reseted or not. Game is reseted when a flag is set to 2.
		* If flag is equal to 1 it means that one more player is needed to @see reset().
		* If flag is equal to 0, it means that nobody has invoked the @see reset() method yet.
		*/
	int reseted_; //flaga mowiaca czy gra jest zresetowana, true - zrestartowana, false - nie

	/*!
	 * Variable used for condition() method. condition() uses it to know if there is a need for checking game.
	 */
	mutable bool hasChanged;

	/*!
	 * An actual state of a game (VICTORY, DRAW, STILL_PLAYING).
	 */
	mutable GameResult state_;

	/*!
	 * Mutex used for synchronizing an access to Game methods.
	 */
	mutable std::shared_timed_mutex mtx;

	/*!
	 *	Struct which contains coordinates of points that has resulted in a VICTORY of a Game.
	 */
	mutable WinnerPoints winPnt;

public:
	/*!
	 * A default constructor. It sets up all the variables at the beggining.
	 */
	Game();

	/*!
	 * Destructor.
	 */
	~Game();

	/*!
	 *	The size of a game board.
	 */
	const int BOARD_SIZE = 16;

	/*!
	 *	Method for returning a private member of a class representing game board.
	 *  @return game board
	 */
	inline Board getBoard() const { return board_; };

	/*!
	 * Resets game to make it ready for play again. Two players are needed to use a function to reset the game.
	 */
	void reset();

	/*!
	 * Adds player to the game.
	 * @param id Player id.
	 * @param name Name of a player.
	 * @return Sign which will be used by a player(CROSS, CIRCLE).
	 */
	Sign addPlayer(const int& id, const std::string& name);

	/*!
	 *  @return last move
	 */
	Move getLastMove() const;

	/*!
	 *	Method for making a move.
	 *  @param id Player id who made a move.
	 *  @param x x coordinate of a move
	 *  @param y y coordinate of a move
	 *  @return true if move was done correctly, false otherwise.
	 */
	bool makeMove(const int& id, const int& x, const int& y);

	/*!
	 *  @param id Player id
	 *	@return Name of a opponent. If there is no such id, it returns null string.
	 */
	std::string getOpponentsName(const int& id) const;

	/*!
	 *  Checks if there is a player with such id in actual game.
	 *  @param id Player id
	 *	@return true if player with such id is present, false otherwise
	 */
  bool hasPlayer(const int& id) const;

	/*!
	 *  Checks if there are 2 players in a Game.
	 *	@return true - 2 players are present, false - there is an empty space for other player
	 */
	bool isFull() const;

	/*!
	*  Checks if the game is empty.
	*	@return true - game is empty, false - not empty
	*/
	bool isEmpty() const;

	/*!
	*	 @return struct with points that resulted in a VICTORY.
	*/
	WinnerPoints getWinnerPoints() const;

	/*!
	 *  @param id Player id
	 *	@return How many games player won.
	 */
	inline int getPlayerPoints(const int& id) const { return (id == oPlayer.id ? oPlayer.victories : xPlayer.victories); };

	/*!
	 *  @param id Player id
	 *  @return How many games opponent won.
	 */
	inline int getOpponentsPoints(const int& id) const { return (id != oPlayer.id ? oPlayer.victories : xPlayer.victories); };


	/*!
	 *  Checks game result.
	 *	@return Result of a game(VICTORY, DRAW, STILL_PLAYING).
	 */
	GameResult checkGame();

	/*!
  	*	@return Actual state of a game.
	  */
	inline GameResult getState() const { return state_; };

	/*!
	 *  Method used for testing class.
	 *  @param board Board to set game with.
	 */
	inline void setBoard(const Board& board) { board_ = board; };

	/*!
	 * Method for setting the player as inactive.
	 *  @param id Player id
	 *	@return
	 */
	bool setPlayerInactive(int id);

	/*!
	 *  Checks if opponent is inactive.
	 *  @param id Player id
	 *	@return true if player is inactive, false otherwise
	 */
	bool isOpponentInactive(int id) const;
};


#endif // GAME_HPP
