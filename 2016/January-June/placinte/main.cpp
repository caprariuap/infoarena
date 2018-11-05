#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("pomi.in");
ofstream fout("pomi.out");
int a[81],b[81],k,i,m;
char s[81],c;

int main()
{fin.getline(s,81);a[0]=strlen(s);
for (i=a[0]-1;i>=0;i--)
    a[a[0]-i]=s[i]-'0';
fin.getline(s,81);b[0]=strlen(s);
for (i=b[0]-1;i>=0;i--)
    b[b[0]-i]=s[i]-'0';
fin>>k;
int c[81];
c[0]=1;
c[1]=1;
while (rest(a,k)>0) adunare(a,c);
while (rest(b,k)>0) scadere(b,c);
scadere (b,a);
impartire (b,k);
for (i=b[0];i;i--) fout<<b[0];
}
