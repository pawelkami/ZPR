/*
 *  File contains implemented methods of a GameList class.
 */

#include "GameList.hpp"

GameList::GameList() : list_(), mtx()
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
  WriteLock lock(mtx);
  int ret = firstUnusedID;
  firstUnusedID = (firstUnusedID + 1) % 100000;
  return ret;
}

Sign GameList::addPlayer(const int& id, const std::string& name)
{
  WriteLock lock(mtx);
  for(Game& game : list_)
  {
    if(!game.isFull())
    {
      return game.addPlayer(id, name);
    }
  }

  list_.emplace_back();			/// dodanie nowej gry
                            /// nie możemy tu tak po prostu użyć push_back, bo mutex nie ma konstruktora kopiującego
  return list_.back().addPlayer(id, name);
}

std::string GameList::getOpponentsName(const int& id) const
{
  ReadLock lock(mtx);
  const Game* game = findGame(id);

  return (game != nullptr) ? game->getOpponentsName(id) : "";
}

Move GameList::getLastMove(const int& id) const
{
  ReadLock lock(mtx);
  const Game* game = findGame(id);

  return (game != nullptr) ? game->getLastMove() : Move();
}

bool GameList::makeMove(const int& id, const int& x, const int& y)
{
  ReadLock lock(mtx);
  bool ret;		// was move done?

  Game* game = findGame(id);

  if(game != nullptr)
  {
    ret = game->makeMove(id, x ,y);

    if(ret == false)
      return false;

    game->checkGame();
  }
  return true;
}

GameResult GameList::getResult(const int& id) const
{
  ReadLock lock(mtx);
  const Game* game = findGame(id);

  return (game != nullptr) ? game->getState() : STILL_PLAYING;
}

void GameList::resetGame(const int& id)
{
  WriteLock lock(mtx);
  Game* game = findGame(id);

  if(game != nullptr)
    game->reset();
}

int GameList::getPlayerPoints(const int& id) const
{
  ReadLock lock(mtx);
  const Game* game = findGame(id);

  return (game != nullptr) ? game->getPlayerPoints(id) : -1;
}

int GameList::getOpponentsPoints(const int& id) const
{
  ReadLock lock(mtx);

  const Game* game = findGame(id);

  return (game != nullptr) ? game->getOpponentsPoints(id) : -1;
}

void GameList::setGameBoard(const int& id, Board board)
{
  WriteLock lock(mtx);

  Game* game = findGame(id);

  if(game != nullptr)
  {
      game->setBoard(board);
  }
}

const Game* GameList::findGame(const int& id) const
{
  for(const Game& game : list_)
  {
    if(game.hasPlayer(id))
    {
      return &game;
    }
  }

  return nullptr;
}

Game* GameList::findGame(const int& id)
{
  return const_cast<Game*>( static_cast<const GameList*>(this)->findGame(id));
}

bool GameList::unregister(int id)
{
  WriteLock lock(mtx);
  for(auto it = list_.begin(); it != list_.end(); ++it)
  {
    if(it->hasPlayer(id))
    {
      it->setPlayerInactive(id);
      if(it->isEmpty())
        list_.erase(it);
      return true;
    }
  }
  return false;
}

bool GameList::hasOpponentLeft(int id) const
{
  ReadLock lock(mtx);
  const Game* game = findGame(id);

  if(game != nullptr)
    return game->isOpponentInactive(id);
  return false;
}

WinnerPoints GameList::getWinnerPoints(const int& id) const
{
  const Game *game = findGame(id);
  WinnerPoints winpoint;
  if(game != nullptr)
    winpoint = game->getWinnerPoints();
  else
  {
    winpoint.x1 = winpoint.x2 = winpoint.x3 = winpoint.x4 = winpoint.x5 = -1;
    winpoint.y1 = winpoint.y2 = winpoint.y3 = winpoint.y4 = winpoint.y5 = -1;
  }
  return winpoint;
}
