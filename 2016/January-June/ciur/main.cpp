#include <fstream>
using namespace std;
ifstream fin("ciur.in");
ofstream fout("ciur.out");
int n;
int i,nrp;
char prim[2000001];
int main()
{
    fin>>n;
    prim[0]=prim[1]=1;
    for (i=3; i<=n; i+=2)
        if (i%2!=0&&!prim[i])
        {
            ++nrp;
            for (long j=2*i; j<=n; j+=i)
                prim[j]=1;
        }
    fout<<nrp+1<<'\n';
}
