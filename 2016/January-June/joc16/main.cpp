#include <fstream>

using namespace std;

ifstream fin("joc6.in");
ofstream fout("joc6.out");

int a[155];
int s1,s2;
int best[155][155];
int n,i,j;
int maxi;

int main()
{fin>>n;
for (i=1;i<=n;i++)
{for (j=1;j<=n;j++)
fin>>a[j];
if (i%2==1)
{int ii,jj;maxi=0;
for (ii=1;ii<=n;ii++)
{int maxim=0;
for (jj=1;jj<ii;jj++)
    if (best[i][jj]>maxim&&a[jj]<=a[ii]) maxim=best[i][jj];
best[i][ii]=1+maxim;
if (best[i][ii]>maxi) maxi=best[i][ii];
}
s1+=maxi;
}
else
{{int ii,jj;maxi=0;
for (ii=1;ii<=n;ii++)
{int maxim=0;
for (jj=1;jj<ii;jj++)
    if (best[i][jj]>maxim&&a[jj]>=a[ii]) maxim=best[i][jj];
best[i][ii]=1+maxim;
if (best[i][ii]>maxi) maxi=best[i][ii];
}
s2+=maxi;
}
}
}
fout<<s1<<' '<<s2<<'\n';
if (s1>s2) fout<<"UNU";
else if (s1<s2) fout<<"DOI";
else fout<<"REMIZA";
}
