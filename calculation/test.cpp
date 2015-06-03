#include <boost/test/included/unit_test.hpp>
#include "Game.hpp"
#include "GameList.hpp"
#include "Move.hpp"
#include <iostream>

using namespace boost::unit_test;

int first_player_id;
int second_player_id;
int third_player_id;
int fourth_player_id;
int fifth_player_id;
Sign first_player_sign;
Sign second_player_sign;
Sign third_player_sign;
Sign fourth_player_sign;
Sign fifth_player_sign;

/*!
 * test_case1 - it tests result of two games already initializated
 */
void test_case1()
{
    bool cond = (GameList::getInstance()->getResult(third_player_id) == STILL_PLAYING 
                  && GameList::getInstance()->getResult(first_player_id) == STILL_PLAYING);
  	BOOST_CHECK_EQUAL(cond, true);
}

/*!
 * test_case2 - it tests result of game, where are five circles in left upper corner
 */
void test_case2()
{
    GameList::getInstance()->resetGame(first_player_id);
    GameList::getInstance()->resetGame(second_player_id);
  	Board board =
  	{
    {"O","O","O","O","","","","","","","","","","","",""},
  	{"","","","","","","","","","","","","","","",""},
  	{"","","","","","","","","","","","","","","",""},
  	{"","","","","","","","","","","","","","","",""},
  	{"","","","","","","","","","","","","","","",""},
  	{"","","","","","","","","","","","","","","",""},
  	{"","","","","","","","","","","","","","","",""},
  	{"","","","","","","","","","","","","","","",""},
  	{"","","","","","","","","","","","","","","",""},
  	{"","","","","","","","","","","","","","","",""},
  	{"","","","","","","","","","","","","","","",""},
  	{"","","","","","","","","","","","","","","",""},
  	{"","","","","","","","","","","","","","","",""},
  	{"","","","","","","","","","","","","","","",""},
  	{"","","","","","","","","","","","","","","",""},
  	{"","","","","","","","","","","","","","","",""}
  	};

    GameList::getInstance()->setGameBoard(first_player_id, board);
    GameList::getInstance()->makeMove(first_player_id, 0, 4);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), VICTORY);
}

/*!
 * test_case3 - test of result of game with five circles and five crosses
 * (without victory conditions)
 */
void test_case3()
{
    GameList::getInstance()->resetGame(third_player_id);
    GameList::getInstance()->resetGame(fourth_player_id);
    Board board =
  	{
    {"O","O","X","O","O","","X","","","","","","","","",""},
    {"","X","","","","","","","","","","","","","",""},
    {"","","X","X","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""}
  	};

    GameList::getInstance()->setGameBoard(third_player_id, board);
    GameList::getInstance()->makeMove(third_player_id, 0, 5);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(third_player_id), STILL_PLAYING);
}

/*!
 * test_case4 - test of result of game with full board but without victory condition
 */
void test_case4()
{
    GameList::getInstance()->resetGame(first_player_id);
    GameList::getInstance()->resetGame(second_player_id);
	  Board board =
  	{
    {"","X","X","O","O","X","X","O","O","X","X","O","O","X","X","O"},
    {"X","O","O","X","X","O","O","X","X","O","O","X","X","O","O","X"},
    {"O","X","X","O","O","X","X","O","O","X","X","O","O","X","X","O"},
    {"X","O","O","X","X","O","O","X","X","O","O","X","X","O","O","X"},
    {"O","X","X","O","O","X","X","O","O","X","X","O","O","X","X","O"},
    {"X","O","O","X","X","O","O","X","X","O","O","X","X","O","O","X"},
    {"O","X","X","O","O","X","X","O","O","X","X","O","O","X","X","O"},
    {"X","O","O","X","X","O","O","X","X","O","O","X","X","O","O","X"},
    {"O","X","X","O","O","X","X","O","O","X","X","O","O","X","X","O"},
    {"X","O","O","X","X","O","O","X","X","O","O","X","X","O","O","X"},
    {"O","X","X","O","O","X","X","O","O","X","X","O","O","X","X","O"},
    {"X","O","O","X","X","O","O","X","X","O","O","X","X","O","O","X"},
    {"O","X","X","O","O","X","X","O","O","X","X","O","O","X","X","O"},
    {"X","O","O","X","X","O","O","X","X","O","O","X","X","O","O","X"},
    {"O","X","X","O","O","X","X","O","O","X","X","O","O","X","X","O"},
    {"X","O","O","X","X","O","O","X","X","O","O","X","X","O","O","X"}
  	};

    GameList::getInstance()->setGameBoard(first_player_id, board);
    GameList::getInstance()->makeMove(first_player_id, 0, 0);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), DRAW);
}

/*!
 * test_case5 - it tests game where three crosses were inserted by method setBoard
 * and another two crooses by method makeMove, there are five crosses from left down
 * to right upper, from (4, 0) to (0, 4)
 */
