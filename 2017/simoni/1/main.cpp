#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("mission.in");
ofstream fout("mission.out");

int n,i;

struct punct
{
    long long x,y;
    int poz;
} a[1010];

struct pctcentru
{
    long double x,y;
} centru;

long double cp(pctcentru A, punct B, punct C)
{
    return (long double)((B.y-A.y)*(C.x-A.x)-(C.y-A.y)*(B.x-A.x));
}

class cmp
{
public:
    bool operator()(punct A, punct B)
    {
        return cp(centru,A,B)<0;
    }
};

int main()
{
    fin >> n;
    long long sx,sy;
    sx=sy=0;
    for (i=1; i<=n; i++)
        fin >> a[i].x >> a[i].y,a[i].poz=i-1,sx+=a[i].x,sy+=a[i].y;
    centru.x=sx/n;
    centru.y=sy/n;
    sort(a+1,a+n+1,cmp());
    int start;
    for (i=1; i<=n; i++)
        if (a[i].poz==0)
        start=i;
    for (i=start; i<=n; i++)
        fout << a[i].poz << ' ';
    for (i=1; i<start; i++)
        fout << a[i].poz << ' ';
    fout << '\n';
//    for (i=1; i<=n; i++)
//        fout << a[i].poz << ' ';
}
