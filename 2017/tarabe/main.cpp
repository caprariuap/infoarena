#include <fstream>
#define nmax 200010

using namespace std;

ifstream fin("tarabe.in");
ofstream fout("tarabe.out");

int n,k,i;
long long a[nmax],b[nmax];

bool posibil(long long maxc)
{
    long long ck=0;
    for (i=1; i<=n; i++)
        if (maxc>=a[i])
        {
            long long x=(maxc-a[i])/b[i]+1;
            ck+=x;
        }
    if (ck>=k)
        return 1;
    return 0;
}

int main()
{
    fin >> n >> k;
    for (i=1; i<=n; i++)
        fin >> b[i] >> a[i];
    long long st,dr,mij;
    st=1;
    dr=123456789;
    while (st<dr)
    {
        mij=(st+dr)/2;
        if (posibil(mij))
            dr=mij;
        else
            st=mij+1;
    }
    long long maxc=st,ans=0,ck=0;
    for (i=1; i<=n; i++)
        if (maxc>=a[i])
        {
            long long x=(maxc-a[i])/b[i]+1;
            ck+=x;
            ans=ans+x*a[i]+b[i]*(x*(x-1)/2);
        }
    ans=ans-maxc*(ck-k);
    fout << ans << '\n';
}
/*
ai+(n-1)bi=X
n=(X-ai)/bi+1
ai+ai+bi+ai+2*bi+...+ai+(x-1)*bi=maxc
x*ai+bi*(x-1)*x/2
*/
