#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("reinvent.in");
ofstream fout("reinvent.out");

queue <int> q;
vector <int> v[100010];
int n,m,i,j,x,d[100010],rad[100010];

int main()
{
    fin >> n >> m >> x;
    for (i=1; i<=m; i++)
    {
        int a,b;
        fin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (i=1; i<=x; i++)
    {
        int X;
        fin >> X;
        q.push(X);
        rad[X]=X;
    }
    while (!q.empty())
    {
        int nod=q.front();
        q.pop();
        for (i=0; i<v[nod].size(); i++)
        {
            int vecin=v[nod][i];
            if (rad[vecin]==0)
            {
                rad[vecin]=rad[nod];
                d[vecin]=d[nod]+1;
                q.push(vecin);
            }
            else if(rad[vecin]!=rad[nod])
            {
                //fout << vecin << ' ' << nod << ' ' << rad[vecin] << ' ' << rad[nod] << ' ' << d[vecin] << ' ' << d[nod] << '\n';
                fout << d[vecin]+d[nod]+1 << '\n';
                return 0;
            }
        }
    }
}
