#include <fstream>
using namespace std;
ifstream fin("charlie.in");
ofstream fout("charlie.out");
int p,a[100002],i,st[100002];
char c;
int main()
{
    fin>>p;
    fin.get();
    while (fin>>c)
        a[++i]=c-'a'+1;
    a[0]=i;
    if (p==1)
    {
        int lungimemax=0,lungime;
        for (i=2; i<a[0]; i++)
        {
            if (a[i]<a[i-1]&&a[i]<a[i+1])
            {
                int ok=1;
                int k=i;
                while (ok)
                {
                    i+=2;
                    if (a[i]>=a[i-1]||a[i]>=a[i+1]) ok=0;
                }
                lungime=i-k+1;
                if (lungime>lungimemax) lungimemax=lungime;
            }
        }
        fout<<lungimemax;
    }
    else
    {int scor=0;int vf=2;st[1]=a[1];st[2]=a[2];
    for (i=3;i<=a[0];i++)
    {while (st[vf]<st[vf-1]&&st[vf]<a[i])
    {if (st[vf-1]>a[i]) scor+=st[vf-1];
    else scor+=a[i];
    vf--;
    }
    st[++vf]=a[i];
    }
    for (i=1;i<=vf;i++)
    {c=st[i]+'a'-1;
    fout<<c;
    }
    fout<<'\n'<<scor;
    }
fout<<'\n';
}
