#include <cstdio>
#define min(a,b) a<b ? a : b

using namespace std;

long n,m,i,j,k,a[100010],log[100010],rmq[100010][18],doi[18];

int main()
{
    freopen("rmq.in","r",stdin);
    freopen("rmq.out","w",stdout);
    scanf("%d%d",&n,&m);
    doi[0]=1;
    for (i=1; i<=20; i++)
        doi[i]=doi[i-1]*2;
    log[1]=0;
    for (i=2; i<=n; i++)
        log[i]=log[i/2]+1;
    for (i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for (i=1; i<=n; i++)
        rmq[i][0]=a[i];
    for (i=1; i<=log[n]; i++)
        for (j=1; j<=n-doi[i]+1; j++)
            rmq[j][i]=min(rmq[j][i-1],rmq[j+doi[i-1]][i-1]);
    for (i=1; i<=m; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",min(rmq[x][log[y-x+1]],rmq[y-doi[log[y-x+1]]+1][log[y-x+1]]));
    }
}
