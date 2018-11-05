#include <fstream>

using namespace std;

ifstream fin("suma4.in");
ofstream fout("suma4.out");

int n,i,c[70000],m,dp[60][3600],minim,p[70000],j,k;
int dx[4]= {0,0,1,1};
int dy[4]= {0,1,0,1};

int son(int i, int j)
{
    int randuri=(j-1)/i;
    return j-randuri*i+randuri*(i+1);
}

int main()
{
    fin >> n;
    for (i=1; i<=n; i++)
        fin >> c[i];
    m=1;
    while (m*(m+1)*(2*m+1)/6!=n)
        m++;
    fout << m << ' ';
    for (i=1; i<=m; i++)
        for (j=1; j<=i*i; j++)
            dp[i][j]=7000000;
    for (j=1; j<=m*m; j++)
    {
        i=m;
        int primul=(i-1)*i*(2*i-1)/6;
        dp[m][j]=c[primul+j];
    }
    for (i=m-1; i>=1; i--)
    {
        int primul=(i-1)*i*(2*i-1)/6;
        for (j=1; j<=i*i; j++)
        {
            int fiu=son(i,j);
            for (k=0; k<4; k++)
                {
                    int urm=fiu+i*(i+1)*(2*i+1)/6;
                    if (dp[i+1][fiu+dx[k]*(i+1)+dy[k]]+c[primul+j]<dp[i][j]||(dp[i+1][fiu+dx[k]*(i+1)+dy[k]]+c[primul+j]==dp[i][j]&&p[primul+j]>urm+dx[k]*(i+1)+dy[k]))
                    dp[i][j]=dp[i+1][fiu+dx[k]*(i+1)+dy[k]]+c[primul+j],p[primul+j]=urm+dx[k]*(i+1)+dy[k];
                    }
        }
    }
    minim=70000000;
    minim=dp[1][1];
    fout << minim << '\n';
//    for (i=1; i<=m; i++)
//    {
//        int primul=(i-1)*i*(2*i-1)/6;
//        for (j=1; j<=i*i; j++)
//            fout << dp[i][j] << ' ';
//        fout << '\n';
//    }
    i=1;
    while (i!=0)
    {
        fout << i << ' ';
        i=p[i];
    }
    fout << '\n';
}
