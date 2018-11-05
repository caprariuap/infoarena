#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("numere.in");
ofstream fout("numere.out");
int a[101],u,v,b[101],c[101],d[101],k,i;
char s[101];
void citire()
{fin>>s>>u>>v;
a[0]=strlen(s);
for (i=1;i<=a[0];i++)
{k=s[a[0]-i]-'0';
a[i]=k;
}
}
void scadere(int a[101],int b[101])
{int t=0;
for (i=b[0]+1;i<=a[0];i++) b[i++]=0;
for (i=1;i<=a[0];i++)
{a[i]=a[i]-b[i]-t;
if (a[i]<0) t=1,a[i]+=10;
else t=0;
}
}
void adunare(int a[101],int b[101])
{int t=0;
for (i=b[0]+1;i<=a[0];i++) b[i]=0;
for (i=1;i<=a[0];i++)
{a[i]+=b[i]+t;
t=a[i]/10;
a[i]%=10;
}
if (t!=0) a[++a[0]]=t;
}
void impartire(int a[101],unsigned long x)
{unsigned long r=0;
for (i=a[0];i;i--)
{a[i]=(r=10*r+a[i])/x;
r%=x;
}
while (!a[a[0]]&&a[0]>1) a[0]--;
}
int main()
{citire();
for (i=0;i<=101;i++)
    b[i]=a[i],c[i]=a[i],d[i]=a[i];
impartire(b,u);
impartire(c,v);
u*=v;
impartire(d,u);
scadere(a,b);
scadere(a,c);
adunare(a,d);
for (i=a[0];i>0;i--)
    fout<<a[i];
}
