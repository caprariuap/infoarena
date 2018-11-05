#include <fstream>
using namespace std;
ifstream fin("ai.in");
ofstream fout("ai.out");
int n,t1,t2,s1,s2,s3,s4,r1,r2,r3,r4,i,j,lmax,k;
short a[1002][1002];
short rob1[1001][1001],rob2[1001][1001];
bool sus[1001][1001],stanga[1001][1001];
struct ceva{short cx,cy;}locuri1[1002],locuri2[1002];
int nr[3];
void marcarecoliniara1(int x,int y,int z)
{a[x][y]=1,locuri1[++nr[z]].cx=x;locuri1[nr[z]].cy=y;
if (x<t1)
{for (int i=x+1;i<t1;i++)
if ((i-t1)*(y-t2)%(x-t1)==0)
    if (a[i][(i-t1)*(y-t2)/(x-t1)+t2]>=0)locuri1[++nr[z]].cx=i,locuri1[nr[z]].cy=(i-t1)*(y-t2)/(x-t1)+t2;
}
else
    {for (int i=x-1;i>t1;i--)
if ((i-t1)*(y-t2)%(x-t1)==0)
   if (a[i][(i-t1)*(y-t2)/(x-t1)+t2]>=0) locuri1[++nr[z]].cx=i,locuri1[nr[z]].cy=(i-t1)*(y-t2)/(x-t1)+t2;
}
if (x==t1)
{if (y<t2) for (int i=y+1;i<t2;i++)
if (a[x][i]>=0) a[x][i]=1,locuri1[++nr[z]].cx=x,locuri1[nr[z]].cy=i;
else
    for (int i=y-1;i>t2;i--)
if (a[x][i]>=0) a[x][i]=1,locuri1[++nr[z]].cx=x,locuri1[nr[z]].cy=i;
}
if (y==t2)
{if (x<t1)
for (int i=x+1;i<t1;i++)
if (a[i][y]>=0) a[i][y]=1,locuri1[++nr[z]].cx=i,locuri1[nr[z]].cy=y;
else
for (int i=x-1;i>t1;i--)
if (a[i][y]>=0) a[i][y]=1,locuri1[++nr[z]].cx=i,locuri1[nr[z]].cy=y;
}
}
void marcarecoliniara2(int x,int y,int z)
{a[x][y]=1,locuri2[++nr[z]].cx=x;locuri2[nr[z]].cy=y;
if (x<t1)
{for (int i=x+1;i<t1;i++)
if ((i-t1)*(y-t2)%(x-t1)==0)
    if (a[i][(i-t1)*(y-t2)/(x-t1)+t2]>=0)locuri2[++nr[z]].cx=i,locuri2[nr[z]].cy=(i-t1)*(y-t2)/(x-t1)+t2;
}
else
    {for (int i=x-1;i>t1;i--)
if ((i-t1)*(y-t2)%(x-t1)==0)
   if (a[i][(i-t1)*(y-t2)/(x-t1)+t2]>=0) locuri2[++nr[z]].cx=i,locuri2[nr[z]].cy=(i-t1)*(y-t2)/(x-t1)+t2;
}
if (x==t1)
{if (y<t2) for (int i=y+1;i<t2;i++)
if (a[x][i]>=0) a[x][i]=1,locuri1[++nr[z]].cx=x,locuri1[nr[z]].cy=i;
else
    for (int i=y-1;i>t2;i--)
if (a[x][i]>=0) a[x][i]=1,locuri1[++nr[z]].cx=x,locuri1[nr[z]].cy=i;
}
if (y==t2)
{if (x<t1)
for (int i=x+1;i<t1;i++)
if (a[i][y]>=0) a[i][y]=1,locuri1[++nr[z]].cx=i,locuri1[nr[z]].cy=y;
else
for (int i=x-1;i>t1;i--)
if (a[i][y]>=0) a[i][y]=1,locuri1[++nr[z]].cx=i,locuri1[nr[z]].cy=y;
}

}
int p,u;
struct coada{int x,y,l;} c[1000002],w;
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
int main()
{fin>>n>>t1>>t2>>s1>>s2>>s3>>s4>>r1>>r2>>r3>>r4;
int ab,cd;
fin>>k;
for (i=1;i<=k;i++)
    fin>>ab>>cd,a[ab][cd]=-1;
for (i=0;i<=n;i++) a[0][i]=a[n+1][i]=a[i][0]=a[i][n+1]=-2;
a[t1][t2]=-2;
marcarecoliniara1(s1,s2,1);
marcarecoliniara2(s3,s4,2);
for (i=1;i<=n;i++)
{for (j=1;j<=n;j++)
if (a[i][j]==-1)
{if (sus[i][j]==0)
{int l=1;int k=i; while (a[++k][j]==-1) l++,sus[k][j]=1;
if (l>lmax) lmax=l;
}
if (stanga[i][j]==0)
    {int l=1;int k=j; while (a[i][++k]==-1) l++,sus[i][k]=1;
if (l>lmax) lmax=l;
}
}
}
fout<<lmax<<'\n';
p=u=1;
c[p].x=r1;c[p].y=r2;
int gasit1,gasit2;gasit1=gasit2=0;
int loc1x,loc1y,loc2x,loc2y;
while (p<=u&&(!gasit1||!gasit2))
{w=c[p];
p++;
for (k=0;k<4;k++)
{if (a[w.x+dx[k]][w.y+dy[k]]>=0&&(rob1[w.x][w.y]+1<rob1[w.x+dx[k]][w.y+dy[k]]||rob1[w.x+dx[k]][w.y+dy[k]]==0))
{u++;
c[u].x=w.x+dx[k];
c[u].y=w.y+dy[k];
rob1[c[u].x][c[u].y]=rob1[w.x][w.y]+1;
for (int z=1;z<=nr[1]&&!gasit1;z++)
    if (rob1[locuri1[z].cx][locuri1[z].cy]>0)
    gasit1=1,loc1x=rob1[locuri1[z].cx][locuri1[z].cy];
for (int z=1;z<=nr[2]&&!gasit2;z++)
    if (rob1[locuri2[z].cx][locuri2[z].cy]>0)
    gasit2=1,loc1y=rob1[locuri2[z].cx][locuri2[z].cy];
}
}
}
p=u=1;
c[p].x=r3;c[p].y=r4;
gasit1=gasit2=0;
while (p<=u&&(!gasit1||!gasit2))
{w=c[p];
p++;
for (k=0;k<4;k++)
{if (a[w.x+dx[k]][w.y+dy[k]]>=0&&(rob2[w.x][w.y]+1<rob2[w.x+dx[k]][w.y+dy[k]]||rob2[w.x+dx[k]][w.y+dy[k]]==0))
{u++;
c[u].x=w.x+dx[k];
c[u].y=w.y+dy[k];
rob2[c[u].x][c[u].y]=rob2[w.x][w.y]+1;
for (int z=1;z<=nr[1]&&!gasit1;z++)
    if (rob2[locuri1[z].cx][locuri1[z].cy]>0)
    gasit1=1,loc2x=rob2[locuri1[z].cx][locuri1[z].cy];
for (int z=1;z<=nr[2]&&!gasit2;z++)
    if (rob2[locuri2[z].cx][locuri2[z].cy]>0)
    gasit2=1,loc2y=rob2[locuri2[z].cx][locuri2[z].cy];
}
}
}
int raspuns=max(loc1x,loc2y);
if (max(loc1y,loc2x)<raspuns) raspuns=max(loc1y,loc2x);
fout<<raspuns<<'\n';
}
