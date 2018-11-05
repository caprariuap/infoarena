#include <fstream>
using namespace std;
ifstream fin("piticot.in");
ofstream fout("piticot.out");
int A,b,c,x,k,l,nrc,jucator[1001],ok,i,a[1001],nrmutari,invingator;
struct cercuri{int C,P;};
cercuri cerc[3001];
void mutare(int i)
{nrmutari++;
x=(A*x+b)%c;
if (a[i]+x>=l-1)
{ok=0;invingator=i;}
a[i]+=x;
while (cerc[a[i]].C==1)
{if (cerc[a[i]].P>0)
{if (a[i]+cerc[a[i]].P>=l-1)
{ok=0;invingator=i;a[i]=l-1;}
else a[i]+=cerc[a[i]].P;nrmutari++;}
else
{if (cerc[a[i]].P<0)
{a[i]+=cerc[a[i]].P;nrmutari++;
if (a[i]<0)
    a[i]=0;
}
else
    mutare(i);
}
}
}
int main()
{fin>>A>>b>>c>>x;
fin>>k>>l;
for (i=1;i<=l-2;i++)
    fin>>cerc[i].C>>cerc[i].P;
ok=1;
while (ok==1)
{for (i=1;i<=k;i++)
{mutare(i);
if (ok==0)
    break;
}
}
fout<<invingator<<endl<<nrmutari;
}
