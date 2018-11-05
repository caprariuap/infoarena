#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("ferma3.in");
ofstream fout("ferma3.out");
char a[412][412];
int b[412][412],parcele[160002],nrp,folosire[160002];
int dx[]= {0,-1,0,1};
int dy[]= {-1,0,1,0};
void umple(int x,int y)
{
    b[x][y]=nrp;
    parcele[nrp]++;
    for (int k=0; k<4; k++)
    {
        if (!b[x+dx[k]][y+dy[k]]&&a[x+dx[k]][y+dy[k]]==a[x][y])
            umple (x+dx[k],y+dy[k]);
    }
}
int main()
{
    int i,j,v,n,m,maxim=0;
    fin>>v>>n>>m;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            fin>>a[i][j];
    fin.close();
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        {
            if (!b[i][j])
            {
                nrp++;
                umple(i,j);
            }
            if (parcele[nrp]>maxim) maxim=parcele[nrp];
        }
    if (v==1)
        fout<<maxim;
    else
    {
        char solutie;
        int solx,soly,sol=0,s;
        for (i=1; i<=n; i++)
            for (j=1; j<=m; j++)
            {
                char aux=a[i][j];
                for (int k=0; k<4; k++)
                {
                    if (i+dx[k]<=n&&i+dx[k]>0&&j+dy[k]<=m&&j+dy[k]>0&&a[i+dx[k]][j+dy[k]]!=aux)
                    {
                        a[i][j]=a[i+dx[k]][j+dy[k]];
                        s=1;
                        for (int l=0; l<4; l++)
                            if (a[i+dx[l]][j+dy[l]]==a[i][j]&&folosire[b[i+dx[l]][j+dy[l]]]==0)
                                s+=parcele[b[i+dx[l]][j+dy[l]]],folosire[b[i+dx[l]][j+dy[l]]]=1;
                        folosire[b[i+dx[k]][j+dy[k]]]=0;
                        for(int o=0; o<4; o++)
                        {
                            folosire[b[i+dx[o]][j+dy[o]]]=0;
                        }
                        if (s>sol)
                        {
                            solx=i;
                            soly=j;
                            solutie=a[i][j];
                            sol=s;
                        }
                    }
                }
                a[i][j]=aux;
            }
        fout<<solx<<' '<<soly<<'\n'<<solutie;
    }
    fout<<'\n';
    fout.close();
}
