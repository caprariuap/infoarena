#include <fstream>
#define MOD 1000000007

using namespace std;

ifstream fin("monstri.in");
ofstream fout("monstri.out");

long long ans,x;
int i,n;

long long explog(long long a, long long x)
{
    if (x==0)
        return 1;
    if (x==1)
        return a;
    long long k=explog(a,x/2);
    if (x%2)
    {
        k=(k*k)%MOD;
        k=(k*a)%MOD;
        return k;
    }
    k=(k*k)%MOD;
    return k;
}

int main()
{
    fin >> n;
    for (i=1; i<=n; i++)
    {
        fin >> x;
        long long cans=explog(2,x);
        ans=(ans+cans)%MOD;
    }
    fout << ans << '\n';
    fin.close();
    fout.close();
    return 0;
}
