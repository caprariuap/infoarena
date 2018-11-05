#include <fstream>
using namespace std;
ifstream fin("harta1.in");
ofstream fout("harta1.out");
int p,n,m,k,i,j;int a[110][110]; int nrdep[15];
int nrtari,aux;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
void fill(int x,int y)
{a[x][y]=0;
int k;for (k=0;k<4;k++) if (a[x+dx[k]][y+dy[k]]==aux) fill(x+dx[k],y+dy[k]);
}
int main()
{fin>>p>>n>>m>>k;
if (p==1)
{int x,d=0;for (i=1;i<=n;i++)
for (j=1;j<=m;j++)
{fin>>x;if (!x) d++;}
fout<<d;
}
else
{for (i=1;i<=n;i++)
for (j=1;j<=m;j++)
    fin>>a[i][j];
for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    if (a[i][j]) nrdep[a[i][j]]++,aux=a[i][j],fill(i,j);
int maxim=0;for (i=1;i<=k;i++) if (nrdep[i]>maxim) maxim=nrdep[i];
for (i=1;i<=k;i++) if (nrdep[i]==maxim) fout<<i<<' ';
}
fout<<'\n';
}
