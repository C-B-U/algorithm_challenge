#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int L,C;
string s;
int visited[16];

void back(int sx, string s2 , int m, int j ){
    if(s2.size()==L){
        if(m>=1&&j>=2){
            cout << s2 << "\n";
            return ;
        }
    }else{
        for(int i = sx ; i<C;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                back(i+1,s2+s[i],m+1,j);
            }else{
                back(i+1,s2+s[i],m,j+1);
            }
        }
        return;
    }



}


int main(){

    cin >> L >> C;

    for(int i = 0 ; i <C;i++){
        char a;
        cin >> a;
        s+=a;

    }
    std::sort(s.begin(), s.end());

    back(0,"",0,0);
    return 0 ;


}
