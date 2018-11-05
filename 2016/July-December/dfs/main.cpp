#include <fstream>
#include <vector>
#define nmax 100010

using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

int n,m,nr;
bool use[nmax];
vector <int> v[nmax];

void dfs(int nod)
{use[nod]=1;
for (int i=0; i<v[nod].size(); i++)
    if (!use[v[nod][i]])
    dfs(v[nod][i]);
}

int main()
{fin>>n>>m;
for (int i=1; i<=m; i++)
{int a,b;
fin>>a>>b;
v[a].push_back(b);
v[b].push_back(a);
}
for (int i=1; i<=n; i++)
    if (!use[i])
    dfs(i),nr++;
fout<<nr<<'\n';
}
