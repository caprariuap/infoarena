#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("cutii.in");
ofstream fout("cutii.out");
short int a[82],b[82];
int maimare(short int a[82],short int b[82])
{short int nrelemente1=a[0];
short int nrelemente2=b[0];
while (a[nrelemente1]==b[nrelemente2])
{nrelemente2--;
nrelemente1--;
}
if (a[nrelemente1]>b[nrelemente1])
    return 1;
return 0;
}
void citire()
{char caracter1,caracter2;
short int l;
short int i;
while (fin.get(caracter1)&&caracter1!=' ')
{l++;
a[0]++;
a[a[0]]=caracter1-'0';
}
while (fin>>caracter2)
{l++;
b[0]++;
b[b[0]]=caracter2-'0';
}
for (i=1;i<=b[0]/2;i++)
    swap(b[i],b[b[0]-i+1]);
for (i=1;i<=a[0]/2;i++)
    swap(a[i],a[a[0]-i+1]);
}
void inmultire(short int H[82])
{ int i;
  unsigned long T=0;

  for (i=1;i<=H[0];i++)
    { H[i]=H[i]*2+T;
      T=H[i]/10;
      H[i]=H[i]%10;
    }
  while (T)
    { H[++H[0]]=T%10;
      T/=10;
    }
}
void scadere(short int A[82],short int B[82])
{ int i, T=0;

  for (i=A[0]+1;i<=B[0];) A[i++]=0;
  for (i=1;i<=B[0];i++)
    B[i]+= (T=(B[i]-=A[i]+T)<0) ? 10 : 0;

  while (!B[B[0]]&&B[0]>0) B[0]--;
}
void impartire(short int AA[82], unsigned long X)
{short int j;
  unsigned long R=0;

  for (j=AA[0];j;j--)
    { AA[j]=(R=10*R+AA[j])/X;
      R%=X;
    }
  while (!AA[AA[0]] && AA[0]>1) AA[0]--;
}
int main()
{short int i,numar=0;
citire();
if (maimare(a,b)==1)
    for (i=0;i<=81;i++)
    swap(a[i],b[i]);

while ((a[1]+b[1])%2==0&&a[0]>0)
{numar++;
scadere(a,b);
inmultire (a);
if (maimare(a,b)==1)
    for (i=0;i<=81;i++)
    swap (a[i],b[i]);

if (b[1]%2==0)
{impartire(a,2);
impartire(b,2);
}
}
if (a[0]==0)
    fout<<numar;
 else
    fout<<'-'<<'1';
}
