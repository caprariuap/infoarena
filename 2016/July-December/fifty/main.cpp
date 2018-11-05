#include <cstdio>

using namespace std;

int t,n,m,i,j;

void rezolva()
{
    scanf("%d%d",&n,&m);
    int maxa,maxb,x,y;
    maxa=maxb=-1;
    for (i=1; i<=m; i++)
    {
        scanf("%d%d",&x,&y);
        if (x>maxa)
            maxa=x;
        if (y>maxb)
            maxb=y;
    }
    if (maxa+maxb>n)
    {
        printf("-1\n");
        return;
    }
    for (i=1; i<=maxa; i++)
        printf("a");
    for (i=1; i<=n-maxa; i++)
        printf("b");
    printf("\n");
}

int main()
{
    freopen("fifty.in","r",stdin);
    freopen("fifty.out","w",stdout);
    scanf("%d",&t);
    for (int i=1; i<=t; i++)
        rezolva();
}