void test_case5()
{
    GameList::getInstance()->resetGame(first_player_id);
    GameList::getInstance()->resetGame(second_player_id);
	  Board board =
  	{
    {"","","","","X","","","","","","","","","","",""},
    {"","","","X","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","X","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""}
  	};

  	GameList::getInstance()->setGameBoard(first_player_id, board);
    GameList::getInstance()->makeMove(second_player_id, 2, 2);
    GameList::getInstance()->makeMove(second_player_id, 4, 0);

    BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), VICTORY);
}

/*!
 * test_case6 - test of game which board's left down corner
 * is full of crosses but there isn't any victory condition
 */
void test_case6()
{
    GameList::getInstance()->resetGame(first_player_id);
    GameList::getInstance()->resetGame(second_player_id);
	  Board board =
  	{
    {"","0","","","","","","","","","","","","","",""},
    {"","","","","X","","","","O","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","X","","","","","","","","","","","","",""},
    {"","","","","","","","","0","","","","O","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","X","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","X","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","X","","","","","","","","O","",""},
    {"X","X","X","X","","","","","","","","","","","",""},
    {"X","X","X","X","","","","","","","","","","","",""},
    {"X","X","X","X","","","","","","","","","","","",""},
    {"","X","X","X","","","","","","","","","","","",""}
  	};

    GameList::getInstance()->setGameBoard(first_player_id, board);
    GameList::getInstance()->makeMove(second_player_id, 15, 4);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), STILL_PLAYING);
}

/*!
 * test_case7 - it tests result of game with five circles in
 * right down corner
 */
void test_case7()
{
    GameList::getInstance()->resetGame(first_player_id);
    GameList::getInstance()->resetGame(second_player_id);
	  Board board =
  	{
    {"","","","","X","","","","","","","","","","",""},
    {"","","","X","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","X","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","","O"},
    {"","","","","","","","","","","","","","","O",""},
    {"","","","","","","","","","","","","O","O","",""},
    {"","","","","","","","","","","","X","O","X","",""},
    {"","","","","","","","","","","X","","X","O","",""}
  	};

    GameList::getInstance()->setGameBoard(first_player_id, board);
    GameList::getInstance()->makeMove(first_player_id, 15, 11);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), VICTORY);
}

/*!
 * test_case8 - test of result of game where situation is similar to 
 * test_case6 but here we have victory condition
 */
void test_case8()
{
    GameList::getInstance()->resetGame(first_player_id);
    GameList::getInstance()->resetGame(second_player_id);
	  Board board =
  	{
    {"","0","","","","","","","","","","","","","",""},
    {"","","","","X","","","","O","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","X","","","","","","","","","","","","",""},
    {"","","","","","","","","0","","","","O","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","X","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","X","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"X","","","","","X","","","","","","","","O","",""},
    {"X","X","X","X","","","","","","","","","","","",""},
    {"X","X","","X","","","","","","","","","","","",""},
    {"X","X","X","X","","","","","","","","","","","",""},
    {"","X","X","X","X","","","","","","","","","","",""}
  	};

    GameList::getInstance()->setGameBoard(first_player_id, board);
    GameList::getInstance()->makeMove(second_player_id, 13, 2);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), VICTORY);
}

/*!
 * test_case9 - test of result of game where isn't any new sign 
 * in comparison with board from last test (test_case8)
 */
void test_case9()
{
    BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), VICTORY);
}

/*!
 * test_case10 - test of result of game with five crosses which are 
 * crosswise from left upper to right down in the middle of board
 */
void test_case10()
{
    GameList::getInstance()->resetGame(first_player_id);
    GameList::getInstance()->resetGame(second_player_id);
	  Board board =
  	{
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","X","","","","","","","","","",""},
    {"","","","","","","X","","","","","","","","",""},
    {"","","","","","","","X","","","","","","","",""},
    {"","","","","","","","","X","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""}
  	};

    GameList::getInstance()->setGameBoard(first_player_id, board);
    GameList::getInstance()->makeMove(second_player_id, 4, 4);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(second_player_id), VICTORY);
}

/*!
 * test_case11 - test of result of game with five circles 
 * in the middle, vertically placed
 */
void test_case11()
{
    GameList::getInstance()->resetGame(third_player_id);
    GameList::getInstance()->resetGame(fourth_player_id);
	  Board board =
  	{
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","O","","","","","","","",""},
    {"","","","","","","","O","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","O","","","","","","","",""},
    {"","","","","","","","O","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""}
  	};

    GameList::getInstance()->setGameBoard(third_player_id, board);
    GameList::getInstance()->makeMove(third_player_id, 8, 7);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(third_player_id), VICTORY);
}

