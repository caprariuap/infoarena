#include <cstdio>
#include <algorithm>
#include <vector>
#define nmax 200010
#define pu(x) ((x^(x-1))&x)

using namespace std;

FILE *fin=fopen("calafat.in","r");
FILE *fout=fopen("calafat.out","w");

struct eveniment
{
    long long st,poz;
};
long long n,m,i,p[nmax],a[nmax],j;
vector <eveniment> v[nmax];
long long ans[nmax],aib[nmax];

void update(long long poz, long long x)
{
    if (poz==0)
        return ;
    for (long long i=poz; i<=n; i+=pu(i))
        aib[i]+=x;
}

long long query(long long poz)
{
    long long ret=0;
    for (long long i=poz; i; i-=pu(i))
        ret+=aib[i];
    return ret;
}

int main()
{
    fscanf(fin,"%lld%lld",&n,&m);
    for (i=1; i<=n; i++)
        fscanf(fin,"%lld",&a[i]);
    for (i=1; i<=m; i++)
    {
        eveniment nou;
        long long x;
        fscanf(fin,"%lld%lld",&nou.st,&x);
        nou.poz=i;
        v[x].push_back(nou);
    }
    for (i=1; i<=n; i++)
    {
        long long x=a[i];
        if (!p[x])
            a[i]=0;
        else
            a[p[x]]=i-p[x];
        update(p[x],a[p[x]]);
        for (j=0; j<v[i].size(); j++)
            ans[v[i][j].poz]=query(i)-query(v[i][j].st-1);
        p[x]=i;
    }
    for (i=1; i<=m; i++)
        fprintf(fout,"%lld\n",ans[i]);
}
