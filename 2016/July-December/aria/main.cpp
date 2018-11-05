#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

ifstream fin("aria.in");
ofstream fout("aria.out");

struct puncte
{
    long double x,y;
} p[100010];
int n,i;
long double s;

long double arie(puncte a, puncte b, puncte c)
{
    return (a.x*b.y+b.x*c.y+a.y*c.x-b.y*c.x-a.y*b.x-a.x*c.y)/2;
}

int main()
{
    fin>>n;
    for (i=1; i<=n; i++)
        fin>>p[i].x>>p[i].y;
    for (i=2; i<n; i++)
    {
        s+=arie(p[1],p[i],p[i+1]);
    }
    fout << fixed << setprecision(5) << abs(s);
}
/*
     (x1 y1 1)
A=DET(x2 y2 1)*1/2=(x1(y2-y3)+y1(x2-x3)+y2x3-x2y3)/2
     (x3 y3 1)
*/
