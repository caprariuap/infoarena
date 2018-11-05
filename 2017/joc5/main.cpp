#include <fstream>

using namespace std;

ifstream fin("joc5.in");
ofstream fout("joc5.out");

int n,i,j,x,ans;

void solve()
{
    ans=0;
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
        {
            fin >> x;
            if (i==j)
                ans=(ans^x);
        }
    if (ans==0)
        fout << "2\n";
    else
        fout << "1\n";
}

int main()
{
    fin >> n;
    while (n!=0)
    {
        solve();
        fin >> n;
    }
    fin.close();
    fout.close();
    return 0;
}
