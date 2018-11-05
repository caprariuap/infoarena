#include <fstream>
#define nmax 1210

using namespace std;

ifstream fin("scara3.in");
ofstream fout("scara3.out");

int n,k,l,i,j,a[nmax],e[nmax],best[nmax],cost[nmax];

int main()
{
    fin >> n;
    fin >> k;
    for (i=1; i<=k; i++)
    {
        int X,Y;
        fin >> X >> Y;
        a[X]=Y;
    }
    fin >> l;
    for (i=1; i<=l; i++)
    {
        int X,Y;
        fin >> X >> Y;
        e[X]=Y;
    }
    best[1]=1;
    cost[1]=0;
    for (i=2; i<=n; i++)
    {
        best[i]=best[i-1]+1;
        cost[i]=cost[i-1];
        for (j=1; j<i; j++)
        {
            if (a[j]>=i-j)
                if (best[i]==0||best[i]>best[j]+1||(best[i]==best[j]+1&&cost[i]>cost[j]))
                    best[i]=best[j]+1,cost[i]=cost[j];
            if (e[j]*2>=i-j)
                if (best[i]==0||best[i]>best[j]+1||(best[i]==best[j]+1&&cost[i]>cost[j]+(i-j+1)/2))
                    best[i]=best[j]+1,cost[i]=cost[j]+(i-j+1)/2;
        }
    }
    fout << best[n] << ' ' << cost[n] << '\n';
}
