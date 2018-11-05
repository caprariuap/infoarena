#include <fstream>
using namespace std;
ifstream fin("lacusta.in");
ofstream fout("lacusta.out");
unsigned char a[251][251];
unsigned short d[251][251],m;
int minimum(unsigned short i,unsigned short j)
{unsigned short int mini=32000,k,rezultat;
for (k=1;k<=m;k++)
if (d[i-1][k]<mini&&k!=j) mini=d[i-1][k],rezultat=k;
return rezultat;
}
int main()
{unsigned short int n;fin>>n>>m;unsigned short int i,j;
for (i=1;i<=n;i++)
    for (j=1;j<=m;j++) {unsigned int x;fin>>x;a[i][j]=x;}
for (i=2;i<=m;i++) d[1][i]=a[1][1]+a[1][i];
for (i=2;i<=m;i++) d[2][i]=d[1][i]+a[2][i];
d[2][1]=32000;
for (i=3;i<=n;i++)
    for (j=1;j<=m;j++)
    {
    d[i][j]=a[i][j]+a[i-1][j]+d[i-1][minimum(i,j)];
    }
d[n][m]=32000;
for (j=1;j<m;j++)
if (d[n][j]+a[n][m]<d[n][m]) d[n][m]=d[n][j]+a[n][m];
fout<<d[n][m]<<'\n';
}
