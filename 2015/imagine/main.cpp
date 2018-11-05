#include <fstream>
using namespace std;
ifstream fin("imagine.in");
ofstream fout("imagine.out");
int a[260][260],l;
void citire()
{fin>>l;
int i,j;
for (i=1;i<=l;i++)
for (j=1;j<=l;j++)
    fin>>a[i][j];
}
int imagine(int x1,int y1,int x2,int y2)
{int i,j,Mijloc_x,Mijloc_y;
int ok=0;
for (i=x1;i<=x2;i++)
    {for (j=y1;j<=y2;j++)
    if (a[i][j]==1) {ok=1;break;}
    if (ok==1) break;
    }
if (ok==0)
    return 2;
for (i=x1;i<=x2;i++)
    {for (j=y1;j<=y2;j++)
    if (a[i][j]==0) {ok=0;break;}
    if (ok==0) break;
    }
if (ok==0)
{Mijloc_x=(x1+x2)/2;
Mijloc_y=(y1+y2)/2;
return 1+imagine(x1, Mijloc_y+1, Mijloc_x, y2)+
imagine(Mijloc_x+1, Mijloc_y+1, x2, y2)+
imagine(x1, y1, Mijloc_x, Mijloc_y)+
imagine(Mijloc_x+1, y1, x2, Mijloc_y);}
else
    return 2;
}
int main()
{citire();
fout<<imagine(1,1,l,l);
}
