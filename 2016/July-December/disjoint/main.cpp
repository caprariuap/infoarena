#include <cstdio>
#include <vector>

using namespace std;

int n,m,i,j,p[100010],op;

vector <int> v[100010];

int compresie(int x)
{
    int rad=p[x];
    while (p[rad]!=rad)
        rad=p[rad];
    while (p[x]!=x)
    {
        v[rad].push_back(x);
        x=p[x];
    }
    return rad;
}

int radacina(int x)
{
    while (p[x]!=x)
        x=p[x];
    return x;
}

int main()
{
    freopen("disjoint.in","r",stdin);
    freopen("disjoint.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=1; i<=n; i++)
        p[i]=i;
    for (i=1; i<=m; i++)
    {
        int x,y;
        scanf("%d%d%d",&op,&x,&y);
        if (op==2)
        {
            if (compresie(x)==compresie(y))
                printf("DA\n");
            else
                printf("NU\n");
        }
        else
        {
            int xx=radacina(x);
            int yy=radacina(y);
            if (v[xx].size()<v[yy].size())
            {
                for (j=0; j<v[xx].size(); j++)
                    v[yy].push_back(v[xx][j]);
                p[xx]=yy;
            }
            else
            {
                for (j=0; j<v[yy].size(); j++)
                    v[xx].push_back(v[yy][j]);
                p[yy]=xx;
            }
        }
    }
}
