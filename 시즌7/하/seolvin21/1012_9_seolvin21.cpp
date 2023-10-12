#include <iostream>

int main()
{
	char l;
	int max = 0;
	int alphabet[26] = { NULL };

	while (std::cin >> l) {
		if ('a' <= l && l <= 'z')
			alphabet[l - 'a']++;
	}

	for (int i = 0; i < 26; ++i) {
		if (max < alphabet[i])
			max = alphabet[i];
	}
	for (int i = 0; i < 26; ++i) {
		if (alphabet[i] == max)
			std::cout << char(i + 'a');
	}
}