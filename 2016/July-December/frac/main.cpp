#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("frac.in");
ofstream fout("frac.out");

long long n,p,st,dr,i,j,divizori[5000],nr;

void descompunere(long long n)
{
    if (n%2==0)
        divizori[++nr]=2;
    while (n%2==0)
        n/=2;
    i=3;
    while (n>1)
    {
        if (n%i==0)
        {
            divizori[++nr]=i;
            while (n%i==0&&n>1)
                n/=i;
        }
        i+=2;
    }
}

long long ans(long long m)
{
    long long rez=m;
    long long pow=(1<<nr)-1;
    for (i=1; i<=pow; i++)
    {
        int nrbiti=0;
        long long aux=m;
        for (j=1; j<=nr; j++)
        {
            if ((1<<(j-1)&i)>0)
                aux/=divizori[j],nrbiti++;
        }
        if (nrbiti%2==1)
            rez-=aux;
        else
            rez+=aux;
    }
    return rez;
}

int main()
{
    fin >> n >> p;
    descompunere(n);
    st=1;
    dr=9000000000000000000;
    while (st<dr)
    {
        long long m=(st+dr)/2;
        long long k=ans(m);
        if (k==p)
        {
            dr=m;
        }
        else if (k>p)
            dr=m-1;
        else
            st=m+1;
    }
    fout << st << '\n';
}
