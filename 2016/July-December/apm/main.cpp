#include <fstream>
#include <vector>
#include <queue>
#include <cstdio>
#define nmax 200010
#define mmax 400010

using namespace std;

int n,m,i,j;
vector <int> v[nmax],cost[nmax];
int nr,costcurent;
struct arbore{int a,b;} arbp[mmax];
struct muchie{int nod1,nod2,cost;};
bool use[nmax];

class cmp
{
public:
bool operator()(muchie &a, muchie &b)
{
    if (a.cost<b.cost)
        return 0;
    return 1;
}
};
priority_queue <muchie, vector<muchie>, cmp> arb;

int main()
{
    freopen("apm.in","r",stdin);
    freopen("apm.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=1; i<=m; i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v[a].push_back(b);
        cost[a].push_back(c);
        v[b].push_back(a);
        cost[b].push_back(c);
    }
    int nrm=0;
    nr++;
    use[1]=1;
    for (i=0; i<v[1].size(); i++)
    {
        muchie x;
        x.nod1=1;
        x.nod2=v[1][i];
        x.cost=cost[1][i];
        arb.push(x);
    }
    while (nr<n)
    {
        while (use[arb.top().nod1]&&use[arb.top().nod2])
            arb.pop();
        muchie x;
        x=arb.top();
        arb.pop();
        nrm++;
        arbp[nrm].a=x.nod1;
        arbp[nrm].b=x.nod2;
        int nod=x.nod1;
        if (use[x.nod1])
            nod=x.nod2;
        use[nod]=1;
        for (i=0; i<v[nod].size(); i++)
        {
            muchie y;
            y.nod1=nod;
            y.nod2=v[nod][i];
            y.cost=cost[nod][i];
            if (!use[y.nod2])
            arb.push(y);
        }
        nr++;
        costcurent+=x.cost;
    }
    printf("%d\n%d\n",costcurent,nrm);
    for (i=1; i<=nrm; i++)
        printf("%d %d\n",arbp[i].a,arbp[i].b);
}

/// Foloseste set pentru o solutie mai rapida
