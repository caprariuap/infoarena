#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("replace.in");
ofstream fout("replace.out");
char s[30001],sir[30001],nt[11];
char reguli[11][82],rezultate[11][82];
int i,j,k,n,l,lungimi[11],lungime[11],ok;
char *p;
int main()
{fin.getline(nt,11);
ok=strlen(nt);
for (i=0;i<ok;i++)
    {k=nt[i]-'0';n=n*10+k;}
for (i=1;i<=n;i++)
{fin.getline(reguli[i],81,'\n');
fin.getline(rezultate[i],81,'\n');
lungimi[i]=strlen(reguli[i]);if (lungimi[i]==0) {lungimi[i]=1;reguli[i][0]=' ';}
lungime[i]=strlen(rezultate[i]);
}
fin.getline(s,256);
l=strlen(s);
for (i=1;i<=n;i++)
{p=strstr(s,reguli[i]);
while (p!=NULL)
{strcpy(sir,p+lungimi[i]);
strncpy(p,rezultate[i],lungime[i]);
strcpy(p+lungime[i],sir);
p=strstr(s,reguli[i]);
}
}
fout<<s;
}
