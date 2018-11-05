#include <fstream>
#include <queue>
#define pmax 203

using namespace std;

ifstream fin("zmeu2.in");
ofstream fout("zmeu2.out");

struct noduri
{
    uint8_t poz,durata;
    int16_t capete;
} nod;
int n,p,k,i,j;
bool g[pmax][pmax];
int16_t best[pmax][503],d[pmax],c[pmax];
queue <noduri> q;

int main()
{
    fin >> n >> p >> k;
    for (i=1; i<=p; i++)
        fin >> d[i] >> c[i],g[i][i]=g[p][i]=g[i][1]=1;
    for (i=1; i<=k; i++)
    {
        int a,b;
        fin >> a >> b;
        g[a][b]=1;
    }
    nod.poz=1;
    nod.durata=d[1];
    nod.capete=n-c[1];
    for (i=1; i<p; i++)
            if (g[nod.poz][i]==0&&nod.capete-c[i]>0)
                if (best[i][nod.capete-c[i]]==0||best[i][nod.capete-c[i]]>nod.durata+d[i])
                {
                    noduri nod2;
                    nod2.poz=i;
                    nod2.durata=nod.durata+d[i];
                    nod2.capete=nod.capete-c[i];
                    best[i][nod2.capete]=nod2.durata;
                    q.push(nod2);
                }
    while (!q.empty())
    {
        nod=q.front();
        while (best[nod.poz][nod.capete]!=0&&best[nod.poz][nod.capete]<nod.durata)
        q.pop(),nod=q.front();
        q.pop();
        for (i=1; i<=p; i++)
            {
                int16_t X,Y;
                X=nod.capete-c[i];
                Y=nod.durata+d[i];
                if (g[nod.poz][i]==0&&X>0)
                if (best[i][X]==0||best[i][X]>Y)
                {
                    noduri nod2;
                    nod2.poz=i;
                    nod2.durata=Y;
                    nod2.capete=X;
                    best[i][nod2.capete]=nod2.durata;
                    q.push(nod2);
                }
            }
    }
    int minim=0;
    for (i=1; i<=n; i++)
        if (minim==0||(best[p][i]!=0&&best[p][i]<minim))
            minim=best[p][i];
    if (minim==0)
    {
        fout << "-1\n";
        return 0;
    }
    fout << minim << '\n';
}
