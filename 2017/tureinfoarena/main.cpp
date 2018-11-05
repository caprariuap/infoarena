#include <fstream>

using namespace std;

ifstream fin("ture.in");
ofstream fout("ture.out");

long long n,m,k,p,i,j,h,dp[260][100000],doi[30],nr[100000],ans;
bool a[260][260];

int main()
{
    fin >> n >> m >> k >> p;
    if (k==0)
    {
        fout << "1\n";
        return 0;
    }
    if (n<m)
    {
        swap(n,m);
        for (i=1; i<=p; i++)
        {
            long long x,y;
            fin >> x >> y;
            a[y][x]=1;
        }
    }
    else
    {
        for (i=1; i<=p; i++)
        {
            long long x,y;
            fin >> x >> y;
            a[x][y]=1;
        }
    }
    if (k>m)
    {
        fout << "0\n";
        return 0;
    }
    doi[0]=1;
    for (i=1; i<=20; i++)
        doi[i]=2*doi[i-1];
    for (i=1; i<=m; i++)
        if (a[1][i]==0)
            {
                dp[1][doi[i-1]]=1;
                if (k==1)
                    ans++;
            }
    if (k==1)
    {
        fout << ans << '\n';
        return 0;
    }
    dp[1][0]=1;
    for (i=1; i<=doi[m]-1; i++)
    {
        int X=0;
        for (j=1; j<=m; j++)
            if ((doi[j-1]&i)>0)
            X++;
        nr[i]=X;
    }
    for (i=2; i<=n; i++)
    {
        for (h=1; h<=doi[m]-1; h++)
        {
            dp[i][h]=dp[i-1][h];
            for (j=1; j<=m; j++)
            {
                if ((h&doi[j-1])>0&&a[i][j]==0)
                    dp[i][h]=dp[i][h]+dp[i-1][(h^doi[j-1])];
            }
//            if (nr[h]==k)
//                ans+=dp[i][h],fout << h << ' ' << i << ' ' << dp[i][h] << '\n';
        }
        dp[i][0]=1;
    }
    for (i=0; i<=doi[m]-1; i++)
    {
        if (nr[i]==k)
            ans+=dp[n][i];
    }
    fout << ans << '\n';
}
