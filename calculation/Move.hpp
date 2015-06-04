/*!
 *  @file   Move.hpp
 *  @brief Header file for Move class.
 */
#ifndef MOVE_HPP
#define MOVE_HPP

#include "Project_declarations.hpp"


/*!
 *  \brief Class representing move.
 */
class Move
{
public:

  /*!
   *  x coordinate
   */
  int x_;

  /*!
   *  y coordinate
   */
  int y_;

  /*!
   *  Sign of a move (CIRCLE OR CROSS)
   */
  Sign sign_;

  /*!
   *  Sets move with coordinates and sign.
   *  @param x x coordinate.
   *  @param y y coordinate.
   *  @param s sign which made a move.
   */
  void setPoint(int x, int y, Sign s){ x_ = x; y_ = y; sign_ = s;};

  /*!
   *  Comparing operator == for comparing two moves.
   *  @return true if moves are the same.
   */
  bool operator ==( const Move & m) { return (x_ == m.x_ && y_ == m.y_ && sign_ == m.sign_); };

  /*!
   *  Default constructor.
   */
  Move() : x_(-1), y_(-1), sign_(NONE) {}

  /*!
   *  Constructor with arguments.
   *  @param xx x coordinate
   *  @param yy y coordinate
   *  @param s sign
   */
  Move(int xx, int yy, Sign s) : x_(xx), y_(yy), sign_(s) {}
};

#endif // MOVE_HPP
