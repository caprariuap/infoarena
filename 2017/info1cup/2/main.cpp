#include <fstream>

using namespace std;

ifstream fin("monstri.in");
ofstream fout("monstri.txt");

bool used[3000000];
int ans=0;
int doi[30],i;
int numere[3000000];

void bkt(int poz)
{
    if (poz==2000)
    {
        numere[poz]=doi[20]-1;
        for (int i=0; i<=3000000; i++)
            used[i]=0;
        int ans2=0;
        ans=0;
        for (int i=1; i<=2000; i++)
            for (int j=i+1; j<=2000; j++)
                if (!used[(numere[i]&numere[j])])
                {
                    ans++;
                    used[(numere[i]&numere[j])]=1;
                }
                else
                    ans2++;
        return;
    }
    for (int i=numere[poz-1]-1; i<=doi[20]-1; i++)
    {
        numere[poz]=i;
        bkt(poz+1);
        if (ans>200000)
            return;
        else
            fout << ans << '\n';
    }
}

int main()
{
    doi[0]=1;
    int NR=0;
    for (i=1; i<=20; i++)
        doi[i]=doi[i-1]*2;
    for (i=0; i<=19; i++)
        numere[++NR]=doi[i];
    for (i=0; i<=19; i++)
        numere[++NR]=doi[20]-1-doi[i];
    numere[++NR]=doi[20]-1;
    int nrgaps=1;
    for (i=42; i<=2000&&nrgaps<20;)
    {
        int start=doi[20]-1;
        for (int j=0; j<20; j++)
        {
            int deafisat=start;
            for (int k=j; k<min(20-nrgaps,j+nrgaps); k++)
                deafisat-=doi[k];
            if (i<2000&&deafisat<doi[20]-1)
                numere[++i]=deafisat;
        }
        nrgaps=nrgaps+1;
    }
//    numere[0]=doi[20]-1;
//    while (ans<2000)
//    {
//        bkt(1);
////        fout << ans << ' ' << ans2 << '\n';
////        for (int i=0; i<=3000000; i++)
////            if (used[i])
////                fout << i << '\n';
//    }
    int ans2=0;
    ans=0;
    for (int i=1; i<=2000; i++)
        for (int j=i+1; j<=2000; j++)
            if (!used[(numere[i]&numere[j])])
            {
                ans++;
                used[(numere[i]&numere[j])]=1;
            }
            else
                ans2++;
    for (i=1; i<=2000; i++)
        fout << numere[i] << ' ';
    fout << '\n';
    fout << ans << '\n' << ans2;
}
