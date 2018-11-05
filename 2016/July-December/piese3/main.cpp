#include <cstdio>
#include <vector>
#include <algorithm>
#define DIM 10000

using namespace std;

int T,N,C,i,j,a[1000010],p[50010];
bool use[50010];
char buff[DIM];
int poz=0;

vector <int> v[50010];

FILE *f=fopen("piese3.in","r");

void citeste(int &numar)
{
     numar = 0;
     //cat timp caracterul din buffer nu e cifra ignor
     while (buff[poz] < '0' || buff[poz] > '9')
          //daca am "golit" bufferul atunci il umplu
          if (++poz == DIM)
               fread(buff,1,DIM,f),poz=0;
     //cat timp dau de o cifra recalculez numarul
     while ('0'<=buff[poz] && buff[poz]<='9')
     {
          numar = numar*10 + buff[poz] - '0';
          if (++poz == DIM)
               fread(buff,1,DIM,f),poz=0;
     }
}

struct afisare
{
    int X,Y;
} vf[50010];

bool compara(afisare lhs, afisare rhs)
{
    return lhs.X < rhs.X;
}

int compresie(int x)
{
    int rad=x;
    while (p[rad]!=rad)
        rad=p[rad];
    while (x!=rad)
    {
        int aux=x;
        x=p[x];
        p[aux]=rad;
    }
    return rad;
}

int disjoint(int xx, int yy)
{
    int z=v[yy].size();
    if (v[xx].size()>v[yy].size())
        for (int i=0; i<z; i++)
        {
            int Y=v[yy][v[yy].size()-1];
            v[yy].pop_back();
            v[xx].push_back(Y);
            p[Y]=xx;
        }
    else
    {
        z=v[xx].size();
        for (int i=0; i<z; i++)
        {
            int X=v[xx][v[xx].size()-1];
            v[xx].pop_back();
            v[yy].push_back(X);
            p[X]=yy;
        }
    }
    if (v[xx].size()>v[yy].size())
        return xx;
    return yy;
}

void rezolva()
{
    int cmax=-1;
    citeste(N);
    citeste(C);
    for (i=1; i<=N; i++)
    {
        p[i]=i;
        for (j=1; j<=C; j++)
        {
            int x;
            citeste(x);
            if (x>cmax) cmax=x;
            if (!a[x])
            {
                a[x]=i;
                if (use[i]==0)
                    v[a[x]].push_back(i),use[i]=1;
            }
            else
            {
                use[i]=1;
                //v[a[x]].push_back(i),p[i]=a[x];
                int xx=compresie(i);
                int yy=compresie(a[x]);
                if (xx!=yy)
                {
                    if (v[xx].size()>0)
                    {
                        int z=disjoint(xx,yy);
                        p[i]=z;
                    }
                    else
                    {
                        v[yy].push_back(i);
                        p[i]=yy;
                    }
                }
            }
        }
    }
    int nr=0;
    for (i=1; i<=N; i++)
    {
        if (v[i].size()>0)
            sort(v[i].begin(),v[i].end());
        a[i]=p[i]=use[i]=0;
        if (v[i].size()>0)
            vf[nr].X=v[i][0],vf[nr].Y=i,nr++;
        else vf[i].Y=0;
    }
    sort(vf,vf+nr,compara);
    for (i=0; i<nr; i++)
    {
        for (j=0; j<v[vf[i].Y].size(); j++)
            printf("%d ",v[vf[i].Y][j]);
        printf("\n");
        //cout<<"DA"<<vf[i].X<<' '<<vf[i].Y<<'\n';
        vf[i].X=vf[i].Y=0;
    }
    for (i=1; i<=N; i++)
        v[i].clear();
    for (i=N+1; i<=cmax; i++)
        a[i]=0;
}

int main()
{
    freopen("piese3.out","w",stdout);
    citeste(T);
    for (int z=1; z<=T; z++)
        rezolva();
}
