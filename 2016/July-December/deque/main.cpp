#include <cstdio>
#define NMAX 5000010

using namespace std;

long long suma;
int n,k,i,j,a[NMAX],dq[NMAX],vf,bz;

FILE *fin=fopen("deque.in","r");
FILE *fout=fopen("deque.out","w");

int main()
{
    fscanf(fin,"%d%d",&n,&k);
    vf=-1;
    for (i=1; i<=n; i++)
    {
        fscanf(fin,"%d",&a[i]);
        while (bz<=vf&&a[i]<a[dq[vf]])
            vf--;
        dq[++vf]=i;
        if (i-k==dq[bz])
            bz++;
        if (i>=k)
        suma+=a[dq[bz]];
    }
    fprintf(fout,"%lld\n",suma);
}
