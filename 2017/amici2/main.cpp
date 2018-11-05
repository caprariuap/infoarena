#include <fstream>
#include <vector>
#include <cstring>
#include <queue>
#define nmax 21212

using namespace std;

ifstream fin("amici2.in");
ofstream fout("amici2.out");

vector <int> v[nmax];
int n,m,i,j,T;

pair <int, int> bfs(int start)
{
    queue <int> q;
    int dist[nmax];
    memset(dist,0,sizeof(dist));
    q.push(start);
    while (!q.empty())
    {
        int nod=q.front();
        q.pop();
        for (int i=0; i<v[nod].size(); i++)
            if ((dist[v[nod][i]]==0&&v[nod][i]!=start)||dist[v[nod][i]]>dist[nod]+1)
            {
                dist[v[nod][i]]=dist[nod]+1;
                q.push(v[nod][i]);
            }
    }
    int maxim=-1,poz;
    for (i=1; i<=n; i++)
        if (dist[i]>maxim)
            maxim=dist[i],poz=i;
    return make_pair(poz,maxim);
}

void solve()
{
    fin >> n >> m;
    for (i=1; i<=n; i++)
        v[i].clear();
    for (i=1; i<=m; i++)
    {
        int A,B;
        fin >> A >> B;
        v[A].push_back(B);
        v[B].push_back(A);
    }
    int dia=bfs(bfs(1).first).second;
    i=1;
    int ans=0;
    while (i<dia)
        i=(i<<1),ans++;
    fout << ans << '\n';
}

int main()
{
    fin >> T;
    while (T--)
        solve();
}
