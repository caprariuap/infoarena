#include <fstream>
using namespace std;
ifstream fin("tabel.in");
ofstream fout("tabel.out");
int n,m,a[51][51],i,j,p,k,x,nrg,h,l,s;
int main()
{fin>>n>>m;
fin>>p;
for (i=1;i<=p;i++)
{fin>>k>>j>>x;
if (x!=0)
a[k][j]=x;
else
    a[k][j]=-2;
}
k=0;
for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
if (a[i][j]==0)
a[i][j]=-1,k++;
for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
if (a[i][j]==-2)
a[i][j]=0;
while (k>0)
{for (i=1;i<=m;i++)
{nrg=0;
for (j=1;j<=n;j++)
if (a[j][i]==-1)
    nrg++;
if (nrg==1)
    {for (h=1;h<=n;h++)
    {if (a[h][i]==-1)
{if (h<n)
{s=a[n][i];
for (l=1;l<n;l++)
    s-=a[l][i];
a[h][i]=s-1;
}
else
{s=0;
for (l=1;l<n;l++)
s+=a[l][i];
a[h][i]=s;
}
k--;
}
}
}
}
for (i=1;i<=n;i++)
{nrg=0;
for (j=1;j<=m;j++)
if (a[i][j]==-1)
    nrg++;
if (nrg==1)
    {for (h=1;h<=m;h++)
    {if (a[i][h]==-1)
{if (h<m)
{s=a[i][m];
for (l=1;l<m;l++)
    s-=a[i][l];
a[i][h]=s-1;
}
else
{s=0;
for (l=1;l<m;l++)
s+=a[i][l];
a[i][h]=s;
}
k--;
}
}
}
}
}
for (i=1;i<=n;i++)
{for (j=1;j<=m;j++)
fout<<a[i][j]<<' ';
fout<<endl;
}
}
