#ifndef GRA_H
#define GRA_H

typedef enum _sign {_null, cross, circle} _sign;  /// _null = 0, cross = 1, circle = 2

class Game
{
public:
	Game();
	~Game();
	short condition();		/// sprawdzenie warunkow zwyciestwa
	void get_point(int a, int b, _sign w);		/// pobranie wspolrzednych nowego kolka lub krzyzyka
private:
	int x;		// oba inty reprezentuja wspolrzedne ostatnio dodanego znaku
	int y;
	_sign which;	// znak jaki ostatnio wstawiono w miejscu (x, y)
	_sign board[16][16];	/// reprezentacja planszy
};

#endif // GRA_H
