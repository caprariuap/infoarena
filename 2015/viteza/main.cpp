#include <fstream>
using namespace std;
ifstream fin("viteza.in");
ofstream fout("viteza.out");
int n,i,x,s[10001],va,vb,r,j;
int main()
{fin>>n;
for (i=0;i<n;i++)
{fin>>x;
x=x<<2;
va+=x;
}
for (i=0;i<n;i++)
{fin>>x;
x=x<<2;
vb+=x;
}
while (vb!=0)
{r=va%vb;
va=vb;
vb=r;
}
i=1;
while (va>0)
{s[i]=va%2;
i++;
va/=2;
}
i--;
for (j=i;j>=1;j--)
    fout<<s[j]<<' ';
for (j=n;j>i;j--)
    fout<<'0'<<' ';
}
