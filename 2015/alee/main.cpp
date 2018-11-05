#include <fstream>
using namespace std;
ifstream fin("alee.in");
ofstream fout("alee.out");
int p,u,n,m,i,j,a[200][200],o,r,k,xi,yi,xf,yf;
int dx[5]={-1,0,1,0};
int dy[5]={0,-1,0,1};
struct element
{int x,y,d;
};
element c[40000];
element w;
void citire()
{fin>>n>>m;
for (i=1;i<=m;i++)
{fin>>o>>r;
a[o][r]=1;
}
fin>>xi>>yi>>xf>>yf;
}
int interior (int f, int g)
{if (f>=1&&f<=n&&g>=1&&g<=n)
return 1;
else
    return 0;
}
int main()
{citire();
p=u=1;
c[p].x=xi;
c[p].y=yi;
c[p].d=1;
while (p<=u)
{w.x=c[p].x;
w.y=c[p].y;
w.d=c[p].d;
p++;
for (k=0;k<4;k++)
{if (a[w.x+dx[k]][w.y+dy[k]]==0&&interior(w.x+dx[k],w.y+dy[k]))
{u++;
c[u].x=w.x+dx[k];
c[u].y=w.y+dy[k];
c[u].d=w.d+1;
a[c[u].x][c[u].y]=1;
}
}
}
for (i=1;i<=p;i++)
{if (c[i].x==xf&&c[i].y==yf)
fout<<c[i].d;
}
return 0;
}
