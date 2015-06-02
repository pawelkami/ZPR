#include <boost/test/included/unit_test.hpp>
#include "Game.hpp"
#include "GameList.hpp"
#include <iostream>

using namespace boost::unit_test;

int first_player_id;
int second_player_id;
int third_player_id;
int fourth_player_id;
Sign first_player_sign;
Sign second_player_sign;
Sign third_player_sign;
Sign fourth_player_sign;

/*!
 * test_case1 - test wyniku gry dla pustej planszy
 */
void test_case1()
{
	  GameList::getInstance()->resetGame(third_player_id);
    GameList::getInstance()->resetGame(fourth_player_id);
  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(third_player_id), STILL_PLAYING);
}

/*!
 * test_case2 - test wyniku gry dla 5 kolek w lewym rogu planszy
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
 * test_case3 - test wyniku gry dla planszy z 5 kolkami i 5 krzyzykami
 * (brak spelnionych warunkow zwyciestwa)
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
 * test_case4 - test wyniku gry dla pelnej planszy, gdzie brak
 * warunkow zwyciestwa
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
 * test_case5 - test wyniku gry dla 3 iksow oraz 2 dostawionych funkcja setPoint,
 * piatka iksow po skosie od pola (4, 0) do (0, 4)
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
 * test_case6 - test wyniku gry dla czesciowo wypelnionej planszy
 * z zageszczeniem iksow w lewym dolnym rogu planszy
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
    {"X","","","","","X","","","","","","","","O","",""},
    {"X","X","X","X","","","","","","","","","","","",""},
    {"X","X","X","X","","","","","","","","","","","",""},
    {"X","X","X","X","","","","","","","","","","","",""},
    {"","X","X","X","","","","","","","","","","","",""}
  	};

    GameList::getInstance()->setGameBoard(first_player_id, board);
    GameList::getInstance()->makeMove(second_player_id, 15, 4);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), VICTORY);
}

/*!
 * test_case7 - test wyniku gry dla pelnej planszy, gdzie brak
 * warunkow zwyciestwa
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
 * test_case8 - test wyniku gry dla pelnej planszy, gdzie brak
 * warunkow zwyciestwa
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
    {"","X","X","X","","","","","","","","","","","",""}
  	};

    GameList::getInstance()->setGameBoard(first_player_id, board);
    GameList::getInstance()->makeMove(second_player_id, 13, 2);

  	BOOST_CHECK_EQUAL(GameList::getInstance()->getResult(first_player_id), STILL_PLAYING);
}

/*!
 * test_case9 - test wyniku gry dla planszy, gdzie 5 krzyzykow
 * jest ustawionych po ukosie na srodku (od lewego gornego rogu do prawego dolnego)
 */
void test_case9()
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
 * test_case10 - test wyniku gry dla planszy z piecioma kolkami
 * na srodku ustawionymi pionowo
 */
void test_case10()
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
 * test_case11 - test wyniku gry dla planszy, gdzie w lewym gornym
 * rogu jest piec kolek po przekatnej do prawego dolnego rogu i
 * wszystkie otoczone krzyzykami
 */
void test_case11()
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
 * test_case12 - test wyniku gry dla planszy zawierajacej 5 kolek
 * na srodku po przekatnej z lewego dolnego rogu do prawego gornego
 */
void test_case12()
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
 * test_case13 - test wyniku gry dla planszy, gdzie na srodku jest
 * poziomo ustawione 5 kolek
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
 * test_case14 - test wyniku gry planszy w pelni wypelnionej krzyzykami i kolkami
 * tak aby bylo jak najwiecej jak najwiekszych skupisk jednakowych znakow tj.
 * jak najwiecej krzyzykow i kolek skupionych po 4 na roznych prostych
 */
void test_case14()
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
 * test_case15 - test wyniku gry dla planszy w pelni wypelnionej kolkami i krzyzykami
 * z naciskiem na utworzenie jak najwiecej jak najwiekszych skupisk tj. po 4 jednego znaku
 * ostatni zostaje wstawiony krzyzyk, ktory sprawia, ze powstaja: jedna 7 iksow w poziomie
 * oraz jedna 6 iksow w pionie
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
 * test_case16 - test wyniku gry dla pelnej planszy, wypelnionej w podobny sposob jak plansze w
 * testach nr 14 i 15, ale ostatni wstawiamy krzyzyk, ktory stwarza warunki zwyciestwa w pionie
 * (5 iksow) w obu ukosach (lewa_gora-prawy_dol 6 iksow oraz lewy_dol-prawa_gora 8 iksow)
 */
