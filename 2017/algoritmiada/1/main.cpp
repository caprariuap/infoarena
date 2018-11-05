#include <fstream>

using namespace std;

ifstream fin("lss.in");
ofstream fout("lss.out");

long long k,p,i,sum,x;

int main()
{
    fin >> k >> p;
    for (i=1; i<=p; i++)
    {
        fin >> x;
        x%=k;
        if (x==0)
            x=k;
        if (x>i)
            sum=sum+x-i+1;
        else
            sum++;
    }
    fout << sum << '\n';
    fin.close();
    fout.close();
}
