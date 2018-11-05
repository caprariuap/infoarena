#include <cstdio>
#include <iostream>

using namespace std;

FILE *fin=fopen("joc13.in","r");
FILE *fout=fopen("joc13.out","w");

int i,j,l,n,k,a[5010][2],dp[5010][2][12],maxim;

int main()
{
    fscanf(fin,"%d %d", &n, &k);
    for (j=0; j<2; j++)
        for (i=1; i<=n; i++)
            fscanf(fin,"%d",&a[i][j]);
    dp[1][0][1]=a[1][0];
    dp[1][1][1]=a[1][0]+a[1][1];
    for (i=2; i<=n; i++)
        for (j=0; j<2; j++)
    {
        int maxx=-2000000000;
        for (l=2; l<=k&&i-l+1>=1; l++)
            dp[i][j][l]=a[i][j]+dp[i-1][j][l-1],maxx=max(dp[i][j][l],maxx);
        dp[i][1-j][1]=maxx+a[i][1-j];
    }
    maxim=dp[n][1][1];
    int poz=1;
    for (i=1; i<=k; i++)
        if (dp[n][1][i]>maxim)
            maxim=dp[n][1][i],poz=i;
    fprintf(fout,"%d\n",maxim);
}
