#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("ecuatii.in");
ofstream fout("ecuatii.out");
char s[51];
float a,b,c,x,delta,x2=0.00;
int main()
{fin>>s;
int i=0;
if (s[0]=='-')
{if (s[1]=='x') a=-1;
else
{i=1;while (s[i]!='x') a=a*10+s[i]-'0',i++;
a=-a;
}
}
else
    {if (s[1]=='x') a=1,i=1;
    else
        while (s[i]!='x') a=a*10+s[i]-'0',i++;
    }
i+=3;
if (s[i]=='-')
{i++; if (s[i]!='x'){while (s[i]!='x') b=b*10+s[i]-'0',i++;
b=-b;}
else
    b=-1;
}
else {i++;if (s[i]!='x') while (s[i]!='x') b=b*10+s[i]-'0',i++;
else
        b=1;}
i++;
if (s[i])
{if (s[i]=='+')
{i++;while (s[i]) c=c*10+s[i]-'0',i++;}
else
{i++;while (s[i]) c=c*10+s[i]-'0',i++;c=-c;
}
}
else
    c=0;
delta=b*b-4*a*c;
if (delta==0) fout<<-b/(2*a);
else
{x=(-b+sqrt(delta))/(2*a);
x2=(-b-sqrt(delta))/(2*a);
if (x<x2) fout<<x<<' '<<x2;
else
  fout<<x2<<' '<<x;
}
fout<<a<<b<<c;
    return 0;
}
