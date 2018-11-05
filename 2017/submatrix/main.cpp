#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#define nmax 305

using namespace std;

ifstream fin("submatrix.in");
ofstream fout("submatrix.out");

int n,m,k,a[nmax][nmax],v[nmax*nmax],i,j,nr,fr[nmax*nmax],ck,l,ans;
vector <int> V;

void diag(int i, int j)
{
    memset(fr, 0, sizeof(fr));
    l=1;
    fr[a[i][j]]=1;
    ck=1;
    while (i<n&&j<m)
    {
        i++;
        j++;
        l++;
        for (int x=i-l+1; x<=i; x++)
        {
            if (fr[a[x][j]]==0)
                ck++;
            fr[a[x][j]]++;
        }
        for (int x=j-l+1; x<j; x++)
        {
            if (fr[a[i][x]]==0)
                ck++;
            fr[a[i][x]]++;
        }
        while (ck>k)
        {
            for (int x=i-l+1; x<=i; x++)
            {
                if (fr[a[x][j-l+1]]==1)
                    ck--;
                fr[a[x][j-l+1]]--;
            }
            for (int x=j-l+2; x<=j; x++)
            {
                if (fr[a[i-l+1][x]]==1)
                    ck--;
                fr[a[i-l+1][x]]--;
            }
            l--;
        }
        if (l>ans)
            ans=l;
    }
}

int main()
{
    fin >> n >> m >> k;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        {
            fin >> a[i][j];
            V.push_back(a[i][j]);
        }
//    sort(v+1,v+nr+1);
//    int real=1;
//    for (i=1; i<=nr; i++)
//    {
//        v[real]=v[i];
//        j=i+1;
//        while (v[real]==v[j]&&j<=nr)
//            j++;
//        if (j>nr)
//            break;
//        i=j;
//        real++;
//    }
//    nr=real;
//    for (i=1; i<=n; i++)
//        for (j=1; j<=m; j++)
//            a[i][j]=lower_bound(v+1,v+nr+1,a[i][j])-v;
    vector<int>::iterator it;
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(),V.end())-V.begin());
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
        {
            it = lower_bound(V.begin(), V.end(), a[i][j]);
            a[i][j] = (int)(it-V.begin());
        }
//    for (i=1; i<=n; i++)
//    {
//        for (j=1; j<=m; j++)
//            fout << a[i][j] << ' ';
//        fout << '\n';
//    }
    for (int i=1; i<=m; i++)
        diag(1,i);
    for (int i=2; i<=n; i++)
        diag(i,1);
    fout << ans << '\n';
//    fout << nr << ' ';
//    for (i=1; i<=nr; i++)
//        fout << v[i] << ' ';
}
