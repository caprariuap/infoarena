#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("interesant.in");
ofstream fout("interesant.out");

char s[205][5010];
int n,i,j,poz,lmax,lungimi[205];
int p;
bool interesant[205];

bool verif(int i,int j)
{int hp,h,k;
if (lungimi[i]>lungimi[j]) swap(i,j);
hp=-1;
for (k=0;k<lungimi[i];k++)
{for (h=hp+1;h<lungimi[j];h++)
if (s[i][k]==s[j][h]) {hp=h;break;}
if (h==lungimi[j]) return 0;
}
return 1;
}

int main()
{fin>>p>>n;
if (p==1)
{fin>>s[1];
poz=1;lmax=strlen(s[1]);
for (i=2;i<=n;i++)
{fin>>s[i];
int l=strlen(s[i]);
if (l>lmax) lmax=l,poz=i;
else if (l==lmax&&strcmp(s[i],s[poz]<0)) poz=i;
}
fout<<s[poz]<<' ';
}
else
{for (i=1;i<=n;i++)
{fin>>s[i];
interesant[i]=1;
lungimi[i]=strlen(s[i]);
for (j=1;j<i;j++)
    if (verif(i,j))
{if (lungimi[i]>lungimi[j])
interesant[j]=0;
else interesant[i]=0;
}
}
int nri=0;
for (i=1;i<=n;i++)
    if (interesant[i])
    nri++;fout<<nri<<'\n';
for (i=1;i<=n;i++)
    if (interesant[i])
    fout<<s[i]<<'\n';
}
fin.close();
fout.close();
}
