#include<fstream>
using namespace std;
ifstream in("calcule.in");
ofstream out("calcule.out");
int a[100001],r[100000];
int main()
{ int n,i,k,x,j,s=0,sx=0;
r[0]=1;
in>>n>>k;
for(i=0;i<n;i++)
{in>>x;
sx=(sx+x)%k;
s=(s+r[sx])%20011;
r[sx]++;
for(j=x-1;a[j]==0&&j>0;j--);
a[j]--;a[x]++;
}
x=0;
for(i=1;i<20001;i++)
	x=x+a[i];
out<<x<<'\n'<<s;
return 0;
}
