#include <iostream>
#include <string>

int main()
{
	std::string binary;
	std::string octal;

	std::cin >> octal;

	if (octal.length() == 1 && octal[0] == '0') {
		std::cout << "0";
		return 0;
	}

	for (int i = 0; i < octal.length(); ++i) {
		switch (octal[i]) {
		case '0':
			binary += "000";
			break;
		case '1':
			binary += "001";
			break;
		case '2':
			binary += "010";
			break;
		case '3':
			binary += "011";
			break;
		case '4':
			binary += "100";
			break;
		case '5':
			binary += "101";
			break;
		case '6':
			binary += "110";
			break;
		case '7':
			binary += "111";
			break;
		}
	}

	int i;
	for (i = 0; i < binary.length(); ++i) {
		if (binary[i] == '1') {
			break;
		}
	}

	for (int j = i; j < binary.length(); ++j) {
		std::cout << binary[j];
	}

	return 0;
}