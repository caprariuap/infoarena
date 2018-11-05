#include <fstream>
#include <algorithm>
#include <stack>

using namespace std;

ifstream fin("trenuri3.in");
ofstream fout("trenuri3.out");

struct calator
{
    int st,sf,schimbare,poz;
} p[100010],event[500010];

int n,m,i,j,a[100010],c[100010],locuri[100010],nr,ans[100010],nrlocuri,lt,inSt[100010];

stack <int> trains;

class cmp
{
public:
    bool operator()(calator A, calator B)
    {
        return (A.st>B.st||(A.st==B.st&&A.schimbare>B.schimbare)||(A.st==B.st&&A.schimbare==B.schimbare&&A.sf>B.sf)||(A.st==B.st&&A.sf==B.sf&&A.schimbare==B.schimbare&&A.schimbare==0&&A.poz<=B.poz));
    }
};

int main()
{
    fin >> n >> m;
    for (i=1; i<=n; i++)
        fin >> a[i] >> c[i],locuri[i]=c[i];
    for (i=1; i<=m; i++)
        fin >> p[i].sf >> p[i].st,p[i].schimbare=-1,p[i].poz=i,event[i]=p[i],swap(p[i].st,p[i].sf),event[m+i]=p[i],event[m+i].poz=m+i,event[m+i].schimbare=1;
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
                        lt=trains.top(),inSt[lt]=0,trains.pop();
                    locuri[trains.top()]--;
                    ans[event[i].poz]=trains.top();
                    nrlocuri--;
                }
            }
            else
            {
                int tren=ans[event[i].poz-m];
                if (!inSt[tren])
                trains.push(tren),inSt[tren]=1;
                locuri[tren]++;
                nrlocuri++;
            }
        }
    }
    int ANS=0;
    for (i=1; i<=m; i++)
        if (ans[i]>0)
        ANS++;
    fout << ANS << '\n';
    for (i=1; i<=m; i++)
        fout << ans[i] << '\n';
}
