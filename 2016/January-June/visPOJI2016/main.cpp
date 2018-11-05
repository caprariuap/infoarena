#include <fstream>
using namespace std;
ifstream fin("vis.in");
ofstream fout("vis.out");
int dx[5]={-1,0,1,0};
int dy[5]={0,-1,0,1};
int lmin=10000000,k1,k2,k,n,l1,c1,l2,c2;
int8_t ca[1002][1002];
int b[1002][1002];
short a[1002][1002];
int okk1[5];
int okk2[5];
struct coada{short x,y;bool ok1,ok2;} c[3500001],w;
int verif(int x,int y)
{if (x<y) return 1;
if (x==2&&y==1) return 1;
return 0;
}
int main()
{fin>>n>>k1>>k2>>l1>>c1>>l2>>c2;
for (int i=1;i<=n;i++)
    {for (int j=1;j<=n;j++)
    fin>>a[i][j];
    b[0][i]=b[n+1][i]=b[i][0]=b[i][n+1]=ca[0][i]=ca[n+1][i]=ca[i][0]=ca[i][n+1]=-1;}
int p,u;p=u=1;
int gasit=0;
c[p].x=1;c[p].y=1;b[1][1]=1;c[p].ok1=0;c[p].ok2=0;
okk1[0]=0;
okk2[0]=1000000;
okk1[1]=okk1[2]=k1;
okk2[1]=okk2[2]=k2;
b[1][1]=1;
while (p<=u&&!gasit)
{int aux=ca[c[p].x][c[p].y];
w=c[p];
for (k=0;k<4;k++)
{int dxk=w.x+dx[k];int dyk=w.y+dy[k];
if (b[dxk][dyk]!=-1)
if (b[dxk][dyk]==0||(b[dxk][dyk]>b[w.x][w.y]+1||verif(ca[w.x][w.y],ca[dxk][dyk])))
if (a[dxk][dyk]<=okk1[w.ok1]||a[dxk][dyk]>=okk2[w.ok2])
{u++;
c[u].x=dxk;
c[u].y=dyk;
b[c[u].x][c[u].y]=b[w.x][w.y]+1;
c[u].ok1=w.ok1;
c[u].ok2=w.ok2;
if (c[u].x==l1&&c[u].y==c1) c[u].ok1=1;
else if (c[u].x==l2&&c[u].y==c2) c[u].ok2=1;
if (c[u].ok1==1) ca[c[u].x][c[u].y]=1;
if (c[u].ok2==1) {if (ca[c[u].x][c[u].y]==0) ca[c[u].x][c[u].y]=2;else ca[c[u].x][c[u].y]=3;}
if (c[u].x==n&&c[u].y==n&&b[n][n]<lmin)
    gasit=1,lmin=b[n][n];
}
}

p++;
}
fout<<lmin<<'\n';
}
