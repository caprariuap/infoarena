#include <fstream>

using namespace std;

ifstream fin("perechi2.in");
ofstream fout("perechi2.out");

int c,n,a[2016],i,p[2016];
int j;

int main()
{fin>>c>>n;
for (i=1; i<=n; i++)
fin>>a[i],p[i]=i;
for (i=1; i<n; i++)
    for (j=i+1; j<=n; j++)
    if (a[i]>a[j])
    swap(a[i],a[j]),swap(p[i],p[j]);
if (c==1)
{if (a[1]==a[2]&&a[2]<a[3]&&a[3]==a[n])
fout<<p[1]<<' '<<p[2]<<' '<<a[3]-a[2];
else fout<<'0';
fout<<'\n';
}
else
{int maxim=a[n];
for (i=1; i<n; i+=2)
{int k=maxim-a[i];
fout<<p[i]<<' '<<p[i+1]<<' '<<k<<'\n';
a[i]+=k;
a[i+1]+=k;
if (a[i+1]>maxim) maxim=a[i+1];
}
int k=maxim-a[1];
a[1]+=k;
a[n]+=k;
if (k!=0)
fout<<p[1]<<' '<<p[n]<<' '<<k<<'\n';
for (i=2; i<n-1; i+=2)
    if (maxim-a[i]!=0)
    fout<<p[i]<<' '<<p[i+1]<<' '<<maxim-a[i]<<'\n';
}
}
