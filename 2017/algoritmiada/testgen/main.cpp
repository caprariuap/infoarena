#include <fstream>

using namespace std;
ifstream fin("ok.in");
ofstream fout("ok.out");

int main()
{
    long long i,rng;
    rng=23;
    fout << 1000000000 << ' ' << 1000000000 << '\n';
    for (i=1; i<=100000; i++)
        fout << ((i*rng+rng/45)%1000000000) << ' ';
}
