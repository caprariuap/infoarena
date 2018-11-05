#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("alfabetar.in");
ofstream fout("alfabetar.out");
char s[102][202];
int n,i,j,l,lmax;
int main()
{fin>>n;
for (i=0;i<n;i++)
{fin>>s[i];
l=strlen(s[i]);
if (l>lmax)
    lmax=l;
}

for (i=0;i<n;i++)
{for (j=0;j<lmax;j++)
if (s[i][j]=='\0')
    s[i][j]=' ';
}
for (i=lmax-1;i>=0;i--)
{for (j=0;j<n;j++)
fout<<s[j][i];
fout<<endl;
}
    return 0;
}