/*!
 * test_case12 - test of game where in board's left upper corner
 * are five circles which are crosswise placed from right down
 * to left upper among crosses 
 */
void test_case12()
{
    GameList::getInstance()->resetGame(third_player_id);
    GameList::getInstance()->resetGame(fourth_player_id);
	  Board board =
  	{
    {"O","X","X","","","","","","","","","","","","",""},
    {"X","O","X","","","","","","","","","","","","",""},
    {"X","X","O","X","","","","","","","","","","","",""},
    {"","","X","","X","","","","","","","","","","",""},
    {"","","","X","O","X","","","","","","","","","",""},
    {"","","","","X","O","","","","","","","","","",""},
    {"","","","","","X","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""}
  	};

    GameList::getInstance()->setGameBoard(third_player_id, board);
    GameList::getInstance()->makeMove(third_player_id, 3, 3);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(fourth_player_id), VICTORY);
}

/*!
 * test_case13 - test of result of game where on board
 * are five circles in the middle, which are crosswise placed 
 * from left down corner to right upper
 */
void test_case13()
{
    GameList::getInstance()->resetGame(first_player_id);
    GameList::getInstance()->resetGame(second_player_id);
	  Board board =
  	{
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","O","","","","",""},
    {"","","","","","","","","","O","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","O","","","","","","","",""},
    {"","","","","","","O","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""}
  	};

    GameList::getInstance()->setGameBoard(first_player_id, board);
    GameList::getInstance()->makeMove(first_player_id, 7, 8);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), VICTORY);
}

/*!
 * test_case14 - test of result of game where on the board
 * are horizontally placed five circles in the middle
 */
void test_case14()
{
    GameList::getInstance()->resetGame(first_player_id);
    GameList::getInstance()->resetGame(second_player_id);
	  Board board =
  	{
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","O","O","O","O","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""}
  	};

    GameList::getInstance()->setGameBoard(first_player_id, board);
    GameList::getInstance()->makeMove(first_player_id, 9, 9);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), VICTORY);
}

/*!
 * test_case15 - test of result of game where board are full
 * and where we can find many concentrations of foursome 
 * circles and crosses in different arrangements
 */
void test_case15()
{
    GameList::getInstance()->resetGame(first_player_id);
    GameList::getInstance()->resetGame(second_player_id);
  	Board board =
  	{
    {"O","O","O","O","X","O","X","O","X","X","X","X","O","O","O","O"},
  	{"X","X","X","X","O","O","X","O","X","X","X","X","O","O","O","O"},
  	{"X","X","X","X","O","O","X","X","O","O","O","X","O","X","X","X"},
  	{"X","X","X","O","O","O","O","O","X","X","O","X","X","X","X","O"},
  	{"O","O","X","O","X","X","X","X","O","O","O","O","X","O","X","O"},
  	{"X","O","O","X","X","X","X","O","O","X","X","X","O","X","X","X"},
  	{"X","X","X","X","O","X","X","X","O","X","O","X","X","X","O","O"},
  	{"O","O","O","O","O","X","O","X","X","O","X","O","X","O","X","O"},
  	{"X","O","X","O","X","O","X","O","X","O","X","O","X","X","X","X"},
  	{"X","X","X","X","O","O","O","O","X","O","X","O","X","X","O","X"},
  	{"X","X","O","O","O","X","X","X","","X","X","X","O","O","O","X"},    // <-- (10, 8, CIRCLE)
  	{"O","O","X","X","O","X","X","O","X","O","O","X","X","X","O","O"},
  	{"O","O","O","O","X","X","O","O","X","X","O","O","O","X","X","X"},
  	{"X","X","O","O","X","X","X","O","O","X","O","X","O","X","O","O"},
  	{"O","X","O","X","O","O","X","X","O","X","X","X","X","O","X","O"},
  	{"X","O","O","O","X","O","X","O","X","O","O","O","X","O","X","X"}
  	};

    GameList::getInstance()->setGameBoard(first_player_id, board);
    GameList::getInstance()->makeMove(first_player_id, 10, 8);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), DRAW);
}

/*!
 * test_case16 - test of result of game where board has a similar 
 * filling as board in test_case15 but here we have a two victory conditions
 * (seven crosses horizontally and six vertically)
 */
