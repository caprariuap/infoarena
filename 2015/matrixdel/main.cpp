#include <fstream>
using namespace std;
ifstream fin("matrixdel.in");
ofstream fout("matrixdel.out");
int l,c,p,q,i,j,a[102][102],x,k;
int main()
{fin>>l>>c;
for (i=1;i<=l;i++)
    for (j=1;j<=c;j++)
    fin>>a[i][j];
fin>>p;
for (i=1;i<=p;i++)
{fin>>x;
for (k=x+1-i;k<=l;k++)
for (j=1;j<=c;j++)
    a[k][j]=a[k+1][j];
l--;
}
fin>>q;
for (i=1;i<=q;i++)
{fin>>x;
for (k=x+1-i;k<=c;k++)
for (j=1;j<=l;j++)
    a[j][k]=a[j][k+1];
c--;
}
for (i=1;i<=l;i++)
{for (j=1;j<=c;j++)
    fout<<a[i][j]<<' ';
fout<<endl;
}
}
