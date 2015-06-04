/*
 *  Header file for GameList class.
 */

#ifndef GAMELIST_HPP
#define GAMELIST_HPP

#include "Game.hpp"
#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <shared_mutex>


/*!
 *  GameList class which implements list of a games on a server.
 *  Used Singleton pattern.
 */
class GameList
{
private:

  /*!
   *  List of Games.
   */
  std::list<Game> list_;


  /*!
   *  Mutex.
   */
  mutable std::shared_timed_mutex mtx;


  /*!
   *  First id that is not used any player.
   */
  int firstUnusedID;


  /*!
   *  Smart pointer to the instance of a class.
   */
  static PGameList pInstance;


  /*!
   *  Default constructor.
   */
  GameList();
  GameList(const GameList&) = delete;
public:

  /*!
   *  Destructor.
   */
  ~GameList();


  /*!
   *  Get instance of class.
   *  @return Smart pointer to the class.
   */
  static PGameList getInstance();


  /*!
   *  @return New id for a player.
   */
  int getNewID();


  /*!
   *  Adding new player to the game with an empty place.
   *  @param id Player id
   *  @param name Player name
   */
  Sign addPlayer(const int& id, const std::string& name);


  /*!
   *  @return Opponent's name
   */
  std::string getOpponentsName(const int& id) const;

  /*!
   *  @param id Player id
   *  @return last move
   */
  Move getLastMove(const int& id) const;

  /*!
   *  Method which make move in a game.
   *  @param id Player id
   *  @param x x coordinate
   *  @param y y coordinate
   */
  bool makeMove(const int& id, const int& x, const int& y);

  /*!
   *  @param Player id
   *  @return result of a game
   */
  GameResult getResult(const int& id) const;

  /*!
   *  Method resets Game with player whose id was passed.
   *  @param id Player id
   */
  void resetGame(const int& id);

  /*!
   *  Method for testing purposes. Sets board in a Game.
   *  @param id Player id
   *  @param board Board which you want to set to the Game.
   */
  void setGameBoard(const int & id, Board board); // <--

  /*!
   *  @param id Player id
   *  @return Player points
   */
  int getPlayerPoints(const int& id) const;

  /*!
   *  @param id Player id
   *  @return Opponent points
   */
  int getOpponentsPoints(const int& id) const;

  /*!
   *  Method used to find the game with player whose id was passed as argument.
   *  @param id Player id
   *  @return Pointer to found Game. If Game was not found it returns nullptr.
   */
  Game* findGame(const int& id);

  /*!
   *  Const version of method used to find the game with player whose id was passed as argument.
   *  @param id Player id
   *  @return Pointer to found Game. If Game was not found it returns nullptr.
   */
  const Game* findGame(const int& id) const;

  /*!
   *  Method used to unregister player from Game.
   *  @param id Player id
   *  @return true when method unregistered player, false otherwise
   */
  bool unregister(int id);

  /*!
   *  Does the player's opponent left.
   *  @param id Player id
   *  @return true if it has opponent left, false otherwise
   */
  bool hasOpponentLeft(int id) const;

  /*!
   *  Return coordinates of points that resulted in a victory.
   *	@return struct with points that resulted in a victory
   */
  WinnerPoints getWinnerPoints(const int& id) const;
};

#endif // GAMELIST_HPP
