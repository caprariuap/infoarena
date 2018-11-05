#include <cstdio>
#include <vector>

using namespace std;

int n,m,i,j,k;

struct graf
{
    int nod,cost;
    graf *next;
} *g[50010];

int poz[50010],h[50010],d[50010];

void downheap(int y)
{
    int x;
    while (y<=k)
    {
        x=y;
        if (y*2<=k)
        {
            x=y*2;
            if (x+1<=k)
                if (d[h[x+1]]<d[h[x]])
                    x++;
        }
        else return;
        if (d[h[y]]>d[h[x]])
        {
            poz[h[y]]=x;
            poz[h[x]]=y;
            swap(h[x],h[y]);
            y=x;
        }
        else return;
    }
}

void upheap(int y)
{
    int x;
    while (y>1)
    {
        x=y/2;
        if (d[h[x]]>d[h[y]])
        {
            poz[h[x]]=y;
            poz[h[y]]=x;
            swap(h[x],h[y]);
            y=x;
        }
        else y=1;
    }
}

int main()
{
    freopen("dijkstra.in","r",stdin);
    freopen("dijkstra.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=1; i<=m; i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        graf *q=new graf;
        q->nod=b;
        q->cost=c;
        q->next=g[a];
        g[a]=q;
    }
    for (i=2; i<=n; i++)
        d[i]=100000000,poz[i]=-1;
    h[++k]=1;
    poz[1]=1;
    while (k)
    {
        int minim=h[1];
        swap(h[1],h[k]);
        poz[h[1]]=1;
        k--;
        downheap(1);
        graf *q=g[minim];
        while (q)
        {
            if (d[q->nod]>d[minim]+q->cost)
            {
                d[q->nod]=d[minim]+q->cost;
                if (poz[q->nod]==-1)
                {
                    h[++k]=q->nod;
                    poz[h[k]]=k;
                    upheap(k);
                }
                else upheap(poz[q->nod]);
            }
            q=q->next;
        }
    }
    for (i=2; i<=n; i++)
        printf("%d ", d[i]==100000000 ? 0 : d[i]);
}
