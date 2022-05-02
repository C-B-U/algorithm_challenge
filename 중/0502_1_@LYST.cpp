#include <iostream>

using namespace std;

int main()
{
    int num;
    int mini = 1;
    int layer = 0;
    cin >> num;

    while(1)
    {
        if(mini <= num && num <= mini + layer*6) break;
        mini += layer*6;
        layer++;
        //cout << layer << " : " << mini << endl;
    }

    cout << layer+1;

    return 0;
}
