#include "GameList.hpp"

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
  WriteLock lock(mtx);
  int ret = firstUnusedID;
  firstUnusedID = (firstUnusedID + 1) % 100000;
  return ret;
}

Sign GameList::addPlayer(const int& id, const std::string& name)
{
  WriteLock lock(mtx);
  for(Game& game : list)
  {
    if(!game.isFull())
    {
      return game.addPlayer(id, name);
    }
  }

  list.emplace_back();			/// dodanie nowej gry
                            /// nie możemy tu tak po prostu użyć push_back, bo mutex nie ma konstruktora kopiującego
  return list.back().addPlayer(id, name);
}

std::string GameList::getOpponentsName(const int& id) const
{
  ReadLock lock(mtx);
  for(const Game& game : list)
  {
    if(game.hasPlayer(id))
      return game.getOpponentsName(id);
  }
  return "";
}

Move GameList::getLastMove(const int& id) const
{
  ReadLock lock(mtx);
  for(const Game& game : list)
  {
    if(game.hasPlayer(id))
      return game.getLastMove();
  }
  return Move();
}

bool GameList::makeMove(const int& id, const int& x, const int& y)
{
  ReadLock lock(mtx);
  bool ret;		// czy udało się wykonać ruch
  for(Game& game : list)
  {
    if(game.hasPlayer(id))
    {
      ret = game.makeMove(id, x ,y);

      if(ret == false)
        return false;

      game.condition();
      break;
    }
  }
  return ret;
}

GameResult GameList::getResult(const int& id) const
{
  ReadLock lock(mtx);
  for(const Game& game : list)
  {
    if(game.hasPlayer(id))
      return game.getState();
  }
  return STILL_PLAYING;
}

void GameList::resetGame(const int& id)
{
  WriteLock lock(mtx);
  for(Game& game : list)
  {
    if(game.hasPlayer(id))
    {
      game.reset();
      break;
    }
  }
}

int GameList::getPlayerPoints(const int& id) const
{
  ReadLock lock(mtx);
  for(const Game& game : list)
  {
    if(game.hasPlayer(id))
      return game.getPlayerPoints(id);
  }
  return -1;	// w razie braku takiego gracza
}

int GameList::getOpponentsPoints(const int& id) const
{
  ReadLock lock(mtx);
  for(const Game& game : list)
  {
    if(game.hasPlayer(id))
      return game.getOpponentsPoints(id);
  }

  return -1;	// w razie braku takiego gracza
}

void GameList::setGameBoard(const int& id, Board board)
{
  WriteLock lock(mtx);
  for(Game& game : list)
  {
    if(game.hasPlayer(id))
    {
      game.setBoard(board);
      break;
    }
  }
}
