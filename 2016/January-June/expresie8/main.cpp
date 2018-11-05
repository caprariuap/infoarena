#include <fstream>
using namespace std;
ifstream fin("expresie8.in");
ofstream fout("expresie8.out");
long long n,i,a[1001],smax,s,st,pi,si,ok,s3,s2;
int main()
{fin>>n;
for (i=1;i<=n;i++)
    fin>>a[i],st+=a[i];
smax=0;
for (i=1;i<n;i++)
{s=st-a[i]-a[i+1]+a[i]*a[i+1];
if (s>s2)
{s2=s;
pi=i;
}
if (i!=1)
{s=st-a[i-1]-a[i]-a[i+1]+a[i-1]*a[i]*a[i+1];
if (s>s3)
    s3=s;
}
}
a[pi]*=a[pi+1];
for (i=pi+1;i<n;i++)
    a[i]=a[i+1];
n--;
smax=0;
st=s2;
for (i=1;i<n;i++)
{s=a[i]*a[i+1]-a[i]-a[i+1];
if (s>smax)
smax=s;
}
if (smax+s2>s3) fout<<smax+s2;
else fout<<s3;
}
