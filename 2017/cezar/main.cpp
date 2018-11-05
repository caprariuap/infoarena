#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

FILE *fin=fopen("cezar.in","r");
FILE *fout=fopen("cezar.out","w");

short cost[10001];

class cmp
{
public:
    bool operator()(int a, int b)
    {
        return cost[a]>cost[b];
    }
};

long long ans;
int n,k,i,j;
priority_queue <short, vector <short>, cmp> q;
vector <short> v[10001];

int main()
{
    fscanf(fin,"%hd%hd",&n,&k);
    for (i=1; i<n; i++)
    {
        short a,b;
        fscanf(fin,"%hd%hd",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
        cost[i]=1;
    }
    cost[n]=1;
    for (i=1; i<=n; i++)
        if (v[i].size()==1)
            q.push(i);
    for (j=n-1; j>=k+1; j--)
    {
        short nod=q.top();
        q.pop();
        short nod2=v[nod][0];
        v[nod].pop_back();
        for (i=0; i<v[nod2].size()&&v[nod2][i]!=nod; i++);
        swap(v[nod2][i],v[nod2][v[nod2].size()-1]);
        v[nod2].pop_back();
        cost[nod2]+=cost[nod];
        if (v[nod2].size()==1)
            q.push(nod2);
        ans=ans+cost[nod];
    }
    fprintf(fout,"%lld",ans);
}
