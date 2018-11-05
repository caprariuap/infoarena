#include <fstream>
using namespace std;
ifstream fin("piata.in");
ofstream fout("piata.out");
int i,j,iT,n,iM,jT,jM,a[40001];
int b[40001];
long long S;
int main()
{
    fin>>n;
    fin>>iT>>jT>>iM>>jM;
    for(i=1; i<=n; i++)
{int Si=0;int x=i;
    while(x>0)
    {
        Si+=x%10;
        x=x/10;
    }
    a[i]=Si;
}
    for (j=jT; j<=jM; j++)
       if (iT<=j)
        S+=a[j-iT+1];
       else
        S+=a[n+j-iT+1];
        int aux=S;
   for (i=iT+1;i<=iM;i++)
   {int Sl=aux;
   if (jM>=i-1) {Sl-=a[jM-i+2];if (jT>=i) Sl+=a[jT-i+1];
   else Sl+=a[n+jT-i+1];}
   else Sl=Sl-a[n+jM-i+2]+a[n+jT+1-i];

   aux=Sl;
   S+=Sl;
   }
    fout<<S;


}
