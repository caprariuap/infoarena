#include <fstream>
using namespace std;
ifstream fin("joc.in");
ofstream fout("joc.out");
int n,m,a[1002][1002],b[1002][1002],l,cc,i,j,maxib=-30000,maxim;
int maxi1(int a,int b,int c,int d)
{int maxif=a;
if (maxif<b)
    maxif=b;
if (maxif<c)
    maxif=c;
if (maxif<d)
    maxif=d;
return maxif;
}
int main()
{fin>>n>>m;
for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
{fin>>a[i][j];
b[i][j]=maxi1(b[i-1][j],b[i][j-1],a[i][j]-b[i][j-1],a[i][j]-b[i-1][j]);
if (b[i][j]>maxib) l=i,cc=j,maxib=b[i][j];
}
fout<<maxib<<' '<<l<<' '<<cc<<'\n';
}