void test_case16()
{
    GameList::getInstance()->resetGame(first_player_id);
    GameList::getInstance()->resetGame(second_player_id);
    Board board =
  	{
    {"O","O","O","O","X","O","X","O","X","X","X","X","O","O","O","O"},
  	{"X","X","X","X","O","O","X","O","X","X","X","X","O","O","O","O"},
  	{"X","X","X","X","O","O","X","X","O","O","O","X","O","X","X","X"},
  	{"X","X","X","O","O","O","O","O","X","X","O","X","X","X","X","O"},
  	{"O","O","X","O","X","X","X","X","O","O","O","O","X","O","X","O"},
  	{"X","O","O","X","X","X","X","O","O","X","X","X","O","X","X","X"},
  	{"X","X","X","X","O","X","X","X","O","X","O","X","X","X","O","O"},
  	{"O","O","O","O","O","X","O","X","X","O","X","O","X","O","X","O"},
  	{"X","O","X","O","X","O","X","O","X","O","X","O","X","X","X","X"},
  	{"X","X","X","X","O","O","O","O","X","O","X","O","X","X","O","X"},
  	{"X","X","O","O","O","X","X","X","","X","X","X","O","O","O","X"},    // <-- (10, 8, CROSS)
  	{"O","O","X","X","O","X","X","O","X","O","O","X","X","X","O","O"},
  	{"O","O","O","O","X","X","O","O","X","X","O","O","O","X","X","X"},
  	{"X","X","O","O","X","X","X","O","O","X","O","X","O","X","O","O"},
  	{"O","X","O","X","O","O","X","X","O","X","X","X","X","O","X","O"},
  	{"X","O","O","O","X","O","X","O","X","O","O","O","X","O","X","X"}
  	};

    GameList::getInstance()->setGameBoard(first_player_id, board);
    GameList::getInstance()->makeMove(second_player_id, 10, 8);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), VICTORY);
}

/*!
 * test_case17 - test of result of game where board is full with similar 
 * filling as in test_case15 and test_case16 but here are more victory conditions
 */
void test_case17()
{
    GameList::getInstance()->resetGame(first_player_id);
    GameList::getInstance()->resetGame(second_player_id);
	  Board board =
  	{
    {"O","O","O","O","X","O","X","O","X","X","X","X","O","O","O","O"},
  	{"X","X","X","X","O","O","X","O","X","X","X","X","O","O","O","O"},
  	{"O","X","X","X","O","O","X","X","O","O","O","X","O","X","X","X"},
  	{"X","O","X","O","O","O","O","O","X","X","O","X","X","X","X","O"},
  	{"O","X","X","O","X","X","X","X","O","O","O","O","X","O","X","O"},
  	{"X","O","X","X","X","X","X","O","O","X","X","X","O","X","X","X"},
  	{"X","X","O","X","X","X","O","X","O","X","O","X","X","X","O","O"},
  	{"O","O","O","O","","O","O","X","X","O","X","O","X","O","X","O"},    // <-- (7, 4, CROSS)
  	{"X","O","X","X","X","X","O","O","X","O","X","O","X","X","X","X"},
  	{"X","X","X","X","O","O","O","O","X","O","X","O","X","X","O","X"},
  	{"X","X","O","O","O","X","X","X","O","X","X","X","O","O","O","X"},
  	{"O","O","X","X","O","X","X","O","X","O","O","X","X","X","O","O"},
  	{"O","O","O","O","X","X","O","O","X","X","O","O","O","X","X","X"},
  	{"X","X","O","O","X","X","X","O","O","X","O","X","O","X","O","O"},
  	{"O","X","O","X","O","O","X","X","O","X","X","X","X","O","X","O"},
  	{"X","O","O","O","X","O","X","O","X","O","O","O","X","O","X","X"}
  	};

    GameList::getInstance()->setGameBoard(first_player_id, board);
    GameList::getInstance()->makeMove(second_player_id, 7, 4);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), VICTORY);
}

/*!
 * test_case18 - test of result of game where both of players
 * have fourth signs in one line and the victory is depend on
 * last sign which can be inserted in the same place for both 
 */
void test_case18()
{
    GameList::getInstance()->resetGame(first_player_id);
    GameList::getInstance()->resetGame(second_player_id);
	  Board board =
  	{
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","O","X","","","","","",""},
    {"","","","","","","","O","","X","","","","","",""},
    {"","","","","","","O","","","X","","","","","",""},
    {"","","","","","O","","","","X","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""}
  	};

    GameList::getInstance()->setGameBoard(first_player_id, board);
    GameList::getInstance()->makeMove(first_player_id, 7, 9);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), VICTORY);
}

/*!
 * test_case19 - test of result of game where board was
 * filling only by method makeMove, so like it is while
 * real playing on server
 */
void test_case19()
{
    GameList::getInstance()->resetGame(first_player_id);
    GameList::getInstance()->resetGame(second_player_id);
    GameList::getInstance()->makeMove(second_player_id, 8, 9);
    GameList::getInstance()->makeMove(first_player_id, 8, 5);
    GameList::getInstance()->makeMove(second_player_id, 7, 9);
    GameList::getInstance()->makeMove(first_player_id, 7, 6);
    GameList::getInstance()->makeMove(second_player_id, 6, 9);
    GameList::getInstance()->makeMove(first_player_id, 6, 7);
    GameList::getInstance()->makeMove(second_player_id, 5, 9);
    GameList::getInstance()->makeMove(first_player_id, 5, 8);
    GameList::getInstance()->makeMove(second_player_id, 4, 9);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), VICTORY);
}

