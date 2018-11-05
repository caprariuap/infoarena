#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("nano.in");
ofstream fout("nano.out");
int comparare(long long  H1[],long long  H2[])
{while (H1[0] && !H1[H1[0]]) H1[0]--;
  while (H2[0] && !H2[H2[0]]) H2[0]--;

  if (H1[0] < H2[0]) {
    return -1;
  } else if (H1[0] > H2[0]) {
    return +1;
  }

  for (int i = H1[0]; i > 0; --i) {
    if (H1[i] < H2[i]) {
      return -1;
    } else if (H1[i] > H2[i]) {
      return +1;
    }
  }
  return 0;
}
void adunare(long long  b[],long long  a[])
{int i,t=0;
for (i=b[0]+1;i<=a[0];i++)
    b[i]=0;
for (i=1;i<=a[0];i++)
{a[i]+=b[i]+t;
t=a[i]/10;
a[i]%=10;
}
if (t) a[++a[0]]=t;
}
void scadere(long long  a[],long long  b[])
{int i,t=0;
for (i=b[0]+1;i<=a[0];) b[i++]=0;
for (i=1;i<=a[0];i++)
{a[i]=a[i]-(b[i]+t);
if (a[i]<0) t=1; else t=0;
if (t) a[i]+=10;
}
while (!a[a[0]]&&a[0]) a[0]--;
}
void impartirela2(long long  a[])
{int i;
unsigned long r=0;
for (i=a[0];i;i--)
{r=10*r+a[i];
a[i]=r/2;
r%=2;
}
while (!a[a[0]]&&a[0]) a[0]--;
}
void inmultire(long long A[],long long  B[],long long  C[])
{long long  i,j,T=0;

  C[0]=A[0]+B[0]-1;
  for (i=1;i<=A[0]+B[0];) C[i++]=0;
  for (i=1;i<=A[0];i++)
    for (j=1;j<=B[0];j++)
      C[i+j-1]+=A[i]*B[j];
  for (i=1;i<=C[0];i++)
    { T=(C[i]+=T)/10;
      C[i]%=10;
    }
  if (T) C[++C[0]]=T;
}
void incrementare(long long  a[])
{long long  b[11];b[0]=1;b[1]=1;
if (a[0]>1||(a[0]==1&&a[1]>1))
adunare(b,a);
else
{if (a[0]==1&&a[1]==1)
a[1]=2;
else
    a[0]=a[1]=1;
}
}
int rad(long long s[],long long  d[],long long  x[])
{int i;long long  k[2001],aux2[2001],xsec[2001];
for (i=0;i<=d[0];i++)
    k[i]=d[i];
for (i=0;i<=x[0];i++)
    xsec[i]=x[i];
adunare(s,k);
impartirela2(k);

inmultire(k,k,aux2);
if (comparare(aux2,xsec)==1) {long long  b[1001];b[0]=1;b[1]=1;scadere(k,b); return rad(s,k,xsec);}
else
{
incrementare(k);
inmultire (k,k,aux2);
if (comparare(aux2,xsec)<=0) {return rad(k,d,xsec);}
else {long long  b[1001];b[0]=1;b[1]=1;scadere(k,b); long long  auxiliar2[1001];
inmultire(k,k,auxiliar2);
if (comparare(auxiliar2,x)==0)
    return 1;
else
    {return 0;}
}
}
}
int main()
{int n,i;
fin>>n;
for (i=1;i<=n;i++)
{char c[2],s[501];
long long a[2001],asecundar[2001];long long  b[11];b[1]=1;b[0]=1;
fin>>a[0];asecundar[0]=a[0];
fin.getline(c,2);
fin.getline(s,501);
for (int j=a[0]-1;j>=0;j--) {int m=s[j]-'0';a[a[0]-j]=m;asecundar[a[0]-j]=m;}
if (rad(b,asecundar,a))
{for (int z=a[0];z;z--) fout<<a[z]; fout<<endl;
}
}
}
