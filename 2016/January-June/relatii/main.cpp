#include <fstream>
using namespace std;
ifstream fin("relatii.in");
ofstream fout("relatii.out");
char c1,c2,c3;
int p[11],i,st,dr,n,m,j,r[11][11];
int verificare()
{for (i=1;i<n;i++)
for (j=i+1;j<=n;j++)
if (r[p[i]][p[j]]==1) return 0;
return 1;
}
int main()
{fin>>n>>m;
for (i=1;i<=m;i++)
{fin>>c1>>c2>>c3;
if (c2=='>')
    {r[c1-'a'+1][c3-'a'+1]=1;r[c3-'a'+1][c1-'a'+1]=-1;}
else
    {r[c1-'a'+1][c3-'a'+1]=-1;r[c3-'a'+1][c1-'a'+1]=1;}
}
for (i=1;i<=n;i++)
    p[i]=i;
while (1)
{if (verificare())
break;
for (j=n-1;p[j]>p[j+1];j--);
for (i=n;p[i]<p[j];i--);
swap(p[i],p[j]);
for (st=j+1,dr=n;dr>st;st++,dr--)
    swap(p[st],p[dr]);
}
for (i=1;i<=n;i++)
fout<<(char)(p[i]+'a'-1);
}
