#include <cstdio>

using namespace std;

int n,i,j,k,a[260][260];
int d[260][260];

int main()
{
    freopen("rf.in", "r", stdin);
    freopen("rf.out", "w", stdout);
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
            scanf("%d", &a[i][j]),d[i][j]=1;
        d[i][i]=0;
    }
    for (k=1; k<=n; k++)
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                if (a[k][i]+a[k][j]==a[i][j]&&i!=j)
                {
                    if (d[k][i]+d[k][j]>d[i][j])
                        d[i][j]=d[j][i]=d[k][i]+d[k][j];
                }
                else if (a[k][i]+a[k][j]<a[i][j]&&i!=j)
                {
                    a[i][j]=a[j][i]=a[k][i]+a[k][j];
                    d[i][j]=d[j][i]=d[k][i]+d[k][j];
                }
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
            printf("%d ",d[i][j]);
        printf("\n");
    }
}
