#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("euro3.in");
ofstream fout("euro3.out");

int n,vmax,i,j,a[4010],dp[8010],ans[8010];

void solve()
{
    fin >> n >> vmax;
    for (i=1; i<=n; i++)
        fin >> a[i];
    for (i=1; i<=vmax; i++)
        dp[i]=-1,ans[i]=10000;
    sort(a+1,a+n+1);
    for (i=1; i<=n; i++)
    {
        for (j=vmax; j>=a[i]; j--)
            dp[j]=max(dp[j],dp[j-a[i]]);
        dp[a[i]]=a[i];
        for (j=0; j<=vmax; j++)
            if (ans[j]>a[i]-dp[j]&&dp[j]!=-1)
                ans[j]=a[i]-dp[j];
    }
    for (i=1; i<=vmax; i++)
        if (ans[i]==10000)
            fout << "-1 ";
        else
            fout << ans[i] << ' ';
    fout << '\n';
}

int main()
{
    int t;
    fin >> t;
    for (int T=1; T<=t; T++)
        solve();
}
