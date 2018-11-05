#include <iostream>
#include <vector>
#include <cstdio>
#define max(a,b) a>b ? a : b

using namespace std;

vector <int> v[20000];
int n,i,ans[20000],use[20000],arb[20000];

void dfs(int x)
{
    use[x]=1;
    for (int i=0; i<v[x].size(); i++)
        if (use[v[x][i]]==0)
        {
            dfs(v[x][i]);
            arb[x]+=arb[v[x][i]];
            if (ans[x]<arb[v[x][i]])
                ans[x]=arb[v[x][i]];
        }
    arb[x]++;
}

int main()
{
    freopen("sediu.in","r",stdin);
    freopen("sediu.out","w",stdout);
    cin >> n;
    for (i=1; i<n; i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    for (i=1; i<=n; i++)
        ans[i]=max(ans[i],n-arb[i]);
    int maxim=1000000;
    for (i=1; i<=n; i++)
        if (ans[i]<maxim)
            maxim=ans[i];
    cout << maxim << ' ';
    int nr=0;
    for (i=1; i<=n; i++)
        if (ans[i]==maxim)
            nr++;
    cout << nr << '\n';
    for (i=1; i<=n; i++)
        if (ans[i]==maxim)
            cout << i << ' ';
    cout << '\n';
}
