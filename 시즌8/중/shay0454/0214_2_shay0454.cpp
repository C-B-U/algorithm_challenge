#include<iostream>
using namespace std;
int get_num_of_wrong_alphabet(string a,string b, int gab) { 
	int diff = 0;
	for (int i = 0; i < a.size(); i++)if (a[i] != b[i + gab])diff++;
	return diff;
}
int check_diff(string a,string b){
	int min = 50;
	for (int i = 0, temp; i <= b.size() - a.size(); i++) { if (min > (temp = get_num_of_wrong_alphabet(a, b, i))) min = temp; }
	return min;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string a, b;
	cin >> a >> b;
	cout << check_diff(a, b);
	//임의의 알파벳을 앞, 뒤로 넣으므로 임의의 알파벳을 겹치는 알파벳을 넣었다고 보게 될 수 있음
	//이 경우 원래의 string a와 a의 앞에 넣은 gab에 해당하는 b의 위치부터 비교만 하면 됨 (앞은 맞게 넣었고, 뒤는 차이가 있어도 같은 알파벳을 넣어 차이가 없게 할 수 있음)
}
