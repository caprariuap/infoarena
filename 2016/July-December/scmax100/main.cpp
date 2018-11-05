#include <fstream>

using namespace std;

ifstream fin("scmax.in");
ofstream fout("scmax.out");

int n,a[100010],best[100010],p[100010],l[100010],i,j,poz,nr,k,maxim;

void afisare(int x)
{
    if (p[x]>0)
        afisare(p[x]);
    fout<<a[x]<<' ';
}

int cb(int x)
{
    int p,u,m;
    p=0;
    u=nr;
    while (p<=u)
    {
        m=(p+u)/2;
        if (a[l[m]]<x&&a[l[m+1]]>=x) return m;
        else if (a[l[m+1]]<x) p=m+1;
        else u=m-1;
    }
    return nr;
}

int main()
{
    int pozmax=0;
    fin>>n;
    for (i=1; i<=n; i++) fin>>a[i];
    nr=1;
    best[1]=l[1]=1;
    for (i=2; i<=n; i++)
    {
        poz=cb(a[i]);
        p[i]=l[poz];
        best[i]=poz+1;
        l[poz+1]=i;
        if (nr<poz+1) nr=poz+1;
    }
    for (i=1; i<=n; i++)
    {
        if (maxim<best[i])
            maxim=best[i],pozmax=i;
    }
    fout<<maxim<<'\n';
    afisare(pozmax);
}
