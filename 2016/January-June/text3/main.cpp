#include <fstream>
using namespace std;
ifstream fin("text3.in");
ofstream fout("text3.out");
char cuvinte[20001][21];
short int lungimi[20001];
int nrc,precedent[27],maxim,maxi,p,j,raspunsuri[20001];
int best[27],construire[20001];
int main()
{
    while (fin>>cuvinte[++nrc])
    {
        while (cuvinte[nrc][lungimi[nrc]])++lungimi[nrc];
        lungimi[nrc]--;
    }
    nrc--;
    fout<<nrc<<'\n';
    int i;
    for (i=1; i<=nrc; i++)
    {
        int s=cuvinte[i][0]-'a'+1;
        int f=cuvinte[i][lungimi[i]]-'a'+1;
        if(best[s]+1>best[f])
        {
            best[f]=best[s]+1;
            construire[i]=precedent[s];
            precedent[f]=i;
        }
    }
    for (i=1; i<=26; i++)
    {
        if (best[i]>maxim) maxim=best[i],p=precedent[i];
    }
    fout<<nrc-maxim;
    fout<<'\n';
    i=p;
    j=0;

    while (i>0)
    {
        raspunsuri[++j]=i;
        i=construire[i];
    }
    for (i=j; i; i--)
        fout<<cuvinte[raspunsuri[i]]<<'\n';
}
