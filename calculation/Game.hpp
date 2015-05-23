#ifndef GAME_HPP
#define GAME_HPP

#include <cstdlib>
#include <iostream>
#include <memory>
#include <array>

//enum Sign {EMPTY, CROSS, CIRCLE};  /// _null = 0, cross = 1, circle = 2
enum GameResult { STILL_PLAYING, DRAW, VICTORY };
std::string getPlayerName();

#define BOARD_SIZE 16
const std::string CROSS = "X";
const std::string CIRCLE = "O";
const std::string NONE = "";

class Game;
typedef std::shared_ptr<Game> PGame;
typedef std::string Sign;

typedef std::array<std::array<std::string, BOARD_SIZE>, BOARD_SIZE> Board;

class Game
{
private:
	Game();
	Game(const Game&) = delete;
	void operator=(const Game&) = delete;
	GameResult checkVertically();
	GameResult checkHorizontally();
	GameResult checkLeftDownRightUpper();
	GameResult checkLeftUpperRightDown();
	GameResult checkDraw();

	static PGame pInstance;
	int x_;		// oba inty reprezentuja wspolrzedne ostatnio dodanego znaku
	int y_;
	Sign which_;	// znak jaki ostatnio wstawiono w miejscu (x, y)
	Board board_;	// reprezentacja planszy

public:
	static PGame getInstance();
	~Game();
	GameResult condition();		/// sprawdzenie warunkow zwyciestwa
	void get_point(int a, int b, Sign w);		/// pobranie wspolrzednych nowego kolka lub krzyzyka
	inline Board getBoard() { return board_; };
	void setBoard(Board board);

};

#endif // GAME_HPP
