#include <fstream>
using namespace std;
ifstream fin("taxe1.in");
ofstream fout("taxe1.out");
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
short a[105][105];
int i,j,s,n,ok;
int p,u;
short int b[105][105];
struct element{short int x,y;short int ramas;};
element c[100000],w;
int main()
{fin>>s>>n;
for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    fin>>a[i][j];
fin.close();
for (i=0;i<=n+1;i++) a[i][0]=a[0][i]=a[n+1][i]=a[i][n+1]=-1;
p=u=1;
c[p].x=c[p].y=1;
c[p].ramas=s-a[1][1];
while (p<=u)
{w=c[p];
p++;
for (i=0;i<4;i++)
{if ((b[w.x+dx[i]][w.y+dy[i]]<w.ramas-a[w.x+dx[i]][w.y+dy[i]]||(w.x+dx[i]==n&&w.y+dy[i]==n&&w.ramas-a[w.x+dx[i]][w.y+dy[i]]>=b[w.x+dx[i]][w.y+dy[i]]))&&a[w.x+dx[i]][w.y+dy[i]]>=0)
{u++;
c[u].x=w.x+dx[i];
c[u].y=w.y+dy[i];
c[u].ramas=w.ramas-a[c[u].x][c[u].y];
b[c[u].x][c[u].y]=c[u].ramas;
for (j=p;b[c[j].x][c[j].y]>c[j].ramas;j++) p++;
if (c[u].x==n&&c[u].y==n) ok=1;
}
}
}
if (b[n][n]>=0&&ok==1)
    fout<<b[n][n];
else
    fout<<"-1";
fout<<'\n';
fout.close();
}
