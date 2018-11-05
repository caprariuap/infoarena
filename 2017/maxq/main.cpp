#include <fstream>

using namespace std;

ifstream fin("maxq.in");
ofstream fout("maxq.out");

struct arbint
{
    long long total,ls,rs,sum;
} arb[600010];
int n,m,i,j,a[200010];
long long maxim,s;

void build(int nod, int st, int dr)
{
    if (st==dr)
    {
        arb[nod].total=arb[nod].sum=a[st];
        arb[nod].rs=arb[nod].ls=a[st];
        return;
    }
    int mij=(st+dr)/2;
    build(2*nod,st,mij);
    build(2*nod+1,mij+1,dr);
    arb[nod].sum=arb[2*nod].sum+arb[2*nod+1].sum;
    arb[nod].ls=max(arb[2*nod].ls,arb[2*nod].sum+arb[2*nod+1].ls);
    arb[nod].rs=max(arb[2*nod+1].rs,arb[2*nod+1].sum+arb[2*nod].rs);
    arb[nod].total=arb[2*nod].rs+arb[2*nod+1].ls;
    arb[nod].total=max(arb[nod].total,max(arb[2*nod].total,arb[2*nod+1].total));
    //fout << st << ' ' << dr << ' ' << arb[nod].sum << ' ' << arb[nod].total << ' ' << arb[nod].ls << ' ' << arb[nod].rs << '\n';
}

void update(int val, int poz, int nod, int st, int dr)
{
    if (st==dr)
    {
        arb[nod].total=arb[nod].sum=val;
        arb[nod].rs=arb[nod].ls=val;
        return;
    }
    int mij=(st+dr)/2;
    if (poz<=mij)
        update(val,poz,2*nod,st,mij);
    else
        update(val,poz,2*nod+1,mij+1,dr);
    arb[nod].sum=arb[2*nod].sum+arb[2*nod+1].sum;
    arb[nod].ls=max(arb[2*nod].ls,arb[2*nod].sum+arb[2*nod+1].ls);
    arb[nod].rs=max(arb[2*nod+1].rs,arb[2*nod+1].sum+arb[2*nod].rs);
    arb[nod].total=arb[2*nod].rs+arb[2*nod+1].ls;
    arb[nod].total=max(arb[nod].total,max(arb[2*nod].total,arb[2*nod+1].total));
}

void interogare(int poz1, int poz2, int nod, int st, int dr)
{
    if (poz1<=st&&dr<=poz2)
    {
        if (s<0)
            s=0;
        maxim=max(maxim,max(arb[nod].total,s+arb[nod].ls));
        s=max(s+arb[nod].sum,arb[nod].rs);
        return;
    }
    int mij=(st+dr)/2;
    if (poz1<=mij)
        interogare(poz1,poz2,2*nod,st,mij);
    if (poz2>mij)
        interogare(poz1,poz2,2*nod+1,mij+1,dr);
}

int main()
{
    fin >> n;
    for (i=1; i<=n; i++)
        fin >> a[i];
    build(1,1,n);
    fin >> m;
    for (i=1; i<=m; i++)
    {
        int op,X,Y;
        fin >> op >> X >> Y;
        if (!op)
        {
            X++;
            update(Y,X,1,1,n);
        }
        else
        {
            maxim=-20000000100;
            s=0;
            X++;
            Y++;
            interogare(X,Y,1,1,n);
            if (maxim<0)
                maxim=0;
            fout << maxim << '\n';
        }
    }
}
