#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#define nmax 1010

using namespace std;

ifstream fin("fof.in");
ofstream fout("fof.out");

int n,m;
bool use[nmax];
int d[nmax];
int f[nmax];

vector <int> a;
vector <int> v[nmax];
queue <int> q;

void bfs(int nod)
{
    q.push(nod);
    use[nod]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if (d[x]==2)
        {
            f[x]++;
            if (f[x]==1)
                a.push_back(x);
        }
        if (d[x]<2)
            for(int i=0; i<v[x].size(); i++)
            {
                if(!use[v[x][i]]||d[v[x][i]]==2)
                {
                    q.push(v[x][i]);
                    use[v[x][i]]=1;
                    d[v[x][i]]=d[x]+1;
                }
            }
    }
}

bool cmp(int a, int b)
{
    if (f[a]>f[b]||(f[a]==f[b]&&a<b))
        return 1;
    return 0;
}

int main()
{
    fin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int a,b;
        fin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i=1; i<=n; i++)
    {
        bfs(i);
        sort(a.begin(),a.end(),cmp);
        for (int j=0; j<a.size(); j++)
            fout<<a[j]<<' ';
        a.clear();
        for (int j=0; j<=n; j++)
            use[j]=f[j]=d[j]=0;
        fout<<'\n';
    }
}
