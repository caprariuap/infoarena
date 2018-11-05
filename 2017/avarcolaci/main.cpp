#include <cstdio>

using namespace std;

FILE *fin=fopen("avarcolaci.in","r");
FILE *fout=fopen("avarcolaci.out","w");

int n,i,maj[20];

int main()
{
    int T;
    fscanf(fin,"%d",&T);
    while (T)
    {
        fscanf(fin,"%d",&n);
        int k;
        k=0;
        for (i=1; i<=2*n; i++)
        {
            int x;
            fscanf(fin,"%d",&x);
            if (!k)
            {
                maj[T]=x;
                k=1;
            }
            else if (maj[T]==x)
                k++;
            else
                k--;
        }
        T--;
    }
    fclose(fin);
    fopen("avarcolaci.in","r");
    fscanf(fin,"%d",&T);
    while (T)
    {
        int nr=0;
        fscanf(fin,"%d",&n);
        for (i=1; i<=2*n; i++)
        {
            int x;
            fscanf(fin,"%d",&x);
            if (x==maj[T])
                nr++;
        }
        if (nr>n)
            fprintf(fout,"%d\n",maj[T]);
        else
            fprintf(fout,"Mozart\n");
        T--;
    }
}
