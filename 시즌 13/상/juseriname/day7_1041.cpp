#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
/**
모서리 계산 중요
1면,2면,3면 최소합 구하기...

**/

int main()
{
    int n; // 1->1,000,000 // 제곱하면 최대 10조... -> long long int
    cin >> n;
    int e[6]={0,}; //<0-A,5-F>,<1-B,4-E>,<2-C,3-D>
    for(int i=0;i<6;i++)
    {
        cin >> e[i];
    }
    long long hap=0;
    if(n==1)
    {
        sort(e,e+6);
        for(int i=0;i<5;i++)
        {
            hap+= e[i];
        }
    }
    else
    {
        //3면 4 -> 4
        int temp1[8]={e[0]+e[1]+e[2],e[0]+e[1]+e[3],e[0]+e[4]+e[2],e[0]+e[4]+e[3],e[5]+e[1]+e[2],e[5]+e[1]+e[3],e[5]+e[4]+e[2],e[5]+e[4]+e[3]};
        sort(temp1,temp1+8);
        //cout << temp1[0] << '\n';
        hap+= (4)*(temp1[0]);
        //2면 4(n-2)+4(n-1) -> 8n - 12
        int temp2[12]={e[0]+e[1],e[0]+e[4],e[0]+e[2],e[0]+e[3],e[5]+e[1],e[5]+e[4],e[5]+e[2],e[5]+e[3],e[1]+e[2],e[1]+e[3],e[4]+e[2],e[4]+e[3],};
        sort(temp2,temp2+12);
        //cout<< temp2[0] << '\n';
        hap+= (8*n-12)*(temp2[0]);
        //1면 4(n-2)(n-1)+(n-1)^2 -> 5n^2 - 16n - 12
        int temp3[6]={e[0],e[1],e[2],e[3],e[4],e[5]};
        sort(temp3,temp3+6);
        //cout << temp3[0] << '\n';
        hap+= (5*pow(n,2)-16*n+12)*(temp3[0]);
    }
    cout << hap << '\n';
    return 0;
}
