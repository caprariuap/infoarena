#include <fstream>
#define MOD 666013

using namespace std;

ifstream fin("colors.in");
ofstream fout("colors.out");

int n,i,dp[1000010][2][2];
bool a[5];

int main()
{
    fin >> n;
    char c1,c2;
    fin >> c1 >> c2;
    if (c1=='V')
        a[1]=1;
    if (c2=='V')
        a[2]=1;
    dp[2][!a[2]][a[1]]=1;
    dp[1][a[1]][!a[1]]=1;
    for (i=3; i<=n; i++)
    {
        char c;
        fin >> c;
        bool cul=0;
        bool notcul=1;
        if (c=='V')
            cul=1,notcul=0;
        dp[i][notcul][notcul]=(dp[i-1][notcul][cul]+dp[i-1][notcul][notcul])%MOD;
        dp[i][notcul][cul]=(dp[i-1][cul][cul]+dp[i-1][notcul][notcul])%MOD;
        dp[i][cul][notcul]=(dp[i-1][cul][notcul]+dp[i-1][cul][cul])%MOD;
        dp[i][cul][cul]=(dp[i-1][notcul][cul]+dp[i-1][cul][notcul])%MOD;

//        else
//        {
//            dp[i][!cul][!cul]=(dp[i-1][!cul][cul]+dp[i-1][!cul][!cul])%MOD;
//            dp[i][cul][!cul]=(dp[i-1][cul][cul]+dp[i-1][cul][!cul])%MOD;
//            dp[i][!cul][cul]=(dp[i-1][cul][!cul]+dp[i-1][cul][cul])%MOD;
//            dp[i][cul][cul]=(dp[i-1][!cul][cul]+dp[i-1][!cul][!cul])%MOD;
//        }

    }
    fout << (dp[n][1][0]+dp[n][1][1])%MOD << '\n';
    for (i=1; i<=n; i++)
    {
        fout << dp[i][0][0] << ' ' << dp[i][0][1] << ' ' << dp[i][1][0] << ' ' << dp[i][1][1] << '\n';
    }
}
