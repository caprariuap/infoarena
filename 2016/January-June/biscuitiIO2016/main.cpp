#include <fstream>
using namespace std;
ifstream fin("biscuiti.in");
ofstream fout("biscuiti.out");
int n,p,k;
int i;
int s1[1001];
int s2[1001];
void scadere(int a[],int b[])
{long long r=0;
int i;
for (i=1;i<=a[0];i++)
{a[i]=a[i]-b[i]-r;
if (a[i]<0) r=1;
else r=0;
if (r) a[i]+=10;
}
while (!a[a[0]]&&a[0]) a[0]--;
}
void inmultire(int a[],int x)
{long long t=0;
int i;
for (i=1;i<=a[0];i++)
{a[i]=a[i]*x+t;
t=a[i]/10;
a[i]%=10;
}
while (t) a[++a[0]]=t%10,t/=10;
}
void cpy(int a[],int b[])
{for (int i=0;i<=b[0];i++)
a[i]=b[i];
}
int main()
{
    fin>>p>>n>>k;
    if (p==1)
    {
        int rezultat;
        rezultat=n-(k%2)*(n*2/k+1)/2;
        fout<<3*rezultat;
    }
    else
    {
        s1[1]=3;
        s1[0]=1;
        s2[1]=1;
        s2[0]=2;
        s2[2]=1;
        if (n==0)
            fout<<1;
        else if (n==1)
            fout<<3;
             else if (n==2)
             fout<'1'<<'1';
else
{for (i=3;i<=n;i++)
{int aux[1001];
cpy(aux,s2);
inmultire(s2,4);
scadere(s2,s1);
cpy(s1,aux);
}
for (i=s2[0];i;i--)
    fout<<s2[i];
}
    }
fout<<'\n';
}
