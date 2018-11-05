#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct muchie
{
    int nod1,nod2,cost;
};

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

priority_queue <muchie,vector<muchie>,cmp> arb;

int n,k,i,j,a[50][50],nr,use[50],costcurent;

int main()
{
    cin>>n>>k;
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
        {
            cin>>a[i][j];
            muchie x;
            x.nod1=i;
            x.nod2=j;
            x.cost=a[i][j];
            if (i!=j)
                arb.push(x);
        }
    nr=n;
    while (nr>k)
    {
        while (use[arb.top().nod1]||use[arb.top().nod2])
            arb.pop();
        muchie x;
        x=arb.top();
        arb.pop();
        costcurent+=x.cost;
        use[x.nod1]=1;
        nr--;
    }
    cout<<costcurent<<'\n';
}
