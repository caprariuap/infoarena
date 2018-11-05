#include <cstdio>

using namespace std;

int n,m,ppoz[1001],i,j;

int main()
{
    freopen("cautare1.in","r",stdin);
    freopen("cautare1.out","w",stdout);
    scanf("%d %d", &n, &m);
    for (i=1; i<=n; i++)
    {
        int x;
        scanf("%d", &x);
        if (ppoz[x]==0)
            ppoz[x]=i;
    }
    for (i=1; i<=m; i++)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", ppoz[x]);
    }
}
