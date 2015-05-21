#include "Game.hpp"
#include <iostream>

using namespace std;

int main()
{
	int x, y;
	int kto;  // 0 - kolko, 1 - krzyzyk
	GameResult cond;

	for (int i = 0; ; i++)
	{
		i %= 2;

		if (i == 0)		// ruch kolka
		{
			cout << "Podaj wspolrzedne kolka: ";
			cin >> x >> y;
			cout << endl;
			Game::getInstance()->get_point(x, y, CIRCLE);
			if ((cond = Game::getInstance()->condition()) != 0)
			{
				kto = 0;
				break;
			}
		}
		else		// ruch krzyzyka
		{
			cout << "Podaj wspolrzedne krzyzyka: ";
			cin >> x >> y;
			cout << endl;
			Game::getInstance()->get_point(x, y, CROSS);
			if ((cond = Game::getInstance()->condition()) != 0)
			{
				kto = 1;
				break;
			}
		}
	}

	if (cond == VICTORY)
	{
		cout << "Wygral gracz wstawiajacy ";
		cout << ((kto == 0) ? "kolko" : "krzyzyk") << endl;
	}
	if (cond == DRAW)
	{
		cout << "Gra zakonczona remisem\n";
	}
	cout << "Wcisnij 'q' zeby zakonczyc\n";

	while(getchar() != 'q');

	return 0;
}
