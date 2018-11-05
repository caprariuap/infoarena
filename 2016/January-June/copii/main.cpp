#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("copii.in");
ofstream fout("copii.out");

int n,i,j,nrsol,nc;
int v[15];
bool a[15][15];

void verifica()
{bool r[15][15];
int i,j;
if (nc<=1) return;
for (i=1; i<=nc; i++)
    {for (j=1; j<=nc; j++)
    r[i][j]=0;
    r[i][i]=1;}
for (i=1; i<=n; i++)
    for (j=1; j<=n; j++)
    if (a[i][j]==1&&j!=i&&v[i]!=v[j])  r[v[i]][v[j]]=1;
    for (i=1; i<=nc; i++)
    for (j=1; j<=nc; j++)
        if (r[i][j]==0) return;
nrsol++;
}

void generare(int k)
{
    if (k==n+1) verifica();
    else
    {
        for (int j=1; j<=nc; j++)
        {
            v[k]=j;
            generare(k+1);
        }
        nc++;
        v[k]=nc;
        generare(k+1);
        nc--;
    }
}

int main()
{
    fin>>n;char c;
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
            fin >> c, a[i][j]=c-'0';
    generare(1);
    fout<<nrsol;
}