/*!
 * test_case20 - test of result of a similar game as 
 * is in test_case19 but players filling board in 
 * different order
 */
void test_case20()
{
    GameList::getInstance()->resetGame(first_player_id);
    GameList::getInstance()->resetGame(second_player_id);
    GameList::getInstance()->makeMove(first_player_id, 8, 5);
    GameList::getInstance()->makeMove(second_player_id, 8, 9);
    GameList::getInstance()->makeMove(first_player_id, 7, 6);
    GameList::getInstance()->makeMove(second_player_id, 7, 9);
    GameList::getInstance()->makeMove(first_player_id, 6, 7);
    GameList::getInstance()->makeMove(second_player_id, 6, 9);
    GameList::getInstance()->makeMove(first_player_id, 5, 8);
    GameList::getInstance()->makeMove(second_player_id, 5, 9);
    GameList::getInstance()->makeMove(first_player_id, 4, 9);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), VICTORY);
}

/*!
 * test_case21 - test of result of game where players were putting
 * their signs in right upper corner, there are ten crosses and eleven 
 * circles, which won, beacuse of fivesome (0,15) from to (4, 15)
 */
void test_case21()
{
    GameList::getInstance()->resetGame(first_player_id);
    GameList::getInstance()->resetGame(second_player_id);
    GameList::getInstance()->makeMove(first_player_id, 0, 15);
    GameList::getInstance()->makeMove(second_player_id, 2, 10);
    GameList::getInstance()->makeMove(first_player_id, 5, 11);
    GameList::getInstance()->makeMove(second_player_id, 2, 11);
    GameList::getInstance()->makeMove(first_player_id, 4, 11);
    GameList::getInstance()->makeMove(second_player_id, 2, 12);
    GameList::getInstance()->makeMove(first_player_id, 3, 12);
    GameList::getInstance()->makeMove(second_player_id, 3, 13);
    GameList::getInstance()->makeMove(first_player_id, 4, 13);
    GameList::getInstance()->makeMove(second_player_id, 3, 14);
    GameList::getInstance()->makeMove(first_player_id, 4, 14);
    GameList::getInstance()->makeMove(second_player_id, 4, 12);
    GameList::getInstance()->makeMove(first_player_id, 3, 15);
    GameList::getInstance()->makeMove(second_player_id, 5, 14);
    GameList::getInstance()->makeMove(first_player_id, 4, 15);
    GameList::getInstance()->makeMove(second_player_id, 2, 14);
    GameList::getInstance()->makeMove(first_player_id, 2, 15);
    GameList::getInstance()->makeMove(second_player_id, 1, 14);
    GameList::getInstance()->makeMove(first_player_id, 4, 14);
    GameList::getInstance()->makeMove(second_player_id, 0, 14);
    GameList::getInstance()->makeMove(first_player_id, 1, 15);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), VICTORY);
}

/*!
 * test_case22 - test of result of game where players were putting their
 * signs in left down corner, as a result their get foursome circles and crosses
 */
void test_case22()
{
  	GameList::getInstance()->resetGame(first_player_id);
    GameList::getInstance()->resetGame(second_player_id);
    GameList::getInstance()->makeMove(first_player_id, 0, 15);
    GameList::getInstance()->makeMove(second_player_id, 2, 10);
    GameList::getInstance()->makeMove(first_player_id, 5, 11);
    GameList::getInstance()->makeMove(second_player_id, 2, 11);
    GameList::getInstance()->makeMove(first_player_id, 4, 11);
    GameList::getInstance()->makeMove(second_player_id, 2, 12);
    GameList::getInstance()->makeMove(first_player_id, 3, 12);
    GameList::getInstance()->makeMove(second_player_id, 3, 13);
    GameList::getInstance()->makeMove(first_player_id, 4, 13);
    GameList::getInstance()->makeMove(second_player_id, 3, 14);
    GameList::getInstance()->makeMove(first_player_id, 4, 14);
    GameList::getInstance()->makeMove(second_player_id, 4, 12);
    GameList::getInstance()->makeMove(first_player_id, 3, 15);
    GameList::getInstance()->makeMove(second_player_id, 5, 14);
    GameList::getInstance()->makeMove(first_player_id, 2, 15);
    GameList::getInstance()->makeMove(second_player_id, 2, 14);
    GameList::getInstance()->makeMove(first_player_id, 4, 14);
    GameList::getInstance()->makeMove(second_player_id, 1, 14);
    GameList::getInstance()->makeMove(first_player_id, 1, 15);
    GameList::getInstance()->makeMove(second_player_id, 0, 14);
    GameList::getInstance()->makeMove(first_player_id, 5, 15);
    GameList::getInstance()->makeMove(second_player_id, 4, 15);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), STILL_PLAYING);
}

