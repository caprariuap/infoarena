#include <fstream>
#define abs(a,b) a > b ? a-b : b-a

using namespace std;

ifstream fin("gard5.in");
ofstream fout("gard5.out");

long long n,cost,a[110],maxim,nrspec;
int i;
bool spec[110];

int main()
{
    fin >> n;
    for (i=1; i<=n; i++)
    {
        fin >> a[i];
        if (a[i]>maxim)
            spec[i]=1,maxim=a[i],nrspec++;
    }
    a[n+1]=n+1;
    for (i=2; i<=n; i++)
        if (!spec[i])
        {
            if (a[i]>a[i+1])
                cost=cost+a[i]-a[i+1];
            else
                cost=cost+a[i+1]-a[i];
            if (a[i]>a[i-1])
                cost=cost+a[i]-a[i-1];
            else
                cost=cost+a[i-1]-a[i];
        }
    fout << cost << ' ';
    long long NRSOL=1;
    for (i=1; i<=n-nrspec; i++)
        NRSOL=NRSOL*i;
    fout << NRSOL << '\n';
}
