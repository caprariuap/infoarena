#include <fstream>
using namespace std;
ifstream fin("sudest.in");
ofstream fout("sudest.out");
short n,a[102][102],nrpasi,pas[200];
struct pasii{short cx,cy;};pasii solutie[200],curent[200];
short p[102][102];
int dx[]={0,1};
int dy[]={1,0};
short smax;
short s;
int interior(int x,int y)
{if (x>=1&&x<=n&&y>=1&&y<=n)
return 1;
return 0;
}
void bkt(int x,int y,int nrpas)
{int k;
if (x==n&&y==n)
    {if (s>smax)
    {smax=s;for (k=1;k<=nrpasi;k++)
    solutie[k]=curent[k];}}
else
{for (k=0;k<2;k++)
{int dxk=x+dx[k]*pas[nrpas];
int dyk=y+dy[k]*pas[nrpas];
if (interior(dxk,dyk)&&p[dxk][dyk]<s+a[dxk][dyk])
    curent[nrpas].cx=dxk,curent[nrpas].cy=dyk,p[dxk][dyk]=p[x][y]+a[dxk][dyk],s+=a[dxk][dyk],bkt(dxk,dyk,nrpas+1),s-=a[dxk][dyk];
}
}
}
int main()
{fin>>n;
int i,j;
for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    fin>>a[i][j];
fin>>nrpasi;
for (i=1;i<=nrpasi;i++)
    fin>>pas[i];
bkt(1,1,1);fout<<p[n][n]+a[1][1]<<'\n';fout<<'1'<<' '<<'1'<<'\n';
for (i=1;i<=nrpasi;i++)
fout<<solutie[i].cx<<' '<<solutie[i].cy<<'\n';
}
