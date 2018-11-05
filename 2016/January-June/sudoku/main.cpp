#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("sudoku.in");
ofstream fout("sudoku.out");
int x[10][10];
void citire()
{char c;
for (int i=1;i<=9;i++)
    for (int j=1;j<=9;j++)
    fin>>c,x[i][j]=c-'0';
}
int verif(int i,int j)
{int l,c,ii,jj;
for (ii=1;ii<=9;ii++)
    if (x[ii][j]==x[i][j]&&ii!=i)
    return 0;
for (jj=1;jj<=9;jj++)
    if (x[i][jj]==x[i][j]&&jj!=j)
    return 0;
l=((i+2)/3)*3-2;
c=((j+2)/3)*3-2;
for (ii=l;ii<=l+2;ii++)
    for (jj=c;jj<=c+2;jj++)
    if (x[ii][jj]==x[i][j]&&(ii!=i||jj!=j))
    return 0;
return 1;
}
void afisare()
{int i,j;
for (i=1;i<=9;i++)
{for (j=1;j<=9;j++)
fout<<x[i][j];
fout<<'\n';
}
}
void bkt(int i,int j)
{if (i>9) afisare();
else
{if (x[i][j])
{if (j<9) bkt(i,j+1);
if (j==9) bkt(i+1,1);
}
else
{int k;for (k=1;k<=9;k++)
{x[i][j]=k;if (verif(i,j)) {if (j<9) bkt(i,j+1);
if (j==9) bkt(i+1,1);}
x[i][j]=0;}
}
}
}
int main()
{citire();
bkt(1,1);
}
