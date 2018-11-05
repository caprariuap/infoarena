#include <fstream>
using namespace std;
ifstream fin("colina.in");
ofstream fout("colina.out");
int n,m,i,j,a,x,h[100001],z,s,mijl,st,sf,valmax,ceva;
int main()
{fin>>n>>m;
int maxim=0;
for (i=1;i<=n;i++)
    {fin>>h[i];
    }
st=1;
sf=n;
for (i=1;i<=n;i++)
    if (h[i]>h[i-1]&&h[i]>h[i+1])
{maxim=i;break;}
for (j=1;j<=m;j++)
{fin>>x;
z=a=0;
st=1;
sf=maxim;
while (st<=sf&&z==0)
{mijl=(st+sf)/2;
if (h[mijl]==x)
z=mijl;
else
    if (x<h[mijl])
    sf=mijl-1;
    else
        st=mijl+1;
}
st=maxim+1;
sf=n;
while (st<=sf&&a==0)
{mijl=(st+sf)/2;
if (h[mijl]==x)
    a=mijl;
else
    if (x<h[mijl])
    st=mijl+1;
    else
        sf=mijl-1;
}
if (z>0||a>0)
{fout<<"DA"<<' ';
if (z>0)
    fout<<z<<' ';
if (a>0)
fout<<a;
fout<<'\n';
}
else
    fout<<"NU"<<'\n';
}
return 0;
}
