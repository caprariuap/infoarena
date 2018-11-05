#include <fstream>

using namespace std;

ifstream fin("sortare2.in");
ofstream fout("sortare2.out");

int n,i,poz[100100],nrg;

int main()
{
    fin >> n;
    for (i=1; i<=n; i++)
    {
        int x;
        fin >> x;
        poz[x]=i;
    }
    for (i=2; i<=n; i++)
    {
        if (poz[i]<poz[i-1])
            nrg++;
    }
    fout << nrg << '\n';
}
