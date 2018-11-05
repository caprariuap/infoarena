#include <fstream>
#include <queue>
#include <vector>
#define nmax 100010

using namespace std;

ifstream fin("bfs.in");
ofstream fout("bfs.out");

int n,m,s;
int d[nmax];
bool use[nmax];

queue <int> c;
vector <int> v[nmax];

void bfs()
{
    c.push(s);
    use[s]=1;
    while (!c.empty())
    {
        int x=c.front();
        c.pop();
        for (int i=0; i<v[x].size(); i++)
        {
            if (!use[v[x][i]])
            {
                c.push(v[x][i]);
                use[v[x][i]]=1;
                d[v[x][i]]=d[x]+1;
            }
        }
    }
}

int main()
{fin>>n>>m>>s;
for (int i=1; i<=m; i++)
{int a,b;
fin>>a>>b;
v[a].push_back(b);
}
bfs();
for (int i=1; i<=n; i++)
    if (d[i]||i==s)
    fout<<d[i]<<' ';
    else fout<<-1<<' ';
fout<<'\n';
}
