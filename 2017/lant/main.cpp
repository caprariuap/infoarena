#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

ifstream fin("lant.in");
ofstream fout("lant.out");

char linie[1010],cuv[155][35];
char semne[10]= {" ,:;.!?-"};
long long k,nr,i,j,nrc,rez[155];
vector <int> v[155];
bool use[155];

int calculeazasim(int x, int y)
{
    long long n,m,dp[50][50];
    n=strlen(cuv[x]);
    m=strlen(cuv[y]);
    int i,j;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            dp[i][j]=0;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (cuv[x][i-1]==cuv[y][j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    return m-dp[n][m]+n-dp[n][m];
}

void dfs(int x)
{
    use[x]=1;
    if (v[x].size()==0)
        rez[x]=1;
    for (int i=0; i<v[x].size(); i++)
    {
        if (use[v[x][i]]==0)
            dfs(v[x][i]);
        rez[x]+=rez[v[x][i]];
    }
}

int main()
{
    fin >> k;
    while (!fin.eof())
    {
        fin.getline(linie,1010,'\n');
        char *p=strtok(linie,semne);
        while (p)
        {
            bool ok=1;
            for (i=1; i<=nrc; i++)
                if (strcmp(p,cuv[i])==0)
                    ok=0;
            if (ok)
                ++nrc,strcpy(cuv[nrc],p);
            p=strtok(NULL,semne);
        }
    }
    for (i=1; i<nrc; i++)
        for (j=i+1; j<=nrc; j++)
        {
            int x=calculeazasim(i,j);
            if (x<=k)
                v[i].push_back(j);
        }

    dfs(1);
    fout << rez[1] << '\n';
}
