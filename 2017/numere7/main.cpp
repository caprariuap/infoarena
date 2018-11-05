#include <fstream>

using namespace std;

ifstream fin("numere7.in");
ofstream fout("numere7.out");

long long fact[22],x,i,j,n,ans[22];
int fr[22];
long long pozitie(int j)
{
    fr[j]--;
    long long nr;
    nr=0;
    for (int i=1; i<=9; i++)
        nr+=fr[i];
    nr=fact[nr];
    for (int i=1; i<=9; i++)
        if (fr[i]>0)
            nr/=fact[fr[i]];
    fr[j]++;
    return nr;
}

int main()
{
    fin >> x;
    char c;
    while (fin>>c)
    {
        fr[c-'0']++;
        n++;
    }
    fact[0]=1;
    for (i=1; i<=n; i++)
        fact[i]=fact[i-1]*i;
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=9; j++)
            if (fr[j]>0)
            {
                long long k=pozitie(j);
                if (k>=x)
                    break;
                else
                    x-=k;
            }
        if (j==10)
        {
            //fout << i << ' ' << ans[1] << ' ';
            fout << "-1\n";
            return 0;
        }
        ans[i]=j;
        fr[j]--;
    }
    for (i=1; i<=n; i++)
        fout << ans[i];
    fout << '\n';
}
