#ifndef GAME_HPP
#define GAME_HPP

#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <shared_mutex>
//#include <boost/thread/shared_mutex.hpp>

enum GameResult { STILL_PLAYING, DRAW, VICTORY };

#define BOARD_SIZE 16			// rozmiar planszy

// zmienne odpowiadające za znaki na planszy
typedef std::string Sign;
const Sign CROSS = "X";
const Sign CIRCLE = "O";
const Sign NONE = "";

class Player
{
public:
	int id;
	std::string name;
	std::string sign;
	int victories;
	inline void incrementVictories() { ++victories; };
	Player() : id(-1), name(""), sign(NONE), victories(0) {}
	Player(int i, std::string n, std::string s, int v) : id(i), name(n), sign(s), victories(v) {}
};

typedef std::lock_guard<std::shared_timed_mutex> WriteLock;
typedef std::shared_lock<std::shared_timed_mutex> ReadLock;
class Move;

typedef std::vector<std::vector<Sign> > Board;

class Game
{
private:
	GameResult checkVertically() const;
	GameResult checkHorizontally() const;
	GameResult checkLeftDownRightUpper() const;
	GameResult checkLeftUpperRightDown() const;
	GameResult checkDraw() const;
	void setPoint(const int& a, const int& b, const Sign& w);		/// zapisanie wspolrzednych nowego kolka lub krzyzyka
	inline void setBoard(const Board& board) { board_ = board; };	// ustawienie planszy na podaną w argumencie
	void setBoard(const Sign&);		// wypełnienie planszy danym znakiem

	Player oPlayer;
	Player xPlayer;
	int x_;		// oba inty reprezentuja wspolrzedne ostatnio dodanego znaku
	int y_;
	Sign which_;	// znak jaki ostatnio wstawiono w miejscu (x, y)
	Board board_;	// reprezentacja planszy
	mutable int reseted_; //flaga mowiaca czy gra jest zresetowana, true - zrestartowana, false - nie
	mutable bool hasChanged;	// zmienna pomocnicza dla funkcji condition - sprawdza czy trzeba na nowo sprawdzać wynik gry
	mutable GameResult state_;		// stan gry ( VICTORY, DRAW, STILL_PLAYING )
	mutable std::shared_timed_mutex mtx;

public:
	Game();
	~Game();
	inline Board getBoard() const { return board_; };
	void reset();
	void displayBoard() const;     /// funkcja do testowania, na koniec powinniśmy ją usunąć
	Sign addPlayer(const int& id, const std::string& name);		/// dodaje do gry gracza i zwraca figurę, którą będzie grał
	Move getLastMove() const;
	bool makeMove(const int& id, const int& x, const int& y);
	std::string getOpponentsName(const int& id) const;		/// zwraca imię przeciwnika gracza o podanym id. Jeśli gracz o podanym id
	                                        /// nie uczestniczy w danej grze, zwracany string jest pusty
  bool hasPlayer(const int& id) const;		/// sprawdza czy w grze uczestniczy gracz o podanym id
	bool isFull() const;
	GameResult condition();		/// sprawdzenie warunkow zwyciestwa
	inline bool getReseted() const { return reseted_; };
	inline int getPlayerPoints(const int& id) const { return (id == oPlayer.id ? oPlayer.victories : xPlayer.victories); };
	inline int getOpponentsPoints(const int& id) const { return (id != oPlayer.id ? oPlayer.victories : xPlayer.victories); };
	inline GameResult getState() const { return state_; };
};

class Result;

class GameList;
typedef std::shared_ptr<GameList> PGameList;

class GameList
{
private:
	std::list<Game> list;
	mutable std::shared_timed_mutex mtx;
	int firstUnusedID;
	static PGameList pInstance;
	GameList();
	GameList(const GameList&) = delete;
public:
	~GameList();
	static PGameList getInstance();
	int getNewID();
	Sign addPlayer(const int& id, const std::string& name);
	std::string getOpponentsName(const int& id) const;
	Move getLastMove(const int& id) const;
	bool makeMove(const int& id, const int& x, const int& y);
	GameResult getResult(const int& id) const;
	void resetGame(const int& id);
	int getPlayerPoints(const int& id) const;
	int getOpponentsPoints(const int& id) const;
};

class Move
{
public:
	int x;
	int y;
	Sign sign;
	Move() : x(-1), y(-1), sign(NONE) {}
	Move(int xx, int yy, Sign s) : x(xx), y(yy), sign(s) {}
};

#endif // GAME_HPP
