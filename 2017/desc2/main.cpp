#include <fstream>
#include <vector>
#define MOD 10007

using namespace std;

ifstream fin("desc2.in");
ofstream fout("desc2.out");

int n,k,x,i,j,dp[10000],aux,sum[10000];

int main()
{
    fin >> n >> k >> x;
    n=n-x*k*(k-1)/2;
    dp[0]=1;
    sum[0]=1;
    for (i=1; i<=k; i++)
        for (j=i; j<=n; j++)
        {
            dp[j]=(sum[j-i])%MOD,sum[j]=(sum[j]+dp[j])%MOD;
        }
    fout << dp[n] << '\n';
}
/*
dp[n][k]=dp[n-k][1]+dp[n-k][2]+...+dp[n-k][k]
*/
