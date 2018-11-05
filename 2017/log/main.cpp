#include <fstream>
#define nmax 10010

using namespace std;

ifstream fin("log.in");
ofstream fout("log.out");

int n,i,a[nmax],b[nmax],p[nmax],k,j,t1,t2,t3,dp[nmax];

int calcul(int A, int B)
{
    return t3*(A-B)*(A-B);
}

int main()
{
    fin >> n;
    fin >> t1 >> t2 >> t3;
    for (i=1; i<=n; i++)
    {
        fin >> a[i] >> b[i];
        p[i]=i;
        if (a[i]==b[i-1])
            p[i]=p[i-1];
    }
    dp[1]=calcul(a[1],b[1]);
    for (i=2; i<=n; i++)
    {
        dp[i]=2e9;
        for (j=p[i]; j<=i; j++)
            if (j>1)
                dp[i]=min(dp[i],dp[j-1]+calcul(a[j],b[i])+t2*(i-j)+t1);
            else
                dp[i]=min(dp[i],dp[j-1]+calcul(a[j],b[i])+t2*(i-j));
    }
    fout << dp[n] << '\n';
    fin.close();
    fout.close();
    return 0;
}
