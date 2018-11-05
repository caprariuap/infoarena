#include <fstream>
using namespace std;
ifstream fin("morse.in");
ofstream fout("morse.out");
int s,i,smax,y,nr,a[17];
short int k,aa,b;
short int nr1bin(int x)
{s=0;
while (x>0)
{y=x%2;
x/=2;
s+=y;
}
return s;
}
int main()
{fin>>aa>>b;
for (i=aa;i<=b;i++)
{if (nr1bin(i)>smax)
smax=nr1bin(i);
}
for (i=aa;i<=b;i++)
{if (nr1bin(i)==smax)
{k=i;
nr=0;
while (k>0)
{a[nr]=k%2;
nr++;
k/=2;
}
nr--;
for (k=nr;k>=0;k--)
    if (a[k]==1)
    fout<<'-';
else
    fout<<'.';
fout<<' ';
}
}
}
