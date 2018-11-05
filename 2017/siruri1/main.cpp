#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("siruri1.in");
ofstream fout("siruri1.out");
int a[101],b[101],i,n,aux,j;
int main()
{fin>>n;
for (i=1;i<=n;i++)
{fin>>a[i];
b[i]=a[i];
}
for (i=1;i<=n;i++)
    for (j=i+1;j<=n;j++)
    if (b[i]>b[j])
{aux=b[i];
b[i]=b[j];
b[j]=aux;
}
for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
        if (a[i]==b[j])
        fout<<j<<' ';
}
