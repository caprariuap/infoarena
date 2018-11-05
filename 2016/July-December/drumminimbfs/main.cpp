#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m,i,j;

vector <int> v[1000000],cost[1000000];
int costminim[1000000];
bool use[1000000];

void dfs(int nod,int costcurent)
{
    costminim[nod]=costcurent;
    use[nod]=1;
    for(int i=0;i<v[nod].size();i++)
        if(!use[v[nod][i]]||costcurent+cost[nod][i]<costminim[v[nod][i]])
            dfs(v[nod][i],costcurent+cost[nod][i]);
}


int main()
{
    cin>>n>>m;
    for (i=1; i<=m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(b);
        cost[a].push_back(c);
        v[b].push_back(a);
        cost[b].push_back(c);
    }
    dfs(1,0);
    for (i=1; i<=n; i++)
        cout<<costminim[i]<<'\n';
    return 0;
}
