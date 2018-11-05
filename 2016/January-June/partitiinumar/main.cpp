#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("partitiinumar.in");
ofstream fout("partitiinumar.out");
int n,x[41],s;
void bkt(int k)
{if (s==n)
{for (int i=1;i<k;i++)
    fout<<x[i]<<' ';fout<<'\n';}
if (k<=n)
{int i;
for (i=x[k-1];s+i<=n;i++)
{s+=i;x[k]=i;bkt(k+1);s-=i;
}
}
}
int main()
{x[0]=1;fin>>n;
bkt(1);
}
