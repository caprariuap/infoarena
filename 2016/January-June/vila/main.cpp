#include <fstream>

using namespace std;

ifstream fin("vila.in");
ofstream fout("vila.out");

int n,m;
char a[135][135];
int suprafete[50000];
int valori[135][135],nrv;

int dx[]= {-1,0,1,0};
int dy[]= {0,-1,0,1};

int interior(int x,int y)
{
    if (x>=1&&x<=n&&y>=1&&y<=m)
        return 1;
    return 0;
}

void fill(int x,int y)
{
    valori[x][y]=nrv;
    suprafete[nrv]++;
    int k;
    for (k=0; k<4; k++)
        if (interior(x+dx[k],y+dy[k])&&a[x+dx[k]][y+dy[k]]=='-'&&!valori[x+dx[k]][y+dy[k]])
            fill(x+dx[k],y+dy[k]);
}

int smax,pozx,pozy;
bool folosit[50000];

int main()
{
    fin>>n>>m;
    int i,j,k;
    for (i=1; i<=n; i++)
        {for (j=1; j<=m; j++)
            fin>>a[i][j];
        a[i][0]=a[i][m+1]='0';
        }
        for (j=1; j<=m; j++)
            a[0][j]=a[n+1][j]='0';
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (!valori[i][j]&&a[i][j]=='-')
            {
                ++nrv;
                fill(i,j);
                if (suprafete[nrv]>smax) smax=suprafete[nrv];
            }
    fout<<nrv<<'\n'<<smax<<'\n';
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (a[i][j]=='1')
            {
                int s=1;
                for (k=0; k<4; k++)
                    folosit[suprafete[valori[i+dx[k]][j+dy[k]]]]=0;
                for (k=0; k<4; k++)
                    if (interior(i+dx[k],j+dy[k])&&a[i+dx[k]][j+dy[k]]=='-')
                    if (!folosit[valori[i+dx[k]][j+dy[k]]])
                        s+=suprafete[valori[i+dx[k]][j+dy[k]]],folosit[valori[i+dx[k]][j+dy[k]]]=1;

                for (k=0; k<4; k++)
                    folosit[valori[i+dx[k]][j+dy[k]]]=0;
                if (s>smax) pozx=i,pozy=j,smax=s;
            }

    fout<<pozx<<' '<<pozy<<' '<<smax<<'\n';
}
