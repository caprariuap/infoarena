#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

ifstream fin("mosia.in");
ofstream fout("mosia.out");

struct punct
{
    int x,y,d;
} a[1010],minim;

long double dp[1010],dp2[1010];
int n,i,j,poz;

int cp(punct A, punct B, punct C)
{
    return (B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y);
}

long double lungime(punct A, punct B)
{
    return sqrt((B.y-A.y)*(B.y-A.y)+(B.x-A.x)*(B.x-A.x));
}

bool maiaproape(punct A, punct B, punct C)
{
    if (B.x<=A.x)
    {
        if (C.x>A.x)
            return 1;
        else
            return lungime(A,B)<lungime(A,C);
    }
    return lungime(A,B)>lungime(A,C);
}

bool cmp(punct A, punct B)
{
    int K=cp(a[1],A,B);
    if (K<0)
        return 1;
    if (K==0&&maiaproape(a[1],A,B))
        return 1;
    return 0;
}

int main()
{
    fin >> n;
    minim.x=minim.y=151225;
    for (i=1; i<=n; i++)
    {
        fin >> a[i].x >> a[i].y >> a[i].d;
        if (a[i].y<minim.y||(a[i].y==minim.y&&a[i].x<minim.x))
            minim=a[i],poz=i;
    }
    punct aux;
    aux=a[1];
    a[1]=a[poz];
    a[poz]=aux;
    sort(a+2,a+n+1,cmp);
    dp[1]=a[1].d*lungime(a[n],a[2])/2;
    for (i=2; i<n; i++)
    {
        int st,dr;
        st=i-1;
        dr=i+1;
        dp[i]=dp[i-1];
        if (dp[i]<dp[i-2]+a[i].d*lungime(a[st],a[dr])/2)
            dp[i]=dp[i-2]+a[i].d*lungime(a[st],a[dr])/2;
    }
    dp[n]=dp[n-1];
    for (i=2; i<=n; i++)
    {
        int st,dr;
        st=i-1;
        dr=i+1;
        if (st<1)
            st=n;
        if (dr>n)
            dr=1;
        dp2[i]=dp2[i-1];
        if (dp2[i]<dp2[i-2]+a[i].d*lungime(a[st],a[dr])/2)
            dp2[i]=dp2[i-2]+a[i].d*lungime(a[st],a[dr])/2;
    }
    fout << fixed << setprecision(4) << max(dp[n],dp2[n]) << '\n';
//    for (i=1; i<=n; i++)
//        fout << a[i].x << ' ' << a[i].y << '\n';
}
