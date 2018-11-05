#include <cstdio>
#include <vector>
#define nmax 100010

using namespace std;

int n,m,i,j,d[nmax],log[3*nmax],doi[50],nivel[3*nmax],PE[3*nmax],nr,root,rmq[3*nmax][20],index[nmax];

vector <int> v[nmax];

void euler(int x)
{
    int i;
    PE[++nr]=x;
    index[x]=nr;
    for (i=0; i<v[x].size(); i++)
        {
            nivel[v[x][i]]=nivel[x]+1;
            euler(v[x][i]);
            PE[++nr]=x;
        }
}

int main()
{
    freopen("lca.in","r",stdin);
    freopen("lca.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=2; i<=n; i++)
    {
        scanf("%d",&d[i]);
        v[d[i]].push_back(i);
    }
    nr=0;
    euler(1);
    for (i=2; i<=nr; i++)
        log[i]=log[i/2]+1;
    i=0;
    for (int k=1; k<=nr; k*=2)
        doi[i++]=k;
    for (i=1; i<=nr; i++)
        rmq[i][0]=PE[i];
    for (j=1; j<=log[nr]; j++)
        for (i=1; i<=nr-doi[j]+1; i++)
            if (nivel[rmq[i][j-1]]<nivel[rmq[min(i+doi[j-1],nr)][j-1]])
                rmq[i][j]=rmq[i][j-1];
            else
                rmq[i][j]=rmq[min(i+doi[j-1],nr)][j-1];
    for (i=1; i<=m; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        a=index[a];
        b=index[b];
        if (a>b)
            swap(a,b);
        int d=b-a+1;
        d=log[d];
        if (nivel[rmq[a][d]]<nivel[rmq[b-doi[d]+1][d]])
            printf("%d\n",rmq[a][d]);
        else
            printf("%d\n",rmq[b-doi[d]+1][d]);
    }
}
