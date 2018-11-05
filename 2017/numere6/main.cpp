#include <cstdio>
#define MOD 9973
#define INPUT "numere6.in"
#define OUTPUT "numere6.out"

using namespace std;

FILE *f = fopen(INPUT, "r");
FILE *g = fopen(OUTPUT, "w");

int a,b,dp[2][110],d[110],isd[9010],i,j,k,nrd;

int main()
{
    fscanf(f, "%d %d", &a, &b);
    for (i=1; i*2<=b; i++)
        if (b%i==0)
            d[++nrd]=i,isd[i]=nrd;
    d[++nrd]=b;
    isd[b]=nrd;
    for (i=1; i<10; i++)
        if (isd[i])
            dp[1][isd[i]]=1;
    int ind=1;
    for (i=2; i<=a; i++)
    {
        ind=1-ind;
        for (j=1; j<=nrd; j++)
        {
            dp[ind][j]=0;
            for (k=1; k<=9; k++)
            {
                int kk = d[j]/k;
                if (d[j]/k*k==d[j] && isd[kk])
                {
                    dp[ind][j]+=dp[1-ind][isd[kk]];
                    if(dp[ind][j] > MOD)
                        dp[ind][j] -= MOD;
                }
            }
        }
    }
    fprintf(g, "%d\n", dp[a%2][isd[b]]);
}
