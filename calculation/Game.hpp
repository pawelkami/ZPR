#ifndef GAME_HPP
#define GAME_HPP

#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <shared_mutex>
#include "Player.hpp"
#include "Move.hpp"
#include "Project_declarations.hpp"
//#include <boost/thread/shared_mutex.hpp>

enum GameResult { STILL_PLAYING, DRAW, VICTORY };


class Game
{
private:
	GameResult checkVertically() const;
	GameResult checkHorizontally() const;
	GameResult checkLeftDownRightUpper() const;
	GameResult checkLeftUpperRightDown() const;
	GameResult checkDraw() const;
	void setPoint(const int& a, const int& b, const Sign& w);		/// zapisanie wspolrzednych nowego kolka lub krzyzyka
	void setBoard(const Sign&);		// wypełnienie planszy danym znakiem

	Player oPlayer;
	Player xPlayer;
	Move move_;	//ostatni ruch
	Board board_;	// reprezentacja planszy
	mutable int reseted_; //flaga mowiaca czy gra jest zresetowana, true - zrestartowana, false - nie
	mutable bool hasChanged;	// zmienna pomocnicza dla funkcji condition - sprawdza czy trzeba na nowo sprawdzać wynik gry
	mutable GameResult state_;		// stan gry ( VICTORY, DRAW, STILL_PLAYING )
	mutable std::shared_timed_mutex mtx;

public:
	Game();
	~Game();
	const int BOARD_SIZE = 16;			// rozmiar planszy

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
	inline void setBoard(const Board& board) { board_ = board; };	// ustawienie planszy na podaną w argumencie
};


#endif // GAME_HPP
