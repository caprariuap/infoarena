#include <cstdio>

using namespace std;

int n,p2[21],i,j,nr;
long long p3[21],p5[21],val1,val2;

long long trei(long long x)
{
    long long numar,cx;
    numar=cx=x;
    int bit=0;
    while (cx)
    {
        if (cx%2==1)
            numar=numar-p2[bit]+p3[bit];
        cx/=2;
        bit++;
    }
    return numar;
}

long long cinci(long long x)
{
    long long numar,cx;
    numar=cx=x;
    int bit=0;
    while (cx)
    {
        if (cx%2==1)
            numar=numar-p2[bit]+p5[bit];
        cx/=2;
        bit++;
    }
    return numar;
}

int main()
{
    freopen("3si5.in","r",stdin);
    freopen("3si5.out","w",stdout);
    scanf("%d ", &n);
    printf("1\n1\n");
    p2[0]=p3[0]=p5[0]=1;
    for (i=1; i<=20; i++)
        p2[i]=p2[i-1]*2,p3[i]=p3[i-1]*3,p5[i]=p5[i-1]*5;
    val1=3;
    val2=5;
    nr=2;
    i=j=2;
    while (nr<2*n)
    {
        if (i==n+1)
        {
            printf("%lld",val2);
            val2=cinci(++j);
        }
        else
        {
            if (val1<val2)
            {
                printf("%lld",val1);
                val1=trei(++i);
            }
            else
            {
                printf("%lld",val2);
                val2=cinci(++j);

            }
        }
        nr++;
        printf("\n");
    }
}
