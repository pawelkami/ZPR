#ifndef GAME_HPP
#define GAME_HPP

#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <mutex>

//enum Sign {EMPTY, CROSS, CIRCLE};  /// _null = 0, cross = 1, circle = 2
enum GameResult { STILL_PLAYING, DRAW, VICTORY };

#define BOARD_SIZE 16
const std::string CROSS = "X";
const std::string CIRCLE = "O";
const std::string NONE = "";

class Player
{
public:
	int id;
	std::string name;
	std::string sign;
	int victories;
	Player()
	{
		id = -1;
		name = "";
		sign = NONE;
		victories = 0;
	}
	Player(int i, std::string n, std::string s, int v) : id(i), name(n), sign(s), victories(v) {}
};

typedef std::string Sign;
class Move;

typedef std::vector<std::vector<std::string> > Board;

class Game
{
private:
	GameResult checkVertically() const;
	GameResult checkHorizontally() const;
	GameResult checkLeftDownRightUpper() const;
	GameResult checkLeftUpperRightDown() const;
	GameResult checkDraw() const;
	void setPoint(int a, int b, Sign w);		/// zapisanie wspolrzednych nowego kolka lub krzyzyka
	void setBoard(Board board);	// ustawienie planszy na podaną w argumencie
	void setBoard(Sign);		// wypełnienie planszy danym znakiem
	inline void setReseted(bool flag) { reseted_ = flag; };

  Player oPlayer;
	Player xPlayer;
	int x_;		// oba inty reprezentuja wspolrzedne ostatnio dodanego znaku
	int y_;
	Sign which_;	// znak jaki ostatnio wstawiono w miejscu (x, y)
	Board board_;	// reprezentacja planszy
	mutable bool reseted_; //flaga mowiaca czy gra jest zresetowana, true - zrestartowana, false - nie
	mutable bool hasChanged;	// zmienna pomocnicza dla funkcji condition - sprawdza czy trzeba na nowo sprawdzać wynik gry
	mutable GameResult state_;
	mutable std::mutex mtx;

public:
	Game();
	~Game();
	inline Board getBoard() const { return board_; };
	void reset();
	void displayBoard() const;     /// funkcja do testowania, na koniec powinniśmy ją usunąć
	Sign addPlayer(int id, std::string name);		/// dodaje do gry gracza i zwraca figurę, którą będzie grał
	Move getLastMove() const;
	void makeMove(int id, int x, int y);
	std::string getOpponentsName(int id) const;		/// zwraca imię przeciwnika gracza o podanym id. Jeśli gracz o podanym id
	                                        /// nie uczestniczy w danej grze, zwracany string jest pusty
  bool hasPlayer(int id) const;		/// sprawdza czy w grze uczestniczy gracz o podanym id
	bool isFull() const;
	GameResult condition() const;		/// sprawdzenie warunkow zwyciestwa
	inline bool getReseted() const { return reseted_; };
};

class Result;

class GameList;
typedef std::shared_ptr<GameList> PGameList;

class GameList
{
private:
	std::list<Game> list;
	std::mutex mtx;
	int firstUnusedID;
	static PGameList pInstance;
	GameList();
	GameList(const GameList&) = delete;
public:
	~GameList();
	static PGameList getInstance();
	int getNewID();
	Sign addPlayer(int id, std::string name);
	std::string getOpponentsName(int id) const;
	Move getLastMove(int id) const;
	void makeMove(int id, int x, int y);
	GameResult getResult(int id) const;
	void resetGame(int id);
};

class Move
{
public:
	int x;
	int y;
	Sign sign;
	Move()
	{
		x = -1;
		y = -1;
		sign = NONE;
	}
	Move(int xx, int yy, Sign s) : x(xx), y(yy), sign(s) {}
};

#endif // GAME_HPP
