/*!
 *  @file   Project_declarations.hpp
 * @brief File contains typedefs and declarations for Tic Tac Toe game project.
 */

#ifndef PROJECT_DECLARATIONS_HPP
#define PROJECT_DECLARATIONS_HPP

// variables which represents signs on a board
typedef std::string Sign;
const Sign CROSS = "X";
const Sign CIRCLE = "O";
const Sign NONE = "";;

#ifdef _MSC_VER

#include <memory>
#include <mutex>
//#include <concrt.h>
typedef std::mutex Mutex;
typedef std::lock_guard<Mutex> WriteLock;
typedef std::lock_guard<Mutex> ReadLock;

/*
class WinWriterLock
{
  Mutex& mtx;
public:
  WinWriterLock(WinWriterLock const &) = delete;
  WinWriterLock& operator=(WinWriterLock const &) = delete;
  explicit WinWriterLock(Mutex& m) : mtx(m)
  {
    mtx.lock();
  }
  ~WinWriterLock() 
  {
    mtx.unlock();
  }
};

class WinReaderLock
{
  Mutex& mtx;
public:
  WinReaderLock(WinReaderLock const &) = delete;
  WinReaderLock& operator=(WinReaderLock const &) = delete;
  explicit WinReaderLock(Mutex& m) : mtx(m)
  {
    mtx.lock_read();
  }
  ~WinReaderLock() 
  {
    mtx.unlock();
  }
};

typedef WinWriterLock WriteLock;
typedef WinReaderLock ReadLock;
*/
#else

#include <shared_mutex>
typedef std::shared_timed_mutex Mutex;
typedef std::lock_guard<Mutex> WriteLock;
typedef std::shared_lock<Mutex> ReadLock;

#endif
typedef std::vector<std::vector<Sign> > Board;

class GameList;
typedef std::shared_ptr<GameList> PGameList;

#endif // PROJECT_DECLARATIONS_HPP
