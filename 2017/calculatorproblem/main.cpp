#include <iostream>

using namespace std;

int ans[10061],a,b,vf,bz,i,c[50000];

int main()
{
    while (cin>>a>>b)
    {
        vf=-1;
        bz=0;
        for (int i=0; i<=10000; i++)
            ans[i]=1000000;
        c[++vf]=a;
        ans[a]=0;
        while (vf>=bz)
        {
            if (ans[(c[bz]+1)%10000]>ans[c[bz]]+1)
            {
                ans[(c[bz]+1)%10000]=ans[c[bz]]+1;
                c[++vf]=(c[bz]+1)%10000;
            }
            if (ans[c[bz]*2%10000]>ans[c[bz]]+1)
            {
                ans[c[bz]*2%10000]=ans[c[bz]]+1;
                c[++vf]=c[bz]*2%10000;
            }
            if (ans[c[bz]/3]>ans[c[bz]]+1)
            {
                ans[c[bz]/3]=ans[c[bz]]+1;
                c[++vf]=c[bz]/3;
            }
            bz++;
        }
        cout<<ans[b]<<'\n';
    }
}
