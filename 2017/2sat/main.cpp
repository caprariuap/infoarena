#include <cstdio>
#include <vector>
#define nmax 100010
#define mmax 200010

using namespace std;

FILE *fin=fopen("2sat.in","r");
FILE *fout=fopen("2sat.out","w");

vector <int> v[2*nmax],vt[2*nmax];
int n,m,i,j,postordine[2*nmax],nr;
bool used[2*nmax],posibil,val[2*nmax];

int non(int x)
{
    if (x<=n)
        return n+x;
    return x-n;
}

void sortt(int x)
{
    used[x]=1;
    for (int i=0; i<v[x].size(); i++)
        if (!used[v[x][i]])
            sortt(v[x][i]);
    postordine[++nr]=x;
}

void revdfs(int x)
{
    if (val[x])
        posibil=0;
    used[x]=0;
    val[non(x)]=1;
    for (int i=0; i<vt[x].size(); i++)
        if (used[vt[x][i]])
            revdfs(vt[x][i]);
}

int main()
{
    posibil=1;
    fscanf(fin,"%d%d",&n,&m);
    for (i=1; i<=m; i++)
    {
        int x,y;
        fscanf(fin,"%d%d",&x,&y);
        if (x<0)
            x=non(-x);
        if (y<0)
            y=non(-y);
        v[non(x)].push_back(y);
        v[non(y)].push_back(x);
        vt[x].push_back(non(y));
        vt[y].push_back(non(x));
    }
    for (i=1; i<=2*n; i++)
        if (!used[i])
            sortt(i);
    for (i=2*n; i; i--)
        if (used[postordine[i]]&&used[non(postordine[i])])
            revdfs(postordine[i]);
    if (posibil==0)
    {
        fprintf(fout,"-1\n");
        return 0;
    }
    for (i=1; i<=n; i++)
        fprintf(fout,"%d ",val[i]);
    fprintf(fout,"\n");
}
