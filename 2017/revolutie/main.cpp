#include <fstream>
#define nmax 150

using namespace std;

ifstream fin("revolutie.in");
ofstream fout("revolutie.out");

int n,i,j,a[nmax][nmax],l[nmax];
bool use[nmax];

void schimbare(int i, int j)
{
    for (int k=1; k<=n; k++)
        swap(a[i][k],a[j][k]);
}

bool pairup(int x)
{
    if (use[x])
        return 0;
    use[x]=1;
    for (int i=1; i<=n; i++)
        if (a[x][i]&&!l[i])
        {
            l[i]=x;
            return 1;
        }
    for (int i=1; i<=n; i++)
        if (a[x][i]&&l[i]!=x&&pairup(l[i]))
        {
            l[i]=x;
            return 1;
        }
    return 0;
}

int main()
{
    fin >> n;
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
            fin >> a[i][j];
    int nok=0;
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
            use[j]=0;
        nok+=pairup(i);
    }
    if (nok!=n)
    {
        fout << "-1\n";
        return 0;
    }
    fout << n << '\n';
    for (i=1; i<=n; i++)
       for (j=i; j<=n; j++)
        if (l[j]==i)
       {
           fout << "C " << i << ' ' << j << '\n';
           swap(l[i],l[j]);
       }
}
