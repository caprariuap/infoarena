#include <fstream>
using namespace std;
ifstream fin("joc11.in");
ofstream fout("joc11.out");
int n,m;int nrc;
char a[52][52];
bool b[52][52];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
char aux;int ok=1;
int interior(int x,int y)
{if (x>=1&&x<=n&&y>=1&&y<=m)
return 1;
return 0;
}
int dimensiune;
void fill(int x,int y)
{dimensiune++;char aux=a[x][y];
a[x][y]='0';
int k;
for (k=0;k<4;k++)
    if (a[x+dx[k]][y+dy[k]]==aux&&interior(x+dx[k],y+dy[k]))
       fill(x+dx[k],y+dy[k]);
a[x][y]=aux;
}
void filll(int x,int y)
{int k;b[x][y]=1;
for (k=0;k<4;k++)
    if (b[x+dx[k]][y+dy[k]]==0&&interior(x+dx[k],y+dy[k]))
       fill(x+dx[k],y+dy[k]);
}
void fillll(int x,int y)
{int k;b[x][y]=0;
for (k=0;k<4;k++)
    if (b[x+dx[k]][y+dy[k]]==1&&interior(x+dx[k],y+dy[k]))
       fill(x+dx[k],y+dy[k]);
}
void mutarecoloana(int x,int y)
{int i=y,j;
while (a[x][i]=='0'&&interior(x,i)) i++;j=i;
while (a[x][j]>='A'&&a[x][j]<='V') j++;j--;
int d=i-y;
int k;
for (k=y;k<=j-d;k++)
    a[x][k]=a[x][k+d];
}
int main()
{fin>>n>>m;int dmax=0;
int i,j;
char c;
for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
fin>>a[i][j];
int x,y;
while (ok)
{dmax=0;for (int s=0,i=1;i<=n;i++)
    for (j=1;j<=m;j++)
if (a[i][j]!='0')
    {dimensiune=0;fill(i,j);
    if (dimensiune>dmax) dmax=dimensiune,x=i,y=j;}
int ii,jj;
if (dimensiune>=2)
{if (nrc%2==0)
filll(x,y);
else fillll(x,y);
for (ii=1;ii<=n;ii++)
    for (jj=1;jj<=m;j++)
if (a[ii][jj]!='0')
{int k=ii;
while (k&&a[k][jj]>='A'&&a[k][jj]<='V') k++;
if (k<n+1) {int h;for (h=k+1;h>=ii;h--)
    a[h][jj]=a[h+1][jj];
}
}
for (ii=1;ii<=m;i++)
    if (a[n][ii]=='0')
{int k;
for (k=1;k<=n;k++)
    mutarecoloana(k,ii);}
nrc++;}
else ok=0;
}
}
