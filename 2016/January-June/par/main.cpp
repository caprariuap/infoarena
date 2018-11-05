#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("par.in");
ofstream fout("par.out");

char c;
int pi,pd,i;

int main()
{int n;fin>>n;
    for (i=1;i<=n;i++)
    {fin>>c;
        if (c=='(')
            pd++;
        else
        {
            if (pd) pd--;
            else pi++;
        }
    }
if (pi%2==0&&pd%2==0)
{int sol=pd/2+pi/2;
fout<<sol;
}
else
    {if (pi%2!=0&&pd%2!=0) {int sol=pd/2+pi/2+2;fout<<sol;}
else fout<<"-1";}
fout<<'\n';
}
