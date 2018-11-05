#include <fstream>
#include <cstring>
#define nmax 250010

using namespace std;

ifstream fin("zlego.in");
ofstream fout("zlego.out");

int i,urm[nmax],n,T,a[nmax];
long long ans[nmax];

void prefix()
{
    urm[1]=0;
    int k=0;
    for (i=2; i<=n; i++)
    {
        while (k>0&&a[k+1]!=a[i])
            k=urm[k];
        if (a[k+1]==a[i])
            k++;
        urm[i]=k;
    }
}

void solve()
{
    fin >> n;
    for (i=1; i<=n; i++)
        fin >> a[i];
    for (i=1; i<=n; i++)
        fin >> ans[i];
    prefix();
    for (i=n; i; i--)
        ans[urm[i]]+=ans[i];
    for (i=1; i<=n; i++)
        fout << ans[i] << '\n';
}

int main()
{
    fin >> T;
    while (T--)
        solve();
}
