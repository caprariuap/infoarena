#include <cstdio>
#include <vector>
#include <map>
#define nmax 100010

using namespace std;

FILE *fin=fopen("tric.in","r");
FILE *fout=fopen("tric.out","w");

vector <int> v[nmax];
map <int, int> m[nmax];
int n,muchii,i,j,use[nmax],p[nmax],ans;

int main()
{
    fscanf(fin,"%d%d",&n,&muchii);
    for (i=1; i<=muchii; i++)
    {
        int a,b;
        fscanf(fin,"%d%d",&a,&b);
        a++;
        b++;
        v[a].push_back(b);
        v[b].push_back(a);
        m[a][b]=1;
        m[b][a]=1;
    }
    for (i=1; i<=n; i++)
    for (j=0; j<v[i].size(); j++)
    {
        int vecin=v[i][j];
        for (int h=0; h<v[vecin].size(); h++)
            if (m[i][v[vecin][h]]==1)
            ans++;
    }
    fprintf(fout,"%d\n",ans/6);
    fclose(fin);
    fclose(fout);
    return 0;
}
