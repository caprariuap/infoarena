#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("opmult.in");
ofstream fout("opmult.out");
int t,x,i;
bool ok[260];
char s[2010];
struct stiva{short c1,c2;} st[400];
short vf;
char operatii[400];
short citirenumar()
{short numar=0;
while (s[i]>='0'&&s[i]<='9')
numar=numar*10+s[i]-'0',i++;
return numar;
}
void intersectie(int k)
{int a,b,c,d;
if (st[k].c1<st[k+1].c1)
a=st[k].c1,b=st[k].c2,c=st[k+1].c1,d=st[k+1].c2;
else
  a=st[k+1].c1,b=st[k+1].c2,c=st[k].c1,d=st[k].c2;
int z;if (b<c) {for (z=a;z<=b;z++) ok[z]=0;for (z=c;z<=d;z++) ok[z]=0;
st[k].c1=st[k].c2=-1; return ;}
for (z=a;z<=c;z++) ok[z]=0;for (z=b;z<=d;z++) ok[z]=0;
st[k].c1=max(st[k].c1,st[k+1].c1);
st[k].c2=min(st[k].c2,st[k+1].c2);
}
void reuniune(int k)
{int z;
for (z=st[k+1].c1;z<=st[k+1].c2;z++)
    ok[z]=1;
}
void diferenta(int k)
{for (int z=st[k+1].c1;z<=st[k+1].c2;z++)
ok[z]=0;
}
int main()
{fin>>t;
int k;
for (k=1;k<=t;k++)
{fin>>x>>s;
int l=strlen(s);
i=0;vf=0;for (int z=1;z<=255;z++) ok[z]=0;
while (i<l)
{if (s[i]=='(')
        i++,st[++vf].c1=citirenumar()+1;
if (s[i]=='[')
    i++,st[++vf].c1=citirenumar();
if (s[i]==',')
    i++,st[vf].c2=citirenumar();
if (s[i]==')')
    st[vf].c2--,i++;
if (s[i]==']')
    i++;
if (s[i]=='u')
    operatii[vf]=1,i++;
if (s[i]=='-')
    operatii[vf]=0,i++;
if (s[i]=='n')
   {i++;if (s[i]=='(')
        i++,st[++vf].c1=citirenumar()+1;
if (s[i]=='[')
    i++,st[++vf].c1=citirenumar();
if (s[i]==',')
    i++,st[vf].c2=citirenumar();
if (s[i]==')')
    st[vf].c2--,i++;
if (s[i]==']')
    i++;
    intersectie(vf-1),vf--;
   }
}
for (i=st[1].c1;i<=st[1].c2;i++) ok[i]=1;
for (i=1;i<vf;i++)
    if (operatii[i]==1) reuniune(i);
else diferenta(i);
if (ok[x]==1) fout<<"DA";
else fout<<"NU";
fout<<'\n';
}
}
