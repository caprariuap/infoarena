#include <fstream>
using namespace std;
ifstream fin("perle.in");
ofstream fout("perle.out");
int n,a[10001],i;
int mutareC(int k);
int mutareB(int k);
int mutareB(int k)
{
    if (k+1<=a[0])
        if (a[k]==2) return mutareB(k+1);
    if (k+4<=a[0])
        if (a[k+2]==3&&a[k]==1) return mutareC(k+4);
    return a[0]+2;
}
int mutareC(int k)
{
    if (k+2<=a[0])
        if (a[k]==3) return mutareC(mutareB(k+1));
    if (k+2<=a[0])
        if (a[k]==1&&a[k+1]==2) return k+3;
    if (k<=a[0])
        if (a[k]==2) return k+1;
    return a[0]+2;
}
int main()
{
    fin>>n;
    for (i=1; i<=n; i++)
    {
        fin>>a[0];
        for (int j=1; j<=a[0]; j++) fin>>a[j];
        if (a[0]==1||mutareB(1)==a[0]+1||mutareC(1)==a[0]+1)
            fout<<'1';
        else fout<<'0';
        fout<<'\n';
    }
}
