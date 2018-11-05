#include <iostream>
#include <cstdio>

using namespace std;

int euclidextins(int a, int b, int &x, int &y)
{
    if (b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int x0,y0;
    int d=euclidextins(b,a%b,x0,y0);
    x=y0;
    y=x0-(a/b)*y0;
    return d;
}

int main()
{
    freopen("inversmodular.in","r",stdin);
    freopen("inversmodular.out","w",stdout);
    int A,N;
    cin >> A >> N;
    int x,y;
    int d=euclidextins(A,N,x,y);
    if (x<0)
        x+=N;
    cout << x << '\n';
}
