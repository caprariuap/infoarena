#include <fstream>

using namespace std;

ifstream fin("sqr.in");
ofstream fout("sqr.out");

int n,i;
bool nonprime[100005];
int nrp,numere[105000],prezenta[105000];

void ciur()
{
    int i,j;
    nonprime[0]=nonprime[1]=1;
    numere[++nrp]=2;
    for (i=3; i<=100000; i+=2)
        if (!nonprime[i])
        {
            numere[++nrp]=i;
            for (j=i+i+i; j<=100000; j=j+i+i)
                nonprime[j]=1;
        }
}

int a[1005];

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
    while (t) a[++a[0]]=t%10,t/=10;
}

void descompunere(int &x)
{

    int contor=1;
    while (x>1)
    {
        while (x%numere[contor]==0)
        {
            x/=numere[contor];
            prezenta[contor]++;
        }
        contor++;
    }
}

int main()
{
    ciur();
    fin>>n;
    int x;

    for (i=1; i<=n; i++)
    {
        fin>>x;
        descompunere(x);
    }
    a[1]=a[0]=1;
    for (i=1; i<=nrp; i++)
        if (prezenta[i]%2)
           inmultire(a,numere[i]);
    for (i=a[0]; i; i--) fout<<a[i];
    fout<<'\n';
}
