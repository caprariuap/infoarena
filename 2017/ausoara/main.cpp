#include <cstdio>
#define nmax 105
#define mmax 1005

using namespace std;

FILE *fin=fopen("ausoara.in","r");
FILE *fout=fopen("ausoara.out","w");

int n,i,j,m[nmax],a[nmax][mmax],ind[nmax],ans[mmax],nr;

int main()
{
    fscanf(fin,"%d",&n);
    for (i=1; i<=n; i++)
    {
        fscanf(fin,"%d",&m[i]);
        for (j=1; j<=m[i]; j++)
            fscanf(fin,"%d",&a[i][j]);
    }
    for (i=1; i<=n; i++)
        ind[i]=1;
    bool nok=0;
    while (1)
    {
        int maxim=0,poz=0;
        for (i=1; i<=n; i++)
        {
            if (a[i][ind[i]]>maxim)
                maxim=a[i][ind[i]],poz=i;
            if (ind[i]>m[i])
            {
                nok=1;
                break;
            }
        }
        if (nok)
            break;
        for (i=1; i<=n; i++)
        {
            while (a[i][ind[i]]<maxim&&ind[i]<=m[i])
                ind[i]++;
            if (ind[i]==m[i]+1)
            {
                nok=1;
                break;
            }
        }
        if (nok)
            break;
        bool ok=1;
        for (i=1; i<=n; i++)
            if (a[i][ind[i]]!=maxim)
                ok=0;
        if (ok)
        {
            ans[++nr]=maxim;
            for (i=1; i<=n; i++)
                ind[i]++;
        }
        else
            ind[poz]++;
    }
    fprintf(fout,"%d ",nr);
    for (j=1; j<=nr; j++)
        fprintf(fout,"%d ",ans[j]);
    fprintf(fout,"\n");
    fclose(fin);
    fclose(fout);
    return 0;
}
