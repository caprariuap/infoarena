#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

vector <int> newbridges,v[550];
bool viz[550];
int start[550],nr,subsize[550];

void sortBridges(int x)
{
    viz[x]=1;
    newbridges.push_back(x);
    start[x]=++nr;
    subsize[x]=1;
    for (int i=0; i<v[x].size(); i++)
        if (viz[v[x][i]])
        {
            swap(v[x][i],v[x][v[x].size()-1]);
            v[x].pop_back();
        }
    for (int i=0; i<v[x].size(); i++)
        if (!viz[v[x][i]])
        {
            sortBridges(v[x][i]);
            subsize[x]+=subsize[v[x][i]];
        }
}

int query(vector < int > v);

int findEgg(int N, vector <pair <int, int> > bridges)
{
    memset(viz, 0, sizeof(viz));
    memset(start, 0, sizeof(start));
    memset(subsize, 0, sizeof(subsize));
    for (int i=0; i<=N; i++)
        v[i].clear();
    for (int i=0; i<bridges.size(); i++)
    {
        int A,B;
        A=bridges[i].first;
        B=bridges[i].second;
        v[A].push_back(B);
        v[B].push_back(A);
    }
    sortBridges(1);
    int ok=1;
    int X=1;
    int tata;
    while (1)
    {
        ok=0;
        int st,dr;
        st=0;
        tata=-1;
        if (X!=1)
            for (int i=0; i<v[X].size(); i++)
                if (subsize[v[X][i]]>subsize[X])
                {
                    tata=i;
                    break;
                }
        dr=v[X].size()-1;
        if (dr<0)
            return X;
        vector <int> qvector;
        qvector.push_back(X);
        if (query(qvector)>0)
            return X;
        while (st<dr)
        {
            int mid=(st+dr)/2;
            int dimensiune=0;
            for (int i=st; i<=mid; i++)
                if (i!=tata)
                    dimensiune=dimensiune+subsize[v[X][i]];
            qvector.clear();
            std::vector<int>::iterator it;
            it=newbridges.begin()+start[v[X][st]]-1;
            qvector.assign(it,it+dimensiune);
            if (tata<st||tata>mid)
                qvector.push_back(X);
            ok=query(qvector);
            if (ok>0)
            {
                dr=mid;
                continue;
            }
            st=mid+1;
        }
        X=v[X][st];
    }
}
int X, Q;
vector < int > g[512+10];

int main()
{
    ifstream fin("input.in");
    ofstream fout("output.out");

    int n, nr;
    vector < pair < int, int > > V;
    vector < int > Eggs;

    fin >> n >> nr; //there are nr Easter Eggs
    for (int i = 1; i <= nr; ++i)
    {
        int x;
        fin >> x; //the i-th Easter Eggs
        Eggs.push_back(x);
    }

    //the bridges
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        fin >> x >> y;
        V.push_back({x, y});
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (vector < int > :: iterator it = Eggs.begin(); it != Eggs.end(); ++it)
    {
        Q = 0;
        X = *it;
        fout << findEgg(n, V) << '\n';
        fout << Q << '\n';
        fout << '\n';
    }
}

bool used[512+10], is[512+10];

void browse(int node)
{
    used[node] = 1;
    for (vector < int > :: iterator it = g[node].begin(); it != g[node].end(); ++it)
    {
        if (used[*it]) continue;
        if (is[*it]) browse(*it);
    }
}

bool beautiful(vector < int > v)
{
    int n = (int)v.size();

    memset(used, 0, sizeof(used));
    memset(is, 0, sizeof(is));

    for (int i = 0; i < n; ++i)
        is[v[i]] = 1;

    browse(v[0]);
    for (int i = 0; i < n; ++i)
        if (!used[v[i]]) return 0;
    return 1;
}

int query(vector < int > v)
{
    if (!beautiful(v))
    {
        printf("The query-islands are not beautiful");
        exit(0);
    }

    bool res = 0;
    Q++;
    for (vector < int > :: iterator it = v.begin(); it != v.end(); ++it)
        res |= (X == *it);
    return res;
}
