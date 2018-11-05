#include <fstream>
#include <vector>
#include <queue>
#define nmax 355

using namespace std;

ifstream fin("fmcm.in");
ofstream fout("fmcm.out");

int n,m,s,t,i,f[nmax][nmax],c[nmax][nmax],dbf[nmax],d[nmax],reald[nmax],cost[nmax][nmax],p[nmax],fmin,flux,cm;
bool inQ[nmax];
vector <int> v[nmax];

void bellmanford()
{
    queue <int> Q;
    for (i=1; i<=n; i++)
        dbf[i]=2000000;
    dbf[s]=0;
    Q.push(s);
    inQ[s]=1;
    while (!Q.empty())
    {
        int nod=Q.front();
        Q.pop();
        inQ[nod]=0;
        for (i=0; i<v[nod].size(); i++)
        {
            int vecin=v[nod][i];
            if (c[nod][vecin])
            {
                if (dbf[nod]+cost[nod][vecin]<dbf[vecin])
                {
                    dbf[vecin]=dbf[nod]+cost[nod][vecin];
                    if (inQ[vecin]==0)
                        Q.push(vecin),inQ[vecin]=1;
                }
            }
        }
    }
}

bool dijkstra()
{
    priority_queue<pair <int, int>, vector <pair<int, int> >, greater<pair<int, int> > > H;
    for (i=1; i<=n; i++)
        d[i]=2000000,p[i]=-1;
    d[s]=0;
    reald[s]=0;
    H.push(make_pair(d[s],s));
    while (!H.empty())
    {
        int nod=H.top().second,dist=H.top().first;
        H.pop();
        if (dist>d[nod])
            continue;
        for (i=0; i<v[nod].size(); i++)
        {
            int vecin=v[nod][i];
            if (c[nod][vecin]>f[nod][vecin])
            {
                int aux=cost[nod][vecin]+dbf[nod]-dbf[vecin];
                if (dist+aux<d[vecin])
                {
                    d[vecin]=dist+aux;
                    H.push(make_pair(d[vecin],vecin));
                    reald[vecin]=reald[nod]+cost[nod][vecin];
                    p[vecin]=nod;
                }
            }
        }
    }
    if (p[t]==-1)
        return 0;
    for (i=1; i<=n; i++)
        dbf[i]=reald[i];
    fmin=1000000000;
    for (i=t; i!=s; i=p[i])
        fmin=min(fmin,c[p[i]][i]-f[p[i]][i]);
    flux+=fmin;
    cm+=fmin*reald[t];
    for (i=t; i!=s; i=p[i])
        f[p[i]][i]+=fmin,f[i][p[i]]-=fmin;
    return 1;
}

int main()
{
    fin >> n >> m >> s >> t;
    for (i=1; i<=m; i++)
    {
        int A,B,C,D;
        fin >> A >> B >> C >> D;
        v[A].push_back(B);
        v[B].push_back(A);
        cost[A][B]=D;
        cost[B][A]=-D;
        c[A][B]=C;
        c[B][A]=0;
    }
    bellmanford();
    flux=cm=0;
    while (dijkstra());
    fout << cm << '\n';
}
