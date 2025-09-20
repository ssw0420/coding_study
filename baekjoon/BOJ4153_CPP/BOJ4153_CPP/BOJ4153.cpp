#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int Heru, Ausar, Auset;
	while (true)
	{
		cin >> Heru >> Ausar >> Auset;
		if (Heru == 0 && Ausar == 0 && Auset == 0)
		{
			break;
		}
		int SquareHeru = Heru * Heru;
		int SquareAusar = Ausar * Ausar;
		int SquareAuset = Auset * Auset;
		int LargestNumber = (SquareHeru > SquareAusar) ?
			((SquareHeru > SquareAuset) ? SquareHeru : SquareAuset)
			: ((SquareAusar > SquareAuset) ? SquareAusar : SquareAuset);
		if (LargestNumber == SquareHeru)
		{
			if (LargestNumber == SquareAusar + SquareAuset)
			{
				cout << "right\n";
			}
			else
			{
				cout << "wrong\n";
			}
		}
		else if (LargestNumber == SquareAuset)
		{
			if (LargestNumber == SquareAusar + SquareHeru)
			{
				cout << "right\n";
			}
			else
			{
				cout << "wrong\n";
			}
		}
		else if (LargestNumber == SquareAusar)
		{
			if (LargestNumber == SquareAuset + SquareHeru)
			{
				cout << "right\n";
			}
			else
			{
				cout << "wrong\n";
			}
		}
	}
	return 0;
}