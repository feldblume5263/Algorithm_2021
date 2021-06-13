#include <iostream>

using namespace std;

int			main(void)
{
	char			a[13] = "dacffbdbfbea";
	int			N = strlen(a);
	int			R = strlen("abcdef");
	int			*count = new int[R + 1];
	char			aux[13];


	for (int i = 0; i <= R; i++)
		count[i] = 0;

	for (int i = 0; i < N; i++)
	{
		count[a[i] - 'a' + 1]++;
	}

	for (int r = 0; r < R; r++)
	{
		count[r + 1] += count[r];
	}

	for (int i = 0; i < N; i++)
	{
		aux[count[a[i] - 'a']] = a[i];
		count[a[i] - 'a']++;
	}

	for (int i = 0; i < N; i++)
		a[i] = aux[i];

	for (int i = 0; i < N; i++)
		cout << a[i] << " ";
	cout << endl;
}
