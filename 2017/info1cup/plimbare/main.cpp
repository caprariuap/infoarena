#include <fstream>
#include <vector>
#define MOD 1000000007
#define nmax 400010
#define pu(x) ((x^(x-1))&x)

using namespace std;

ifstream fin("plimbare.in");
ofstream fout("plimbare.out");

long long n,m,i,j,p[nmax],ord[nmax],prio[nmax],poz[nmax],maxprio[nmax];
long long fact[nmax],ans[nmax],aib[nmax];
vector <long long> v[nmax];

void update(int poz, int x)
{
    for (int i=poz; i<=n; i+=pu(i))
        aib[i]+=x;
}

int query(int poz)
{
    int i,ans=0;
    for (i=poz; i>0; i-=pu(i))
        ans+=aib[i];
    return ans;
}
long long euclidextins(long long a, long long b, long long &x, long long &y)
{
    if (b==0)
    {
        x=1;
        y=0;
        return a;
    }
    long long x0,y0;
    long long d=euclidextins(b,a%b,x0,y0);
    x=y0;
    y=x0-(a/b)*y0;
    return d;
}

long long invmod(long long A, long long N)
{
    long long x,y;
    long long d=euclidextins(A,N,x,y);
    if (x<0)
        x+=N;
    return x;
}

long long comb(long long N, long long K)
{
    long long ret=fact[N];
    ret=(ret*invmod(fact[K],MOD))%MOD;
    ret=(ret*invmod(fact[N-K],MOD))%MOD;
    return ret;
}

bool ok=1;

void posibil(int x)
{
    if (!ok)
        return;
    for (int i=0; i<v[x].size(); i++)
    {
        posibil(v[x][i]);
        if (maxprio[v[x][i]]!=0&&poz[x]>maxprio[v[x][i]])
            ok=0;
    }
    if (poz[x]!=0)
        update(poz[x],1);
    if (prio[x]!=1000000)
    {
        if (query(maxprio[x])-query(prio[x]-1)!=maxprio[x]-prio[x]+1)
            ok=0;
        return;
    }
}

void searchmin(long long x)
{
    maxprio[x]=prio[x]=poz[x];
    if (prio[x]==0)
        prio[x]=1000000;
    for (long long i=0; i<v[x].size(); i++)
    {
        searchmin(v[x][i]);
        long long A,B,X,Y;
//        A=prio[x];
//        B=maxprio[x];
//        X=prio[v[x][i]];
//        Y=maxprio[v[x][i]];
//        if (prio[x]!=1000000&&Y!=1000000&&!((B<X||A>Y)))
//        {
//            ok=0;
//            return ;
//        }
        prio[x]=min(prio[x],prio[v[x][i]]);
        maxprio[x]=max(maxprio[x],maxprio[v[x][i]]);
    }
}

void dfs(long long x)
{
    ans[x]=1;
    long long nrsons,nrprio;
    nrprio=0;
    nrsons=v[x].size();
    for (long long i=0; i<v[x].size(); i++)
    {
        if (prio[v[x][i]]<1000000)
            nrprio++;
        dfs(v[x][i]);
        ans[x]=(ans[x]*ans[v[x][i]])%MOD;
    }
    ans[x]=(ans[x]*comb(nrsons,nrprio))%MOD;
    ans[x]=(ans[x]*fact[nrsons-nrprio])%MOD;
}

int main()
{
    fin >> n >> m;
    for (i=2; i<=n; i++)
    {
        fin >> p[i];
        v[p[i]].push_back(i);
    }
    for (i=1; i<=m; i++)
    {
        fin >> ord[i];
        poz[ord[i]]=i;
    }
    fact[0]=1;
    for (i=1; i<=400000; i++)
        fact[i]=(fact[i-1]*i)%MOD;
    searchmin(1);
    posibil(1);
    if (!ok)
    {
        fout << "0\n";
        return 0;
    }
    dfs(1);
    fout << ans[1] << '\n';
//    fout << comb(100,30) << '\n';
//    fout << (fact[7]*8)%MOD << ' ' << fact[8];
}
