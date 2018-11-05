#include <cstdio>

const int maxn = 50001;
const int inf = 1 << 30;

FILE *in = fopen("dijkstra.in","r"), *out = fopen("dijkstra.out","w");

struct graf
{
    int nod, cost;
    graf *next;
};

int n, m;
graf *a[maxn];
int d[maxn], h[maxn], poz[maxn], k;

void add(int where, int what, int cost)
{
    graf *q = new graf;
    q->nod = what;
    q->cost = cost;
    q->next = a[where];
    a[where] = q;
}

void read()
{
    fscanf(in, "%d %d", &n, &m);

    int x, y, z;
    for ( int i = 1; i <= m; ++i )
    {
        fscanf(in, "%d %d %d", &x, &y, &z);
        add(x, y, z);
    }
}

void swap(int x, int y)
{
    int t = h[x];
    h[x] = h[y];
    h[y] = t;
}

void upheap(int what)
{
    int tata;
    while ( what > 1 )
    {
        tata = what >> 1;

        if ( d[ h[tata] ] > d[ h[what] ] )
        {
            poz[ h[what] ] = tata;
            poz[ h[tata] ] = what;

            swap(tata, what);

            what = tata;
        }
        else
            what = 1;
    }
}

void downheap(int what)
{
    int f;
    while ( what <= k )
    {
        f = what;
        if ( (what<<1) <= k )
        {
            f = what << 1;
            if ( f + 1 <= k )
                if ( d[ h[f + 1] ] < d[ h[f] ] )
                    ++f;
        }
        else
            return;

        if ( d[ h[what] ] > d[ h[f] ] )
        {
            poz[ h[what] ] = f;
            poz[ h[f] ] = what;

            swap(what, f);

            what = f;
        }
        else
            return;
    }
}

void dijkstra_heap()
{
    for ( int i = 2; i <= n; ++i )
        d[i] = inf, poz[i] = -1;
    poz[1] = 1;

    h[++k] = 1;

    while ( k )
    {
        int min = h[1];
        swap(1, k);
        poz[ h[1] ] = 1;
        --k;

        downheap(1);

        graf *q = a[min];

        while ( q )
        {
            if ( d[q->nod] > d[min] + q->cost )
            {
                d[q->nod] = d[min] + q->cost;

                if ( poz[q->nod] != -1 )
                    upheap( poz[q->nod] );
                else
                {
                    h[++k] = q->nod;
                    poz[ h[k] ] = k;
                    upheap( k );
                }
            }
            q = q->next;
        }
    }
}

int main()
{
    read();
    dijkstra_heap();

    for ( int i = 2; i <= n; ++i )
        fprintf(out, "%d ", d[i] == inf ? 0 : d[i]);
    fprintf(out, "\n");

    return 0;
}
