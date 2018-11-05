#include <fstream>
using namespace std;
ifstream fin("rj.in");
ofstream fout("rj.out");
struct element
{int x,y;
};
element cr[11000],cj[11000],w;
int dx[9]={1,1,1,0,0,-1,-1,-1};
int dy[9]={1,0,-1,1,-1,1,0,-1};
int ro[103][103],ju[103][103],nr,nj,n,m,i,j,r,k,xr,yr,xj,yj,pr,ur,pj,uj,dmin,xf,yf;
char ch;
void citire()
{fin>>n>>m;fin.get();
for(int i=1;i<=n;i++)
{for(int j=1;j<=m;j++)
{fin.get(ch);
if (ch=='X')
ro[i][j]=ju[i][j]=-1;
else
{if(ch=='R')
{xr=i;
yr=j;
ro[i][j]=1;
ju[i][j]=-1;
}
else
{if(ch=='J')
{xj=i;
yj=j;
ju[i][j]=1;
ro[i][j]=-1;
}
else
ro[i][j]=ju[i][j];
}
}
}        fin.get();
}
for(int i=0;i<=n+1;i++)
ro[i][0]=ro[i][m+1]=ju[i][0]=ju[i][m+1]=-1;
for(int i=0;i<=m+1;i++)
ro[0][i]=ro[n+1][i]=ju[0][i]=ju[n+1][i]=-1;
}
int main()
{citire();
nr=1;
nj=1;
pr=1;
ur=1;
pj=1;
uj=1;
cr[pr].x=xr;
cr[pr].y=yr;
cj[pj].x=xj;
cj[pj].y=yj;
while (pr<=ur)
{w.x=cr[pr].x;
w.y=cr[pr].y;
for (k=0;k<8;k++)
{if (ro[w.x+dx[k]][w.y+dy[k]]==0 || ro[w.x+dx[k]][w.y+dy[k]]>nr)
{ur++;
cr[ur].x=w.x+dx[k];
cr[ur].y=w.y+dy[k];
ro[w.x+dx[k]][w.y+dy[k]]=ro[cr[pr].x][cr[pr].y]+1;
}
}
pr++;
nr=ro[cr[ur].x][cr[ur].y];
}
while (pj<=uj)
{w.x=cj[pj].x;
w.y=cj[pj].y;
for (k=0;k<8;k++)
{if (ju[w.x+dx[k]][w.y+dy[k]]==0||ju[w.x+dx[k]][w.y+dy[k]]>nj)
{uj++;
cj[uj].x=w.x+dx[k];
cj[uj].y=w.y+dy[k];
ju[w.x+dx[k]][w.y+dy[k]]=ju[cj[pj].x][cj[pj].y]+1;
}
}
pj++;
nj=ju[cj[uj].x][cj[uj].y];
}
dmin=104*104;
for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
{if (ro[i][j]==ju[i][j]&&(xr!=i&&xj!=i&&yr!=j&&yj!=j))
if (ro[i][j]<dmin&&ro[i][j]>0)
    {dmin=ro[i][j];
    xf=i;
    yf=j;
}
}
for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
{if (dmin==ro[i][j])
if (i*j<xf*yf)
{xf=i;
yf=j;
}
}
fout<<dmin<<' '<<xf<<' '<<yf;
}
