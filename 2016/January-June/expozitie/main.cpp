#include <fstream>
using namespace std;
ifstream fin("expozitie.in");
ofstream fout("expozitie.out");
int raspuns[10000],n,d,k,i,j;
void inmultire(int a[],int x)
{unsigned long t=0,i;
for (i=1;i<=a[0];i++)
{a[i]=a[i]*x+t;
t=a[i]/10;
a[i]=a[i]%10;
}
while (t)
{a[++a[0]]=t%10;
t/=10;
}
}
void impartire(int a[],int x)
{unsigned long r=0,i;
for (i=a[0];i;i--)
{r=10*r+a[i];
a[i]=r/x;
r%=x;
}
while (a[0]>1&&!a[a[0]]) a[0]--;
}
int main()
{fin>>n>>d>>k;
if (n-d*k<0) fout<<'0';
else
    if (n-d*k==0) fout<<'1';
else
{raspuns[0]=raspuns[1]=1;int X=n-d*k;
for (i=2;i<=X+d-1;i++)
    inmultire(raspuns,i);
for (i=2;i<=X;i++)
    impartire(raspuns,i);
for (i=2;i<=d-1;i++)
    impartire(raspuns,i);
for (i=raspuns[0];i;i--) fout<<raspuns[i];fout<<'\n';
}
    return 0;
}
