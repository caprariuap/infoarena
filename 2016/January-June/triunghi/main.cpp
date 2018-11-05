#include <fstream>
using namespace std;
ifstream citire("triunghi5.in");
ofstream afisare("triunghi5.out");
long long a[50],b[50],i,v,n,k;
int divide(int p, int q)
{
    int st=p;
    int dr=q;
    int x=a[p];
    while (st<dr)
    {
        while (st<dr && a[dr]>=x) dr--;
        a[st]=a[dr];
        while (st<dr && a[st]<=x) st++;
        a[dr]=a[st];
    }
    a[st]=x;
    return st;
}
void qs(int p, int q)
{
    int m=divide(p,q);
    if (p < m-1) qs(p, m-1);
    if (m+1 < q) qs(m+1, q);
}
int main()
{
    citire >> v >> n >> k;
    for (i=1; i<=n; i++)
        citire >> a[i];
    qs(1,n);
    if (v==2)
    {
        int nra=2;
        int nrb=n;
        int a1=1;
        int a2=2;
        int b1=1,b2=1;
        if (a[a1]!=a[a2]){b[++nrb]=1;while (nra<n&&nrb<k&&b1+b2<=a[1])
        { int x=b1;b2+=b1; if(b2+b1<=a[1]) b[++nrb]=b2;b1=b2-x;
        }
        }
        else
        {

        }
        while (nra<=n && nrb<k)
        {
            if (3*a[a1]<=a[a2])
            {
                b1=a[a1];
                b2=a[a1]+a[a1-1];if (b2<=a[a2]&&b2>b1+b[nrb])  b[++nrb]=b2;
b1=a[a1];
                while (3*b1<=a[a2]&&nrb<k)
                {int aux=b2;
                    b2+=b1;
                    b1=aux;
                  if (b2+b1<=a[a2])  b[++nrb]=b2;

                }
            }
            a1++;
            a2++;nra++;
        }
        if (nrb<k)
        {
            b[++nrb]=a[n-1]+a[n];
            if (nrb<k)
            {
                b[++nrb]=a[n]+b[nrb-1];
                while (nrb<k)
                    b[++nrb]=b[nrb-1]+b[nrb-2];
            }
        }
        for (i=n+1;i<=k;i++) a[i]=b[i];
        qs(1,k);
        for (i=1; i<=k; i++)
        afisare << a[i] << ' ';
    }
    else
    {
        a[2]=a[1];
        for (i=3; i<=k; i++)
            a[i]=a[i-1]+a[i-2];
    for (i=1; i<=k; i++)
        afisare << a[i] << ' ';
    }
    afisare << '\n';
}
