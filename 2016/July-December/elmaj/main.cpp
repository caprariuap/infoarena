#include <cstdio>
#include <map>

using namespace std;

map<int,int> m;
int n,x,a[1000010],nr,aux;

int majoritate()
{
    int k=0;
    for (int i=0; i<n; i++)
    {
        if (!k)
        {
            aux=a[i];
            k=1;
        }
        else if (a[i]==aux)
            k++;
        else
            k--;
    }
    if (aux<0)
        return aux;
    for (int i=0; i<n; i++)
    {
        if (a[i] == aux)
            nr++;
    }
    if (nr>n/2)
        return nr;
    else
        return -1;
}

int main()
{
    freopen("elmaj.in","r",stdin);
    freopen("elmaj.out","w",stdout);
    scanf("%d",&n);
    for (int i=0; i<n; i++)
        scanf("%d",&a[i]);
    nr=majoritate();
    printf("%d %d",aux,nr);
    return 0;
}
