#include <fstream>
using namespace std;
ifstream fin("inginer.in");
ofstream fout("inginer.out");
char ch;
int dx[5]={-1,0,1,0};
int dy[5]={0,-1,0,1};
int n,m,i,j,b,p,u,g,k;
int a[80][80],dmin,matrice[80][80];
struct element{int x,y,d;};
element c[6500];
element w;
struct date{int o,q;};
date v[6500];
date z[6500];
void citire()
{fin>>n>>m;
for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
{fin>>ch;
if (ch=='X')
    a[i][j]=-1;
else
    a[i][j]=0;
}
b=1;
while (fin>>v[b].o>>v[b].q>>z[b].o>>z[b].q)
    b=b+1;
b-=2;
}
void bordare()
{for (i=0;i<=m+1;i++)
{a[0][i]=0;
a[n+1][i]=0;
}
for (i=0;i<=n+1;i++)
{a[i][0]=0;
a[i][m+1]=0;
}
}
int interior(int x, int y)
{if (x>=0&&x<=n+1&&y>=0&&y<=m+1)
return 1;
else
    return 0;
}
void lee()
{dmin=0;
for (i=0;i<=n+1;i++)
for (j=0;j<=m+1;j++)
    matrice[i][j]=a[i][j];
matrice[z[g].o][z[g].q]=matrice[v[g].o][v[g].q]=0;
p=1;
u=1;
c[p].x=v[g].o;
c[p].y=v[g].q;
c[p].d=0;
while (p<=u)
{w.x=c[p].x;
w.y=c[p].y;
w.d=c[p].d;
p++;
for (k=0;k<4;k++)
{if (matrice[w.x+dx[k]][w.y+dy[k]]==0&&interior(w.x+dx[k],w.y+dy[k]))
{u++;
c[u].x=w.x+dx[k];
c[u].y=w.y+dy[k];
c[u].d=w.d+1;
matrice[w.x+dx[k]][w.y+dy[k]]=w.d+1;
}
}
}
for (i=1;i<=u;i++)
    if (z[g].o==c[i].x&&z[g].q==c[i].y)
    dmin=c[i].d;
fout<<dmin<<endl;
}
int main()
{citire();
bordare();
for (g=1;g<=b;g++)
    lee();
}
