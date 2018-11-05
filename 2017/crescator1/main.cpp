#include <fstream>
#include <map>

using namespace std;

ifstream fin("crescator1.in");
ofstream fout("crescator1.out");

map <int,int> m;
int n,a[100100],i,sol,nr;

int sc(int x)
{
    int ret=0;
    while (x>0)
    {
        ret=ret+x%10;
        x/=10;
    }
    return ret;
}

int main()
{
    fin >> n;
    fin >> a[1];
    sol++;
    nr=a[1];
    for (i=2; i<=n; i++)
    {
        fin >> a[i];
        m[a[i]]=m[a[i]]+1;
    }
    for (i=2; i<=n; i++)
    {
        nr=nr+sc(nr);
        sol=sol+m[nr];
    }
    fout << sol << '\n';
}
