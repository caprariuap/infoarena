#include <fstream>
using namespace std;
ifstream fin("gardul.in");
ofstream fout("gardul.out");
int n,p,q,cp,cq,r,nv,nr,na;
int main()
{fin>>n>>p>>q;
cp=p;
cq=q;
while (cq>0)
{r=cp%cq;
cp=cq;
cq=r;
}
cp=p*q/cp;
nv=n/cp;
nr=n/p-nv;
na=n/q-nv;
fout<<n-(nr+nv+na)<<endl<<nr<<endl<<na<<endl<<nv;
}
