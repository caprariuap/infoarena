#include <fstream>
using namespace std;
ifstream fin("culori3.in");
ofstream fout("culori3.out");
int n,s[10001],i;
void inmultire(int a[],int x)
{int t=0,i;
for (i=1;i<=a[0];i++)
{a[i]=a[i]*x+t;t=a[i]/10;
a[i]%=10;
}
while (t) a[++a[0]]=t%10,t/=10;
}
int x,y;
int main()
{fin>>n;
s[0]=1;
if (n==1) fout<<5;
else if (n==2) fout<<8;
    else if (n==3) fout<<14;
    else
    {if (n%2==0) s[0]=1,s[1]=8;
    else s[0]=2,s[1]=4,s[2]=1;
    int putere=(n-n%2-2)/2;
for (i=1;i<=putere;i++)
    inmultire(s,3);
for (n=s[0];n;n--) fout<<s[n];
    }
}
