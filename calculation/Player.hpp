#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Project_declarations.hpp"


class Player
{
public:
  int id;
  std::string name;
  Sign sign;
  int victories;
  bool active;
  inline void incrementVictories() { ++victories; };
  Player() : id(-1), name(""), sign(NONE), victories(0), active(false) {}
  Player(int i, std::string n, std::string s, int v, bool a) : id(i), name(n), sign(s), victories(v), active(a) {}
};

#endif // PLAYER_HPP
