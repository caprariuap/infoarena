#include <fstream>
#include <vector>

using namespace std;

ifstream fin("vot1.in");
ofstream fout("vot1.out");

int n,m,i,j,nr,k,use[100010],st[100010];
vector <int> v[100010],vt[100010],rez[100010];

void sortt(int x)
{
    use[x]=1;
    for (int i=0; i<v[x].size(); i++)
        if (!use[v[x][i]])
            sortt(v[x][i]);
    st[++k]=x;
}

void dfs(int x)
{
    rez[nr].push_back(x);
    use[x]=0;
    for (int i=0; i<vt[x].size(); i++)
        if (use[vt[x][i]])
            dfs(vt[x][i]);
}

int ANS,REZ[1010];

int main()
{
    fin >> n;
    for (i=1; i<=n; i++)
    {
        int a;
        fin >> a;
        v[i].push_back(a);
        vt[a].push_back(i);
    }
    for (i=1; i<=n; i++)
        if (!use[i])
            sortt(i);
    for (i=n; i; i--)
        if (use[st[i]])
        {
            nr++;
            dfs(st[i]);
        }
    for (i=1; i<=nr; i++)
    {
        if (rez[i].size()>1)
            ANS+=rez[i].size();
    }
    fout << ANS << '\n';
}
