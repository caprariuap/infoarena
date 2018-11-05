#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("dragoni.in");
ofstream fout("dragoni.out");

struct viking
{
    int P,D;
};

int n,m,p,i,j,dmax[810],maxim,d[810][810];
vector <int> v[810],cost[810];
queue <viking> q;
bool use[810];

void dfs(int x)
{
    if (dmax[x]>maxim)
        maxim=dmax[x];
    use[x]=1;
    for (int i=0; i<v[x].size(); i++)
        if (!use[v[x][i]]&&cost[x][i]<=dmax[1])
            dfs(v[x][i]);
}

void p1()
{
    maxim=0;
    dfs(1);
    fout << maxim << '\n';
}

void p2()
{
    if (n==1)
    {
        fout << "0\n";
        return;
    }
    d[1][1]=0;
    viking Hiccup;
    Hiccup.P=1;
    Hiccup.D=1;
    q.push(Hiccup);
    while (!q.empty())
    {
        viking nod=q.front();
        q.pop();
        for (i=0; i<v[nod.P].size(); i++)
        {
            int vecin=v[nod.P][i];
            int dis=cost[nod.P][i];
            if (dis<=dmax[nod.D]&&(d[vecin][nod.D]==0||d[vecin][nod.D]>d[nod.P][nod.D]+dis||d[vecin][vecin]>d[nod.P][nod.D]+dis))
            {
                viking nod2;
                nod2.P=vecin;
                nod2.D=nod.D;
                if (d[vecin][nod.D]==0||d[vecin][nod.D]>d[nod.P][nod.D]+dis)
                {
                    d[vecin][nod.D]=d[nod.P][nod.D]+dis;
                    q.push(nod2);
                    nod2.D=vecin;
                    q.push(nod2);
                }
                nod2.D=nod.D;
                if (d[vecin][vecin]==0||d[vecin][vecin]>d[nod.P][nod.D]+dis)
                {
                    d[vecin][vecin]=d[nod.P][nod.D]+dis;
                    q.push(nod2);
                    nod2.D=vecin;
                    q.push(nod2);
                }
            }
        }
    }
    int minim=1100000000;
    for (i=1; i<=n; i++)
        if (d[n][i]!=0&&d[n][i]<minim)
        minim=d[n][i];
    fout << minim << '\n';
}

int main()
{
    fin >> p;
    fin >> n >> m;
    for (i=1; i<=n; i++)
        fin >> dmax[i];
    for (i=1; i<=m; i++)
    {
        int a,b,c;
        fin >> a >> b >> c;
        v[a].push_back(b);
        v[b].push_back(a);
        cost[a].push_back(c);
        cost[b].push_back(c);
    }
    if (p==1)
        p1();
    else
        p2();
}
