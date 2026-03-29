#include <iostream>
#include <vector>
using namespace std;
pair<char,char> node[26];

int n;

void preorder(char c){
    if(c=='.')
        return;
    cout << c;
    preorder(node[c-'A'].first);
    preorder(node[c-'A'].second);
}

void inorder(char c){
    if(c=='.')
        return;
    inorder(node[c-'A'].first);
    cout << c;
    inorder(node[c-'A'].second);
}

void postorder(char c){
    if(c=='.')
        return;
    postorder(node[c-'A'].first);
    postorder(node[c-'A'].second);
    cout << c;
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n;i++){
        char a , b , c;
        cin >> a >> b >> c;
        node[a-'A'].first=b;
        node[a-'A'].second=c;


    }
    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');

}