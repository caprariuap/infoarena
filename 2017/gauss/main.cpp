#include <cstdio>
#include <iomanip>
#define eps 0.0000001

using namespace std;

FILE *fin=fopen("gauss.in","r");
FILE *fout=fopen("gauss.out","w");

int n,m,i,j,k;
double a[305][305],aux,ans[305];

int main()
{
    fscanf(fin,"%d%d",&n,&m);
    for (i=1; i<=n; i++)
        for (j=1; j<=m+1; j++)
            fscanf(fin,"%lf",&a[i][j]);
    i=1;
    j=1;
    while (i<=n&&j<=m)
    {
        for (k=i; k<=n; k++)
            if (a[k][j]<eps||a[k][j]>-eps)
                break;
        if (k==n+1)
        {
            j++;
            continue;
        }
        if (k!=i)
            for (int h=1; h<=m+1; h++)
            {
                double aux=a[i][h];
                a[i][h]=a[k][h];
                a[k][h]=aux;
            }
        for (int h=j+1; h<=m+1; h++)
            a[i][h]/=a[i][j];
        a[i][j]=1;
        for (int g=i+1; g<=n; g++)
        {
            for (int h=j+1; h<=m+1; h++)
                a[g][h]=a[g][h]-a[i][h]*a[g][j];
            a[g][j]=0;
        }
        i++;
        j++;
    }
    for (i=n; i; i--)
        for (j=1; j<=m+1; j++)
            if (a[i][j]>eps||a[i][j]<-eps)
            {
                if (j==m+1)
                {
                    fprintf(fout,"Imposibil\n");
                    return 0;
                }
                ans[j]=a[i][m+1];
                for (int g=j+1; g<=m; g++)
                    ans[j]=ans[j]-a[i][g]*ans[g];
                break;
            }
    for (i=1; i<=m; i++)
    fprintf(fout,"%0.10lf ",ans[i]);
    fclose(fin);
    fclose(fout);
}
