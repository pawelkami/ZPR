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
const Sign NONE = "";

typedef std::lock_guard<std::shared_timed_mutex> WriteLock;
typedef std::shared_lock<std::shared_timed_mutex> ReadLock;

typedef std::vector<std::vector<Sign> > Board;

class GameList;
typedef std::shared_ptr<GameList> PGameList;

#endif // PROJECT_DECLARATIONS_HPP
