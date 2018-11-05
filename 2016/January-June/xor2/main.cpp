#include <fstream>
using namespace std;
ifstream fin("xor2.in");
ofstream fout("xor2.out");
unsigned long long aux,l1,c1,l2,c2,j,k,s,i,t,p;
int main()
{fin>>t>>p;
for (i=1;i<=t;i++)
{fin>>l1>>c1>>l2>>c2;
s=0;
for (j=l1;j<=l2;j++)
{for (k=c1;k<=c2;k++)
{aux=(j^k)%p;
s=(s+aux)%p;
}
}
fout<<s%p<<endl;
}
return 0;
}
