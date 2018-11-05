#include <cstdio>
#define M 100003

using namespace std;

int n,p,i,j;
int dp[2016][2016],ans;

int main()
{
    freopen("fractii2.in","r",stdin);
    freopen("fractii2.out","w",stdout);
    scanf("%d%d",&p,&n);
    if (p==1)
    {
        if (n>2)
        {
            for (int i=1; i<n; i++)
                printf("%d ",i);
            printf("%d",n-1);
        }
        else printf("%d %d",n,n);
    }
    else
    {
        dp[2][1]=1;
        for (i=3; i<=n; i++)
            for (j=1; j<=i/2; j++)
                    dp[i][j]=(dp[i][j]+dp[i][j-1]+dp[i-j][(i-j)/2]-dp[i-j][(j+1)/2-1])%M;
        ans=dp[n][n/2];
        if (ans<0)
            ans+=M;
        printf("%d",ans);
    }
}
