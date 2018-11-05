#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("search.in");
ofstream fout("search.out");

char s[110][5010];
int n,m,i,j,vf,stk[110][5010],poz[110][5010][30];

int main()
{
    fin >> n >> m;
    for (i=1; i<=n; i++)
        s[i][0]=' ',fin >> s[i]+1;
    for (i=1; i<=n; i++)
    {
        int l=strlen(s[i]);
        for (int k=1; k<=26; k++)
            poz[i][l][k]=5010;
        for (j=l-1; j>=0; j--)
        {
            for (int k=1; k<=26; k++)
                poz[i][j][k]=poz[i][j+1][k];
            poz[i][j][s[i][j+1]-'a'+1]=j+1;
        }
    }
    for (int x=1; x<=m; x++)
    {
        char c;
        fin >> c;
        if (c=='-')
            vf--;
        else
        {
            ++vf;
            for (i=1; i<=n; i++)
                if (stk[i][vf-1]==5010)
                    stk[i][vf]=5010;
                else
                    stk[i][vf]=poz[i][stk[i][vf-1]][c-'a'+1];
        }
        int ans=0;
        for (i=1; i<=n; i++)
            if (stk[i][vf]!=5010)
                ans++;
        fout << ans << '\n';
//        for (i=1; i<=n; i++)
//            fout << stk[i][vf] << ' ';
//        fout << '\n';
    }
}
