#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("cutii.in");
ofstream fout("cutii.out");
short int a[82],b[82];
int maimare(short int H1[82],short int H2[82])
 {
  // Elimina zero-urile semnificative, daca exista.
  while (H1[0] && !H1[H1[0]]) H1[0]--;
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
{ int iii, T=0;

  for (iii=A[0]+1;iii<=B[0];) A[iii++]=0;
  for (iii=1;iii<=B[0];iii++)
    {B[iii]=B[iii]-(A[iii]+T);
    if (B[iii]<0) T=1;
    else T=0;
    if (T) B[iii]+=10;
    }

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
