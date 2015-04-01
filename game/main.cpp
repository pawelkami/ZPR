#include "gra.h"
#include <iostream>

using namespace std;

int main()
{
	Game gra;
	int x, y;
	int kto;  // 0 - kolko, 1 - krzyzyk

	for (int i = 0; ; i++)
	{
		i %= 2;

		if (i == 0)		// ruch kolka
		{
			cout << "Podaj wspolrzedne kolka: ";
			cin >> x >> y;
			cout << endl;
			gra.get_point(x, y, circle);
			if (gra.condition())
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
			gra.get_point(x, y, cross);
			if (gra.condition())
			{
				kto = 1;
				break;
			}
		}
	}

	cout << "Wygral gracz wstawiajacy ";
	cout << ((kto == 0) ? "kolko" : "krzyzyk") << endl;

	cin >> x;

	return 0;
}