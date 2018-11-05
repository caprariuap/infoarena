#include <fstream>
using namespace std;
ifstream fin("foto.in");
ofstream fout("foto.out");
int n,m,a[101][101],i,j,nr,nrmax;
void rezolvare(int x,int y)
{if (a[x][y]==2)
{nr++; a[x][y]=1;
rezolvare(x+1,y);
rezolvare(x-1,y);
rezolvare(x,y+1);
rezolvare(x,y-1);
}
}
int main()
{fin>>n>>m;
for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    {fin>>a[i][j];if(a[i][j]==0) a[i][j]=2;}
for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
{if (a[i][j]==2)
{nr=0;
rezolvare(i,j);
if (nr>nrmax)
    nrmax=nr;
}
}
fout<<nrmax;
}
