#include <fstream>
using namespace std;
ifstream fin("zona.in");
ofstream fout("zona.out");
int dx[]= {-1,0,1,0};
int dy[]= {0,1,0,-1};
int nrceva,ok,x,y,n,l,x1,y1,i,j,a[110][110],z,cx[50000],cy[50000];
int verif(int x,int y)
{
    int x1=x,x2=x,y1=y,y2=y;
    while (a[x][y1]==0) y1--;
    if (!y1) return 0;
    while (a[x][y2]==0) y2++;
    if (!y2) return 0;
    while (a[x1][y]==0) x1--;
    if (!x1) return 0;
    while (a[x2][y]==0) x2--;
    if (!x2) return 0;
    return 1;
}
void filll(int x,int y)
{
    a[x][y]=1;
    nrceva++;
    for (int k=0; k<4; k++)
        if (a[x+dx[k]][y+dy[k]]==0)
            filll(x+dx[k],y+dy[k]);
}
int main()
{
    fin>>x>>y>>n>>l;
    x++;
    y++;
    int xi=x;
    int yi=y;
    int is;
    for (i=0; i<=n+1; i++) a[0][i]=a[n+2][i]=a[i][0]=a[i][n+2]=2;
    a[x][y]=1;
    cx[0]=x;
    cy[0]=y;
    int imj;
    for (i=1; i<=l; i++)
    {
        fin>>z;
        x+=dx[z-1];
        y+=dy[z-1];
        a[x][y]=1;
        cx[i]=x;
        cy[i]=y;
        if (!ok)
            for (j=0; j<i; j++)
                if (cx[i]==cx[j]&&cy[i]==cy[j])
                {
                    ok=1;
                    for (int k=0; k<j; k++) a[cx[k]][cy[k]]=0;
                    fout<<i-j<<'\n';
                    imj=i-j;
                }
    }
    for (i=1; i<=n+1&&ok; i++)
        for (j=1; j<=n+1&&ok; j++)
        {
            if (a[i][j]==0)
                if (verif(i,j))
                {
                    ok=0;
                    filll(i,j);
                }
        }
    fout<<nrceva+imj/2-1<<'\n';
}
