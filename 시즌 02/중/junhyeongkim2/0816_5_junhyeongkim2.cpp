#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

string s;
stack<char>st;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> s;
    int temp=1;
    bool flag = false;
    int answer=0;

    for(int i = 0 ; i < s.size();i++){
        if(s[i]=='('){
            st.push('(');
            temp *=2;
        }else if (s[i]=='['){
            st.push('[');
            temp *=3;
        }else if(s[i]==')'){
            if(st.empty()){
                flag=true;
                break;
            }else if(st.top()=='('){
                if(s[i-1]=='('){
                    answer += temp;
                }
                st.pop();
                temp/=2;
            }else{
                flag = true;
                break;
            }
        }else if(s[i]==']'){
            if(st.empty()){
                flag=true;
                break;
            }else if(st.top()=='['){
                if(s[i-1]=='['){
                    answer +=temp;
                }
                st.pop();
                temp/=3;
            }else{
                flag = true;
                break;
            }
        }

    }

    if(flag||!st.empty()){
        cout << 0 << "\n";
    }else{
        cout << answer << "\n";
    }





}