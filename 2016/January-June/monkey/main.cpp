#include <fstream>

using namespace std;

ifstream fin("monkey.in");
ofstream fout("monkey.out");

int n,m;
char a[25][25];
bool viz[27];
int dimensiune,dmax;

int dx[]= {-1,0,1,0};
int dy[]= {0,-1,0,1};

int interior(int x,int y)
{
    if (x>=1&&x<=n&&y>=1&&y<=m)
        return 1;
    return 0;
}

void bkt(int x,int y)
{
    dimensiune++;
    viz[a[x][y]-'A']=1;
    int k;
    int ok=0;
    for (k=0; k<4; k++)
        if (interior(x+dx[k],y+dy[k]))
                if (!viz[a[x+dx[k]][y+dy[k]]-'A'])
                    ok=1,bkt(x+dx[k],y+dy[k]);
                    if (!ok&&dimensiune>dmax) dmax=dimensiune;
                        viz[a[x][y]-'A']=0;
                        dimensiune--;
            }

int main()
{
    fin>>n>>m;
    int i,j;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            fin>>a[i][j];
    bkt(1,1);
    fout<<dmax;
}
