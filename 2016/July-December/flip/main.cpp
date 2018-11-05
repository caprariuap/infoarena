#include <iostream>
#include <cstdio>

using namespace std;

int n,m,i,j,a[20][20],p,smax,use[20];

int main()
{
    freopen("flip.in","r",stdin);
    freopen("flip.out","w",stdout);
    cin >> n >> m;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            cin >> a[i][j];
    p=(1<<m);
    for (int z=0; z<=p; z++)
    {
        for (j=1; j<=m; j++)
            use[j]=0;
        int s=0;
        for (j=1; j<=m; j++)
            if ((1<<(j-1)&z)>0)
                use[j]=1;
        for (i=1; i<=n; i++)
        {
            int sum=0;
            for (j=1; j<=m; j++)
                if (use[j]==1)
                    sum-=a[i][j];
                else
                    sum+=a[i][j];
            if (sum<0)
                s=s-sum;
            else
                s=s+sum;
        }
        if (s>smax)
            smax=s;
    }
    cout << smax << '\n';
}
