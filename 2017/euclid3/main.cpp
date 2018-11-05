#include <fstream>

using namespace std;

ifstream fin("euclid3.in");
ofstream fout("euclid3.out");

int euclidextins(int a, int b, int &x, int &y)
{
    if (b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int x0,y0,d;
    d=euclidextins(b,a%b,x0,y0);
    x=y0;
    y=x0-(a/b)*y0;
    return d;
}

int main()
{
    int T;
    fin >> T;
    for (int i=1; i<=T; i++)
    {
        int a,b,c;
        fin >> a >> b >> c;
        int d,x,y;
        d=euclidextins(a,b,x,y);
        if (c%d==0)
            fout << x*(c/d) << ' ' << y*(c/d) << '\n';
        else
            fout << "0 0\n";
    }
}
