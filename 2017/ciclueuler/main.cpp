#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> v[100010];
int n,m,i,j;

void euler(int x, bool first)
{
    while (v[x].size()>0)
    {
        int y=v[x][v[x].size()-1];
        v[x].pop_back();
        for (int j=0; j<v[y].size(); j++)
            if (v[y][j]==x)
            {
                swap(v[y][j],v[y][v[y].size()-1]);
                v[y].pop_back();
                break;
            }
        euler(y, 1);
    }
    if(first)
        cout<<x<<' ';
}

int main()
{
    freopen("ciclueuler.in","r",stdin);
    freopen("ciclueuler.out","w",stdout);
    cin>>n>>m;
    for (i=1; i<=m; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (i=1; i<=n; i++)
        if (v[i].size()%2!=0)
        {
            cout << "-1\n";
            return 0;
        }
    euler(1, 0);
}
