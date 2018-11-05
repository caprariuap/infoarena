#include <fstream>
using namespace std;
ifstream fin("perm2.in");
ofstream fout("perm2.out");
int n,i,p[200010],c[200010],raspuns,j;
unsigned int vb[13000];
int cmmdc(int a,int b)
{int r;
while (b)
{r=a%b;
a=b;
b=r;
}
return a;
}
int cmmmc(int a,int b)
{return a*b/cmmdc(a,b);
}
int main()
{fin>>n;
raspuns=1;
for (i=1;i<=n;i++) fin>>p[i];
for (i=1;i<=n;i++)
{if (!c[i]) {c[i]=1;int x=p[i];
if (c[i]==1)while(x!=i) {c[i]++;x=p[x];}
for (j=p[i];j!=i;j=p[j])
    c[j]=c[i];}
raspuns=cmmmc(raspuns,c[i]);
}

fout<<raspuns;
}
