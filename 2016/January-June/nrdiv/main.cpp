#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("nrdiv.in");
ofstream fout("nrdiv.out");
long long i,j,r,t,n,x,l,a[50][50],k,nrdiv,prime[1000000],nprime;
char s[51][15],nt[5];
int verifprim(long long x)
{long long d=2;long long nrdiv=1;
while (x>1)
{k=0;
while (x%2==0)
    k++;
d++;
nrdiv=nrdiv*(k+1);
}
if (nrdiv>2)
    return 0;
return 1;
}
int main()
{fin>>n;fin.getline(nt,2);
nprime=1;
prime[1]=2;
for
for (i=1;i<=n;i++)
{fin.getline(s[i],15);
l=strlen(s[i]);
a[i][0]=l;
for (j=1;j<=l;j++)
    a[i][j]=s[i][l-j]-'0';
if (a[i][0]==1&&a[i][1]==1)
    fout<<'1';
else
{nrdiv=1;
for
}
}
}
