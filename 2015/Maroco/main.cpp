#include <fstream>
using namespace std;
ifstream fin("maroco.in");
ofstream fout("maroco.out");
int p,n,scora,scorb,a[101][105];
void citire()
{fin>>n;
for (int i=1;i<=n;i++)
{fin>>a[i][1]>>a[i][2];
for (int j=3;j<=a[i][2]+2;j++)
    fin>>a[i][j];
}
}
void rezolvare()
{int maxim=0,ncurent=0,pozitie;
while (ncurent<n)
{ncurent++;
maxim=0;
for (int i=1;i<=n;i++)
{if (a[i][2]==0&&a[i][1]>maxim)
maxim=a[i][1],pozitie=i;
}
a[pozitie][2]=-1;
if (ncurent%2==1)
scora+=maxim;
else
    scorb+=maxim;
for (int i=1;i<=n;i++)
{for (int j=3;j<=a[i][2]+2;j++)
if (a[i][j]==pozitie)
    {a[i][j]=0;
    for (int k=j;k<a[i][2]+2;k++)
        a[i][k]=a[i][k+1];
    a[i][2]--;}
}
}
}
int main()
{citire();
rezolvare();
if (scora>scorb)
    fout<<'1'<<' '<<scora;
else
    if (scora==scorb)
    fout<<'0'<<' '<<scora;
else
    fout<<'2'<<' '<<scorb;
}
