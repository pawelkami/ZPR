#ifndef GAME_HPP
#define GAME_HPP

#include <cstdlib>
#include <iostream>
#include <memory>

enum Sign {EMPTY, CROSS, CIRCLE};  /// _null = 0, cross = 1, circle = 2
enum GameResult { STILL_PLAYING, DRAW, VICTORY };
std::string getPlayerName();

class Game;
typedef std::shared_ptr<Game> PGame;

class Game
{
public:
	static PGame getInstance();
	~Game();
	GameResult condition();		/// sprawdzenie warunkow zwyciestwa
	void get_point(int a, int b, Sign w);		/// pobranie wspolrzednych nowego kolka lub krzyzyka


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
	Sign board_[16][16];	/// reprezentacja planszy
};

#endif // GAME_HPP
