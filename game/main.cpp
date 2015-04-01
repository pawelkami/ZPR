#include "gra.h"
#include <iostream>

using namespace std;

int main()
{
	Game gra;
	int x, y;
	int kto;  // 0 - kolko, 1 - krzyzyk
	short cond;

	for (int i = 0; ; i++)
	{
		i %= 2;

		if (i == 0)		// ruch kolka
		{
			cout << "Podaj wspolrzedne kolka: ";
			cin >> x >> y;
			cout << endl;
			gra.get_point(x, y, circle);
			if ((cond = gra.condition()) != 0)
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
			if ((cond = gra.condition()) != 0)
			{
				kto = 1;
				break;
			}
		}
	}

	if (cond == 2)
	{
		cout << "Wygral gracz wstawiajacy ";
		cout << ((kto == 0) ? "kolko" : "krzyzyk") << endl;
	}
	if (cond == 1)
	{
		cout << "Gra zakonczona remisem\n";
	}
	cout << "Wcisnij 'q' zeby zakonczyc\n";

	char c;
	while((c = getchar()) != 'q');

	return 0;
}