void test_case16()
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
 * test_case17 - test wyniku gry dla planszy gry, gdzie gracze ustawili po cztery
 * znaki im przydzielone i ich "czworki" maja wspolny koniec, od ktorego zalezy
 * kto zwyciezy gre
 */
void test_case17()
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
 * test_case18 - test wyniku gry dla planszy wypelnianej tylko funkcja setPoint,
 * czyli tak, jak to bedzie wygladalo w rzeczywistosci  (w aplikacji)
 */
void test_case18()
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
 * test_case19 - test sytuacji identycznej jak tescie nr 18,
 * tylko gracze w innej kolejnosci uzupelniali plansze gry
 */
void test_case19()
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
 * test_case20 - test wyniku gry dla planszy wypelnianej przy pomocy metody setPoint
 * symulacja rywalizacji w prawym gornym rogu planszy, gdzie gracze postawili 10 iksow i
 * 11 kolek, ktore zwyciezyly tworzac piatke kolek w pionie na polach od (0,15) do (4, 15)
 */
void test_case20()
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
 * test_case21 - test wyniku gry dla planszy, gdzie gracze naprzemiennie blokowali sie w lewym
 * gornym rogu, powstaly dwie czworki (1 x kolek i 1 x krzyzykow) i kilka mniejszych skupisk
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
 * test_case22 - test wyniku gry, podczas ktorej gracze rywalizowali srodkowo-zachodniej
 * czesci planszy, powstaly dwie udaremnione proby kolek i dwie krzyzykow oraz jedna
 * zwycieska piatka ustawiona przez krzyzyki
 */
void test_case22()
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
 * test_case23 - test wyniku gry dla planszy, wypelnionej tak samo, jak
 * w tescie nr 22, lecz przy pomocy metody setGameBoard
 */
void test_case23()
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
 * test_case24 - test wyniku gry dla planszy wypelnionej przy pomocy
 * metody setPoint, gdzie w lewym gornym rogu pola wypelniane byly
 * krzyzykami zas w lewym dolnym kolkami, zasymulowalem jednoczesnie
 * sytuacje, gdy gracze sie wzajemnie blokuja
 */
