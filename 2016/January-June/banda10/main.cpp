#include <fstream>

using namespace std;

ifstream fin("banda10.in");
ofstream fout("banda10.out");

int n;
char c;
int a[1010];
int doi[1010];

void inmultire(int a[],int x)
{
    int i;
    long long t=0;
    for (i=1; i<=a[0]; i++)
    {
        a[i]=a[i]*x+t;
        t=a[i]/10;
        a[i]%=10;
    }
    while (t)
    {
        a[++a[0]]=t%10;
          t/=10;
    }
}

void adunare(int a[],int b[])
{
    int i;
    long long t=0;
    if (b[0]>a[0]) a[0]=b[0];
    else for (i=b[0]+1; i<=a[0]; i++) b[i]=0;
    for (i=1; i<=a[0]; i++)
    {
        a[i]=a[i]+b[i]+t;
        t=a[i]/10;
        a[i]%=10;
    }
    while (t) a[++a[0]]=t%10,t/=10;
}

int main()
{
    fin>>n;
    int i,j;
    for (i=n-1; i>=0; i--)
    {
        fin>>c;
        if (c=='1')
        {
            doi[0]=doi[1]=1;
            for (j=1; j<=i; j++)
                inmultire(doi,2);
            adunare(a,doi);
        }
    }
    fout<<a[0]<<'\n';
}
