#include <fstream>
using namespace std;

ifstream fin("tsunami.in");
ofstream fout("tsunami.out");

int n,m,h,a[1010][1010];
int i,j;
int sol;
bool b[1010][1010];
int dx[5]={-1,0,1,0};
int dy[5]={0,-1,0,1};
struct coada{int x,y;} c[1000000],w;

bool interior(int x,int y)
{if (x>=1&&x<=n&&y>=1&&y<=m)
return 1;
return 0;
}

void filll(int x,int y)
{b[x][y]=1;
if (a[x][y]) sol++;
int k;
for (k=0; k<4; k++)
    if (h>a[x+dx[k]][y+dy[k]]&&!b[x+dx[k]][y+dy[k]]&&interior(x+dx[k],y+dy[k]))
        filll(x+dx[k],y+dy[k]);
}

int main()
{fin>>n>>m>>h;
for (i=1; i<=n; i++)
    for (j=1; j<=m; j++)
    fin>>a[i][j];
for (i=1; i<=n; i++)
    for (j=1; j<=m; j++)
    if (!a[i][j]&&!b[i][j])
        filll(i,j);
fout<<sol<<'\n';
}
