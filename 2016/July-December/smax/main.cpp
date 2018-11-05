#include <cstdio>
#include <algorithm>
#define DIM 10000000
#define max(a,b) a>b ? a:b
#define min(a,b) a<b ? a:b

using namespace std;

struct punct{int nr,x,y;} a[1010000];

int n,m,d,t,i,j,z,h,maxim;
char buff[DIM];
int poz=0;

FILE * f=fopen("smax.in","r");

bool cmp(punct a, punct b)
{
    if (a.nr<b.nr)
        return 1;
    return 0;
}

void smax()
{
    maxim=-1;
    fscanf(f,"%d",&n);
    fscanf(f,"%d",&m);
    fscanf(f,"%d",&d);
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            fscanf(f,"%d",&a[(i-1)*m+j].nr),a[(i-1)*m+j].x=i,a[(i-1)*m+j].y=j;
    sort(a+1,a+n*m+1,cmp);
    for (i=n*m; i>1; i--)
        for (j=i-1; j>0&&a[j].nr+a[i].nr>maxim; j--)
        if (abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)<=d)
            maxim=a[i].nr+a[j].nr;
    printf("%d\n",maxim);
//    for (i=1; i<=n; i++)
//    {
//        for (j=1; j<=m; j++)
//            printf("%d ",ans[i][j]);
//        printf("\n");
//    }
//    printf("\n");
//    for (i=1; i<=n; i++)
//    {
//        for (j=1; j<=m; j++)
//            printf("%d ",pir[i][j][log[d]]);
//        printf("\n");
//    }
//    printf("\n");
}

int main()
{
    freopen("smax.out","w",stdout);
//    freopen("smax.in","r",stdin);
//    FILE * g=fopen("smax.out","w");
//        for (i=1; i<=500; i++)
//    {
//        for (j=1; j<=500; j++)
//            printf("%d ",i*j);
//        printf("\n");
//    }
    fscanf(f,"%d",&t);
    for (int yy=1; yy<=t; yy++)
        smax();
}
