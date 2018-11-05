#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector <int> v[20000];
int use[20000],a[20000],ans[20000],i,j,n,maxim;

void dfs(int x)
{
    use[x]=1;
    ans[x]=a[x];
    for (int i=0; i<v[x].size(); i++)
        if (use[v[x][i]]==0)
        {
            dfs(v[x][i]);
            if (ans[x]<ans[x]+ans[v[x][i]])
                ans[x]=ans[x]+ans[v[x][i]];
        }
}

int main()
{
    freopen("asmax.in","r",stdin);
    freopen("asmax.out","w",stdout);
    cin >> n;
    for (i=1; i<=n; i++)
        cin >> a[i];
    for (i=1; i<=n-1; i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    maxim=-1000000;
    for (i=1; i<=n; i++)
        if (ans[i]>maxim)
            maxim=ans[i];
    cout << maxim << '\n';
}
