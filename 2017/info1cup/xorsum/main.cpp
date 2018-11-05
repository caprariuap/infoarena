#include <iostream>
#define pu(x) ((x^(x-1))&x)
using namespace std;

//sums[i] = cate perechi de numere au bitul i al sumei lor cu valoarea 0
//nr[i][j] = cate numere pana la i-1 au toti bitii intre i si j egali cu 0

int aib[40000],i,n,m,v[40000],sum,use[40000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (i=1; i<=n; i++)
    {
        cin >> v[i];
        if (v[i]<=40000)
            use[v[i]]++;
    }
    if (n<=4000)
    {
        int sum=0;
        for (i=1; i<=n; i++)
            for (int j=i; j<=n; j++)
                sum=(sum^(v[i]+v[j]));
        cout << sum << '\n';
        return 0;
    }
    for (i=0; i<=4000; i++)
        if (use[i])
            for (int j=i; j<=4000; j++)
                if (use[j])
                {
                    int k=use[i]*use[j];
                    if (k%2&&i!=j)
                        sum=(sum^(i+j));//,cout << i << ' ' << j << '\n';
                    if (i==j&&(use[j]%2==0||use[j]==1))
                        sum=(sum^(i+j));//,cout << i << ' ' << j << '\n';
                }
    cout << sum << '\n';
}
