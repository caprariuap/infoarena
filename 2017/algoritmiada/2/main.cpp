#include <fstream>
#include <vector>

using namespace std;

ifstream fin("fantasy.in");
ofstream fout("fantasy.out");

vector <int> v[1010];
int d[5][1010],D,C,V,i,j,n;
bool use[1010];

void dfs(int nod, int vec)
{
    for (int i=0; i<v[nod].size(); i++)
    {
        int vecin=v[nod][i];
        if (d[vec][vecin]==0||d[vec][vecin]>d[vec][nod]+1)
        {
            d[vec][vecin]=d[vec][nod]+1;
            dfs(vecin,vec);
        }
    }
}

void dfs2(int nod, bool val)
{
    use[nod]=val;
    for (int i=0; i<v[nod].size(); i++)
        if (use[v[nod][i]]!=val)
        {
            d[4][v[nod][i]]=d[4][nod]+1;
            dfs2(v[nod][i],val);
        }
}

bool noint(int x)
{
    int poz1,poz2,poz3;
    poz1=V;
    poz2=C;
    poz3=D;
    while (1)
    {
        int minim1,minim2,minim3,np1,np2,np3;
        minim1=minim2=minim3=2000;
        np1=np2=np3=-1;
        if (poz1==poz2||poz1==poz3)
            return 0;
        if (poz2==poz3)
            return 1;
        if (poz1!=x)
        for (int i=0; i<v[poz1].size(); i++)
        {
            int vecin=v[poz1][i];
            if (d[4][vecin]<minim1)
                minim1=d[4][vecin],np1=vecin;
        }
        for (int i=0; i<v[poz2].size(); i++)
        {
            int vecin=v[poz2][i];
            if (d[2][vecin]<minim2)
                minim2=d[2][vecin],np2=vecin;
        }
        for (int i=0; i<v[poz3].size(); i++)
        {
            int vecin=v[poz3][i];
            if (d[0][vecin]<minim3)
                minim3=d[0][vecin],np3=vecin;
        }
        if (poz1==x)
            np1=x;
        if (np2==poz3&&np3==poz2)
            return 1;
        if (np2==np3&&poz1!=np2)
            return 1;
        if (np2==poz1&&np1==poz2)
            return 0;
        if (np2==np1)
            return 0;
        if (np3==poz1&&np1==poz3)
            return 0;
        if (np3==np1)
            return 0;
        poz1=np1;
        poz2=np2;
        poz3=np3;
    }
}

void solve()
{
    fin >> n >> D  >> C >> V;
    for (i=1; i<=n; i++)
    {
        v[i].clear();
        for (j=0; j<=4; j++)
            d[j][i]=0;
        use[i]=0;
    }
    for (i=1; i<n; i++)
    {
        int a,b;
        fin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(D,2);
    d[2][D]=0;
    dfs(C,1);
    d[1][C]=0;
    dfs(V,0);
    d[0][V]=0;
    bool ok=1;
    for (i=1; i<=n; i++)

    {
        if (d[0][i]>=d[2][i]||d[1][i]>d[2][i])
            continue;
        dfs2(i,ok);
        d[4][i]=0;
        ok=!ok;
        if (noint(i)==1)
        {
            fout << "DA" << '\n';
            return;
        }
    }
    fout << "NU" << '\n';
}

int main()
{
    int t;
    fin >> t;
    for (int X=1; X<=t; X++)
        solve();
}
