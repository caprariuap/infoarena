#include <fstream>
using namespace std;
ifstream fin("panda.in");
ofstream fout("panda.out");
int dx[]= {0,-1,0,1};
int dy[]= {-1,0,1,0};
int p,n,m,t,l,col,k,s,i,j,x,y,a[502][502],matrice[502][502];
struct element
{
    int x,y,d;
};
element w,c[200000];
int cheieacces(int i,int j)
{
    int t=s;
    int xx=a[i][j];
    int kk=k;
    while (t--)
    {
        if (xx%2==kk%2)
            return 0;
        xx/=2;
        kk/=2;
    }
    return 1;
}
int main()
{
    fin>>p;
    fin>>n>>m>>t;
    fin>>l>>col>>k>>s;
    if (p==1)
    {
        for (i=1; i<=t; i++)
            fin>>x>>y;
        for (i=1; i<=n; i++)
            for (j=1; j<=m; j++) fin>>a[i][j];
        int solutie=-1;
        for (i=1; i<=n; i++)
            for (j=1; j<=m; j++)
                if (cheieacces(i,j)) solutie++;
        fout<<solutie;
    }
    else
    {
        int k;
        int distanta,nrr=0;
        for (i=1; i<=t; i++)
        {
            fin>>x>>y;
            matrice[x][y]=2;
        }
        for (i=1; i<=n; i++)
            for (j=1; j<=m; j++) fin>>a[i][j];
        for (i=1; i<=n; i++)
            for (j=1; j<=m; j++)
            {
                if (matrice[i][j]==0)
                {
                    if (cheieacces(i,j)) matrice[i][j]=1;
                }
                else
                {
                    if (matrice[i][j]==2) if (!cheieacces(i,j)) matrice[i][j]=0;
                }
            }
        matrice[l][col]=0;
        int p=1,u=1;
        c[p].x=l;
        c[p].y=col;
        c[p].d=0;
        int ok=1;
        while (p<=u&&ok)
        {
            w=c[p];
            for (k=0; k<4; k++)
            {
                if (matrice[w.x+dx[k]][w.y+dy[k]]&&ok)
                {
                    u++;
                    c[u].x=w.x+dx[k];
                    c[u].y=w.y+dy[k];
                    c[u].d=w.d+1;
                    if (matrice[c[u].x][c[u].y]==2)
                    {
                        ok=0;
                        distanta=c[u].d;
                        nrr++;
                        matrice[c[u].x][c[u].y]=0;
                        int aux=u;
                        while (p<aux)
                        {
                            w=c[p];
                            p++;
                            int kk;
                            for (kk=0; kk<4; kk++)
                            {
                                if (matrice[w.x+dx[kk]][w.y+dy[kk]]==2) nrr++,matrice[w.x+dx[kk]][w.y+dy[kk]]=0;
                            }
                        }
                    }
                    matrice[c[u].x][c[u].y]=0;
                }
            }
            p++;
        }
        fout<<distanta<<' '<<nrr;
    }
    fout<<'\n';
    fin.close();
    fout.close();
}
