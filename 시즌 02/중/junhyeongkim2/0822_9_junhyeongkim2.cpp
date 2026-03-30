#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int graph[26];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n ;
    cin >> n;

    for(int i = 0 ; i < n ;i++){
        string s;
        cin >> s;
        int pow =1;
        for(int i1=s.length()-1;i1>=0;i1--){
            graph[s[i1]-'A']+=pow;
            //cout << s[i1]-'A' << " "<< graph[s[i1]-'A']<<"\n";
            pow*=10;
        }
    }

    sort(graph,graph+26,greater<>());

    int answer=0;
    int count=9;

    for(int i =0; i < 26;i++){
        answer += graph[i] * count--;
    }

    cout << answer << "\n";
    return 0;




}