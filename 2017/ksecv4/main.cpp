#include <fstream>
#define inf (1LL*1000000000*1000000000)
#define bucket 32

using namespace std;

ifstream fin("ksecv4.in");
ofstream fout("ksecv4.out");

long long i,j,n,m,k,mxbucket[1000000],mnbucket[1000000],v[1000000],a[1000000],b[1000000];

bool posibil(long long val)
{
    long long nrs=1;
    long long mx,mn;
    mx=-inf;
    mn=inf;
    for (i=0; i<n; i++)
    {
        if (i%bucket==0&&i+bucket<n)
        {
            long long mnt,mxt;
            mnt=min(mn,mnbucket[i/bucket]);
            mxt=max(mx,mxbucket[i/bucket]);
            if ((mxt-mnt+1)/2<=val)
            {
                mn=mnt;
                mx=mxt;
                i=i+bucket-1;
            }
        }
        mn=min(mn,v[i]);
        mx=max(mx,v[i]);
        if ((mx-mn+1)/2>val)
        {
            nrs++;
            mx=mn=v[i];
            if (nrs>k)
                return 0;
        }
    }
    return 1;
}

int main()
{
    fin >> n >> k >> m;
    for (i=0; i<m; i++)
        fin >> a[i];
    for (i=0; i<m; i++)
        fin >> b[i];
    for (i=0; i<n; i++)
        v[i]=(a[i%m]^b[i/m]);
    for (i=0; i<n; i+=bucket)
    {
        long long mx,mn;
        mx=-inf;
        mn=inf;
        for (j=i; j<n&&j<i+bucket; j++)
        {
            mx=max(mx,v[j]);
            mn=min(mn,v[j]);
        }
        mxbucket[i/bucket]=mx;
        mnbucket[i/bucket]=mn;
    }
    long long l,r,sol=inf;
    l=0;
    r=inf;
    while (l<=r)
    {
        long long mid=(l+r)/2;
        if (posibil(mid))
            sol=mid,r=mid-1;
        else
            l=mid+1;
    }
    fout << l << '\n';
}
