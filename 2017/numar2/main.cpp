#include <fstream>

using namespace std;

ifstream fin("numar2.in");
ofstream fout("numar2.out");

int n,i,m,a[110],use[110],j;
long long ans;

int main()
{
    fin >> n >> m;
    for (i=1; i<=n; i++)
        fin >> a[i];
    ans=a[1];
    use[1]++;
    for (j=2; j<=m; j++)
    {
        long long minim=16000000,poz;
        for (i=1; i<=n; i++)
            {
                while ((use[i]+1)*a[i]<=ans)
                    use[i]++;
                if ((use[i]+1)*a[i]<minim&&(use[i]+1)*a[i]>ans)
                minim=(use[i]+1)*a[i],poz=i;
            }
        use[poz]++;
        ans=minim;
//        fout << ans << ' ';
//        for (i=1; i<=n; i++)
//            fout << use[i] << ' ';
//        fout << '\n';
    }
    fout << ans << '\n';
}
