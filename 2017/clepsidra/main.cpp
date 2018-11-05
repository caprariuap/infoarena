#include <fstream>
#include <vector>
#include <algorithm>
#define nmax 200010
#define MOD 666013

using namespace std;

ifstream fin("clepsidra.in");
ofstream fout("clepsidra.out");

vector <int> v[nmax];
int n,i,j,m,low[nmax],nivel[nmax],ans[nmax],doi[nmax];
bool use[nmax];

void dfs(int x)
{
    use[x]=1;
    low[x]=nivel[x];
    int nrc=(nivel[x] ? 1 : 0);
    for (int i=0; i<v[x].size(); i++)
    {
        int vecin=v[x][i];
        if (use[vecin])
            low[x]=min(low[x],nivel[vecin]);
        else
        {
            nivel[vecin]=nivel[x]+1;
            dfs(vecin);
            if (low[vecin]>=nivel[x])
                ++nrc;
            low[x]=min(low[x],low[vecin]);
        }
    }
    ans[x]=doi[nrc];
}

int main()
{
    fin >> n >> m;
    for (i=1; i<=m; i++)
    {
        int x,y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    doi[0]=1;
    for (i=1; i<=n+5; i++)
        doi[i]=(doi[i-1]*2)%MOD;
    for (i=0; i<=n+5; i++)
    {
        doi[i]-=2;
        if (doi[i]<0)
            doi[i]+=MOD;
        doi[i]%=MOD;
    }
    dfs(1);
    for (i=1; i<=n; i++)
        fout << ans[i] << '\n';
    fin.close();
    fout.close();
    return 0;
}
