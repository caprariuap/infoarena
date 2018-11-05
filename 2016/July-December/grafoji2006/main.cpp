#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m,i,j,dx[7510],dy[7510],x,y,nr;
int fr[7510],r[7510];
bool use[15000];

vector <int> v[7510];
queue <int> q;

int main()
{
    freopen("graf.in","r",stdin);
    freopen("graf.out","w",stdout);
    scanf("%d %d %d %d",&n,&m,&x,&y);
    for (i=1; i<=m; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (i=1; i<=n; i++)
        dx[i]=dy[i]=15000;
    dx[x]=0;
    dy[y]=0;
    q.push(x);
    while (!q.empty())
    {
        int a=q.front();
        q.pop();
        int dd=dx[a];
        for (i=0; i<v[a].size(); i++)
            if (dd+1<dx[v[a][i]])
            {
                dx[v[a][i]]=dd+1;
                q.push(v[a][i]);
            }
    }
    int maxim=0;
    q.push(y);
    while (!q.empty())
    {
        int a=q.front();
        q.pop();
        int dd=dy[a];
        for (i=0; i<v[a].size(); i++)
            if (dd+1<dy[v[a][i]])
            {
                dy[v[a][i]]=dd+1;
                q.push(v[a][i]);
            }
    }
    for (i=1; i<=n; i++)
        if (dx[i]+dy[i]==dx[y])
            fr[dx[i]]++;
    for (i=1; i<=n; i++)
        if (dx[i]+dy[i]==dx[y]&&fr[dx[i]]==1)
            r[++nr]=i;
    for (i=1; i<nr; i++)
        for (j=i+1; j<=nr; j++)
            if (r[i]>r[j])
                swap (r[i],r[j]);
    printf("%d\n",nr);
    for (i=1; i<=nr; i++)
        printf("%d ",r[i]);
    printf("\n");
}
