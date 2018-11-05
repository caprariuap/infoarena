#include <fstream>
#define nmax 1050

using namespace std;

ifstream fin("text5.in");
ofstream fout("text5.out");

int n,i,s[nmax*nmax],lastpos[2][3*nmax],salt[nmax*nmax][2],dp[nmax*nmax][2];

int getkey(int poz, int type)
{
    if (poz+type+2>n+1)
        return -1;
    if (type==0)
        return s[poz]*10+s[poz+1];
    return s[poz]*100+s[poz+1]*10+s[poz+2];
}

int memoizare(int poz, int type)
{
    if (salt[poz][type])
        return salt[poz][type];
    if (poz+type+2>n)
        return poz+type+2;
    int aux=lastpos[type][(poz%(type+2))*1000+getkey(poz,type)];
    if (aux+type+2>n||aux==poz)
    {
        salt[poz][type]=aux+type+2;
        return salt[poz][type];
    }
    int aux2=poz+2+type;
    while (aux2<=aux)
        aux2=memoizare(aux2,type);
    salt[poz][type]=aux2;
    return salt[poz][type];
}

int main()
{
    fin >> n;
    for (i=1; i<=n; i++)
    {
        char c;
        fin >> c;
        s[i]=c-'0';
    }
    for (i=1; i<=n; i++)
    {
        int key0,key1;
        key0=getkey(i,0);
        key1=getkey(i,1);
        if (key0>0)
            {
                int x=i%2;
                lastpos[0][x*1000+key0]=i;
            }
        if (key1>0)
            {
                int x=i%3;
                lastpos[1][x*1000+key1]=i;
            }
    }
    for (i=0; i<=n+5; i++)
        dp[i][0]=dp[i][1]=-1000000000;
    dp[n+1][0]=dp[n+1][1]=0;
    for (i=n-1; i; i--)
    {
        int pos=memoizare(i,0);
        dp[i][0]=max(dp[pos][0],dp[pos][1])+1;
        if (i<n-1)
        {
            pos=memoizare(i,1);
            dp[i][1]=max(dp[pos][0],dp[pos][1])+1;
        }
    }
    fout << max(dp[1][1],dp[1][0]) << '\n';
//    for (i=1; i<=n; i++)
//        fout << dp[i][0] << ' ';
//    fout << '\n';
//    for (i=1; i<=n; i++)
//        fout << dp[i][1] << ' ';
//    fout << '\n';
    int pos=1;
    while (pos<=n)
    {
        if (dp[pos][0]>dp[pos][1])
        {
            fout << pos << " 2\n";
            pos=memoizare(pos,0);
        }
        else
        {
            fout << pos << " 3\n";
            pos=memoizare(pos,1);
        }
    }
}
