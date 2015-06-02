#ifndef MOVE_HPP
#define MOVE_HPP

#include "Project_declarations.hpp"



class Move
{
public:
  int x;
  int y;
  Sign sign;
  void setPoint(int x, int y, Sign s){ this->x = x; this->y = y; sign = s;};
  Move() : x(-1), y(-1), sign(NONE) {}
  Move(int xx, int yy, Sign s) : x(xx), y(yy), sign(s) {}
};

#endif // MOVE_HPP
