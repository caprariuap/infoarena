#include <fstream>
using namespace std;
ifstream fin("compresie.in");
ofstream fout("compresie.out");
int nri,i,l,n;
char s[1000001];
int aflareN()
{int i=0;int nrcar=0;
for (i=0;i<l;)
{if (s[i]=='*')
nri++,i++;
else
{if (s[i]>='0'&&s[i]<='9')
{int nr=0;while (s[i]>='0'&&s[i]<='9')
nr=nr*10+s[i]-'0',i++;
nrcar+=nr,i++;
}
else
    if (s[i]>='a'&&s[i]<='z')
    nrcar++,i++;
}
}
i=2;
while (i*i<nrcar) i++;
return i;
}
char a[1001][1001];
void reconstruire(int x1, int y1, int x2, int y2)
{if (x1<=x2&&y1<=y2)
{if (s[i]=='*')
{int mx=(x1+x2)/2;int my=(y1+y2)/2;i++;
reconstruire(x1,y1,mx,my);
reconstruire(x1,my+1,mx,y2);
reconstruire(mx+1,y1,x2,my);
reconstruire(mx+1,my+1,x2,y2);
}
else
{if (s[i]>='0'&&s[i]<='9')
{while (s[i]>='0'&&s[i]<='9')
i++;
for (int k=x1;k<=x2;k++)
    for (int j=y1;j<=y2;j++)
    a[k][j]=s[i];
i++;
}
else
{if (s[i]>='a'&&s[i]<='z')
{a[x1][y1]=s[i];i++;
	              reconstruire(x1,y1+1,x1,y2); //B
		      reconstruire(x1+1,y1,x2,y1); //C
		      reconstruire(x1+1,y1+1,x2,y2); //D
}
}
}
}
}
int main()
{char c;i=0;
while (fin>>c)
s[i++]=c;
l=i;
n=aflareN();
i=0;
reconstruire(1,1,n,n);
fout<<nri<<'\n';
for (i=1;i<=n;i++)
{for (int j=1;j<=n;j++)
fout<<a[i][j];
fout<<'\n';
}
}
