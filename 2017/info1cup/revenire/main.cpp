#include <fstream>
#include <algorithm>
#define val 500000

using namespace std;

ifstream fin("revenire.in");
ofstream fout("revenire.out");

long long n,x,i,q[1000000],s[100010],rightin[100010],nrsub,sumsub,S[100010],vf,bz,j;

int main()
{
    fin >> n >> x;
    for (i=1; i<=n; i++)
        fin >> q[val+i],s[i]=s[i-1]+q[val+i];
    vf=val+n;
    bz=val+1;
    nrsub=0;
    sumsub=0;
    for (i=1; i<=n; i++)
        S[i]=S[i-1]+s[i];
    for (i=1; i<=n; i++)
    {
        rightin[i]=upper_bound(s+i+1,s+n+1,x+s[i-1])-s-1;
        nrsub=nrsub+rightin[i]-i+1;
        sumsub=sumsub+S[rightin[i]]-S[i-1]-(rightin[i]-i+1)*s[i-1];
        leftin[rightin[i]]=i;
    }
    fout << sumsub << ' ' << nrsub << '\n';
//    for (i=1; i<=n; i++)
//        fout << rightin[i] << ' ';
    for (i=2; i<=n; i++)
    {
        bz++;
        q[++vf]=q[bz-1];
//        for (j=bz; j<=vf; j++)
//            fout << q[j] << ' ';
//        fout << '\n';
        nrsub=nrsub-(rightin[i-1]-(i-1)+1);
        sumsub=sumsub-(S[rightin[i-1]]-S[i-1-1]-(rightin[i-1]-(i-1)+1)*s[i-1-1]);
        nrsub=nrsub+i-1-leftin[i-1]+1;
    }
}
