#include <cstdio>
#include <vector>

using namespace std;

FILE *fin=fopen("biperm.in","r");
FILE *fout=fopen("biperm.out","w");

int n,a[10100][5],i,j,f[10100],s[10100],nrp,nod;

vector <int> v[10100],from[10100];
int use[10100];

void dfs(int x)
{
    use[x]=nrp;
    for (int i=0; i<v[x].size(); i++)
        if (!use[v[x][i]]||(v[x][i]==nod))
            dfs(v[x][i]);
    for (int i=0; i<from[x].size(); i++)
        if (!use[from[x][i]])
            dfs(from[x][i]);
}

int ro,soc;

int main()
{
    fscanf(fin,"%d",&n);
    for (j=0; j<2; j++)
        for (i=1; i<=n; i++)
        {
            fscanf(fin,"%d",&a[i][j]);
            a[i][j+2]=a[i][j];
            if (f[a[i][j]])
            {
                s[a[i][j]]=i;
            }
            else
                f[a[i][j]]=i;
        }
    for (i=1; i<=n; i++)
    {
        v[a[i][0]].push_back(a[i][1]);
        from[a[i][1]].push_back(a[i][0]);
    }
    int minim=0,p,q;
    for (i=1; i<=n; i++)
    {
        if(a[i][0]==a[i][1])continue;
        if(use[i])continue;
        ro=0;
        p=i;
        nrp++;
        j=a[i][0];
        while (1)
        {
            use[p]=1;
            j=a[p][0]+a[p][1]-j;
            q=f[j]+s[j]-p;
            if(q==i)break;
            if(a[p][1]!=a[q][0])
            {
                swap(a[q][0],a[q][1]);
                ro++;
            }
            p=q;

        }
        soc=0;
        p=i;
        swap(a[p][2],a[p][3]);
        soc++;
        j=a[i][2];
        while (1)
        {
            j=a[p][2]+a[p][3]-j;
            q=f[j]+s[j]-p;
            if(q==i)break;
            if(a[p][3]!=a[q][2])
            {
                swap(a[q][3],a[q][2]);
                soc++;
            }
            p=q;

        }
        minim+=ro<soc?ro:soc;
    }
    fprintf(fout,"%d ",(1<<nrp));
    fprintf(fout,"%d\n",minim);
    for (j=0; j<2; j++)
    {
        for (i=1; i<=n; i++)
            fprintf(fout,"%d ",a[i][j]);
        fprintf(fout,"\n");
    }
}
