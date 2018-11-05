#include <fstream>
#include <vector>
#define nmax 100010

using namespace std;

ifstream fin("darb.in");
ofstream fout("darb.out");

int n,i;
int dmax,pmax;
int darb;
bool use1[nmax];
bool use2[nmax];

vector <int> v[nmax];

void dfsi(int p,int d)
{
    use1[p]=1;
    if (d>dmax) dmax=d,pmax=p;
    for (int i=0; i<v[p].size(); i++)
        if (!use1[v[p][i]])
            dfsi(v[p][i],d+1);
}

void dfsf(int p,int d)
{
    use2[p]=1;
    if (d>darb) darb=d;
    for (int i=0; i<v[p].size(); i++)
        if (!use2[v[p][i]])
            dfsf(v[p][i],d+1);
}

int main()
{
    fin>>n;
    for (i=1; i<n; i++)
    {
        int a,b;
        fin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfsi(1,0);
    dfsf(pmax,0);
    fout<<darb+1<<'\n';
}
