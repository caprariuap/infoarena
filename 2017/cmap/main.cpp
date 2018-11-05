#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#define nmax 100010
#define eps 0.000001
#define inf 3e18

using namespace std;

ifstream fin("cmap.in");
ofstream fout("cmap.out");

int n,i;
pair <int, int> a[nmax];
vector <pair <int, int> > x,y,z;

long double dist(pair<int, int> A, pair<int, int> B)
{
    return sqrt((long double)(A.first-B.first)*(A.first-B.first)+(long double)(A.second-B.second)*(A.second-B.second));
}

class comp1
{
public:
    bool operator()(pair<int, int> A, pair<int, int> B)
    {
        return A.first<B.first;
    }
};

class comp2
{
public:
    bool operator()(pair<int, int> A, pair<int, int> B)
{
    return A.second<B.second;
}
};

long double divide(int st, int dr)
{
    if (dr-st+1<=1)
        return inf;
    int mij=(st+dr)/2;
    long double minim=min(divide(st,mij),divide(mij+1,dr));
    x.clear();
    y.clear();
    for (int i=mij; i>=st&&minim>=a[mij].first-a[i].first; i--)
        x.push_back(a[i]);
    for (int i=mij+1; i<=dr&&minim>=a[i].first-a[mij+1].first; i++)
        y.push_back(a[i]);
    sort(x.begin(),x.end(),comp2());
    sort(y.begin(),y.end(),comp2());
    int j,k;
    j=k=0;
    z.clear();
    while (j<x.size()&&k<y.size())
    {
        if (x[j].second<y[k].second)
            z.push_back(x[j]),j++;
        else
            z.push_back(y[k]),k++;
    }
    while (j<x.size())
        z.push_back(x[j]),j++;
    while (k<y.size())
        z.push_back(y[k]),k++;
    for (j=0; j<z.size()-1; j++)
        for (k=j+1; k<z.size()&&k-j<8; k++)
            minim=min(minim,dist(z[j],z[k]));
//    if (st==1&&dr==n)
//    {
//        for (j=0; j<z.size(); j++)
//            fout << z[j].first << ' ' << z[j].second << '\n';
//        fout << '\n';
//    }
    return minim;
}

int main()
{
    fin >> n;
    for (i=1; i<=n; i++)
        fin >> a[i].first >> a[i].second;
    sort(a+1,a+n+1,comp1());
    fout << fixed << setprecision(7) << divide(1,n) << '\n';
    fin.close();
    fout.close();
    return 0;
}
