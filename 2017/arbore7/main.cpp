#include <fstream>
#include <vector>
#define nmax 100010
#define MOD 1000000007

using namespace std;

ifstream fin("arbore7.in");
ofstream fout("arbore7.out");

vector <long long> v[nmax];
long long n,i,nrcwith[nmax],nrcwithout[nmax],subwith[nmax],subwithout[nmax];
bool use[nmax];

void dfs(long long x)
{
    use[x]=1;
    nrcwithout[x]=1;
    subwith[x]=1;
    subwithout[x]=1;
    for (long long i=0; i<v[x].size(); i++)
        if (!use[v[x][i]])
        {
            dfs(v[x][i]);
            nrcwith[x]=nrcwith[x]+max(nrcwith[v[x][i]],nrcwithout[v[x][i]]);
            nrcwithout[x]=nrcwithout[x]+max(nrcwith[v[x][i]],nrcwithout[v[x][i]]-1);
            if (nrcwith[v[x][i]]<nrcwithout[v[x][i]])
                subwith[x]*=subwithout[v[x][i]];
            else
            {
                if (nrcwith[v[x][i]]>nrcwithout[v[x][i]])
                    subwith[x]*=subwith[v[x][i]];
                else
                    subwith[x]*=(subwith[v[x][i]]+subwithout[v[x][i]]);
            }
            if (nrcwith[v[x][i]]<nrcwithout[v[x][i]]-1)
                subwithout[x]*=subwithout[v[x][i]];
            else
            {
                if (nrcwith[v[x][i]]>nrcwithout[v[x][i]]-1)
                    subwithout[x]*=subwith[v[x][i]];
                else
                    subwithout[x]*=(subwith[v[x][i]]+subwithout[v[x][i]]);
            }
            subwith[x]%=MOD;
            subwithout[x]%=MOD;
        }
}

int main()
{
    fin >> n;
    for (i=1; i<n; i++)
    {
        long long a,b;
        fin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    if (nrcwith[1]>nrcwithout[1])
        fout << nrcwith[1] << ' ' << subwith[1];
    else if (nrcwith[1]<nrcwithout[1])
        fout << nrcwithout[1] << ' ' << subwithout[1];
    else
        fout << nrcwith[1] << ' ' << subwith[1]+subwithout[1];
    fout << '\n';
    fin.close();
    fout.close();
    return 0;
}
