#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("litere.in");
ofstream fout("litere.out");
int n,m;
char a[110][110];
int pp,i,j,k;
int lit[27];
int p,u;
int b[110][110];
int dx[4]= {0,-1,0,1};
int dy[4]= {-1,0,1,0};
struct coada
{
    int x,y;
} c[110000],w;
int main()
{
    fin>>pp>>m>>n>>k;
    if (pp==1)
    {
        char x;
        int nrld=0;
        for (i=1; i<=m; i++)
            for (j=1; j<=n; j++)
            {
                fin>>x;
                if (lit[x-'a'+1]==0)
                    lit[x-'a'+1]=1,nrld++;
            }
        unsigned long long rezultat=1;
        if (2*k<nrld)
            k=nrld-k;
        for (i=k+1; i<=nrld; i++)
            rezultat*=i;
        for (i=1; i<=nrld-k; i++)
            rezultat=rezultat/i;
        fout<<rezultat;
    }
    else
    {
        for (i=1; i<=m; i++)
            for (j=1; j<=n; j++)
                fin>>a[i][j];
        for (i=1; i<=m; i++)
            b[i][0]=b[i][n+1]=-1;
        for (i=1; i<=n; i++)
            b[0][i]=b[m+1][i]=-1;
        for (i=1; i<=n; i++)
            if (strchr("aeiou",a[1][i]))
                u++,c[u].x=1,c[u].y=i,b[1][i]=1;
        p=1;
        while (p<=u)
        {
            w=c[p];
            p++;
            for (k=0; k<4; k++)
                if (strchr("aeiou",a[w.x+dx[k]][w.y+dy[k]])&&(b[w.x+dx[k]][w.y+dy[k]]>b[w.x][w.y]+1||b[w.x+dx[k]][w.y+dy[k]]==0))
                {
                    u++;
                    c[u].x=w.x+dx[k];
                    c[u].y=w.y+dy[k];
                    b[c[u].x][c[u].y]=b[w.x][w.y]+1;
                }
        }
        int lmin=110000;
        for (i=1; i<=n; i++)
            if (b[m][i]<lmin&&b[m][i]!=0&&strchr("aeiou",a[m][i])) lmin=b[m][i];
        fout<<lmin<<'\n';
    }
}
