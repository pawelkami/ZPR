/*!
 *  @file   Player.hpp
 *  @brief Header file for class representing Player.
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Project_declarations.hpp"

/*!
 *  \brief Class represents Player.
 */
class Player
{
public:

  /*!
   *  Id of a Player
   */
  int id_;


  /*!
   *  Player name.
   */
  std::string name_;


  /*!
   *  Player sign.
   */
  Sign sign_;


  /*!
   *  How many times has player won.
   */
  int victories_;


  /*!
   *  Is player active or not.
   */
  bool active_;


  /*!
   *  Method which increments victories of a player.
   */
  inline void incrementVictories() { ++victories_; };

  /*!
   *  Default constructor of a Player class. Sets id to -1, name to null string and victories to 0.
   */
  Player() : id_(-1), name_(""), sign_(NONE), victories_(0), active_(false) {}

  /*!
   *  Constructor of a Player class.
   *  @param i Player id
   *  @param n Player name
   *  @param v Player victories
   *  @param a if player is active or not
   */
  Player(int i, std::string n, std::string s, int v = 0, bool a = false) : id_(i), name_(n), sign_(s), victories_(v), active_(a) {}
};

#endif // PLAYER_HPP