/*!
 * test_case23 - test of result of game where players were playing in the middle-west
 * part of board and there were two foursome circles and also crosses, crosses won
 */
void test_case23()
{
    GameList::getInstance()->resetGame(first_player_id);
    GameList::getInstance()->resetGame(second_player_id);
    GameList::getInstance()->makeMove(first_player_id, 6, 0);
    GameList::getInstance()->makeMove(second_player_id, 9, 3);
    GameList::getInstance()->makeMove(first_player_id, 7, 1);
    GameList::getInstance()->makeMove(second_player_id, 10, 0);
    GameList::getInstance()->makeMove(first_player_id, 9, 1);
    GameList::getInstance()->makeMove(second_player_id, 9, 5);
    GameList::getInstance()->makeMove(first_player_id, 9, 2);
    GameList::getInstance()->makeMove(second_player_id, 7, 5);
    GameList::getInstance()->makeMove(first_player_id, 8, 2);
    GameList::getInstance()->makeMove(second_player_id, 6, 5);
    GameList::getInstance()->makeMove(first_player_id, 7, 2);
    GameList::getInstance()->makeMove(second_player_id, 6, 6);
    GameList::getInstance()->makeMove(first_player_id, 6, 2);
    GameList::getInstance()->makeMove(second_player_id, 5, 5);
    GameList::getInstance()->makeMove(first_player_id, 7, 3);
    GameList::getInstance()->makeMove(second_player_id, 5, 7);
    GameList::getInstance()->makeMove(first_player_id, 8, 4);
    GameList::getInstance()->makeMove(second_player_id, 3, 8);
    GameList::getInstance()->makeMove(first_player_id, 6, 4);
    GameList::getInstance()->makeMove(second_player_id, 5, 4);
    GameList::getInstance()->makeMove(first_player_id, 8, 5);
    GameList::getInstance()->makeMove(second_player_id, 5, 3);
    GameList::getInstance()->makeMove(first_player_id, 4, 8);
    GameList::getInstance()->makeMove(second_player_id, 5, 2);
    GameList::getInstance()->makeMove(first_player_id, 5, 6);
    GameList::getInstance()->makeMove(second_player_id, 5, 1);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), VICTORY);
}

/*!
 * test_case24 - test of result of game with similar situations as it was
 * in test_case22 but here we filled board by method setGameBoard
 */
void test_case24()
{
	  Board board =
  	{
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","X","X","X","X","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""},
    {"","","","","","","","","","","","","","","",""}
  	};

    GameList::getInstance()->setGameBoard(first_player_id, board);
    GameList::getInstance()->makeMove(second_player_id, 5, 1);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), VICTORY);
}

/*!
 * test_case25 - it tests if method makeMove is well-working
 * in strange situations, when one player end game and another one 
 * want to insert his sign
 */
 
void test_case25()
{
    GameList::getInstance()->resetGame(first_player_id);
    bool cond = GameList::getInstance()->makeMove(second_player_id, 0, 0);
    BOOST_CHECK_EQUAL(cond, false);
}

/*!
 * test_case26 - test of result of game where players
 * are inserting their signs in different part of a board
 * and they are blocking each other
 */
void test_case26()
{
    GameList::getInstance()->resetGame(second_player_id);
    GameList::getInstance()->makeMove(first_player_id, 0, 15);
    GameList::getInstance()->makeMove(second_player_id, 0, 0);
    GameList::getInstance()->makeMove(first_player_id, 11, 0);
    GameList::getInstance()->makeMove(second_player_id, 1, 0);
    GameList::getInstance()->makeMove(first_player_id, 12, 1);
    GameList::getInstance()->makeMove(second_player_id, 14, 1);
    GameList::getInstance()->makeMove(first_player_id, 4, 1);
    GameList::getInstance()->makeMove(second_player_id, 1, 1);
    GameList::getInstance()->makeMove(first_player_id, 13, 2);
    GameList::getInstance()->makeMove(second_player_id, 4, 0);
    GameList::getInstance()->makeMove(first_player_id, 11, 3);
    GameList::getInstance()->makeMove(second_player_id, 4, 2);
    GameList::getInstance()->makeMove(first_player_id, 15, 3);
    GameList::getInstance()->makeMove(second_player_id, 12, 3);
    GameList::getInstance()->makeMove(first_player_id, 13, 3);
    GameList::getInstance()->makeMove(second_player_id, 4, 3);
    GameList::getInstance()->makeMove(first_player_id, 14, 3);
    GameList::getInstance()->makeMove(second_player_id, 3, 3);
    GameList::getInstance()->makeMove(first_player_id, 11, 4);
    GameList::getInstance()->makeMove(second_player_id, 4, 4);
    GameList::getInstance()->makeMove(first_player_id, 15, 4);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), VICTORY);
}

