#include <cstdio>

using namespace std;

FILE *fin=fopen("immortal.in","r");
FILE *fout=fopen("immortal.out","w");

int dx[4]= {0,-1,0,1};
int dy[4]= {-1,0,1,0};

struct abc
{
    int x,y;
} nemuritor[30];
struct bcd
{
    int x1,x2,y1,y2;
} rez[30];

int a[30][30],i,k,n,m;
bool use[30],ok;

void bkt(int nr)
{
    if (ok)
        return;
    if (nr==k)
    {
        ok=1;
        for (int i=1; i<=k-1; i++)
        fprintf(fout,"%d %d %d %d\n",rez[i].x1,rez[i].y1,rez[i].x2,rez[i].y2);
        return;
    }
    for (int i=1; i<=k; i++)
        if (!use[i])
        {
            int nx,ny;
            nx=nemuritor[i].x;
            ny=nemuritor[i].y;
            for (int j=0; j<4; j++)
                if (a[nx+dx[j]][ny+dy[j]]&&!use[a[nx+dx[j]][ny+dy[j]]]&&nx+2*dx[j]>0&&nx+2*dx[j]<=n&&ny+2*dy[j]>0&&ny+2*dy[j]<=m&&a[nx+2*dx[j]][ny+2*dy[j]]==0)
                {
                    int aux2x,aux2y;
                    aux2x=nx+dx[j];
                    aux2y=ny+dy[j];
                    use[a[aux2x][aux2y]]=1;
                    a[aux2x+dx[j]][aux2y+dy[j]]=i;
                    a[nx][ny]=0;
                    int cpyy=a[aux2x][aux2y];
                    a[aux2x][aux2y]=0;
                    nemuritor[i].x=aux2x+dx[j];
                    nemuritor[i].y=aux2y+dy[j];
                    rez[nr].x1=nx;
                    rez[nr].y1=ny;
                    rez[nr].x2=aux2x+dx[j];
                    rez[nr].y2=aux2y+dy[j];
                    bkt(nr+1);
                    nemuritor[i].x=nx;
                    nemuritor[i].y=ny;
                    a[nx][ny]=i;
                    a[aux2x][aux2y]=cpyy;
                    a[aux2x+dx[j]][aux2y+dy[j]]=0;
                    use[a[aux2x][aux2y]]=0;
                }
        }
}

int main()
{
    fscanf(fin,"%d %d %d",&n,&m,&k);
    for (i=1; i<=k; i++)
    {
        fscanf(fin,"%d %d",&nemuritor[i].x,&nemuritor[i].y);
        a[nemuritor[i].x][nemuritor[i].y]=i;
    }
//    for (i=1; i<=n; i++)
//    {
//        for (int j=1; j<=m; j++)
//            fprintf(fout,"%d ",a[i][j]);
//        fprintf(fout,"\n");
//    }
    bkt(1);
//    for (i=1; i<=k-1; i++)
//        fprintf(fout,"%d %d %d %d\n",rez[i].x1,rez[i].y1,rez[i].x2,rez[i].y2);
}
