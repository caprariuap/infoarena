#include <cstdio>
#define NMAX 500010
#define DIM 10000

using namespace std;

int n,k,i,a[NMAX],dq[NMAX],vf,bz,inc,sf,maxim;

FILE *fin=fopen("secventa.in","r");
FILE *fout=fopen("secventa.out","w");

char buff[DIM];
int poz=0;

void citeste(int &numar)
{
     numar = 0;
     char semn='+';
     while (buff[poz] < '0' || buff[poz] > '9')
     {
          semn = buff[poz];
          if (++poz == DIM)
               fread(buff,1,DIM,fin),poz=0;
     }
     while ('0'<=buff[poz] && buff[poz]<='9')
     {
          numar = numar*10 + buff[poz] - '0';
          if (++poz == DIM)
               fread(buff,1,DIM,fin),poz=0;
     }
     if (semn == '-')
          numar = -numar;
}

int main()
{
    fscanf(fin,"%d%d",&n,&k);
    vf=-1;
    maxim=-2000000000;
    int poz=0;
    for (i=1; i<=n; i++)
    {
        citeste(a[i]);
        while (bz<=vf&&a[i]<a[dq[vf]])
            vf--;
        dq[++vf]=i;
        if (i-k==dq[bz])
            bz++;
        if (i>=k&&a[dq[bz]]>maxim)
        {
            maxim=a[dq[bz]];
            inc=dq[bz];
        }
    }
    int nr=inc;
    sf=inc+k-1;
    while (sf>nr&&inc>1&&a[inc-1]>=a[nr])
        inc--,sf--;
    fprintf(fout,"%d %d %d\n",inc,sf,maxim);
}
