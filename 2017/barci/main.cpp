#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("barci.in");
ofstream fout("barci.out");

long long n,a[100010],i,j,vf,bz,dq[300010],nrb,c,b;

int main()
{
    fin >> n >> c >> b;
    for (i=1; i<=n; i++)
        fin >> a[i];
    sort(a+1,a+n+1);
    vf=-1;
    bz=0;
    for (i=n; i>0; i--)
    {
        dq[++vf]=i;
                while (vf>bz&&a[dq[bz]]-a[dq[vf]]>b)
            bz++,nrb++;
        while (vf>bz&&a[dq[vf]]+a[dq[bz]]<=c&&a[dq[bz]]-a[dq[vf]]<=b)
        {
            vf--;
            bz++;
            nrb++;
        }

    }
    while (vf>bz&&a[dq[vf]]+a[dq[bz]]<=c&&a[dq[bz]]-a[dq[vf]]<=b)
    {
        vf--;
        bz++;
        nrb++;
    }
    nrb=nrb+vf-bz+1;
    fout << nrb << '\n';
}
