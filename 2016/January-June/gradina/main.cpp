#include <fstream>

using namespace std;

ifstream fin("gradina.in");
ofstream fout("gradina.out");

int n,m;
struct gradina
{
    bool perete[4];
} a[25][25];
int i,j;
short flori[25][25],nrflori,arii[450];

void citire()
{short x;
    fin>>n>>m;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        {
            fin>>x;
            int z;
            for (z=0; z<4; z++)
            {
                int m=x;
                if ((m&(1<<z))) a[i][j].perete[z]=1;
            }
        }
}

short dx[]={0,1,0,-1};
short dy[]={1,0,-1,0};
short dimensiune,Amax;

short interior(int x,int y)
{if (x>=1&&x<=n&&y>=1&&y<=m)
return 1;
return 0;
}

void fill(int x,int y)
{flori[x][y]=nrflori;
int k;
arii[nrflori]++;
for (k=0;k<4;k++)
    if (interior(x+dx[k],y+dy[k])&&!flori[x+dx[k]][y+dy[k]]&&!a[x+dx[k]][y+dy[k]].perete[k])
fill(x+dx[k],y+dy[k]);
}

int main()
{
    citire();
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
    {if (!flori[i][j])
    {++nrflori;
    fill(i,j);
    if (arii[nrflori]>Amax) Amax=arii[nrflori];
    }
    }
    fout<<nrflori<<'\n'<<Amax<<'\n';
    int aria=0,lmax=0,cmax=0,dmax;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
          {
              int k;
              for (k=0;k<4;k++)
              {int s=arii[flori[i][j]];
              if (a[i][j].perete[k]==1)
                   {int kk;
                       if (k==0) kk=2;
                       if (k==1) kk=3;
                       if (k==2) kk=0;
                       if (k==3) kk=1;
if (s+arii[flori[i+dx[kk]][j+dy[kk]]]>aria)
                   {lmax=i,cmax=j,dmax=k,aria=s+arii[flori[lmax+dx[kk]][cmax+dy[kk]]];}
                   }
              }
          }
    }
if (nrflori>1)
{
    fout<<aria<<' '<<lmax<<' '<<cmax<<' ';
char sol;
if (dmax==0) sol='V';
if (dmax==1) sol='N';
if (dmax==2) sol='E';
if (dmax==3) sol='S';
fout<<sol<<'\n';
}
}
