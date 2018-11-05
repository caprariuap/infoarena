#include <cstdio>

using namespace std;

long long i,j,k,n,m[510],dp[510][510],nr,dif;

int main()
{
    freopen("podm.in","r",stdin);
    freopen("podm.out","w",stdout);
    scanf("%d",&n);
    for (i=0; i<=n; i++)
        scanf("%d",&m[i+1]);
    for (i=1; i<n; i++)
        dp[i][i+1]=m[i]*m[i+1]*m[i+2];
    nr=2;
    dif=2;
    while (nr<n)
    {
        for (i=1; i+nr<=n; i++)
        {
            j=i+nr;
            for (k=i; k<=j; k++)
                if (dp[i][j]==0||(dp[i][k]+dp[k+1][j]+m[i]*m[j+1]*m[k+1]<dp[i][j]))
                    dp[i][j]=dp[i][k]+dp[k+1][j]+m[i]*m[j+1]*m[k+1];
        }
        nr++;
    }
    printf("%lld",dp[1][n]);
}
