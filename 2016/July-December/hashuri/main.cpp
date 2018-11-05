#include <cstdio>
#include <vector>

using namespace std;

vector <int> m[666670];

int n,i;

FILE *fin=fopen("hashuri.in","r");
FILE *fout=fopen("hashuri.out","w");

void adauga(int x)
{
    int lista=x%666667;
    for (int i=0; i<m[lista].size(); i++)
        if (x==m[lista][i])
            return;
    m[lista].push_back(x);
}

void elimina(int x)
{
    int lista=x%666667;
    vector <int>::iterator i;
    for (i=m[lista].begin(); i!=m[lista].end(); i++)
        if (x==*i)
        {
            m[lista].erase(i);
            return;
        }
}

int main()
{
    fscanf(fin,"%d",&n);
    int op,x;
    for (i=1; i<=n; i++)
    {
        fscanf(fin,"%d%d",&op,&x);
        if (op==1)
            adauga(x);
        else if (op==2)
            elimina(x);
        else
        {
            int ok=0;
            int lista=x%666667;
            for (int j=0; j<m[lista].size(); j++)
                if (m[lista][j]==x)
                {
                    ok=1;
                    break;
                }
            fprintf(fout,"%d\n",ok);
        }
    }
}
