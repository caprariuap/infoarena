#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("lgdrum.in");
ofstream fout("lgdrum.out");
int a[101][101],matrix[101][101],n,omg,m,f,l,i,j,codd,codp,k,abcde;
struct orase {int xo,yo;};
orase orasp[42],orasd[42];
struct coada{int x,y,d;};
coada c[50000],w;
int dx[5]={-1,0,1,0};
int dy[5]={0,-1,0,1};
int nrop;
int nrod;
int ok,kinf,binnr,r,binu[500],binud[500],binnrd,p,u,ii,jj,dmin,dminmax,q;
char plecare[14],destinatie[14],s[14];
void citire()
{nrop=nrod=1;
fin>>n>>m;
fin>>plecare;
fin>>destinatie;
l=strlen(plecare);
for (int abcd=0;abcd<l;abcd++)
{f=plecare[abcd];
codp+=f;
}
l=strlen(destinatie);
for (int abcd=0;abcd<l;abcd++)
{f=destinatie[abcd];
codd+=f;
}
for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
{fin>>s;
l=strlen(s);
for (k=0;k<l;k++)
{f=s[k];
a[i][j]+=f;
}
if (strcmp(s,plecare)==0&&strlen(s)==strlen(plecare))
    {orasp[nrop].xo=i;
    orasp[nrop].yo=j;
    nrop++;}
else
    if (strcmp(s,destinatie)==0)
{orasd[nrod].xo=i;
orasd[nrod].yo=j;
nrod++;
}
}
nrod--;
nrop--;
}
int decinbin(int q, int r)
{binnr=0;
binnrd=0;
for (int qwe=0;qwe<=500;qwe++)
{binu[qwe]=0;binud[qwe]=0;
}
while (q>0){binu[binnr++]=q%2;q/=2;}
binu[++binnr]=1;
binnrd=0;
while (r>0){binud[binnrd++]=r%2;r/=2;}
binud[++binnrd]=1;
ok=0;
abcde=min(binnr,binnrd);
for (kinf=0;kinf<=abcde;kinf++)
    if (binu[kinf]==1&&binud[kinf]==0)
    {ok=1;break;}
return ok;
}
int interior (int f, int g)
{omg=max(n,m);if (f>=1&&f<=omg&&g>=1&&g<=omg)
return 1;
else
    return 0;
}
void lee()
{for (int iii=1;iii<=n;iii++)
for (int jjj=1;jjj<=m;jjj++)
    matrix[iii][jjj]=0;
p=u=1;
c[p].x=orasp[ii].xo;
c[p].y=orasp[ii].yo;
c[p].d=1;
while (p<=u&&matrix[orasd[jj].xo][orasd[jj].yo]==0)
{w.x=c[p].x;
w.y=c[p].y;
w.d=c[p].d;
p++;
for (k=0;k<4;k++)
{if (decinbin(a[w.x][w.y],a[w.x+dx[k]][w.y+dy[k]])==1)
{if (matrix[w.x+dx[k]][w.y+dy[k]]==0&&interior(w.x+dx[k],w.y+dy[k])==1)
{u++;
c[u].x=w.x+dx[k];
c[u].y=w.y+dy[k];
c[u].d=w.d+1;
matrix[c[u].x][c[u].y]=1;

}
}
}
}
dmin=99999999;
for (k=1;k<=u;k++)
    {
    if (c[k].x==orasd[jj].xo&&c[k].y==orasd[jj].yo)
 {if (c[k].d<dmin&&c[k].d!=1)
        dmin=c[k].d;

        }
c[k].x=c[k].y=c[k].d=0;}
}
int main()
{citire();
for (i=1;i<=n;i++)
{for (j=1;j<=m;j++)
fout<<a[i][j]<<' ';
fout<<endl;
}
for (i=1;i<=nrop;i++)
    fout<<orasp[nrop].xo<<' '<<orasp[nrop].yo<<endl;
for (j=1;j<=nrod;j++)
    fout<<orasd[nrod].xo<<' '<<orasd[nrod].yo<<endl;
dminmax=100000000;
for (ii=1;ii<=nrop;ii++)
{for (jj=1;jj<=nrod;jj++)
lee();

if (dmin<dminmax)
    dminmax=dmin;

}
fout<<dminmax;
}
