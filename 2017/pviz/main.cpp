#include <fstream>
#define MOD 10007

using namespace std;

ifstream fin("pviz.in");
ofstream fout("pviz.out");

int n,m,i,j,dp[2010][2010],ans,a[2010];

int main()
{
    fin >> n >> m;
    for (i=1; i<=m; i++)
        fin >> a[i];
    if (a[m]!=n)
    {
        fout << "0\n";
        fin.close();
        fout.close();
        return 0;
    }
    dp[0][0]=1;
    for (i=1; i<=n; i++)
        for (j=1; j<=min(i,m); j++)
            dp[i][j]=(dp[i-1][j-1]+(a[j]-i+1)*dp[i-1][j])%MOD;
    fout << dp[n][m] << '\n';
}
