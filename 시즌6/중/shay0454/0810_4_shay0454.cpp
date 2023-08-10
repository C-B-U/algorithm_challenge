#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
bool alphabet[26] = { false, };
int N, num, point[30];									                      
string s[30], lower_s, sub_s;
vector<string> v;
bool find_for_option_1(string s,int count_) {					        		//제 1 조건을 위한 함수
	for (auto a = v.begin(); a != v.end(); a++)
		if (*a == s) return false;									                	//이미 있는 단어일 경우 return false
	if (!alphabet[s[0] - 'a']) {									                	//이미 사용한 알파벳인지 확인
		alphabet[s[0] - 'a'] = true;							                		//없을 시 vector에 단어 삽입 및 index 위치 초기화, return true
		point[num] = count_;
		v.push_back(s);
		return true;
	}
	return false;													                         	//그 외 return false
}
void find_for_option_2(string lower_s) {					        		  	//find_for_option_2()함수가 false일시 제 2조건을 위한 함수
	for (int i = 0; i < lower_s.length(); i++)
		if (!alphabet[lower_s[i] - 'a'] && lower_s[i] != ' ') {		  	//이미 사용한 알파벳인지 띄어쓰기가 아닌지 확인
			alphabet[lower_s[i] - 'a'] = true;						            	//true 시 vector에 단어 삽입
			point[num] = i;											                      	//index 위치 초기화
			return;													                          	//return
		}
}
void find_for_option(string lower_s,string sub_s) {
	int count_ = 0;												                      		//index 임시 저장용
	istringstream cin_s(lower_s);						              	  			//getline으로 split을 하기 위한 하나의 장치
	while (getline(cin_s, sub_s, ' ')) {		                      	//하나씩 분리해서 현재 단어가 vector에 들어가 있는지를 확인
		if (find_for_option_1(sub_s, count_)) return;				        	//없으면 return
		else { count_ += sub_s.length() + 1; }				        			  //있을시 나중에 index값으로 찾기위해 현 단어의 길이 + 1(띄어쓰기)를 더함
	}
	find_for_option_2(lower_s);
}
int main() {
	cin >> N; getchar(); fill_n(point, 30, -1);		                  //getline을 쓰기 위해 삽입 이를 사용하여 '\n'를 가져와 정상적 작동을 할 수 있음
	for (num = 0; num < N; num++) {                                 //fill_n()함수로 point의 전체를 -1로 고정
		getline(cin, s[num]); lower_s = s[num];
		for (int j = 0; j < lower_s.length(); j++)
			if (lower_s[j] >= 65 && lower_s[j] <= 90)lower_s[j] += 32;  //비교를 위해 lower로 바꾸는 작업

		find_for_option(lower_s, sub_s);						          	     	//조건 판별
		for (int i = 0; i < s[num].length(); i++) {						        // 찾은 index 위치로 [] 삽입
			if (i == point[num])cout << '[' << s[num][i] << ']';
			else cout << s[num][i];
		} cout << '\n';
	}
	return 0;
}
