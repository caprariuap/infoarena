#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("maxflow.in");
ofstream fout("maxflow.out");

queue <int> q;
vector <int> v[1010];
int n,m,i,j,flux,minf,c[1010][1010],f[1010][1010],s,t,p[1010];

void getAP()
{
    q.push(s);
    p[s]=0;
    while (!q.empty())
    {
        int x=q.front();
        q.pop();
        for (i=0; i<v[x].size(); i++)
        {
            int vecin=v[x][i];
            if (p[vecin]==-1&&c[x][vecin]>f[x][vecin])
                q.push(vecin),p[vecin]=x;
        }
    }
}

int main()
{
    fin >> n >> m;
    s=1;
    t=n;
    for (i=1; i<=m; i++)
    {
        int a,b,cap;
        fin >> a >> b >> cap;
        v[a].push_back(b);
        v[b].push_back(a);
        c[a][b]=cap;
    }
    while (1)
    {
        for (i=1; i<=n; i++)
            p[i]=-1;
        getAP();
        if (p[t]==-1)
            break;
        for (i=0; i<v[t].size(); i++)
        {
            int nod=v[t][i],fmin=c[nod][t]-f[nod][t];
            if (p[nod]>0&&c[p[nod]][nod]>f[p[nod]][nod])
            {
                while (nod!=s)
                {
                    fmin=min(fmin,c[p[nod]][nod]-f[p[nod]][nod]);
                    nod=p[nod];
                }
                f[v[t][i]][t]+=fmin;
                f[t][v[t][i]]-=fmin;
                nod=v[t][i];
                while (nod!=s)
                {
                    f[p[nod]][nod]+=fmin;
                    f[nod][p[nod]]-=fmin;
                    nod=p[nod];
                }
                flux+=fmin;
            }
        }
    }
    fout << flux << '\n';
}
