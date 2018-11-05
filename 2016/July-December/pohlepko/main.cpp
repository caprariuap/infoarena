#include <iostream>
#include <queue>
#define min(G,H) G<H ? G : H

using namespace std;

int n,m,i,j;
char a[3000][3000],aux[10000];

void dfs(int x, int y, int nr)
{
    if (a[x][y]>aux[nr])
        return;
    else
        aux[nr]=a[x][y];
    if (x==n&&y==m)
    {
        aux[nr]=a[x][y];
        aux[++nr]='\0';
        return;
    }
    if (x==n)
    {
        dfs(x,y+1,nr+1);
        return;
    }
    if (y==m)
    {
        dfs(x+1,y,nr+1);
        return;
    }
    if (a[x+1][y]==a[x][y+1])
    {
        dfs(x+1,y,nr+1);
        dfs(x,y+1,nr+1);
    }
    if (a[x+1][y]<a[x][y+1])
    {
        dfs(x+1,y,nr+1);
    }
    else if (a[x+1][y]>a[x][y+1])
    {
        dfs(x,y+1,nr+1);
    }
    else
    {
        dfs(x+1,y,nr+1);
        dfs(x,y+1,nr+1);
    }
}

int main()
{
    cin>>n>>m;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        {
            char c;
            cin>>c;
            a[i][j]=c;
        }
    for (i=0; i<n+m; i++)
        aux[i]='z'+1;
    dfs(1,1,0);
    cout<<aux;
    cout<<'\n';
}
