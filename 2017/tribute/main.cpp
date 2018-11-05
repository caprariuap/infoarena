#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("tribute.in");
ofstream fout("tribute.out");

int n,dx,dy,i,x[50001],y[50001],ans;

int main()
{
    fin >> n >> dx >> dy;
    for (i=1; i<=n; i++)
        fin >> x[i] >> y[i];
    sort(x+1,x+n+1);
    sort(y+1,y+n+1);
    for (i=1; i<=n/2; i++)
    {
        ans+=max(x[n-i+1]-x[i]-dx,0);
        ans+=max(y[n-i+1]-y[i]-dy,0);
    }
    fout << ans << '\n';
}
