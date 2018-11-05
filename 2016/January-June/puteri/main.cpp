#include <fstream>
using namespace std;
ifstream pauleste("puteri.in");
ofstream shmeker("puteri.out");
int a,b,c,alab,alac,blaa,blac,claa,clab,i;
int abc[8000],acb[8000],bac[8000],bca[8000],cba[8000],cab[8000],suma[8001];
void inmultire(int a[],int x)
{
    int t=0,k;
    for (k=1; k<=a[0]; k++)
    {
        a[k]=a[k]*x+t;
        t=a[k]/10;
        a[k]%=10;
    }
    if (t)
        a[++a[0]]=t;
}
void adunare(int a[],int b[])
{
    if (b[0]>a[0]) a[0]=b[0];
    int k,t=0;
    for (k=1; k<=a[0]; k++)
    {
        a[k]=a[k]+b[k]+t;
        t=a[k]/10;
        a[k]%=10;
    }
    if (t)
        a[++a[0]]=t;
}
int main()
{
    pauleste>>a>>b>>c;
    alab=alac=a;
    blaa=blac=b;
    claa=clab=c;
    for (i=1; i<b; i++) alab*=a,clab*=c;
    for (i=1; i<a; i++) blaa*=b,claa*=c;
    for (i=1; i<c; i++) alac*=a,blac*=b;
    abc[0]=acb[0]=bac[0]=bca[0]=cba[0]=cab[0]=1;
    abc[1]=acb[1]=a;
    bac[1]=bca[1]=b;
    cab[1]=cba[1]=c;
    for (i=1; i<blac; i++) inmultire(abc,a);
    for (i=1; i<clab; i++) inmultire(acb,a);
    for (i=1; i<alac; i++) inmultire(bac,b);
    for (i=1; i<claa; i++) inmultire(bca,b);
    for (i=1; i<alab; i++) inmultire(cab,c);
    for (i=1; i<blaa; i++) inmultire(cba,c);
    adunare(suma,abc);
    adunare(suma,acb);
    adunare(suma,bac);
    adunare(suma,bca);
    adunare(suma,cab);
    adunare(suma,cba);
    for (i=suma[0]; i; i--)
        shmeker<<suma[i];
    shmeker<<'\n';
}
