#include<iostream>

void executeCommand(long long& add, long long& mul, long long& del) {
	int command,num=0;
	std::cin >> command;
	if (command == 3) {
		std::cout << (1 + del) * mul+add<<'\n';
		return;
	}
	std::cin >> num;
	switch (command){
		case 0:
			add += num;
			return;
		case 1:
			mul *= num;
			add *= num;
			return;
		case 2:
			del += num;
			return;
	}
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	long long Q, add = 0, mul = 1, del = 0;
	std::cin >> Q;
	while (Q--) {
		executeCommand(add,mul,del);
	}
}
