#include <fstream>
#define aux 44100

using namespace std;

ifstream fin("diamant.in");
ofstream fout("diamant.out");

int n,m,x,j,a[500],nr,i,dp[2][100010],sum,l;

int main()
{
    fin >> n >> m >> x;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            a[++nr]=i*j,sum+=a[nr];
    if (x>sum||x<-sum)
    {
        fout << "0\n";
        fin.close();
        fout.close();
        return 0;
    }
    dp[0][aux]=1;
    for (i=1; i<=nr; i++)
    {
        l=1-l;
        for (j=-sum; j<=sum; j++)
            dp[l][aux+j]=(dp[1-l][aux+j]+dp[1-l][aux+j+a[i]]+dp[1-l][aux+j-a[i]])%10000;
    }
    fout << dp[l][aux+x] << '\n';
//    fout << nr << '\n';
//    for (i=1; i<=nr; i++)
//        fout << a[i] << ' ';
    fout << '\n';
    fin.close();
    fout.close();
    return 0;
}
