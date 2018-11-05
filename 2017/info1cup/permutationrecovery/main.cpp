#include <fstream>
#define nmax 70010

using namespace std;

ifstream fin("input");
ofstream fout("output");

int n,q[nmax],nbigger[nmax],i,j;

int main()
{
    fin >> n;
    for (i=1; i<=n; i++)
        {
            fin >> q[i];
            nbigger[i]=(2*q[i-1]+1-q[i])/2;
        }
    for (i=1; i<=n; i++)
        fout << nbigger[i] << '\n';
}
