#ifndef GAMELIST_HPP
#define GAMELIST_HPP

#include "Game.hpp"
#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <shared_mutex>

class GameList
{
private:
  std::list<Game> list_;
  mutable std::shared_timed_mutex mtx;
  int firstUnusedID;
  static PGameList pInstance;
  GameList();
  GameList(const GameList&) = delete;
public:
  ~GameList();
  static PGameList getInstance();
  int getNewID();
  Sign addPlayer(const int& id, const std::string& name);
  std::string getOpponentsName(const int& id) const;
  Move getLastMove(const int& id) const;
  bool makeMove(const int& id, const int& x, const int& y);
  GameResult getResult(const int& id) const;
  void resetGame(const int& id);
  void setGameBoard(const int & id, Board board); // <--
  int getPlayerPoints(const int& id) const;
  int getOpponentsPoints(const int& id) const;
  Game* findGame(const int& id);
  const Game* findGame(const int& id) const;
  bool unregister(int id);
  bool hasOpponentLeft(int id) const;
  WinnerPoints getWinnerPoints(const int& id) const;
};

#endif // GAMELIST_HPP
