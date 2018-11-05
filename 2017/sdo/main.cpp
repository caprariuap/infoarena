#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

ifstream fin("sdo.in");
ofstream fout("sdo.out");

int a[3000001],n,k,i;

int divide(int p, int q)
{
    int st=p,dr=q,x;
    int poz=rand()%(q-p+1)+p;
    swap(a[poz],a[p]);
    x=a[p];
    while (st<dr)
    {
        while (st<dr&&a[dr]>=x)
            dr--;
        a[st]=a[dr];
        while (st<dr&&a[st]<=x)
            st++;
        a[dr]=a[st];
    }
    a[st]=x;
    return st;
}

int qs(int p, int q)
{
    int m=divide(p,q);
//    fout << a[m] << ' ' << m << '\n';
//    for (int i=1; i<=n; i++)
//        fout << a[i] << ' ';
//    fout << '\n';
    if (k==m)
        return a[k];
    if (k<m)
        return qs(p,m-1);
    else
        return qs(m+1,q);
}

int main()
{
    srand(time(NULL));
    fin >> n >> k;
    for (i=1; i<=n; i++)
        fin >> a[i];
    fout << qs(1,n) << '\n';
}
