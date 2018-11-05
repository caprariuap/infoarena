#include <fstream>
#define MAX 5005

using namespace std;


ifstream fin("rucsac.in");
ofstream fout("rucsac.out");

int n,g;
int p[MAX],w[MAX];
int d[2*MAX];
int i,j;
int pmax;

int main()
{fin>>n>>g;
for (i=1;i<=n;i++)
    fin>>w[i]>>p[i];
for (i=1;i<=n;i++)
    for (j=g;j>=0;j--)
{int pc=d[j];
if (w[i]<=j)
    d[j] = max(pc, d[j - w[i]] + p[i]);
}
fout<<d[g];
}
