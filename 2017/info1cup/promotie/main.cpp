#include <cstdio>
#include <vector>
#include <cstring>
#define nmax 1010

using namespace std;

FILE *fin=fopen("promotie.in","r");
FILE *fout=fopen("promotie.out","w");

int n,M,i,m[nmax],dp[3][1000000],curent,p[nmax],j;
bool use[1000000];
vector <int> v[5];

int main()
{
    fscanf(fin,"%d%d",&M,&n);
    for (i=1; i<=n; i++)
    {
        int nr;
            fscanf(fin,"%d%d",&nr,&p[i]);
        for (j=1; j<=nr; j++)
        {
            int x;
            fscanf(fin,"%d",&x);
            m[i]=m[i]+(1<<(x-1));
        }
    }
    dp[curent][m[1]]=p[1];
    v[curent].push_back(m[1]);
    dp[curent][0]=0;
    v[curent].push_back(0);
    for (i=2; i<=n; i++)
    {
        memset(&use,0,sizeof(use));
        curent=1-curent;
        //memset(&dp[curent],0,sizeof(dp[curent]));
//        for (int j=0; j<v[1-curent].size(); j++)
//            fout << v[1-curent][j] << ' ';fout << '\n';
        v[curent].clear();
        for (j=0; j<v[1-curent].size(); j++)
            dp[curent][v[1-curent][j]]=dp[1-curent][v[1-curent][j]],v[curent].push_back(v[1-curent][j]),use[v[1-curent][j]]=1;
        for (int x=0; x<v[1-curent].size(); x++)
        {
            j=v[1-curent][x];
            if (dp[curent][(m[i]|j)]==0||dp[curent][(m[i]|j)]>p[i]+dp[1-curent][j])
            {
                dp[curent][(m[i]|j)]=p[i]+dp[1-curent][j];
                if (use[(m[i]|j)]==0)
                    v[curent].push_back((m[i]|j)),use[(m[i]|j)]=1;
            }
        }
    }
    fprintf(fout,"%d\n",dp[curent][(1<<M)-1]);
}
