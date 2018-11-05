#include <cstdio>
#include <vector>
#define nmax 1510

using namespace std;

FILE *fin=fopen("bemo.in","r");
FILE *fout=fopen("bemo.out","w");

int n,m,a[nmax][nmax],i,j,x,y,nextx,nexty,from[nmax],to[nmax];
pair <int, int> poz[nmax*nmax];
bool use[nmax][nmax];

bool posibil(int x, int y, int nextval)
{
    nextx=poz[nextval].first;
    nexty=poz[nextval].second;
    if (nextx>=x&&nexty>=y)
        return 1;
    if (nextx>x||nexty>y)
        return 0;
    return 1;
}

int main()
{
    fscanf(fin,"%d%d",&n,&m);
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        {
            fscanf(fin,"%d",&a[i][j]);
            poz[a[i][j]]=make_pair(i,j);
        }
    for (i=1; i<=m; i++)
        to[i]=n+1;
    for (i=1; i<=n*m; i++)
    {
        int x=poz[i].first,y=poz[i].second;
        if (x<from[y]||x>to[y])
            continue;
        for (j=1; j<y; j++)
            to[j]=min(to[j],x);
        for (j=y+1; j<=m; j++)
            from[j]=max(from[j],x);
        use[x][y]=1;
    }
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (use[i][j])
                fprintf(fout,"%d ",a[i][j]);
    fclose(fin);
    fclose(fout);
    return 0;
}
