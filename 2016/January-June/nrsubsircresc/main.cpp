#include <fstream>
using namespace std;
ifstream fin("nrsubsircresc.in");
ofstream fout("nrsubsircresc.out");
unsigned long long a[301],b[301],i,j,n,s;
int main()
{fin>>n;
for (i=1;i<=n;i++)
{fin>>a[i];
b[i]=1;
for (j=1;j<i;j++)
if (a[j]<a[i])
    b[i]+=b[j];
s+=b[i];
}
fout<<s<<'\n';
}
