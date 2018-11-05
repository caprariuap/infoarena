#include <fstream>
using namespace std;
ifstream fin("sortari.in");
ofstream fout("sortari.out");
int a[205],i,j,k,l,s,n;
int main()
{a[0]=1;fin>>n;
a[1]=1;
a[2]=2;
a[3]=6;
for (i=4;i<=n;i++)
{s=0;
l=1;
for (j=1;j<=i-1;j++)
    for (k=j+1;k<=i;k++)
{l=(a[j-1]*a[k-j-1]%19573)*a[i-k];
l%=19573;
s+=l;
s%=19573;}
a[i]=2*s%19573;
}
fout<<a[n]<<'\n';
}
