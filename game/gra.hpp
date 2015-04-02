#ifndef GRA_HPP
#define GRA_HPP

enum Sign {EMPTY, CROSS, CIRCLE};  /// _null = 0, cross = 1, circle = 2
enum GameResult { STILL_PLAYING, DRAW, VICTORY };

class Game
{
public:
	Game();
	~Game();
	GameResult condition();		/// sprawdzenie warunkow zwyciestwa
	void get_point(int a, int b, Sign w);		/// pobranie wspolrzednych nowego kolka lub krzyzyka


private:
	GameResult checkVertically();
	GameResult checkHorizontally();
	GameResult checkLeftDownRightUpper();
	GameResult checkLeftUpperRightDown();
	GameResult checkDraw();

	int x_;		// oba inty reprezentuja wspolrzedne ostatnio dodanego znaku
	int y_;
	Sign which_;	// znak jaki ostatnio wstawiono w miejscu (x, y)
	Sign board_[16][16];	/// reprezentacja planszy
};

#endif // GRA_H
