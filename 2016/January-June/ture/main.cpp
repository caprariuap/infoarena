#include <fstream>
using namespace std;
ifstream fin("ture.in");
ofstream fout("ture.out");
int n,a[101][101],sl,sc,i,j,smax,s,ss,ii,jj,iii,jjj;
void citire()
{fin>>n;
for (int i=1;i<=n;i++)
{sl=0;
for (int j=1;j<=n;j++)
    fin>>a[i][j],sl+=a[i][j];
a[i][0]=sl;
}
}
int main()
{citire();
for (i=1;i<=n;i++)
{sc=0;
for (j=1;j<=n;j++)
    sc+=a[j][i];
a[0][i]=sc;
}
for (i=1;i<=n;i++)
for (j=1;j<=n;j++)
{s=a[0][j]+a[i][0]-2*a[i][j];
if (s>smax)
    {smax=s;ii=i;jj=j;
    }
}
a[ii][0]=0;
a[0][jj]=0;
for (i=1;i<=n;i++)
    a[0][i]-=a[ii][i],a[ii][i]=0,a[i][0]-=a[i][jj],a[i][jj]=0;
for (i=1;i<=n;i++)
for (j=1;j<=n;j++)
{s=a[0][j]+a[i][0]-2*a[i][j];
if (i==ii)
    s-=a[i][0]+a[i][j];
if (j==jj)
    s-=a[0][j]+a[i][j];
if (s>ss)
    ss=s,iii=i,jjj=j;
}
smax+=ss;
fout<<smax;
}
