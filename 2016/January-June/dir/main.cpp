#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("dir.in");
ofstream fout("dir.out");
char s[1601];
char st[1601][31];
char fisier[101][256];
int i,nrfisiere,vf,j;
int l,lf;
int divide(int p,int q)
{int s=p;int d=q;
char x[256];
strcpy(x,fisier[s]);
while (s<d)
{while (s<d&&strcmp(fisier[d],x)>=0) d--;
strcpy(fisier[s],fisier[d]);
while (s<d&&strcmp(fisier[s],x)<=0) s++;
strcpy(fisier[d],fisier[s]);
}
strcpy(fisier[s],x);
return s;
}
void qs(int p,int q)
{int m=divide(p,q);
if (p<m-1) qs(p,m-1);
if (m+1<q) qs(m+1,q);
}
int main()
{i=0;
fin>>s;
if (s[i]>='A'&&s[i]<='Z')
{++vf;
while (s[i]>='A'&&s[i]<='Z')
st[vf][i]=s[i],i++;
while (s[i]>='0'&&s[i]<='9')
st[vf][i]=s[i],i++;st[vf][i]='\0';
}
l=strlen(s);
while (i<l)
{if (s[i]>='A'&&s[i]<='Z')
{int j=0;
while (s[i]>='A'&&s[i]<='Z')
st[vf][j]=s[i],i++,j++;
while (s[i]>='0'&&s[i]<='9')
st[vf][j]=s[i],i++,j++;st[vf][j]='\0';
}
if (s[i]=='(')
vf++,i++;
if (s[i]==')')
vf--,i++;
if (s[i]==',')
    i++;
if (s[i]>='a'&&s[i]<='z')
{nrfisiere++;char aux[31];j=0;
while (s[i]>='a'&&s[i]<='z')
aux[j]=s[i],i++,j++;
while (s[i]>='0'&&s[i]<='9')
aux[j]=s[i],i++,j++;aux[j]='\0';
j=1;
while (j<vf)
{int k;
strcat(fisier[nrfisiere],st[j]);
int lgd=strlen(fisier[nrfisiere]);
fisier[nrfisiere][lgd]='\\';
fisier[nrfisiere][lgd+1]='\0';
j++;
}
strcat(fisier[nrfisiere],aux);
}
}
qs(1,nrfisiere);
fout<<nrfisiere<<'\n';
for (i=1;i<=nrfisiere;i++)
    fout<<fisier[i]<<'\n';
}
