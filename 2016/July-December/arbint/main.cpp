#include <cstdio>
#include <iostream>
#define maxim(a,b) a>b ? a : b
#define NMAX 500000

using namespace std;

FILE *fin=fopen("arbint.in","r");
FILE *fout=fopen("arbint.out","w");

int arbint[NMAX],i,j,n,m,a,b,maxi;

void actualizare(int nod, int st, int dr)
{
    if (st==dr)
    {
        arbint[nod]=b;
        return;
    }
    int mij=(st+dr)/2;
    if (a<=mij)
        actualizare(2*nod,st,mij);
    else
        actualizare(2*nod+1,mij+1,dr);
    arbint[nod]=maxim(arbint[2*nod],arbint[2*nod+1]);
}

void interogare(int nod, int st, int dr)
{
    if (st>=a&&dr<=b)
    {
        if (maxi<arbint[nod])
        maxi=arbint[nod];
        return;
    }
    int mij=(st+dr)/2;
    if (a<=mij)
        interogare(2*nod,st,mij);
    if (mij<b)
        interogare(2*nod+1,mij+1,dr);
}

int main()
{
    fscanf(fin,"%d%d",&n,&m);
    for (i=1; i<=n; i++)
    {
        int x;
        fscanf(fin,"%d",&x);
        a=i;
        b=x;
        actualizare(1,1,n);
    }
    for (i=1; i<=m; i++)
    {
        bool op;
        fscanf(fin,"%d%d%d",&op,&a,&b);
        if (op)
        {
            actualizare(1,1,n);
        }
        else
            {
                maxi=-1;
                interogare(1,1,n);
                fprintf(fout,"%d\n",maxi);
            }
    }
}
