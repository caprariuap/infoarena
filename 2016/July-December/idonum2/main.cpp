#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <fstream>
#define MOD 10000007

using namespace std;

ifstream fin("txt.in");
ofstream fout("txt2.out");

long long t,n,p;
long long phin[31];
long long phiN[31];
long long nr;

struct matrice
{
    long long mat[4][4];
} a;

matrice inmultire(matrice a,matrice b)
{
    int i,j,k;
    matrice rez;
    for (i=1; i<=3; i++)
        for (j=1; j<=3; j++)
        rez.mat[i][j]=0;
    for (i=1; i<=3; i++)
        for (j=1; j<=3; j++)
            for (k=1; k<=3; k++)
                (rez.mat[i][j]+=a.mat[i][k]%MOD*b.mat[k][j]%MOD)%MOD;
    return rez;
}

matrice explog(matrice a, long long pow)
{
    if (pow==1)
        return a;
    matrice k=explog(a,pow/2);
    if (pow%2)
        return inmultire(inmultire(k,k),a);
    return inmultire(k,k);
}

long long exp(int a,long long p)
{
    if (p==1) return a;
    int k=exp(a,p/2)%MOD;
    if (p%2)
        return ((k*k)%MOD)*a%MOD;
    return k%MOD*k%MOD;
}

long long euler(long long n)
{
    if (n==1) return 1;
    long long ans=1;
    long long d=2;
    int pow=0;
    while (n%2==0)
        pow++,n/=2;
    if (pow>1)
        ans*=exp(2,pow-1)%MOD;
    d=3;
    while (n>1&&d*d<=n)
    {
        pow=0;
        while (n%d==0)
            pow++,n/=d;
        if (pow>1)
            ans*=exp(d,pow-1)%MOD*(d-1)%MOD;
            else if (pow==1) ans*=(d-1);
        d+=2;
    }
    if (n>1) ans*=(n-1);
    return ans;
}

long long phi;

int main()
{
    cin>>t;
    int i;
    nr=0;
    for (i=1; i<=t; i++)
    {
        cin>>n>>p;
        bool ok=0;
        for (int j=1; j<=nr; j++)
            if (phin[j]==n)
            ok=1,phi=phiN[j];
        if (!ok)
        phi=euler(n),phin[++nr]=n,phiN[nr]=phi;
        a.mat[1][1]=a.mat[1][2]=a.mat[2][3]=a.mat[3][3]=0;
        a.mat[1][3]=a.mat[3][2]=a.mat[2][2]=(n-phi)%MOD;
        a.mat[2][1]=a.mat[3][1]=phi%MOD;
        if (p>4)
        {
            matrice rez=explog(a,p-4);
            int d01,d00,d10,d01i,d00i,d10i;
            d01i=phi*(n-phi)%MOD;
            d00i=(n-phi)*(n-phi)%MOD;
            d10i=d01i;
            d00=(rez.mat[3][2]*d10i%MOD+rez.mat[2][2]*d00i%MOD+rez.mat[1][2]*d10i%MOD)%MOD;
            d10=(rez.mat[1][3]*d01i%MOD+rez.mat[2][3]*d00i%MOD+rez.mat[3][3]*d10i%MOD)%MOD;
            long long ans=(d00+d10)%MOD*phi%MOD*phi%MOD;
            cout<<ans%MOD;
        }
        else if (p==1) cout<<'0';
        else if (p==2) cout<<phi*phi%MOD;
        else if (p==3) cout<<phi%MOD*phi%MOD*(n-phi)%MOD;
        else cout<<n%MOD*(n-phi)%MOD*phi%MOD*phi%MOD;
        cout<<'\n';
    }
}
/*
    n-phi=0=nr de numere ce nu pot forma parcele perfecte
    phi=1= nr de numere ce pot forma parcele perfecte
    sir de p elemente=> se termina in -1,-1
    p-2 nu poate fi -1=> p-2=1;
    d01[i]=d00[i-1]*phi+d10[i-1]*phi;
    d00[i]=d10[i-1]*(n-phi)+d00[i-1]*(n-phi);
    d10[i]=d01[i-1]*(n-phi);

    (d01[i] d00[i] d10[i])*(  0     0 n-phi)= (d01[i+1] d00[i+1] d10[i+1])
                           (phi n-phi     0)
                           (phi n-phi     0)
*/

