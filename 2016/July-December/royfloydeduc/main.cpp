#include <cstdio>

using namespace std;

int n,i,j,k,a[110][110];

int main()
{
    freopen("royfloyd.in","r",stdin);
    freopen("royfloyd.out","w",stdout);
    scanf("%d",&n);
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
        scanf("%d",&a[i][j]);
    for (k=1; k<=n; k++)
        for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
        if (i!=j&&a[i][k]&&a[k][j]&&(a[i][j]>a[i][k]+a[k][j]||a[i][j]==0)) a[i][j]=a[i][k]+a[k][j];
    for (i=1; i<=n; i++)
        {
            for (j=1; j<=n; j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
}
