#include <fstream>
using namespace std;
ifstream fin("teatru1.in");
ofstream fout("teatru1.out");
int n,m,i,j,nr,nrc,nro;
long long solutie;
int a[510];

void bkt(int k)
{
    if (k>nr)
    {
        solutie++;
    }
    else
    {
        int i;
        int aux=nro;
        if (nrc<n) nrc++,bkt(k+1),nrc--;
        while (nrc>nro&&nro<m) nro++,bkt(k+1);
        nro=aux;
    }
}

void inmultire(int a[],int x)
{
    int i;
    long long t=0;
    for (i=1; i<=a[0]; i++)
    {
        a[i]=a[i]*x+t;
        t=a[i]/10;
        a[i]%=10;
    }
    while (t) a[++a[0]]=t%10,t/=10;
}

int main()
{
    fin>>n>>m;
    nr=n+m;
    bkt(1);
    while (solutie)
    {
        a[++a[0]]=solutie%10;
        solutie=solutie/10;
    }
    if (m>n) fout<<'0';
    else
    {
        for (i=1; i<=m; i++)
            inmultire(a,i*i);
        for (i=m+1; i<=n; i++)
            inmultire(a,i);
        for (i=a[0]; i; i--) fout<<a[i];
    }
    fout<<'\n';
}
