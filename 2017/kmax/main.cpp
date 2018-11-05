#include <fstream>
#define nmax 305

using namespace std;

ifstream fin("kmax.in");
ofstream fout("kmax.out");

int n,k,MOD,c[nmax][nmax],dp[nmax][nmax],i,j,q;

int main()
{
    fin >> n >> k >> MOD;
    c[0][0]=1;
    for (i=1; i<=n; i++)
    {
        c[i][0]=1;
        for (j=1; j<=i; j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
    }
    for (i=1; i<=k; i++)
        dp[1][i]=1;
    for (i=2; i<=n; i++)
        for (j=1; j<=k; j++)
        {
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%MOD;
            for (q=1; q<i; q++)
                dp[i][j]=(dp[i][j]+(((dp[q][k-1]*dp[i-1-q][j])%MOD)*c[i-1][q])%MOD)%MOD;
        }
    fout << dp[n][k] << '\n';
    return 0;
}
