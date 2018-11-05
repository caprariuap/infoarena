#include <fstream>
using namespace std;
ifstream fin("insule.in");
ofstream fout("insule.out");
int dx[4]= {0,-1,0,1};
int dy[4]= {-1,0,1,0};
int a[110][110],n,m;
bool b[110][110];
int best[110][110];
int minim=32768;
int nrinsule[5],p,u;
struct coada
{
    short int x,y;
} c[50000],w;
void citire()
{
    fin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            char c;
            fin>>c;
            a[i][j]=c-'0';
        }
}
int verifr(int i,int j)
{
    for (int k=0; k<4; k++)
        if (a[i+dx[k]][j+dy[k]]==0)
            return 1;
    return 0;
}
int verifg(int i,int j)
{
    for (int k=0; k<4; k++)
        if (a[i+dx[k]][j+dy[k]]==2)
            return 1;
    return 0;
}
int main()
{
    int i,j;
    citire();
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        {
            if (a[i][j]&&!b[i][j])
            {
                p=u=1;
                c[p].x=i;
                c[p].y=j;
                b[i][j]=1;
                while (p<=u)
                {
                    w.x=c[p].x;
                    w.y=c[p].y;
                    p++;
                    for (int k=0; k<4; k++)
                    {
                        if (b[w.x+dx[k]][w.y+dy[k]]==0&&a[w.x+dx[k]][w.y+dy[k]]==a[i][j])
                        {
                            u++;
                            c[u].x=w.x+dx[k];
                            c[u].y=w.y+dy[k];
                            b[c[u].x][c[u].y]=1;
                        }
                    }
                }
                nrinsule[a[i][j]]+=1;
            }
        }
    for (i=1; i<=3; i++) fout<<nrinsule[i]<<' ';
    for (i=0; i<=m+1; i++) a[0][i]=a[n+1][i]=4;
    for (i=0; i<=n+1; i++) a[i][0]=a[i][m+1]=4;

    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (a[i][j]==1&&verifr(i,j))
            {
                p=u=1;
                c[p].x=i;
                c[p].y=j;

                while (p<=u)
                {
                    w=c[p];
                    p++;
                    for (int k=0; k<4; k++)
                    {
                        if (a[w.x+dx[k]][w.y+dy[k]]==0&&
                                (best[w.x+dx[k]][w.y+dy[k]]>best[w.x][w.y]+1||best[w.x+dx[k]][w.y+dy[k]]==0))
                        {
                            u++;
                            c[u].x=w.x+dx[k];
                            c[u].y=w.y+dy[k];
                            best[c[u].x][c[u].y]=best[w.x][w.y]+1;
                            if (verifg(c[u].x,c[u].y)&&best[c[u].x][c[u].y]<minim)
                                minim=best[c[u].x][c[u].y];
                        }
                    }
                }
            }
    fout<<minim<<'\n';

}
