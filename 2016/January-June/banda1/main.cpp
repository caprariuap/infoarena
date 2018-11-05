#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("banda1.in");
ofstream fout("banda1.out");
int n,gmax,g[26],minim=65000,nrc;
int c[3];
void bkt(int k)
{if (k>n)
{if (nrc<minim) minim=nrc;
}
else
{int i;
for (i=1;i<=2;i++)
{if (c[i]+g[k]<=gmax)
c[i]+=g[k],bkt(k+1),c[i]-=g[k];
else
{int aux=c[i];
c[i]=g[k];nrc++;
if (nrc<minim) bkt(k+1);nrc--;c[i]=aux;
}
}
}
}
int main()
{fin>>n>>gmax;
for (int i=1;i<=n;i++)
    fin>>g[i];
nrc=2;
bkt(1);
fout<<minim;
}
