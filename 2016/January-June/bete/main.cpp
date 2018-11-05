#include <fstream>
#define MAX 150

using namespace std;


ifstream fin("bete.in");
ofstream fout("bete.out");

int n,g;
int p[MAX],w[MAX];
int d[MAX][MAX];
int i,j;
int ok,poz;
int hmm[MAX][MAX];
int sol[MAX];

int main()
{
    fin>>n>>g;
    for (i=1; i<=n; i++)
        fin>>w[i];
    for (i=1; i<=n; i++)
        for (j=g; j; j--)
        {
            d[i][j]=d[i-1][j];
            hmm[i][j]=hmm[i-1][j];
            if (w[i]<=j&&d[i-1][j-w[i]]+w[i]>d[i][j]) d[i][j]=d[i-1][j-w[i]]+w[i],hmm[i][j]=i;
        }
    for (i=1; i<=n; i++) if (d[i][g]==g)
        {
            ok=1;
            poz=i;
            break;
        }
    if (!ok) fout<<"NU";
    else
    {
        fout<<"DA"<<'\n';
        poz=i;
        int nrmax=0;
        while (poz!=0)
        {
            g-=w[poz];
            sol[++nrmax]=poz;
            poz=hmm[poz-1][g];
        }
        fout<<nrmax<<'\n';
        for (i=nrmax; i; i--) fout<<sol[i]<<' ';
    }
    fout<<'\n';
}
