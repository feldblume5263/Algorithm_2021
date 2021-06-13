#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const int R = strlen("abcdefghijklmnopqrstuvwxyz") + 1;

void				lsd_string_radix(string array[], int array_size, int max_chars)
{
	string			*temp = new string[array_size];

	for (int i = max_chars - 1; i >= 0; i--)
	{
		int count[R] = {0, };

		for (int j = 0; j < array_size; j++)
			count[static_cast<int>(array[j][i]) - 'a' + 1]++;

		for (int j = 2; j < 26; j++)
			count[j] += count[j - 1];

		for (int j = 0; j < array_size; j++)
			temp[count[static_cast<int>(array[j][i]) - 'a']++] = array[j];

		for (int j = 0; j < array_size; j++)
			array[j] = temp[j];
	}
}

int					main()
{
	string			array[6] = {"paris", "seoul", "viena", "nizza", "praha", "busan"};

	lsd_string_radix(array, 6, 5);
	for (size_t i = 0; i < 6; i++)
		cout << array[i] << endl;
	return 0;
}
