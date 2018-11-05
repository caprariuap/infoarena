#include <fstream>

using namespace std;

ifstream fin("albinuta.in");
ofstream fout("albinuta.out");

int n,q,i,j,l[55],v[55][55],ans[200000],pozin,lgc,cmmmc;

int gcd(int a, int b)
{
    int r;
    while (b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int next(int node, int time)
{
//    time%=cmmmc;
//    if (time==0)
//        time=cmmmc;
    int ret=time%l[node];
    if (ret==0)
        ret=l[node];
    return v[node][ret];
}

void floyd()
{
    int tortoise,hare;
    tortoise=next(1,1);
    hare=next(tortoise,2);
    int th,tt;
    tt=2;
    th=3;
    while (tortoise!=hare||((th%cmmmc)!=(tt%cmmmc)))
    {
        tortoise=next(tortoise,tt);
        tt++;
        hare=next(hare,th);
        th++;
        hare=next(hare,th);
        th++;
    }
    pozin=1;
    tortoise=1;
    tt=1;
    while (tortoise!=hare||((th%cmmmc)!=(tt%cmmmc)))
    {
        tortoise=next(tortoise,tt);
        tt++;
        hare=next(hare,th);
        th++;
        pozin++;
    }
    lgc=1;
    th=tt;
    hare=next(tortoise,th);
    th++;
    while (tortoise!=hare||((th%cmmmc)!=(tt%cmmmc)))
        hare=next(hare,th),th++,lgc++;
}

int main()
{
    fin >> n >> q;
    for (i=1; i<=n; i++)
    {
        fin >> l[i];
        for (j=1; j<=l[i]; j++)
            fin >> v[i][j];
    }
    cmmmc=l[1];
    for (i=2; i<=n; i++)
        cmmmc=cmmmc*l[i]/gcd(cmmmc,l[i]);
//    ans[1]=1;
//    for (i=2; i<=cmmmc; i++)
//            ans[i]=v[ans[i-1]][(i-2)%l[ans[i-1]]+1];
//    fout << next(1,1) << ' ' << next(next(1,1),2) << ' ' << next(next(next(1,1),2),3) << ' ' << next(next(next(next(1,1),2),3),4);
//    i=1;
//    j=1;
//    for (int k=1; k<=30; k++)
//    {
//        fout << i << '\n';
//        i=next(i,j);
//        j++;
//    }
//    fout << '\n';
    floyd();
    int time=1;
    ans[1]=1;
    for (i=1; i<=pozin+lgc-1; i++)
        ans[i+1]=next(ans[i],time),time++;
    for (i=1; i<=q; i++)
    {
        int t;
        fin >> t;
        if (t>pozin+lgc-1)
            t=pozin+(t-pozin)%lgc;
        if ((t-pozin)%lgc==0)
            t+=lgc;
        fout << ans[t] << '\n';
    }
//    fout << pozin << ' ' << lgc << ' ';

}
