#include <iostream>
#include <vector>
#define nmax 100010
#define pu(x) ((x^(x-1))&x)

using namespace std;

vector <int> v2[nmax],v[nmax];
int n,m,i,j,aib[nmax],PE[nmax],nr,nr2,PE2[nmax],index[nmax],subarb1[nmax],subarb2[nmax],ans[nmax],r1,r2;
bool use[nmax];

void update(int poz, int val)
{
    for (int i=poz; i<=n; i+=pu(i))
        aib[i]+=val;
}

int query(int poz)
{
    int ret=0;
    for (int i=poz; i>0; i-=pu(i))
        ret+=aib[i];
    return ret;
}

void dfs1(int x)
{
    use[x]=1;
    PE[++nr]=x;
    index[x]=nr;
    subarb1[x]=1;
    for (int i=0; i<v[x].size(); i++)
        if (!use[v[x][i]])
        {
            dfs1(v[x][i]);
            subarb1[x]+=subarb1[v[x][i]];
        }
}

int tata[nmax];

void dfs2(int x)
{
    use[x]=0;
    PE2[++nr2]=x;
    subarb2[x]=1;
    for (int i=0; i<v2[x].size(); i++)
        if (use[v2[x][i]])
        {
            tata[v2[x][i]]=x;
            dfs2(v2[x][i]);
            subarb2[x]+=subarb2[v2[x][i]];
        }
}

bool use2[nmax];

void markwith0(int x)
{
    use2[x]=1;
    update(index[x],-1);
    cout << "WTF" << x << '\n';
    for (int i=0; i<v2[x].size(); i++)
        if (!use2[v2[x][i]]&&tata[x]!=v2[x][i])
        {
            markwith0(v2[x][i]);
        }
}

void findanswers(int x)
{
    use[x]=1;
    for (int i=0; i<v2[x].size(); i++)
        if (!use[v2[x][i]])
        {
            findanswers(v2[x][i]);
            ans[x]=ans[x]+ans[v2[x][i]]+query(index[x]+subarb1[x]-1)-query(index[x]-1);
            if (!use2[v2[x][i]]&&tata[x]!=v2[x][i])
                markwith0(v2[x][i]);
            if (x==1)
                cout << "DA " << ans[x] << ' ';
        }
//    for (int i=0; i<v2[x].size(); i++)
//        if (!use2[v2[x][i]]&&tata[x]!=v2[x][i])
//        markwith0(v2[x][i]);
//    if (x==7)
//        cout << "WTF" << ' ' << index[x] << ' ' << subarb1[x] << query(index[x]+subarb1[x]-1) << " WTF" << '\n';
    update(index[x],1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> r1 >> r2;
    for (i=1; i<n; i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (i=1; i<n; i++)
    {
        int a,b;
        cin >> a >> b;
        v2[a].push_back(b);
        v2[b].push_back(a);
    }
    dfs1(r1);
    dfs2(r2);
    for (i=1; i<=n; i++)
        use[i]=0;
    findanswers(r2);
    for (i=1; i<=n; i++)
        cout << ans[i] << '\n';
//    for (i=1; i<=n; i++)
//        cout << query(i) << ' ';
//    for (i=1; i<=n; i++)
//        cout << index[i] << ' ';
}
/*
8 1 1
1 2
1 7
7 8
2 3
2 4
2 5
3 6
1 2
1 3
1 7
2 4
2 5
4 8
1 6
*/
