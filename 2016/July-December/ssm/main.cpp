#include <fstream>
using namespace std;
ifstream fin("ssm.in");
ofstream fout("ssm.out");
int n,i,x,inc,sf,best,sum,is;
int main()
{
    fin>>n;
    best=-2000000000;
    for (i=1; i<=n; i++)
    {
        fin>>x;
        if (sum+x>=x)
            sum+=x;
        else
            sum=x,inc=i;
        if (sum>best)
            best=sum,sf=i,is=inc;
    }
    fout<<best<<' '<<is<<' '<<sf<<'\n';
}
