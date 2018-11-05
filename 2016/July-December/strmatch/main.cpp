#include <cstdio>
#include <cstring>
#include <iostream>
#define minim(a,b) a<b ? a : b

using namespace std;

char a[2000010],b[2000010];

int n,m,i,j,urm[2000010],poz[1010],nr;

void prefix()
{
    int k=0,i;
    urm[1]=0;
    for (i=2; i<=n; i++)
    {
        while (k>0&&a[k+1]!=a[i])
            k=urm[k];
        if (a[k+1]==a[i])
            k++;
        urm[i]=k;
    }
}

void kmp()
{
    int q,i;
    q=0;
    for (i=1; i<=m; i++)
    {
        while (q>0&&a[q+1]!=b[i])
            q=urm[q];
        if (a[q+1]==b[i])
            q++;
        if (q==n)
        {
            q=urm[n];
            nr++;
            if (nr<=1000)
                poz[nr]=i-n;
        }
    }

}

int main()
{
    freopen("strmatch.in","r",stdin);
    freopen("strmatch.out","w",stdout);
    scanf("%s%s",&a,&b);
    for (i=0; a[i]!='\0'; i++)
        n++;
    for (i=0; b[i]!='\0'; i++)
        m++;
    for (i=n; i; i--) a[i]=a[i-1];
    for (i=m; i; i--) b[i]=b[i-1];
    prefix();
    kmp();
    printf("%d\n",nr);
    nr=minim(nr,1000);
    for (i=1; i<=nr; i++)
        printf("%d ",poz[i]);
}