void test_case24()
{
    GameList::getInstance()->resetGame(first_player_id);
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
 * test_case0_1 - sprawdzenie poprawnego przydzielenia znaku pierwszemu graczowi
 */

void test_case0_1()
{
    BOOST_REQUIRE_EQUAL(first_player_sign, "O");
}

/*!
 * test_case0_2 - sprawdzenie poprawnego przydzielenia znaku drugiemu graczowi
 */

void test_case0_2()
{
    BOOST_REQUIRE_EQUAL(second_player_sign, "X");
}

/*!
 * test_case0_3 - sprawdzenie poprawnego przydzielenia znaku trzeciemu graczowi
 */

void test_case0_3()
{
    BOOST_REQUIRE_EQUAL(third_player_sign, "O");
}

/*!
 * test_case0_4 - sprawdzenie poprawnego przydzielenia znaku czwartemu graczowi
 */

void test_case0_4()
{
    BOOST_REQUIRE_EQUAL(fourth_player_sign, "X");
}

/*!
 * test_case0_5 - sprawdzenie poprawnego przydzielenia przeciwnika pierwszemu graczowi
 */

void test_case0_5()
{
    BOOST_REQUIRE_EQUAL(GameList::getInstance()->getOpponentsName(first_player_id), "second");
}

/*!
 * test_case0_6 - sprawdzenie poprawnego przydzielenia przeciwnika drugiemu graczowi
 */

void test_case0_6()
{
    BOOST_REQUIRE_EQUAL(GameList::getInstance()->getOpponentsName(second_player_id), "first");
}

/*!
 * test_case0_7 - sprawdzenie poprawnego przydzielenia przeciwnika trzeciemu graczowi
 */

void test_case0_7()
{
    BOOST_REQUIRE_EQUAL(GameList::getInstance()->getOpponentsName(third_player_id), "fourth");
}

/*!
 * test_case0_8 - sprawdzenie poprawnego przydzielenia przeciwnika czwartemu graczowi
 */

void test_case0_8()
{
    BOOST_REQUIRE_EQUAL(GameList::getInstance()->getOpponentsName(fourth_player_id), "third");
}

/*!
 * test_case2_1 - sprawdzenie poprawnego dzialania licznika zwyciestw
 */

void test_case2_1()
{
    BOOST_CHECK_EQUAL(GameList::getInstance()->getPlayerPoints(fourth_player_id), 0);
}

/*!
 * test_case2_2 - sprawdzenie poprawnego dzialania licznika zwyciestw
 */

void test_case2_2()
{
    BOOST_CHECK_EQUAL(GameList::getInstance()->getPlayerPoints(third_player_id), 2);
}

/*!
 * test_case2_3 - sprawdzenie poprawnego dzialania licznika zwyciestw
 */

void test_case2_3()
{
    BOOST_CHECK_EQUAL(GameList::getInstance()->getOpponentsPoints(fourth_player_id), 2);
}

/*!
 * test_case2_4 - sprawdzenie poprawnego dzialania licznika zwyciestw
 */

void test_case2_4()
{
    BOOST_CHECK_EQUAL(GameList::getInstance()->getOpponentsPoints(third_player_id), 0);
}

/*!
 * test_case2_5 - sprawdzenie poprawnego dzialania licznika zwyciestw
 */

void test_case2_5()
{
    BOOST_CHECK_EQUAL(GameList::getInstance()->getPlayerPoints(first_player_id), 8);
}

/*!
 * test_case2_6 - sprawdzenie poprawnego dzialania licznika zwyciestw
 */

void test_case2_6()
{
    BOOST_CHECK_EQUAL(GameList::getInstance()->getPlayerPoints(second_player_id), 8);
}

/*!
 * test_case2_7 - sprawdzenie poprawnego dzialania licznika zwyciestw
 */

void test_case2_7()
{
    BOOST_CHECK_EQUAL(GameList::getInstance()->getOpponentsPoints(first_player_id), 8);
}

/*!
 * test_case2_8 - sprawdzenie poprawnego dzialania licznika zwyciestw
 */

void test_case2_8()
{
    BOOST_CHECK_EQUAL(GameList::getInstance()->getOpponentsPoints(second_player_id), 8);
}

/*!
 * master_test_suite - skumulowanie wszystkich testow
 */
test_suite* init_unit_test_suite( int argc, char * argv[] )
{
    first_player_id = GameList::getInstance()->getNewID();    // pobieramy id dla pierwszego gracza
    second_player_id = GameList::getInstance()->getNewID();   // pobieramy id dla drugiego gracza
    third_player_id = GameList::getInstance()->getNewID();    // --||--
    fourth_player_id = GameList::getInstance()->getNewID();   // --||--
    first_player_sign = GameList::getInstance()->addPlayer(first_player_id, "first");  // dodajemy pierwszego gracza do listy
    second_player_sign = GameList::getInstance()->addPlayer(second_player_id, "second");   // dodajemy drugiego gracza do listy
    third_player_sign = GameList::getInstance()->addPlayer(third_player_id, "third");   // --||--
    fourth_player_sign = GameList::getInstance()->addPlayer(fourth_player_id, "fourth");  // --||--

    test_suite *ts0 = BOOST_TEST_SUITE( "CheckPlayersSuite" );
    ts0->add( BOOST_TEST_CASE( & test_case0_1 ) );
    ts0->add( BOOST_TEST_CASE( & test_case0_2 ) );
    ts0->add( BOOST_TEST_CASE( & test_case0_3 ) );
    ts0->add( BOOST_TEST_CASE( & test_case0_4 ) );
    ts0->add( BOOST_TEST_CASE( & test_case0_5 ) );
    ts0->add( BOOST_TEST_CASE( & test_case0_6 ) );
    ts0->add( BOOST_TEST_CASE( & test_case0_7 ) );
    ts0->add( BOOST_TEST_CASE( & test_case0_8 ) );

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
