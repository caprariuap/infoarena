#include <iostream>

using namespace std;
long long n,i,x,cmmmc,r,a,b,produs;
int main()
{cin>>n;cmmmc=1;
for (i=1;i<=n;i++)
{x=i;produs=cmmmc*x;
while (x)
{r=cmmmc%x;
cmmmc=x;
x=r;
}
cmmmc=produs/cmmmc;
}
cout<<cmmmc;
}
