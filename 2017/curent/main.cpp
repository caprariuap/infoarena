#include <fstream>
#include <vector>
#include <algorithm>
#define nmax 100100
#define pu(x) (x^(x-1)&x)

using namespace std;

ifstream fin("curent.in");
ofstream fout("curent.out");

vector <int> v[nmax];
int n,p[nmax],use[nmax],i,m,t;
int sum[4*nmax],ars[4*nmax],euler[nmax],index[nmax];

struct eveniment
{
    int a,b,op;
} ev[2*nmax];


void actualizare(int a, int val, int nod, int st, int dr)
{

}

int interogare(int a, int b, int nod, int st, int dr)
{
    if (b<st||a>dr)
        return 0;
    int mid=(st+dr)/2;
    if (st!=dr)
    {
        lazy[2*nod]+=lazy[nod];
        lazy[2*nod+1]+=lazy[nod];
        sum[nod]=sum[2*nod]+sum[2*nod+1]+lazy[2*nod]*(mid-st+1)+lazy[2*nod+1]*(dr-mid);
        lazy[nod]=0;
    }
    else
    {
        sum[nod]+=lazy[nod];
        lazy[nod]=0;
        return sum[nod];
    }
    if (a<=st&&dr<=b)
        return sum[nod];
    int ret=0;
    ret=interogare(a,b,2*nod,st,mid)+interogare(a,b,2*nod+1,mid+1,dr);
    return ret;
}

int NR;

void dfs(int x)
{
    use[x]=1;
    for (int i=0; i<v[x].size(); i++)
        if (!use[v[x][i]])
        {
            dfs(v[x][i]);
            use[x]+=use[v[x][i]];
        }
    euler[++NR]=x;
    index[x]=NR;
}

class cmp
{
public:
    bool operator()(eveniment A, eveniment B)
    {
        return (A.a<B.a||(A.a==B.a&&A.op>B.op));
    }
};

int main()
{
    fin >> n;
    for (i=2; i<=n; i++)
    {
        fin >> p[i];
        v[p[i]].push_back(i);
    }
    dfs(1);
//    for (i=1; i<=n; i++)
//        fout << use[i] << ' ';
    fin >> m;
    for (i=1; i<=m; i++)
        fin >> ev[i].a >> ev[i].b >> ev[i].op;
    fin >> t;
    int nr=m;
    for (i=1; i<=t; i++)
    {
        fin >> ev[++nr].a;
        ev[nr].op=-1;
    }
    sort(ev+1,ev+nr+1,cmp());
    for (i=1; i<=4*nmax; i++)
        ai[i]=1;
    for (i=1; i<=nr; i++)
    {
        if (ev[i].op==0)
        {
            update(ev[i].b,0,1,1,n);
        }
        else if (ev[i].op==1)
        {
            update(ev[i].b,1,1,1,n);
        }
        else
        {
            fout << n-query() << '\n';
        }
    }
    fin.close();
    fout.close();
    return 0;
}
