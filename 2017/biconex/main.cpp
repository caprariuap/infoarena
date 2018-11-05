#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

ifstream fin("biconex.in");
ofstream fout("biconex.out");

stack <int> st;
vector <int> v[100010],ans[100010];
int n,m,i,j,low[100010],nivel[100010],nrc;
bool use[100010];

void dfs(int nod)
{
    use[nod]=1;
    st.push(nod);
    low[nod]=nivel[nod];
    for (int i=0; i<v[nod].size(); i++)
    {
        int vecin=v[nod][i];
        if (use[vecin])
            low[nod]=min(low[nod],nivel[vecin]);
        else
        {
            nivel[vecin]=nivel[nod]+1;
            dfs(vecin);
            if (low[vecin]==nivel[nod])
            {
                ++nrc;
                while (st.top()!=vecin) ans[nrc].push_back(st.top()),st.pop();
                ans[nrc].push_back(st.top());
                st.pop();
                ans[nrc].push_back(nod);
            }
            low[nod]=min(low[nod],low[vecin]);
        }
    }
}

int main()
{
    fin >> n >> m;
    for (i=1; i<=m; i++)
    {
        int a,b;
        fin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (i=1; i<=n; i++)
        if (!use[i])
            dfs(i);
    fout << nrc << '\n';
    for (i=1; i<=nrc; i++)
    {
        for (j=ans[i].size()-1; j>=0; j--)
            fout << ans[i][j] <<  ' ';
        fout << '\n';
    }
}
