#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("logic.in");
ofstream fout("logic.out");

char s[250];
int poz;
bool uz[30];
bool prez[30];
int nrv;
bool util[30];
int valori[30];
int fol[30];
int nrsol;

void citire()
{fin>>s;
int i;
for (i=0; s[i]; i++)
if (s[i]>='a'&&s[i]<='z')
if (prez[s[i]-'a'+1]==0)
    prez[s[i]-'a'+1]=1,nrv++,valori[nrv]=s[i]-'a'+1;
}

bool formula(int & poz);
bool implicatie(int & poz);
bool sau(int & poz);
bool si(int & poz);
bool factor(int & poz);

int prec;
int solutii[1100];
void gen(int k)
{if (k>nrv)
{poz=0;
if (formula(poz)) nrsol++;
}
else
{int i;
for (i=fol[k-1]+1;i<=nrv;i++)
if (!util[i])
{util[i]=1;
fol[k]=i;
uz[valori[i]]=0;
gen(k+1);
uz[valori[i]]=1;
gen(k+1);
util[i]=0;
}
}
}

int main()
{int nrs=0;
int i,j;
    citire();
gen(1);
    fout<<nrsol<<'\n';

return 0;
}

bool formula(int & poz)
{bool x=implicatie(poz);
while (s[poz]=='<')
{poz+=3;
bool y=formula(poz);
x=x==y;
}
return x;
}

bool implicatie(int & poz)
{bool x=sau(poz);
while (s[poz]=='=')
{poz+=2;
bool y=implicatie(poz);
x=(!x)||y;
}
return x;
}

bool sau(int & poz)
{bool x=si(poz);
while (s[poz]=='|')
{poz++;
bool y=sau(poz);
x=x||y;
}
return x;
}

bool si(int & poz)
{bool x=factor(poz);
while (s[poz]=='&')
{poz++;
bool y=factor(poz);
x=x&&y;
}
return x;
}

bool factor(int & poz)
{bool rez;
if (s[poz]=='~')
{poz++;
return !factor(poz);
}
if (s[poz]=='(')
{poz++;
rez=formula(poz);
poz++;
return rez;
}
rez=uz[s[poz]-'a'+1];
poz++;
return rez;
}
