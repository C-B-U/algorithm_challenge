#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<int>v1;
vector<int>v2;
map<int,int>m1;

int n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0 ; i < n ; i ++){
        int x =0;
        cin >> x;
        v1.push_back(x);
        v2.push_back(x);
    }

    int cnt=0;
    std::sort(v2.begin(), v2.end());

    for(int i = 0; i < v2.size();i++){
        //cout << cnt << " ";
        //cout << v2[i]<<"\n";
        m1[v2[i]] = cnt;
        if(v2[i+1]>v2[i]){
            cnt++;
        }
    }

    for(int i = 0 ; i < v1.size();i++){
        cout << m1[v1[i]]<<" ";
    }







}