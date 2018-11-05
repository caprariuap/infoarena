#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("mxl.in");
ofstream fout("mxl.out");

int n,k,i;
long long a[45][45];
char s[1605][300];
bool calculat[1605];
int linii[1605],coloane[1605];
int nrsir[45][45];

long long calculare(int x)
{int lg=0;int nr,nr2;
while (s[x][lg]) lg++;
lg--;
int i=1;
long long sol=0;
while (i<=lg)
{
{nr=0;
while (s[x][i]>='0'&&s[x][i]<='9')
    nr=nr*10+s[x][i]-'0',i++;
if (s[x][i]==':')
{nr2=0;i++;
while (s[x][i]>='0'&&s[x][i]<='9')
    nr2=nr2*10+s[x][i]-'0',i++;
if (!calculat[nrsir[nr][nr2]])
    {a[nr][nr2]=calculare(nrsir[nr][nr2]);}
sol+=a[nr][nr2];
}
else
    sol+=nr;
}
if (s[x][i]=='+')
    i++;
}
calculat[x]=1;
return sol;
}

long long calcularenr(char s[])
{int lg=0;int nr,nr2;
while (s[lg]) lg++;
lg--;
int i=0;
if (s[i]!='=')
{nr=0;
while (s[i]>='0'&&s[i]<='9')
    nr=nr*10+s[i]-'0',i++;
return nr;
}
i++;
long long sol=0;
while (i<=lg)
{nr=0;while (s[i]>='0'&&s[i]<='9')
    nr=nr*10+s[i]-'0',i++;sol+=nr;
if (s[i]=='+')
    i++;
}
return sol;
}

int main()
{fin>>n>>k;
for (i=1;i<=k;i++)
{fin>>linii[i]>>coloane[i];nrsir[linii[i]][coloane[i]]=i;
fin>>s[i];
}
for (i=1;i<=k;i++)
    if (!strchr(s[i],':')) a[linii[i]][coloane[i]]=calcularenr(s[i]),calculat[i]=1;
for (i=1;i<=k;i++)
    if (!calculat[i]) a[linii[i]][coloane[i]]=calculare(i);
for (i=1;i<=n;i++)
{for (int j=1;j<=n;j++)
fout<<a[i][j]<<' ';
fout<<'\n';
}
}
