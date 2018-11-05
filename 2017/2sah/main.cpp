#include <cstdio>
#define MOD 100003

using namespace std;

long long n,k,t,i,j;

struct matrice
{
    long long z[4][4];
};

long long trei(long long x, long long p)
{
    if (p==1)
        return x;
    long long k=trei(x,p/2);
    if (p%2)
        return (((k%MOD)*(k%MOD)%MOD)*(x%MOD))%MOD;
    else
        return (k%MOD)*(k%MOD)%MOD;
}

matrice inmultire(matrice a, matrice b)
{
    matrice rez;
    for (int i=1; i<=3; i++)
        for (int j=1; j<=3; j++)
        {
            rez.z[i][j]=0;
            for (int k=1; k<=3; k++)
            rez.z[i][j]=(rez.z[i][j]+a.z[i][k]*b.z[k][j]%MOD)%MOD;
        }
    return rez;
}

matrice explog(matrice x, long long p)
{
    if (p==1)
        return x;
    matrice k=explog(x,p/2);
    if (p%2)
        return inmultire(inmultire(k,k),x);
    else
        return inmultire(k,k);
}

int main()
{
    freopen("2sah.in","r",stdin);
    freopen("2sah.out","w",stdout);
    scanf("%d",&t);
    scanf("%d%d",&n,&k);
    if (t==1)
    {
        if (k==1)
            printf("1");
        else
            printf("%d",trei(3,k-1));
    }
    else
    {
        if (k>n+1)
            printf("0");
        else
        {
            if (k==n||k==n+1)
                printf("1");
            else
            {
                long long p=n-k;
                matrice a;
                a.z[1][1]=a.z[1][2]=a.z[2][2]=a.z[3][1]=0;
                a.z[1][3]=a.z[2][1]=a.z[2][3]=a.z[3][2]=a.z[3][3]=1;
                matrice X;
                for (int i=1; i<=3; i++)
                    for (int j=1; j<=3; j++)
                        X.z[i][j]=a.z[i][j];
                X=explog(a,p);
                long long x,y,z,xx,yy,zz;
                x=0;
                y=z=1;
                zz=(x*X.z[1][3]%MOD+y*X.z[2][3]%MOD+z*X.z[3][3]%MOD)%MOD;
                printf("%d",zz);
            }
        }
    }
    printf("\n");
}

