#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("ubuntzei.in");
ofstream fout("ubuntzei.out");

struct localitate{
int nod,conf;};

int n,m,k,i,j,pr[2017],epr[2017],s;
vector <int> v[2017],c[2017];

int main()
{
    fin >> n >> m >> k;
    for (i=1; i<=k; i++)
        fin >> pr[i],epr[pr[i]]=i,s=s+(1<<i);
    for (i=1; i<=m; i++)
    {
        int a,b,c;
        fin >> a >> b >> c;
        v[a].push_back(b);
        cost[a].push_back(c);
        v[b].push_back(a);
        cost[b].push_back(c);
    }
    for (i=0; i<v[1].size(); i++)
    {
        localitate x;
        x.nod=v[1][i];
        x.conf=epr[i];
        q.push(x);
    }
    while (!q.empty())
    {
        localitate x=q.top();
        q.pop();
        for (i=0; i<v[x.nod].size(); i++)
        {
            int cnf=x.conf+epr[v[x.nod][i]];
            if (costminim[v[x.nod][i]][cnf]>costminim[x.nod][x.conf]+cost[x.nod][i])
            {
                localitate y;
                y.nod=v[x.nod][i];
                y.conf=cnf;
                costminim[y.nod][y.conf]=costminim[x.nod][x.conf]+cost[x.nod][i];
                q.push(y);
            }
        }
    }
    fout << costminim[n][s];
}
