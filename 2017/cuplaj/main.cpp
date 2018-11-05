#include <fstream>
#include <vector>

using namespace std;

ifstream fin("cuplaj.in");
ofstream fout("cuplaj.out");

vector <int> v[10010];
int l[10010],r[10010],use[10010],i,n,m,e,cuplaj;

int pairup(int x)
{
    if (use[x])
        return 0;
    use[x]=1;
    for (int i=0; i<v[x].size(); i++)
        if (!r[v[x][i]])
        {
            l[x]=v[x][i];
            r[v[x][i]]=x;
            return 1;
        }
    for (int i=0; i<v[x].size(); i++)
        if (pairup(r[v[x][i]]))
        {
            l[x]=v[x][i];
            r[v[x][i]]=x;
            return 1;
        }
    return 0;
}

int main()
{
    fin >> n >> m >> e;
    for (i=1; i<=e; i++)
    {
        int a,b;
        fin >> a >> b;
        v[a].push_back(b);
    }
    int nok=1;
    while (nok)
    {
        nok=0;
        for (int i=1; i<=n; i++)
            if (!l[i])
                nok=nok|pairup(i);
        for (i=1; i<=n; i++)
            use[i]=0;
    }
    for (i=1; i<=n; i++)
        if (l[i]>0)
            cuplaj++;
    fout << cuplaj << '\n';
    for (i=1; i<=n; i++)
        if (l[i]>0)
            fout << i << ' ' << l[i] << '\n';
}
