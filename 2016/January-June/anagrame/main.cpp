#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("anagrame.in");
ofstream fout("anagrame.out");

int l,i;
int a[100000];
int n,k;
int vp[27];
bool nonprim[10000000];
int prime[2500000],nr;

void ciur()
{
    int N=10000000;
    int i;
    nonprim[0]=nonprim[1]=1;
    prime[++nr]=2;
    for (i=3; i<=N; i+=2)
        if (!nonprim[i])
        {
            for (int j=i+i+i; j<=N; j=j+i+i)
                nonprim[j]=1;
            prime[++nr]=i;
        }

}

void inmultire (int a[],int x)
{
    int i,t=0;
    for (i=1; i<=a[0]; i++)
        a[i]=a[i]*x+t,t=a[i]/10,a[i]%=10;
    while (t) a[++a[0]]=t%10,t/=10;
}

void impartire(int a[],int x)
{
    int i,r=0;
    for (i=a[0]; i; i--)
    {
        r=10*r+a[i];
        a[i]=r/x;
        r%=x;
    }
    while (!a[a[0]]&&a[0]) a[0]--;
}

int rest(int a[],int x)
{
    int i,r=0;
    for (i=a[0]; i; i--)
    {
        r=10*r+a[i];
        r%=x;
    }
    return r;
}

int main()
{
    char c;
    while (fin>>c)
    {
        if (!vp[c-'a'+1]) k++;
        vp[c-'a'+1]++;
        n++;
    }
    ciur();
    a[0]=a[1]=1;
    for (i=n-k+1; i<=n; i++)
        inmultire(a,i);
    int d=prime[1];
    int contorprime=1;
    while (a[0]>1||a[1]>1)
    {
        k=0;
        while (rest(a,d)==0)
        {
            ++k;
            impartire(a,d);
        }
        fout<<d<<' '<<k<<'\n';
        d=prime[++contorprime];
    }
}
