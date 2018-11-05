#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("spam.in");
ofstream fout("spam.out");
int l,lt,nok,nra,nrn,poza[101],pozn[101],rezultat,inplus;
char s[110][101];
void citire()
{fin>>s[1];
lt=strlen(s[1]);
for (int i=0;i<lt;i++)
{if (s[1][i]=='t'&&s[1][i-1]=='a'&&s[1][i-2]!='.'&&s[1][i+1]!='.'&&i!=1&&i!=lt-1)
poza[++nra]=i-1;
else
if (s[1][i]=='m'&&s[1][i-1]=='a'&&s[1][i-2]=='p'&&s[1][i-3]=='s'&&s[1][i-4]=='o'&&s[1][i-5]=='n')
pozn[++nrn]=i-5;
if (strchr("abcdefghijklmnopqrstuvwxyz01.",s[1][i])=='\0')
nok=1;
}
}
int check(int j)
{int ok=1;l=strlen(s[j]);
if (s[j][0]=='.'||s[j][l-1]=='.'||s[j][0]=='@'||s[j][l-1]=='@')
    ok=0;
else
    for (int i=0;i<l;i++)
    if (s[j][i]=='@'&&(s[j][i-1]=='.'||s[j][i+1]=='.'))
    ok=0;
for (int i=2;i<j;i++)
    if (strcmp(s[i],s[j])==0)
    ok=0;
return ok;
}
int main()
{citire();
int i,j,k;
if (nok==1)
    fout<<'0';
else
{for (i=1;i<=nrn;i++)
if (s[1][pozn[i]-1]=='a'&&s[1][pozn[i]+6]=='t'&&s[1][pozn[i]-2]!='.'&&s[1][pozn[i]+7]!='.'&&s[1][pozn[i]-1]!=0&&s[1][pozn[i]+7]!=l-1)
    inplus++;
rezultat=1;
for (i=1;i<=nra;i++)
{rezultat++;
for (k=0;k<lt;k++)
s[rezultat][k]=s[1][k];
s[rezultat][poza[i]]='@';
for (k=poza[i]+1;k<lt;k++)
    s[rezultat][k]=s[rezultat][k+1];
if (check(rezultat)==0)
    {rezultat--;for (k=0;k<=lt;k++)
    s[rezultat+1][k]='\0';

}
}
for (i=1;i<=nra;i++)
for (j=1;j<=nrn;j++)
{rezultat++;
for (k=0;k<lt;k++)
s[rezultat][k]=s[1][k];
s[rezultat][poza[i]]='@';
for (k=poza[i]+1;k<lt;k++)
    s[rezultat][k]=s[rezultat][k+1];
if (s[rezultat][pozn[j]]!='n'||s[rezultat][pozn[j]+1]!='o')
{for (k=pozn[j]-1;k<lt-6;k++)
    s[rezultat][k]=s[rezultat][k+6];}
else
    {for (k=pozn[j];k<lt-6;k++)
    s[rezultat][k]=s[rezultat][k+6];}
if (check(rezultat)==0)
{rezultat--;for (k=0;k<=lt;k++)
    s[rezultat+1][k]='\0';
}
}
rezultat--;
fout<<rezultat+inplus;
}
}

