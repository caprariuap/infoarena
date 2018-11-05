#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("evaluare.in");
ofstream fout("evaluare.out");
char s[1001];
int suma,ok,us,i,l;
int valori[27],prez[27];
int main()
{
    while (fin>>s[i])
        i++;
    for (i=1; i<=26; i++)
        valori[i]=i;
    l=strlen(s);
    us=1;
    for (i=0; i<l; i++)
    {
        if (strchr("abcdefghijklmnopqrstuvwxyz",s[i]))
        {
            ok=0;
            if (i>=2)
            {
                if (s[i-1]=='+'&&s[i-2]=='+')
                    valori[s[i]-'a'+1]+=1;
                if (s[i-1]=='-'&&s[i-2]=='-')
                    valori[s[i]-'a'+1]-=1;
            }
            if (i<=l-3)
            {
                if (s[i+1]==s[i+2])
                    ok=1;
            }
            if (us==1)
                suma+=valori[s[i]-'a'+1],prez[s[i]-'a'+1]=1;
            if (us==0)
                suma-=valori[s[i]-'a'+1],prez[s[i]-'a'+1]=1;
            if (ok==1)
            {
                if (s[i+1]=='+'&&s[i+2]=='+')
                    valori[s[i]-'a'+1]++,us=0;
                if (s[i+1]=='-'&&s[i+2]=='-')
                    valori[s[i]-'a'+1]--,us=1;
            }
            else
            {
                if (i<l-2)
                {
                    if (s[i+1]=='+')
                        us=1;
                    if (s[i+1]=='-')
                        us=0;
                }
            }
        }
    }
    fout<<suma<<endl;
    for (i=1; i<=26; i++)
        if (prez[i]==1)
            fout<<valori[i]<<endl;
}
