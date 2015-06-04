/*
 *  Header file for class representing Player.
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Project_declarations.hpp"

/*!
 *  Class represents Player.
 */
class Player
{
public:

  /*!
   *  Id of a Player
   */
  int id;


  /*!
   *  Player name.
   */
  std::string name;


  /*!
   *  Player sign.
   */
  Sign sign;


  /*!
   *  How many times has player won.
   */
  int victories;


  /*!
   *  Is player active or not.
   */
  bool active;


  /*!
   *  Method which increments victories of a player.
   */
  inline void incrementVictories() { ++victories; };

  /*!
   *  Default constructor of a Player class. Sets id to -1, name to null string and victories to 0.
   */
  Player() : id(-1), name(""), sign(NONE), victories(0), active(false) {}

  /*!
   *  Constructor of a Player class.
   *  @param i Player id
   *  @param n Player name
   *  @param v Player victories
   *  @param a if player is active or not
   */
  Player(int i, std::string n, std::string s, int v = 0, bool a = false) : id(i), name(n), sign(s), victories(v), active(a) {}
};

#endif // PLAYER_HPP