/*!
 * test_case27 - it tests if method "getLastMove" works as we expect
 */
void test_case27()
{
  bool cond = (GameList::getInstance()->getLastMove(first_player_id) == (*( new Move(15, 4, "O") ) ) );
  BOOST_CHECK_EQUAL(cond, true);
}

/*!
 * test_case28 - it tests if optimalization in method getResult is working
 */
void test_case28()
{
  BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), VICTORY);
}

/*!
 * test_case0_1 - it tests if method addPlayer works properly in first player case
 */

void test_case0_1()
{
    BOOST_REQUIRE_EQUAL(first_player_sign, "O");
}

/*!
 * test_case0_2 - it tests if method addPlayer works properly in second player case
 */

void test_case0_2()
{
    BOOST_REQUIRE_EQUAL(second_player_sign, "X");
}

/*!
 * test_case0_3 - it tests if method addPlayer works properly in third player case
 */

void test_case0_3()
{
    BOOST_REQUIRE_EQUAL(third_player_sign, "O");
}

/*!
 * test_case0_4 - it tests if method addPlayer works properly in fourth player case
 */

void test_case0_4()
{
    BOOST_REQUIRE_EQUAL(fourth_player_sign, "X");
}

/*!
 * test_case0_5 - it tests if application properly assigns first player with his opponent
 */

void test_case0_5()
{
    BOOST_REQUIRE_EQUAL(GameList::getInstance()->getOpponentsName(first_player_id), "second");
}

/*!
 * test_case0_6 - it tests if application properly assigns second player with his opponent
 */

void test_case0_6()
{
    BOOST_REQUIRE_EQUAL(GameList::getInstance()->getOpponentsName(second_player_id), "first");
}

/*!
 * test_case0_7 - it tests if application properly assigns third player with his opponent
 */

void test_case0_7()
{
    BOOST_REQUIRE_EQUAL(GameList::getInstance()->getOpponentsName(third_player_id), "fourth");
}

/*!
 * test_case0_8 - it tests if application properly assigns fourth player with his opponent
 */

void test_case0_8()
{
    BOOST_REQUIRE_EQUAL(GameList::getInstance()->getOpponentsName(fourth_player_id), "third");
}

/*!
 * test_case0_9 - it tests if application properly assigns fifth player with his opponent
 */

void test_case0_9()
{
    BOOST_REQUIRE_EQUAL(GameList::getInstance()->getOpponentsName(fifth_player_id), "");
}

/*!
 * test_case0_10 - it tests if method findGame returns nullptr when we want to find unexisting game
 */

void test_case0_10()
{
    bool cond = (GameList::getInstance()->findGame(100) == nullptr);
    BOOST_CHECK_EQUAL(cond, true);
}

/*!
 * test_case2_1 - it test if victoriescounter is correct
 */

void test_case2_1()
{
    BOOST_CHECK_EQUAL(GameList::getInstance()->getPlayerPoints(fourth_player_id), 0);
}

/*!
 * test_case2_2 - it test if victoriescounter is correct
 */

void test_case2_2()
{
    BOOST_CHECK_EQUAL(GameList::getInstance()->getPlayerPoints(third_player_id), 2);
}

/*!
 * test_case2_3 - it test if victoriescounter is correct
 */

void test_case2_3()
{
    BOOST_CHECK_EQUAL(GameList::getInstance()->getOpponentsPoints(fourth_player_id), 2);
}

/*!
 * test_case2_4 - it test if victoriescounter is correct
 */

void test_case2_4()
{
    BOOST_CHECK_EQUAL(GameList::getInstance()->getOpponentsPoints(third_player_id), 0);
}

/*!
 * test_case2_5 - it test if victoriescounter is correct
 */

void test_case2_5()
{
    BOOST_CHECK_EQUAL(GameList::getInstance()->getPlayerPoints(first_player_id), 8);
}

/*!
 * test_case2_6 - it test if victoriescounter is correct
 */

void test_case2_6()
{
    BOOST_CHECK_EQUAL(GameList::getInstance()->getPlayerPoints(second_player_id), 8);
}

/*!
 * test_case2_7 - it test if victoriescounter is correct
 */

void test_case2_7()
{
    BOOST_CHECK_EQUAL(GameList::getInstance()->getOpponentsPoints(first_player_id), 8);
}

/*!
 * test_case2_8 - it test if victoriescounter is correct
 */

void test_case2_8()
{
    BOOST_CHECK_EQUAL(GameList::getInstance()->getOpponentsPoints(second_player_id), 8);
}

/*!
 * master_test_suite - accumulation of every tests
 */
