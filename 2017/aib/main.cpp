#include <fstream>
#define pu(x) ((x^(x-1))&x)

using namespace std;

ifstream fin("aib.in");
ofstream fout("aib.out");

int aib[100010],i,n,m;

void update(int poz, int x)
{
    for (int i=poz; i<=n; i+=pu(i))
        aib[i]+=x;
}

int query(int poz)
{
    int i,ans=0;
    for (i=poz; i>0; i-=pu(i))
        ans+=aib[i];
    return ans;
}

int opdoi(int a)
{
    if (a==0)
        return -1;
    int poz,bit,curent;
    poz=curent=0;
    bit=1;
    while (bit<=n)
        bit<<=1;
    bit>>=1;
    while (bit>0)
    {
        if (poz+bit<=n&&curent+aib[poz+bit]<=a)
        {
            curent+=aib[poz+bit];
            poz+=bit;
        }
        bit>>=1;
    }
    if (curent!=a)
        return -1;
    else
        return poz;
}

int main()
{
    fin >> n >> m;
    for (i=1; i<=n; i++)
    {
        int x;
        fin >> x;
        update(i,x);
    }
    for (i=1; i<=m; i++)
    {
        int a,b,c;
        fin >> a >> b;
        if (a<2)
        {
            fin >> c;
            if (!a)
                update(b,c);
            else
                fout << query(c)-query(b-1) << '\n';
        }
        else
        fout << opdoi(b) << '\n';
    }
}
