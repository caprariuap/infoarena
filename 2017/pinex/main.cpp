#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("pinex.in");
ofstream fout("pinex.out");

bool nonprim[1000010];
int nrprime[1000000],nrp,i,j;
long long a,b,v[1000000],nr,ans;

void ciur()
{
    nonprim[1]=1;
    nrprime[++nrp]=2;
    for (i=3; i<=1000000; i+=2)
        if (nonprim[i]==0)
        {
            nrprime[++nrp]=i;
            for (j=2*i; j<=1000000; j+=i)
                nonprim[j]=1;
        }
}

void solve()
{
    nr=0;
    ans=0;
    fin >> a >> b;
    int d=0;
    while (b > 1)
    {
        d++;
        if (b%nrprime[d]==0)
        {
            v[++nr]=nrprime[d];
            while (b%nrprime[d]==0)
                b/=nrprime[d];
        }
        if (nrprime[d]>sqrt(b)&&b>1)
        {
            v[++nr]=b;
            b=1;
        }
    }
    long long nr2=(1<<nr)-1;
    for (i=1; i<=nr2; i++)
    {
        int nrbiti=0;
        long long produs=1;
        for (j=0; j<nr; j++)
            if ((1<<j)&i)
                nrbiti++,produs*=v[j+1];
        if (nrbiti%2==1)
            ans=ans+a/produs;
        else
            ans=ans-a/produs;
        //fout << ans << ' ' << nrbiti << ' ' << produs << '\n';
    }
    fout << a-ans << '\n';
}

int main()
{
    int T;
    fin >> T;
    ciur();
    for (int z=1; z<=T; z++)
        solve();
}
