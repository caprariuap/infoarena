#incluide <fstream>
#include <cstring>
using namespace std;
ifstream fin("masca.in");
ofstream fout("masca.out");
int p,n;int nrc,nrdccspcm;
char e[110],s[1010][110];
int main()
{fin>>p>>n;
fin>>e[110];nrc=1;
int i;for (i=1;i<=n;i++) {fin>>s[nrc];int j;
for (j=1;j<nrc;j++) if (strcmp(s[nrc],s[j])==0) nrc--,break;}
if (p==1)
    fout<<nrc;
else
{int l=strlen(e)
for (i=1;i<=nrc;i++)
{int l2=strlen(s[i]);
int k;int ok=1;
if (l<=l2)
{int lcurent=0;int l2curent=0;
while (lcurent<=l&&l2curent<=l2&&ok)
{if (s[i][l2curent]==e[lcurent]||e[lcurent]=='?')
lcurent++,l2curent++;
else if (e[lcurent]=='*') {lcurent++;
char aux[110];int k;
for (k=lcurent;k<=l;k++)
    aux[k]=e[k];
    aux[k]='\0';
for (k=l;k>=l2curent;k--)
    if (e[k])
}
}
}
}
}
}
