#include <fstream>
#include <map>
#include <vector>

using namespace std;

ifstream fin("costuri.in");
ofstream fout("costuri.out");

map <int,vector <int > > m;
int n,i,q,nrel[60000];

int produsc(int x)
{
    int produs=1;
    if (x==0)
        return 0;
    while (x>0)
    {
        produs=produs*(x%10);
        x/=10;
    }
    return produs;
}

int main()
{
    fin >> n;
    for (i=1; i<=n; i++)
    {
        int x;
        fin >> x;
        int pc=produsc(x);
        nrel[pc]++;
        m[pc].push_back(x);
    }
    fin >> q;
    for (i=1; i<=q; i++)
    {
        int P,C;
        fin >> P >> C;
        if (P>nrel[C])
            fout << "-1\n";
        else
            fout << m[C][P-1] << '\n';
    }
}
