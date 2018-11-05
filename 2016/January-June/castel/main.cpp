#include <fstream>

using namespace std;

ifstream fin("castel.in");
ofstream fout("castel.out");

short n,m,i,j,k;
short a[155][155];
bool vizitate[155][155];
short nrcamere,camere[155][155];

short dx[]= {0,-1,0,1};
short dy[]= {-1,0,1,0};
bool chei[25000];
short nrchei;
struct coada
{
    int x,y;
} c[25000];
short xi,yi;

int interior(int x,int y)
{
    if (x>=1&&x<=n&&y>=1&&y<=m)
        return 1;
    return 0;
}

void numerotare()
{
    short i,j;
    short nr=0;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        {
            fin>>a[i][j];
            camere[i][j]=++nr;
            if (nr==k) xi=i,yi=j;
        }
}

int main()
{
    fin>>n>>m>>k;
    short z;
    numerotare();
    vizitate[xi][yi]=1;
    chei[k]=1;
    c[1].x=xi;
    c[1].y=yi;
    nrcamere=1;
    int ok=1;
    while (ok)
    {
        ok=0;
        for (i=1; i<=nrcamere; i++)
        {
            for (z=0; z<4; z++)
            {
                short dxk=c[i].x+dx[z];
                short dyk=c[i].y+dy[z];
                if (!vizitate[dxk][dyk]&&chei[a[dxk][dyk]]&&interior(dxk,dyk))
                {
                    c[++nrcamere].x=dxk;
                    c[nrcamere].y=dyk;
                    ok=1;
                    chei[camere[dxk][dyk]]=1;
                    vizitate[dxk][dyk]=1;
                }
            }
        }
    }
    fout<<nrcamere<<'\n';
}
