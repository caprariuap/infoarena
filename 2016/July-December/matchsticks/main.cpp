#include <iostream>

using namespace std;

long long dp[101][51],n,i,j,t;

int main()
{
    cin>>t;
    for (i=2; i<=7; i++)
        dp[i][0]=1;
    dp[2][1]=1;
    dp[3][1]=7;
    dp[4][1]=4;
    dp[5][1]=2;
    dp[6][1]=6;
    dp[7][1]=8;
    for (i=8; i<=100; i++)
    {

    }
    return 0;
}
