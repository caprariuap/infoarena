#include <cstdio>
#include <vector>
#define nmax 300010

using namespace std;

FILE *fin=fopen("arbvalmax.in","r");
FILE *fout=fopen("arbvalmax.out","w");

vector <int> v[nmax];
int maxwith[nmax],p[nmax],a[nmax],maxson[nmax],maxwithout[nmax],max1[nmax],max2[nmax],n,m,i,nivel[nmax];

void dfs(int x)
{
    maxwith[x]=max(maxwith[p[x]],a[p[x]]);
    for (int i=0; i<v[x].size(); i++)
    {
        nivel[v[x][i]]=nivel[x]+1;
        dfs(v[x][i]);
        int aux=max(max1[v[x][i]],a[v[x][i]]);
        if (aux>max1[x])
        {
            max2[x]=max1[x];
            max1[x]=aux;
            maxson[x]=v[x][i];
        }
        else if (aux>max2[x])
            max2[x]=aux;
    }
}

void dfs2(int x)
{
    for (int i=0; i<v[x].size(); i++)
    {
        if (v[x][i]==maxson[x])
            maxwithout[v[x][i]]=max(maxwithout[x],max2[x]);
        else
            maxwithout[v[x][i]]=max(maxwithout[x],max1[x]);
        dfs2(v[x][i]);
    }
}

int main()
{
    fscanf(fin,"%d%d",&n,&m);
    for (i=2; i<=n; i++)
    {
        fscanf(fin,"%d",&p[i]);
        v[p[i]].push_back(i);
    }
    for (i=1; i<=n; i++)
        fscanf(fin,"%d",&a[i]);
    dfs(1);
    dfs2(1);
    for (i=1; i<=m; i++)
    {
        int x,y;
        fscanf(fin,"%d%d",&x,&y);
        if (nivel[y]<nivel[x])
            swap(x,y);
        int ans=0;
        ans=max(maxwithout[y],maxwith[x]);
        ans=max(ans,max1[y]);
        fprintf(fout,"%d\n",ans);
    }
}
