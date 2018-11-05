#include <cstdio>
#include <vector>
#define nmax 50010

using namespace std;

FILE *fin=fopen("secv2.in","r");
FILE *fout=fopen("secv2.out","w");

long long n,k,s,minim[nmax],maxim,sf,st,inc[nmax],i,a;

int main()
{
    maxim=-1000000000;
    fscanf(fin,"%lld%lld",&n,&k);
    for (i=1; i<=n; i++)
    {
        fscanf(fin,"%lld",&a);
        s+=a;
        minim[i]=minim[i-1];
        inc[i]=inc[i-1];
        if (i>=k)
        if (s-minim[i-k]>maxim)
        {
            maxim=s-minim[i-k];
            sf=i;
            st=inc[i-k]+1;
        }
        if (s<minim[i])
        {
            inc[i]=i;
            minim[i]=s;
        }
    }
    fprintf(fout,"%lld %lld %lld\n",st,sf,maxim);
}
