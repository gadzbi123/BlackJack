#include <iostream>
#include <array>
using namespace std;

void wektor_charakterystyczny()
{
	const int n = 15;
	array<int, n - 1> tab;
	tab.fill(1);

	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			if (j % i == 0 and j != i)
				tab[j - 2] = 0;
		}
	}

	for (int i = 0; i < n - 1; i++)
		cout << tab[i] << " ";
}

int main()
{
	const int n = 15;
	array<int, n - 1> tab;
	tab.fill(1);

	for (int i = 2; i <= n; i++)
	{
		if (tab[i - 2] == 0)
			continue;
		for (int j = 2; j <= n; j++)
		{
			if (j % i == 0 and j != i)
				tab[j - 2] = 0;
		}
	}

	for (int i = 0; i < n - 1; i++)
		cout << tab[i] << " ";
}
