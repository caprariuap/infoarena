#include <fstream>
using namespace std;
ifstream fin("colaj.in");
ofstream fout("colaj.out");
int x,n,m,i,j,k;
bool a[8001][8001];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int interior(int x,int y)
{if (x>=1&&x<=n&&y>=1&&y<=m)
return 1;
return 0;
}
void filll(int x,int y)
{a[x][y]=1;
for (k=0;k<4;k++)
    if (a[x+dx[k]][y+dy[k]]==0&&interior(x+dx[k],y+dy[k]))
    filll(x+dx[k],y+dy[k]);
}
int main()
{fin>>x>>n>>m;
for (i=1;i<=x;i++)
{int aa,b,c,d;
fin>>aa>>b>>c>>d;
for (j=aa;j<=c;j++)
    for (k=b;k<=d;k++)
    a[j][k]=1;
}
int solutie=0;
for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    if (!a[i][j])
    solutie++,filll(i,j);
fout<<solutie<<'\n';
}
