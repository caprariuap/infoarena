#include <fstream>
#define modd(n,x) (n-n/x*x)

using namespace std;

ifstream fin("perechi.in");
ofstream fout("perechi.out");

long long ans;
int n,k,d,nr;

int main()
{
    fin >> n;
    ans=1;
    int ni=n;
    d=2;
    if (d*d==ni)
    {
        fout << 4 << '\n';
        return 0;
    }
    bool prim=1;
    if (n%2==0)
        prim=0;
    if (prim)
    for (int i=3; i*i<=n; i+=2)
        if (n%i==0)
        prim=0;
    if (prim)
    {
        fout << 2 << '\n';
        return 0;
    }
    if (modd(n,2)==0)
    {
        ++nr;
        k=0;
        while (modd(n,2)==0&&n>1)
            ++k,n/=2;
        ans=ans*(2*k+1);
    }
    d=3;
    while (n>1)
    {
        if (modd(n,d)==0)
        {
            ++nr;
            k=0;
            while (modd(n,d)==0&&n>1)
                ++k,n/=d;
            ans=ans*(2*k+1);
            if (d*d==ni)
            {
                fout << 4 << '\n';
                return 0;
            }
        }
        d+=2;
    }
    fout << (ans+1)/2 << '\n';
    return 0;
}
