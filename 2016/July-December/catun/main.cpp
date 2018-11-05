#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n,m,k,i,j,nr;
bool f[40000];
long long d[40000];
int h[40000];
int poz[40000];
int caref[40000];

vector <int> v[40000];
vector <long long> cost[40000];

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
    freopen("catun.in","r",stdin);
    freopen("catun.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for (i=1; i<=k; i++)
    {
        int a;
        scanf("%d",&a);
        f[a]=1;
        h[++nr]=a;
        poz[a]=nr;
        caref[a]=a;
    }
    for (i=1; i<=m; i++)
    {
        int a,b;
        long long c;
        scanf("%d %d %lld",&a,&b,&c);
        v[a].push_back(b);
        cost[a].push_back(c);
        v[b].push_back(a);
        cost[b].push_back(c);
    }
    while (nr)
    {
        int x=h[1];
        eliminare();
        for (i=0; i<v[x].size(); i++)
            if (!d[v[x][i]]&&!f[v[x][i]])
            {
                d[v[x][i]]=d[x]+cost[x][i];
                caref[v[x][i]]=caref[x];
                adaugare(v[x][i]);
            }
            else
            {
                if (d[v[x][i]]>d[x]+cost[x][i])
                {
                    d[v[x][i]]=d[x]+cost[x][i];
                    caref[v[x][i]]=caref[x];
                    if (poz[v[x][i]]<=nr)
                        upheap(v[x][i]);
                    else adaugare(v[x][i]);
                }
                else if (d[v[x][i]]==d[x]+cost[x][i]&&caref[x]<caref[v[x][i]]&&d[v[x][i]])
                {
                    caref[v[x][i]]=caref[x];
                    if (poz[v[x][i]]>nr)
                        adaugare(v[x][i]);
                }
            }
    }
    for (i=1; i<=n; i++)
        if (f[i])
            printf("%d ", 0);
        else printf("%d ", caref[i]);
}
