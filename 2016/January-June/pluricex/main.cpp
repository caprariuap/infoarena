#include <fstream>

using namespace std;

ifstream fin("pluricex.in");
ofstream fout("pluricex.out");

short n,m,d,elevi[24][12],sol[10];
bool mat[12];

bool verificare()
{
    int i,j;
    for (i=1; i<=d; i++) mat[i]=0;
    for (i=1; i<=m; i++)
    {
        for (j=1; j<=elevi[sol[i]][0]; j++)
            mat[elevi[sol[i]][j]]=1;
    }
    for (i=1; i<=d; i++)
        if (!mat[i]) return 0;
    return 1;
}

void gencomb(int k)
{
    if (k-1==m) {if (verificare())
         {for (int i=1; i<=m; i++)
        fout<<sol[i]<<' ';
    fout<<'\n';}
    }

    else
    {
        int i;
        for (i=sol[k-1]+1; i<=n-m+k; i++)
            sol[k]=i,gencomb(k+1);
    }
}

int main()
{
    fin>>n>>m>>d;
    int x,i,j;
    for (i=1; i<=n; i++)
    {
        fin>>elevi[i][0];
        for (j=1; j<=elevi[i][0]; j++)
            fin>>elevi[i][j];
    }
    gencomb(1);
}
