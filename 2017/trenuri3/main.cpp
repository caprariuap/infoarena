#include <fstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

ifstream fin("trenuri3.in");
ofstream fout("trenuri3.out");

struct calator
{
    long long st,sf,schimbare,poz;
} p[100010],event[500010];

long long n,m,i,j,a[100010],c[100010],locuri[100010],nr,ans[100010],nrlocuri,lt,inSt[100010],inQ[100010];

class cmp2
{
public:
    bool operator()(calator A, calator B)
    {
        return A.sf>B.sf;
    }
};

stack <long long> trains;
priority_queue <calator, vector <calator>, cmp2> q;

class cmp
{
public:
    bool operator()(calator A, calator B)
    {
        return (A.st>B.st||(A.st==B.st&&A.schimbare>B.schimbare)||(A.st==B.st&&A.schimbare==B.schimbare&&A.sf>B.sf));
    }
};

int main()
{
    fin >> n >> m;
    for (i=1; i<=n; i++)
        fin >> a[i] >> c[i],locuri[i]=c[i];
    for (i=1; i<=m; i++)
        fin >> p[i].sf >> p[i].st,p[i].schimbare=-1,p[i].poz=i,event[i]=p[i],swap(p[i].st,p[i].sf),event[m+i]=p[i],event[m+i].poz=m+i,event[m+i].schimbare=0;
    nr=2*m;
    for (i=1; i<=n; i++)
        event[++nr].st=a[i],event[nr].sf=0,event[nr].schimbare=c[i],event[nr].poz=i;
    sort(event+1,event+nr+1,cmp());
    for (i=1; i<=nr; i++)
    {
        //fout << event[i].st << ' ' << event[i].sf << ' ' << event[i].poz << '\n';
        if (event[i].sf==0)
            nrlocuri+=event[i].schimbare,trains.push(event[i].poz),inSt[event[i].poz]=1;
        else
        {
            if (event[i].poz<=m)
            {
                if (nrlocuri>0)
                {
                    while (locuri[trains.top()]==0)
                        inSt[trains.top()]=0,trains.pop();
                    locuri[trains.top()]--;
                    ans[event[i].poz]=trains.top();
                    nrlocuri--;
                    q.push(event[i]);
                    inQ[event[i].poz]=1;
                }
                else
                {
                    if (!q.empty())
                    {
                        calator pasager=q.top();
                        while (!q.empty()&&inQ[pasager.poz]==0)
                            q.pop(),pasager=q.top();
                        if (!q.empty())
                        {
                            pasager=q.top();
                            if (pasager.sf<event[i].sf)
                            {
                                inQ[pasager.poz]=0;
                                q.pop();
                                ans[event[i].poz]=ans[pasager.poz];
                                ans[pasager.poz]=0;
                                inQ[event[i].poz]=1;
                                q.push(event[i]);

                            }
                        }
                    }
                }
            }
            else
            {
                long long tren=ans[event[i].poz-m];
                if (tren!=0)
                {
                    if (!inSt[tren])
                        trains.push(tren),inSt[tren]=1;
                    locuri[tren]++;
                    nrlocuri++;
                    inQ[event[i].poz-m]=0;
                }
            }
        }
    }
    long long ANS=0;
    for (i=1; i<=m; i++)
        if (ans[i]>0)
            ANS++;
    fout << ANS << '\n';
    for (i=1; i<=m; i++)
        fout << ans[i] << '\n';
    /*calator pasager;
    while (!q.empty())
        pasager=q.top(),q.pop(),fout << pasager.sf << ' ';
    */
}
