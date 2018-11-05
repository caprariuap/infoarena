#include <iostream>

using namespace std;

int n,p[110],i,nr,ln;
char s[110],afisare[110];
bool found,virg[110];

int lastnumber(int i, int x)
{
    int ret=0;
    for (int j=i; j<=x&&virg[j]==0; j++)
        ret=ret*10+p[j];
    return ret;
}

void bkt(int x)
{
    if (found)
        return;
    if (x==1)
    {
        found=1;
        return;
    }
    for (int i=x; i>=1; i--)
    {
        ln=0;
        for (int j=i; j<=x&&virg[j]==0; j++)
            ln=ln*10+p[j];
        virg[i]=1;
        if (p[i-1]<ln&&ln<lastnumber(i+1,x))
        bkt(i-1);
        if (!found)
            virg[i]=0;
    }
}

int main()
{
    cin >> s;
    for (i=0; s[i]; i++)
        p[i+1]=s[i]-'0';
    n=i;
    bkt(n);
    for (i=1; i<=n; i++)
    {
        if (virg[i])
        cout << ',';
        cout << p[i];
        }
}
