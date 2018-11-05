#include <fstream>
#include <vector>
#define MOD 30011

using namespace std;

ifstream fin("iepuri2.in");
ofstream fout("iepuri2.out");

vector <int> v[110];
int dp[110][110],n,i,j,k,root,t[110];

void dfs(int x)
{
    if (v[x].size()==0)
    {
        for (int i=1; i<=k; i++)
            dp[x][i]=1;
        return;
    }
    for (int i=0; i<v[x].size(); i++)
        dfs(v[x][i]);
    for (int j=0; j<v[x].size(); j++)
        for (int i=k; i>0; i--)
            dp[v[x][j]][i]=dp[v[x][j]][i]+dp[v[x][j]][i+1];
    for (int i=k; i>0; i--)
    {
        dp[x][i]=1;
        for (int j=0; j<v[x].size(); j++)
        {
            int SUM=0;
            SUM=(SUM+dp[v[x][j]][i+1])%MOD;
            dp[x][i]=(dp[x][i]*SUM)%MOD;
        }
    }
}

int main()
{
    fin >> n >> k;
    for (i=1; i<n; i++)
    {
        int a,b;
        fin >> a >> b;
        v[a].push_back(b);
        t[b]=a;
    }
    for (i=1; i<=n; i++)
        if (t[i]==0)
            root=i;
    dfs(root);
    int ans=0;
    for (i=1; i<=k; i++)
        ans=(ans+dp[root][i])%MOD;
    fout << ans << '\n';
//    for (i=1; i<=n; i++)
//    {
//        for (j=1; j<=k; j++)
//            fout << dp[i][j] << ' ';
//        fout << '\n';
//    }
}
