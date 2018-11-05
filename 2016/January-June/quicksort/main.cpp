#include <iostream>
using namespace std;
long long a[100001];
int n;
int divide(int p,int q)
{int x=a[p];
int s=p;int d=q;
while (s<d)
{while (s<d&&a[d]>=x) d--;
a[s]=a[d];
while (s<d&&a[s]<=x) s++;
a[d]=a[s];
}
a[s]=x;
return s;
}
void qs(int p,int q)
{int m=divide(p,q);
if (m-1>p) qs(p,m-1);
if (m+1<q) qs(m+1,q);
}
int main()
{cin>>n;int i;
for (i=0;i<n;i++)
    cin>>a[i];
qs(0,n-1);
for (i=0;i<n;i++)
    cout<<a[i]<<' ';
}
