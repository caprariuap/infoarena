#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

FILE *fin=fopen("cerc3.in","r");
FILE *fout=fopen("cerc3.out","w");

struct cd{int x,y,r,poz;} a[2009],dreapta[2009];
int n,i,j,nrd,sol[2009];
vector <int> v[2009];

int cmmdc(int A, int B)
{
    int r;
    while (B)
    {
        r=A%B;
        A=B;
        B=r;
    }
    return A;
}

class cmp
{
public:
    bool operator()(int A, int B)
    {
        if (sqrt(a[A].x*a[A].x+a[A].y*a[A].y)+a[A].r<sqrt(a[B].x*a[B].x+a[B].y*a[B].y)+a[B].r)
            return 1;
        if (sqrt(a[A].x*a[A].x+a[A].y*a[A].y)+a[A].r==sqrt(a[B].x*a[B].x+a[B].y*a[B].y)+a[B].r)
            return sqrt(a[A].x*a[A].x+a[A].y*a[A].y)-a[A].r<sqrt(a[B].x*a[B].x+a[B].y*a[B].y)-a[B].r;
        return 0;
    }
};

double inceput(int A)
{
    return sqrt(a[A].x*a[A].x+a[A].y*a[A].y)-a[A].r;
}

double sfarsit(int A)
{
    return sqrt(a[A].x*a[A].x+a[A].y*a[A].y)+a[A].r;
}

int main()
{
    fscanf(fin,"%d",&n);
    for (i=1; i<=n; i++)
    {
        fscanf(fin,"%d %d %d",&a[i].x,&a[i].y,&a[i].r);
        int k=cmmdc(a[i].x,a[i].y);
        bool ok=1;
        int ind,ax=a[i].x/k;
        int ay=a[i].y/k;
        ind=nrd+1;
        for (j=1; j<=nrd; j++)
            if (dreapta[j].x==ax&&dreapta[j].y==ay)
                ok=0,ind=j;
        if (ok)
            ++nrd,dreapta[nrd].x=ax,dreapta[nrd].y=ay;
        v[ind].push_back(i);
        a[i].poz=ind;
    }
    fprintf(fout,"%d ",nrd);
    int q=0;
    for (i=1; i<=nrd; i++)
    {
        sort(v[i].begin(),v[i].begin()+v[i].size(),cmp());
        int last=v[i][0];
        sol[i]=1;
        for (j=1; j<v[i].size(); j++)
            if (inceput(v[i][j])>sfarsit(last))
                last=v[i][j],sol[i]++;
        if (sol[i]>q)
            q=sol[i];
    }
    fprintf(fout,"%d ",q);
    int p=0;
    for (i=1; i<=nrd; i++)
        if (sol[i]==q)
        p++;
    fprintf(fout,"%d\n",p);
//    for (i=1; i<=nrd; i++)
//    {
//        for (j=0; j<v[i].size(); j++)
//            fprintf(fout,"%d ",v[i][j]);
//        fprintf(fout,"\n");
//    }
}
