#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025],b[1025],m,n,i,j,l,cmlsc[1025],ab[1025][1025],lgab;

int main()
{
    fin >> n >> m;
    for (i=1; i<=n; i++)
        fin >> a[i];
    for (i=1; i<=m; i++)
        fin >> b[i];
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (a[i]==b[j])
                ab[i][j]=ab[i-1][j-1]+1;
            else
                ab[i][j]=max(ab[i-1][j],ab[i][j-1]);
    fout << ab[n][m] << '\n';
    i=n;
    j=m;
    while (i>0&&j>0)
    {
        if (a[i]==b[j])
            cmlsc[++lgab]=a[i],i--,j--;
        else
            if (ab[i-1][j]<ab[i][j-1])
                j--;
            else
                i--;
    }
    for (i=lgab; i; i--)
        fout << cmlsc[i] << ' ';
    fout << '\n';
}
