#include <fstream>
using namespace std;
ifstream fin("expresie8.in");
ofstream fout("expresie8.out");
int n,i,a[1001],smax,s,st,pi,si;
int main()
{fin>>n;
for (i=1;i<=n;i++)
    fin>>a[i],st+=a[i];
smax=0;
for (i=1;i<n;i++)
{s=a[i]*a[i+1];
if (s>smax)
{smax=s;
pi=i;
}
}
st=st-a[pi]-a[pi+1]+smax;
a[pi]*=a[pi+1];
for (i=pi+1;i<n;i++)
    a[i]=a[i+1];
n--;
smax=0;
for (i=1;i<n;i++)
{s=a[i]*a[i+1];
if (s>smax&&a[i]!=1&&a[i+1]!=1)
{smax=s;
si=i;
}
}
st=st-a[si]-a[si+1]+smax;
fout<<st;
}
