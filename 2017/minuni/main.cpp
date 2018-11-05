#include <cstdio>
#include <algorithm>
#define mmax 100005

using namespace std;

FILE *fin=fopen("minuni.in","r");
FILE *fout=fopen("minuni.out","w");

struct eveniment
{
    long long poz,index;
    bool open;
} ev[2*mmax];

long long n,m,i,j,ans[2*mmax],ai[8*mmax],v[2*mmax],aimax[8*mmax];

class cmp
{
public:
    bool operator()(eveniment A, eveniment B)
    {
        return A.poz<B.poz;
    }
};

void actualizare( long long poz,  long long val,  long long nod,  long long st,  long long dr)
{
    if (st==dr)
    {
        ai[nod]=val;
        aimax[nod]=v[val];
        return;
    }
    long long mid=(st+dr)/2;
    if (poz<=mid)
        actualizare(poz,val,2*nod,st,mid);
    else
        actualizare(poz,val,2*nod+1,mid+1,dr);
    if (aimax[2*nod]>aimax[2*nod+1])
        ai[nod]=ai[2*nod],aimax[nod]=aimax[2*nod];
    else
        ai[nod]=ai[2*nod+1],aimax[nod]=aimax[2*nod+1];
}

long long maxim,nr;

void query( long long poz1,  long long poz2,  long long nod,  long long st,  long long dr)
{
    if (poz1<=st&&dr<=poz2)
    {
        if (aimax[nod]>maxim)
            maxim=aimax[nod],nr=ai[nod];
        return;
    }
    long long mid=(st+dr)/2;
    if (poz1<=mid)
        query(poz1,poz2,2*nod,st,mid);
    if (poz2>mid)
        query(poz1,poz2,2*nod+1,mid+1,dr);
}

int main()
{
    fscanf(fin,"%lld%lld",&n,&m);
    for (i=1; i<=m; i++)
    {
        fscanf(fin,"%lld%lld",&v[i],&v[i+m]);
        ev[i].poz=v[i];
        ev[i].open=1;
        ev[i].index=i;
        ev[m+i].poz=v[i+m];
        ev[m+i].open=0;
        ev[m+i].index=i;
    }
    sort(ev+1,ev+2*m+1,cmp());
//    for (i=1; i<=2*m; i++)
//        fout << ev[i].poz << ' ' << ev[i].open << ' ' << ev[i].index << '\n';
    for (i=1; i<=8*m; i++)
        ai[i]=0,aimax[i]=0;
    for (i=1; i<=2*m; i++)
        if (ev[i].open)
        {
            maxim=0;
            nr=0;
            query(1,ev[i].index,1,1,2*m);
            if (nr>0)
            {
                long long a,b,x,y;
                x=ev[i].poz;
                y=v[ev[i].index+m];
                a=v[nr];
                b=v[nr+m];
//                if (a>=x||b<=y)
//                    fout << x << ' ' << y << ' ' << a << ' ' << b << '\n';
                ans[ev[i].index]=x*(b-y)+(x-a)*(n-b+1);
                //fout << x << ' ' << y << ' ' << a << ' ' << b << '\n';
            }
            else
                ans[ev[i].index]=ev[i].poz*(n-v[ev[i].index+m]+1);
            actualizare(ev[i].index,ev[i].index,1,1,2*m);
        }
        else
        {
            actualizare(ev[i].index,0,1,1,2*m);
        }
    for (i=1; i<=m; i++)
        fprintf(fout,"%lld\n",ans[i]);
    return 0;
}
