#include <fstream>
using namespace std;
ifstream fin("drenaj.in");
ofstream fout("drenaj.out");
int n,m,i,j,a[102][102],nr;
bool b[102][102];
int ok;
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
void citirebordare()
{
    fin>>n>>m;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            fin>>a[i][j];
    for (i=0; i<=n; i++) a[i][0]=a[i][m+1]=10001,b[i][0]=b[i][m+1]=1;
    for (i=0; i<=m; i++) a[0][i]=a[n+1][i]=10001,b[0][i]=b[n+1][i]=1;
}
void bkt(int x, int y)
{
    int k;
    b[x][y]=1;
    for (k=0; k<4; k++)
    {
        if (a[x+dx[k]][y+dy[k]]==a[x][y])
        {
            if (b[x+dx[k]][y+dy[k]]==0)
                bkt(x+dx[k],y+dy[k]);
        }
        else if (a[x+dx[k]][y+dy[k]]<a[x][y])
            ok=1;
    }
}
int main()
{
    citirebordare();
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (b[i][j]==0)
            {
                ok=0;
                bkt(i,j);
                if (ok==0) nr++;
            }
    fout<<nr<<'\n';
}
