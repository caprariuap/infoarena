#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("reteta2.in");
ofstream fout("reteta2.out");
char reteta[1001],ingredient[101][21],nringrediente,aux[21];
int timp,lungime[101],i,j,cantitate[101];
int divide(int p,int q)
{int s=p;int d=q;char x[21];
strcpy(x,ingredient[p]);int aux=cantitate[p];
while (s<d)
{while (s<d&&strcmp(ingredient[d],x)>=0) d--;
strcpy(ingredient[s],ingredient[d]);cantitate[s]=cantitate[d];
while (s<d&&strcmp(ingredient[s],x)<=0) s++;
strcpy(ingredient[d],ingredient[s]);cantitate[d]=cantitate[s];
}
strcpy(ingredient[s],x);cantitate[s]=aux;
return s;
}
void qs(int p,int q)
{int m=divide(p,q);
if (p<m-1) qs(p,m-1);
if (m+1<q) qs(m+1,q);
}
int main()
{char c;int l=-1;
while (fin>>c) reteta[++l]=c;
reteta[l+1]='\0';
i=0;
while (i<=l)
{if (reteta[i]>='a'&&reteta[i]<='z')
{aux[0]=reteta[i];i++;int laux=0;
while (reteta[i]>='a'&&reteta[i]<='z')
aux[++laux]=reteta[i++];aux[laux+1]='\0';
int ok=0;
int numar=reteta[i++]-'0';
while (reteta[i]>='0'&&reteta[i]<='9')
numar=numar*10+reteta[i++]-'0';
for (j=1;j<=nringrediente;j++)
if (strcmp(ingredient[j],aux)==0)
   {ok=1;
cantitate[j]+=numar;
   }
if (!ok)
{nringrediente++;
for (j=0;j<=laux;j++)
ingredient[nringrediente][j]=aux[j];ingredient[nringrediente][laux+1]='\0';
cantitate[nringrediente]=numar;
}
}
if (reteta[i]=='(')
        i++;
if (reteta[i]==')')
{i++;
int numar=reteta[i++]-'0';
while (reteta[i]>='0'&&reteta[i]<='9')
numar=numar*10+reteta[i]-'0',i++;
timp+=numar;
}
}
fout<<timp<<'\n';
qs(1,nringrediente);
for (i=1;i<=nringrediente;i++)
    fout<<ingredient[i]<<' '<<cantitate[i]<<'\n';
}
