#include <fstream>
#include <vector>

using namespace std;

ifstream fin("summax.in");
ofstream fout("summax.out");

vector <unsigned int> dp[2001],t[2001];

int n,i,j,st,dr,p,rez[2001];

void p1()
{
    for (i=1; i<=n; i++)
        t[n][i]=1;
    for (i=n-1; i; i--)
        for (j=1; j<=i; j++)
        {
            if (dp[i+1][j]>dp[i+1][j+1])
            {
                dp[i][j]+=dp[i+1][j];
                t[i][j]=t[i+1][j];
            }
            else if (dp[i+1][j]<dp[i+1][j+1])
            {
                dp[i][j]+=dp[i+1][j+1];
                t[i][j]=t[i+1][j+1];
            }
            else
            {
                dp[i][j]+=dp[i+1][j];
                long long x=t[i+1][j]+t[i+1][j+1];
                long long ct=2000000001;
                x=min(x,ct);
                t[i][j]=x;
            }
        }
    if (p==1)
        fout << t[1][1] << '\n';
//    fout << '\n';
//    for (i=1; i<=n; i++)
//    {
//        for (j=1; j<=i; j++)
//            fout << dp[i][j] << ' ';
//        fout << '\n';
//    }
//    fout << '\n';
//    for (i=1; i<=n; i++)
//    {
//        for (j=1; j<=i; j++)
//            fout << t[i][j] << ' ';
//        fout << '\n';
//    }
//    fout << '\n';
}

void afisare(int i, int j, long long x, long long y)
{
    rez[i]=j;
    if (i==n)
    {
        for (i=1; i<=n; i++)
            fout << rez[i] << ' ';
//        fout << ' ' << x << ' ' << y;
        fout << '\n';
        return;
    }
    if (dp[i+1][j]>dp[i+1][j+1])
        afisare(i+1,j,x,x+t[i+1][j]-1);
    else if (dp[i+1][j]<dp[i+1][j+1])
        afisare(i+1,j+1,x+t[i+1][j],y);
    else
    {
        if (x+t[i+1][j]-1>=st)
            afisare(i+1,j,x,x+t[i+1][j]-1);
        if (x+t[i+1][j]<=dr)
            afisare(i+1,j+1,x+t[i+1][j],y);
    }
}

void p2()
{
    p1();
    afisare(1,1,1,t[1][1]);
}

int main()
{
    fin >> p;
    fin >> n >> st >> dr;
    for (i=1; i<=n; i++)
    {
        dp[i].push_back(0);
        t[i].push_back(0);
        for (j=1; j<=i; j++)
        {
            int x;
            fin >> x;
            dp[i].push_back(x);
            t[i].push_back(0);
        }
    }
    if (p==1)
        p1();
    else
        p2();
}
