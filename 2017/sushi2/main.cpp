#include <cstdio>
#include <vector>
#include <unordered_map>
#define nmax 100010

using namespace std;

FILE *fin=fopen("sushi2.in","r");
FILE *fout=fopen("sushi2.out","w");

unordered_map <long long, int> M;
vector <int> v[nmax],pozitie[nmax];
int ai[16*nmax],euler[4*nmax],nr,p[nmax],n,m,i,j,ans[nmax];

void actualizare(int poz, int val, int nod, int st, int dr)
{
    if (st==dr)
    {
        ai[nod]=max(val,ai[nod]);
        return;
    }
    int mid=(st+dr)/2;
    if (poz<=mid)
        actualizare(poz,val,2*nod,st,mid);
    else
        actualizare(poz,val,2*nod+1,mid+1,dr);
    ai[nod]=max(ai[2*nod]+dr-mid,ai[2*nod+1]);
}

int interogare(int poz1, int poz2, int nod, int st, int dr)
{
    if (poz1<=st&&dr<=poz2)
        return ai[nod]+poz2-dr;
    int mid=(st+dr)/2;
    int ret=-1;
    if (poz1<=mid)
        ret=max(ret,interogare(poz1,poz2,2*nod,st,mid));
    if (poz2>mid)
        ret=max(ret,interogare(poz1,poz2,2*nod+1,mid+1,dr));
    return ret;
}

bool use[nmax];

void dfs(int x)
{
    euler[++nr]=x;
    use[x]=1;
    for (int i=0; i<v[x].size(); i++)
        if (v[x][i]!=p[x]&&!use[v[x][i]])
        {
            p[v[x][i]]=x;
            dfs(v[x][i]);
            euler[++nr]=x;
        }
}

int main()
{
    fscanf(fin,"%d%d",&n,&m);
    for (i=1; i<=n; i++)
    {
        int spam;
        fscanf(fin,"%d ",&spam);
        for (j=1; j<=spam; j++)
        {
            int x;
            fscanf(fin,"%d",&x);
            v[i].push_back(x);
        }
    }
    dfs(1);
    for (i=nr+1; i<=2*nr-1; i++)
        euler[i]=euler[i-nr+1];
    for (i=1; i<nr; i++)
        M[(long long)euler[i]*nmax+euler[i+1]]=i,pozitie[euler[i]].push_back(i);
    pozitie[euler[nr]].push_back(nr);
    for (i=1; i<=16*nmax-10; i++)
        ai[i]=-1000000000;
    for (i=1; i<=m; i++)
    {
        int a,b,c;
        fscanf(fin,"%d%d%d",&a,&b,&c);
        int poz=M[(long long)a*nmax+v[a][b-1]];
        actualizare(poz,c,1,1,2*nr-1);
        actualizare(poz+nr-1,c,1,1,2*nr-1);
    }
//    for (i=1; i<=4*nr; i++)
//        fout << ai[i] << ' ';fout << '\n';
    for (i=1; i<=n; i++)
    {
        pozitie[i].push_back(nr-1+pozitie[i][0]);
        for (j=0; j<pozitie[i].size()-1; j++)
            ans[i]=max(ans[i],interogare(pozitie[i][j]+1,pozitie[i][j+1],1,1,2*nr-1));
    }
    for (i=1; i<=n; i++)
        fprintf(fout,"%d ",ans[i]);
    fprintf(fout,"\n");
//    for (i=1; i<=2*nr-1; i++)
//        fout << euler[i] << ' ';
//    fout << "\n\n";
//    for (i=1; i<=n; i++)
//    {
//        for (j=0; j<pozitie[i].size(); j++)
//            fout << pozitie[i][j] << ' ';
//        fout << '\n';
//    }
}