test_suite* init_unit_test_suite( int argc, char * argv[] )
{
    first_player_id = GameList::getInstance()->getNewID();    // getting id for first player
    second_player_id = GameList::getInstance()->getNewID();   // --||--
    third_player_id = GameList::getInstance()->getNewID();    // --||--
    fourth_player_id = GameList::getInstance()->getNewID();   // --||--
    fifth_player_id = GameList::getInstance()->getNewID();    // --||--
    first_player_sign = GameList::getInstance()->addPlayer(first_player_id, "first");  // adding first player to list
    second_player_sign = GameList::getInstance()->addPlayer(second_player_id, "second");   // --||--
    third_player_sign = GameList::getInstance()->addPlayer(third_player_id, "third");   // --||--
    fourth_player_sign = GameList::getInstance()->addPlayer(fourth_player_id, "fourth");  // --||--
    fifth_player_sign = GameList::getInstance()->addPlayer(fifth_player_id, "fifth"); // --||--

    test_suite *ts0 = BOOST_TEST_SUITE( "CheckPlayersSuite" );
    ts0->add( BOOST_TEST_CASE( & test_case0_1 ) );
    ts0->add( BOOST_TEST_CASE( & test_case0_2 ) );
    ts0->add( BOOST_TEST_CASE( & test_case0_3 ) );
    ts0->add( BOOST_TEST_CASE( & test_case0_4 ) );
    ts0->add( BOOST_TEST_CASE( & test_case0_5 ) );
    ts0->add( BOOST_TEST_CASE( & test_case0_6 ) );
    ts0->add( BOOST_TEST_CASE( & test_case0_7 ) );
    ts0->add( BOOST_TEST_CASE( & test_case0_8 ) );
    ts0->add( BOOST_TEST_CASE( & test_case0_9 ) );
    ts0->add( BOOST_TEST_CASE( & test_case0_10 ) );

    test_suite *ts1 = BOOST_TEST_SUITE( "CheckConditionSuite" );
    ts1->add( BOOST_TEST_CASE( & test_case1 ) );
    ts1->add( BOOST_TEST_CASE( & test_case2 ) );
    ts1->add( BOOST_TEST_CASE( & test_case3 ) );
    ts1->add( BOOST_TEST_CASE( & test_case4 ) );
    ts1->add( BOOST_TEST_CASE( & test_case5 ) );
    ts1->add( BOOST_TEST_CASE( & test_case6 ) );
    ts1->add( BOOST_TEST_CASE( & test_case7 ) );
    ts1->add( BOOST_TEST_CASE( & test_case8 ) );
    ts1->add( BOOST_TEST_CASE( & test_case9 ) );
    ts1->add( BOOST_TEST_CASE( & test_case10 ) );
    ts1->add( BOOST_TEST_CASE( & test_case11 ) );
    ts1->add( BOOST_TEST_CASE( & test_case12 ) );
    ts1->add( BOOST_TEST_CASE( & test_case13 ) );
    ts1->add( BOOST_TEST_CASE( & test_case14 ) );
    ts1->add( BOOST_TEST_CASE( & test_case15 ) );
    ts1->add( BOOST_TEST_CASE( & test_case16 ) );
    ts1->add( BOOST_TEST_CASE( & test_case17 ) );
    ts1->add( BOOST_TEST_CASE( & test_case18 ) );
    ts1->add( BOOST_TEST_CASE( & test_case19 ) );
    ts1->add( BOOST_TEST_CASE( & test_case20 ) );
    ts1->add( BOOST_TEST_CASE( & test_case21 ) );
    ts1->add( BOOST_TEST_CASE( & test_case22 ) );
    ts1->add( BOOST_TEST_CASE( & test_case23 ) );
    ts1->add( BOOST_TEST_CASE( & test_case24 ) );
    ts1->add( BOOST_TEST_CASE( & test_case25 ) );
    ts1->add( BOOST_TEST_CASE( & test_case26 ) );
    ts1->add( BOOST_TEST_CASE( & test_case27 ) );
    ts1->add( BOOST_TEST_CASE( & test_case28 ) );

    test_suite *ts2 = BOOST_TEST_SUITE( "CheckPointsSuite" );
    ts2->add( BOOST_TEST_CASE( & test_case2_1 ) );
    ts2->add( BOOST_TEST_CASE( & test_case2_2 ) );
    ts2->add( BOOST_TEST_CASE( & test_case2_3 ) );
    ts2->add( BOOST_TEST_CASE( & test_case2_4 ) );
    ts2->add( BOOST_TEST_CASE( & test_case2_5 ) );
    ts2->add( BOOST_TEST_CASE( & test_case2_6 ) );
    ts2->add( BOOST_TEST_CASE( & test_case2_7 ) );
    ts2->add( BOOST_TEST_CASE( & test_case2_8 ) );

    framework::master_test_suite().add( ts0 );
    framework::master_test_suite().add( ts1 );
    framework::master_test_suite().add( ts2 );

    return 0;
}
