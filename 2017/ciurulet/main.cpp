#include <fstream>
#include <vector>
#define nmax 1000010

using namespace std;

ifstream fin("ciurulet.in");
ofstream fout("ciurulet.out");

int n,i,j;
char s[nmax],sol[nmax];

int main()
{
    fin >> n;
    for (i=2; i<=n; i++)
        {
            fin >> s[i];
            sol[i]=s[i];
        }
    for (i=2; i<=n; i++)
    {
        char c;
        c=s[i];
        if (c=='1')
        {
            for (j=2*i; j<=n; j+=i)
                sol[j]='1';
        }
        else if (c=='?'&&sol[i]!='1')
        {
            bool ok=1;
            for (j=2*i; j<=n; j+=i)
                if (s[j]=='1')
                    ok=0;
            if (ok)
            sol[i]='1';
            else
                sol[i]='0';
            if (ok)
            {
                for (j=2*i; j<=n; j+=i)
                    sol[j]='1';
            }
        }
        //fout << c;
    }
    //fout << "\n\n\n\n";
    int ans=0;
    for (i=2; i<=n; i++)
        if (sol[i]=='1')
            ans++;
    fout << ans << '\n';
//    for (i=2; i<=n; i++)
//        fout << realprime[i];
//    fout << '\n';
//    for (i=2; i<=n; i++)
//        fout << prim[i];
//    fout << '\n';
    for (i=2; i<=n; i++)
        fout << sol[i];
    fout << '\n';
    fin.close();
    fout.close();
    return 0;
}
