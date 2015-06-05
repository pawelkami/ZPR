/*!
 *  @file   Project_declarations.hpp
 * @brief File contains typedefs and declarations for Tic Tac Toe game project.
 */

#ifndef PROJECT_DECLARATIONS_HPP
#define PROJECT_DECLARATIONS_HPP

#include <string>
#include <vector>
// variables which represents signs on a board
typedef std::string Sign;
const Sign CROSS = "X";
const Sign CIRCLE = "O";
const Sign NONE = "";

#ifdef _MSC_VER

#include <memory>
#include <mutex>
typedef std::mutex Mutex;
typedef std::lock_guard<Mutex> WriteLock;
typedef std::lock_guard<Mutex> ReadLock;

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
