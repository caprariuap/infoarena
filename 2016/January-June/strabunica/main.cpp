#include <fstream>

using namespace std;

ifstream fin("strabunica.in");
ofstream fout("strabunica.out");

long long n,i,j,x,vf,maxim,a[200010],inc[200010];
long long poz[200010];

int main()
{
    fin>>n;
    for (i=1; i<=n; i++)
    {
       fin>>x;
       while (a[vf]>x) {
            if ((i-inc[vf])*a[vf]>maxim)
            maxim=(i-inc[vf])*a[vf];
       vf--;}
       a[++vf]=x;
       poz[vf]=i;
 inc[vf]=poz[vf-1]+1;
    }
    for (i=1;i<=vf;i++)
    {if ((n-inc[i]+1)*a[i]>maxim) maxim=a[i]*(n-inc[i]+1);}
    fout<<maxim<<'\n';
}
