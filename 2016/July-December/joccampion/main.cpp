#include <cstdio>
#define max(a,b) a>b ? a : b

using namespace std;

FILE *fin=fopen("joc.in","r");
FILE *fout=fopen("joc.out","w");

int n,a[1010],m[1010][1010],i,j;
bool mat[1010][1010];

int dp(int i, int j)
{
    if (mat[i][j])
        return m[i][j];
    mat[i][j]=1;
    if (i+1==j)
    {
        m[i][j]=max(a[i]-a[j],a[j]-a[i]);
        return m[i][j];
    }
    if (a[i+1]<a[j])
        m[i][j]=a[i]+dp(i+1,j-1)-a[j];
    else
        m[i][j]=a[i]+dp(i+2,j)-a[i+1];
    if (a[i]<a[j-1])
        m[i][j]=max(m[i][j],a[j]+dp(i,j-2)-a[j-1]);
    else
        m[i][j]=max(m[i][j],a[j]+dp(i+1,j-1)-a[i]);
    return m[i][j];
}

int main()
{
    fscanf(fin,"%d",&n);
    for (i=1; i<=n; i++)
        fscanf(fin,"%d",&a[i]);
    fprintf(fout,"%d\n",dp(1,n));
}
