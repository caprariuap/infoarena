 #include <fstream>
 #include <cstring>
 using namespace std;
 ifstream fin("smiley.in");
 ofstream fout("smiley.out");
char s[10001];
int nr,j,i,l;
int main()
{fin.get(s,10001,'\0');
l=strlen(s);
for (i=0;i<l;i++)
{if (strchr(":;>8",s[i]))
{j=i+1;
while (s[j]=='-')
    j++;
if (strchr("()[]DPOX3",s[j]))
    nr++;

}
}
fout<<nr;
}
