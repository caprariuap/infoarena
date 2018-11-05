#include <fstream>
#include <vector>
#define nmax 9000

using namespace std;

ifstream fin("felinare.in");
ofstream fout("felinare.out");

vector <int> v[nmax];
int n,m,e,i,j,l[nmax],r[nmax],hl[nmax],hr[nmax],cuplaj;
bool use[nmax];

bool pairup(int x)
{
    if (use[x])
        return 0;
    use[x]=1;
    for (int i=0; i<v[x].size(); i++)
        if (!l[v[x][i]])
        {
            l[v[x][i]]=x;
            r[x]=v[x][i];
            hl[x]=1;
            return 1;
        }
    for (int i=0; i<v[x].size(); i++)
        if (pairup(l[v[x][i]]))
        {
            l[v[x][i]]=x;
            r[x]=v[x][i];
            hl[x]=1;
            return 1;
        }
    return 0;
}

void aprinde(int x)
{
    for (int i=0; i<v[x].size(); i++)
        if (!hr[v[x][i]])
        {
            hr[v[x][i]]=1;
            hl[l[v[x][i]]]=0;
            aprinde(l[v[x][i]]);
        }
}

int main()
{
    fin >> n >> e;
    m=n;
    for (i=1; i<=e; i++)
    {
        int A,B;
        fin >> A >> B;
        v[A].push_back(B);
    }
    bool nok=1;
    while (nok)
    {
        nok=0;
        for (i=1; i<=n; i++)
            if (!r[i])
                nok|=pairup(i);
        for (i=1; i<=n; i++)
            use[i]=0;
    }
    for (i=1; i<=n; i++)
        if (r[i])
            cuplaj++;
    fout << 2*n-cuplaj << '\n';
    for (i=1; i<=n; i++)
        if (!hl[i])
            aprinde(i);
    for (i=1; i<=n; i++)
    {
        int pr=0;
        if (!hl[i])
            pr++;
        if (!hr[i])
            pr+=2;
        fout << pr << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
