#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int n ;

vector<string>v1;


int main(){
    cin >> T;
    while(T--){
        cin >> n;
        bool flag = false;

        for(int i = 0  ; i < n;i++){
            string s;
            cin >> s;
            v1.push_back(s);
        }
        std::sort(v1.begin(), v1.end());
        for (int i = 0; i <v1.size()-1 ; ++i) {
            //cout << v1[i] << "\n";
            if(v1[i].length()>=v1[i+1].length()) continue;
            if (v1[i]== v1[i+1].substr(0,v1[i].length())){
                flag = true;
            }
        }
        if(flag==true){
            cout <<"NO" << "\n";
        }else{
            cout << "YES" << "\n";
        }
        v1.clear();
    }


}