#include <cstdio>
#include <iostream>

using namespace std;

int n,i,j,k,rezultat=0;

struct punct
{
    double x,y;
};

struct segment
{
    punct A[2];
} s[510];

long double arie(punct a, punct b, punct c)
{
    long double aria=a.x*b.y+a.y*c.x+b.x*c.y-a.x*c.y-a.y*b.x-b.y*c.x;
    return aria;
}

void rezolva(int I, int J)
{
    bool ok=0;
    for (int i=0; i<=1; i++)
        for (int j=0; j<=1; j++)
            if (s[I].A[i].x==s[J].A[j].x&&s[I].A[i].y==s[J].A[j].y)
            {
                rezultat++;
                ok=1;
            }
    long double a1,a2,a3,a4;
    a1=arie(s[I].A[0],s[J].A[0],s[J].A[1]);
    a2=arie(s[I].A[1],s[J].A[0],s[J].A[1]);
    a3=arie(s[J].A[0],s[I].A[0],s[I].A[1]);
    a4=arie(s[J].A[1],s[I].A[0],s[I].A[1]);
    if (!ok)
        if ((a1*a2<0&&a3*a4<=0)||(a1*a2<=0&&a3*a4<0))
            rezultat++;
}

int main()
{
    //FILE* IN=fopen("geometry.in","r");
    //FILE* OUT=fopen("geometry.out","w");
    freopen("geometry.in","r",stdin);
    freopen("geometry.out","w",stdout);
    cin>>n;
    for (k=1; k<=n; k++)
        cin>>s[k].A[0].x>>s[k].A[0].y>>s[k].A[1].x>>s[k].A[1].y;
    for (i=1; i<n; i++)
        for (j=i+1; j<=n; j++)
            if (i!=j)
                rezolva(i,j);
    printf("%d\n",rezultat);
}
/*
       |   0   0 1 |
A(0XY)=| a.x a.y 1 |/2 = (a.x*b.y - a.y*b.x)/2
       | b.x b.y 1 |
*/
