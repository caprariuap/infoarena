#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("fraze.in");
ofstream fout("fraze.out");
char s[101][256];
int n,np,nrr,a[101][26],raspunsuri[101],nrceva;
int verificare(int i)
{
    int ok=1;
    int suma=0;
    for (int j=1; j<=26; j++)
    {
        suma+=a[i][j];
        if (!a[i][j])
            ok=0;
    }
    if (suma==26&&ok==1)
        return 2;
    return ok;
}
int main()
{
    int i=1;
    while (fin.getline(s[i],256))
    {
        int l=strlen(s[i]);
        a[i][s[i][0]-'A'+1]++;
        for (int j=1; j<l; j++)
        {
            if (s[i][j]>='a'&&s[i][j]<='z')
                a[i][s[i][j]-'a'+1]++;
              if (s[i][j]>='A'&&s[i][j]<='Z')
                a[i][s[i][j]-'A'+1]++;
        }
        if (verificare(i)==1) n++,raspunsuri[++nrr]=i;
        if (verificare(i)==2) n++,raspunsuri[++nrr]=i,np++;
    i++;}
    nrceva=i;
    fout<<n<<' '<<np<<'\n';
    for (i=1; i<=nrr; i++)
        for (int j=i+1; j<=nrr; j++)
            if (strcmp(s[raspunsuri[i]],s[raspunsuri[j]])>0)
                swap(raspunsuri[i],raspunsuri[j]);
    for (i=1; i<=nrr; i++)
        fout<<s[raspunsuri[i]]<<'\n';
}
