#include <fstream>

using namespace std;

ifstream fin("maxk.in");
ofstream fout("maxk.out");

int k,n,v[1000010],fr[100010];
int i,j;
int minim=1000001;

int main()
{
    fin>>n>>k;
    for (i=1; i<=n; i++)
    {
        fin>>v[i];

        fr[v[i]]++;
    }
    i=1;
    j=1;int ok;
    int h;
    while (i<=n&&j<=n&&i<=j)
    {
        for (h=i; h<=j; h++)
            fr[v[h]]--;
        ok=1;
        for (h=1; h<=100000&&ok; h++) if (fr[v[h]]>k) ok=0;
        for (h=i; h<=j; h++) fr[v[h]]++;
        if (ok)
        {
            if (minim>j-i+1) minim=j-i+1;
i++;
        }
        else j++;
    }
    fout<<minim<<'\n';
}
