#include <fstream>

using namespace std;

ifstream fin("xor3.in");
ofstream fout("xor3.out");

int Q,i1,j1,A,B,m,i,j;
int a[500][500];

int main()
{
    fin >> Q >> i1 >> j1 >> A >> B >> m;
    for (i=1; i<=100; i++)
        a[0][i]=i;
    for (i=1; i<=100; i++)
    {
        for (j=1; j<=100; j++)
            a[i][j]=a[i][j-1]^a[i-1][j];
    }
    for (i=0; i<=100; i++)
    {
        for (j=0; j<=100; j++)
            fout << a[i][j] << ' ';
        fout << '\n';
    }
}
