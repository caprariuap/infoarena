#include <fstream>
#define nmax 100010

using namespace std;

ifstream fin("permutare2.in");
ofstream fout("permutare2.out");

long long n,i,j,m,nre[2*nmax],nnre[2*nmax],st,dr,ans,sol;

//long long Abs(long long x)
//{
//    if (x<0)
//        return -x;
//    return x;
//}

long long calcdist(long long poza, long long pozb)
{
    long long ret=poza-pozb;
    if (ret<0)
        ret+=n;
}

int main()
{
    fin >> n >> m;
    for (i=1; i<=n; i++)
    {
        long long x;
        fin >> x;
    }
    for (i=1; i<m; i++)
    {
        long long x;
        fin >> x;
        --nre[x];
        ++nnre[x];
        --nnre[(x+n/2)%n];
        ++nre[(x+n/2+n%2)%n];
        if(x<n/2)
            ++dr;
        if(x>=n/2+n%2)
            ++st;
        sol+=min(x, n-x);
    }
    long long sc=sol;
    for(long long i=0; i<n; ++i)
    {
        sol=min(sol, sc+min(i, n-i));
        st+=nnre[i];
        dr+=nre[i];
        sc+=st-dr;
    }
    fout << sol << '\n';
}
