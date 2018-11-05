#include <fstream>
#include <vector>
#include <algorithm>
#define nmax 100010

using namespace std;

ifstream fin("spiridusi.in");
ofstream fout("spiridusi.out");

vector <int> v[nmax];
int n,c,j,ans,nr,s[nmax],p[nmax],logdoi[nmax],doi[20];
int psum[nmax],a[nmax],dp[20][nmax];
bool use[nmax];

int cbin()
{
    int left=0, right=nr, sol=nr;

    while(left<=right)
    {
        int med=(left+right)/2;
        if(a[nr]-a[med]<=c)
        {
            sol=med;
            right=med-1;
        }
        else
            left=med+1;
    }

    return sol;
}


void dfs(int x)
{
    use[x]=1;
    ++nr;
    a[nr]=a[nr-1]+s[x];
    psum[nr]=psum[nr-1]+p[x];
    int k=logdoi[nr];
    dp[0][nr]=psum[nr];
    for (int i=1; i<=k; i++)
    {
        if (dp[i-1][nr]<dp[i-1][nr-doi[i-1]])
            dp[i][nr]=dp[i-1][nr];
        else
            dp[i][nr]=dp[i-1][nr-doi[i-1]];
    }
    int ind=upper_bound(a+1,a+nr+1,a[nr]-c-1)-a;
    if (ind!=nr)
    {
        k=logdoi[nr-ind+1];
        if (dp[k][nr]<dp[k][ind+doi[k]-1])
        {
            if (ans<psum[nr]-dp[k][nr])
                ans=psum[nr]-dp[k][nr];
        }
        else
        {
            if (ans<psum[nr]-dp[k][ind+doi[k]-1])
                ans=psum[nr]-dp[k][ind+doi[k]-1];
        }
    }
    for (int I=0; I<v[x].size(); I++)
        if (!use[v[x][I]])
            dfs(v[x][I]);
    nr--;
}

int main()
{
    fin >> n >> c;
    for (long long i=1; i<=n; i++)
        fin >> s[i];
    for (long long i=1; i<=n; i++)
        fin >> p[i];
    doi[0]=1;
    long long ii=1;
    while (doi[ii-1]<=n)
        doi[ii]=doi[ii-1]*2,ii++;
    for (long long i=2; i<=n; i++)
        logdoi[i]=logdoi[i/2]+1;
    for (long long i=1; i<n; i++)
    {
        long long X,Y;
        fin >> X >> Y;
        v[X].push_back(Y);
        v[Y].push_back(X);
    }
    dfs(1);
    fout << ans << '\n';
    //fout << POZ2 << ' ' << POZ1 << ' ' << NR2 << ' ' << NR1;
}
