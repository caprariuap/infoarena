#include <fstream>
#include <queue>
#include <vector>
#define NMAX 50010

using namespace std;

int n,m,g,d[NMAX],i,j,nr,h[3*NMAX],poz[NMAX];

vector <int> v[NMAX],cost[NMAX];

void adaugare(int x)
{
    h[++nr]=x;
    poz[x]=nr;
    int y=nr;
    while (y>1)
    {
        if (d[h[y]]<d[h[y/2]])
        {
            swap(poz[h[y]],poz[h[y/2]]);
            swap(h[y],h[y/2]);
            y/=2;
        }
        else y=1;
    }
}

void upheap(int x)
{
    int y=poz[x];
    while (y>1)
    {
        if (d[h[y]]<d[h[y/2]])
        {
            swap(poz[h[y]],poz[h[y/2]]);
            swap(h[y],h[y/2]);
            y/=2;
        }
        else y=1;
    }
}

void eliminare()
{
    swap(poz[h[nr]],poz[h[1]]);
    swap(h[nr],h[1]);
    nr--;
    int y=1;
    while (y<=nr)
    {
        int z=y;
        if (y*2<=nr)
        {
            z=2*y;
            if (y*2+1<=nr&&d[h[z]]>d[h[z+1]])
                z++;
        }
        else return;
        if (d[h[z]]<d[h[y]])
        {
            swap(poz[h[y]],poz[h[z]]);
            swap(h[y],h[z]);
            y=z;
        }
        else return;
    }
}

int main()
{
    freopen("camionas.in","r",stdin);
    freopen("camionas.out","w",stdout);
    scanf("%d %d %d", &n, &m, &g);
    for (i=2; i<=n; i++)
        d[i]=100010,poz[i]=100010;
    for (i=1; i<=m; i++)
    {
        int x,y,z;
        scanf("%d %d %d", &x, &y, &z);
        if (z<g)
            z=1;
        else
            z=0;
        v[x].push_back(y);
        cost[x].push_back(z);
        v[y].push_back(x);
        cost[y].push_back(z);
    }
    d[1]=0;
    adaugare(1);
    d[h[1]]=0;
    while (nr)
    {
        int x=h[1];
        eliminare();
        for (i=0; i<v[x].size(); i++)
            if (d[v[x][i]]>d[x]+cost[x][i])
            {
                d[v[x][i]]=d[x]+cost[x][i];
                if (poz[v[x][i]]<=nr)
                    upheap(v[x][i]);
                else adaugare(v[x][i]);
            }
    }
    printf("%d",d[n]);
}

