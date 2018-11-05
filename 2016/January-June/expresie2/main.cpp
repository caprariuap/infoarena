#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("expresie2.in");
ofstream fout("expresie2.out");
long i,l;
long solutie,nrnumere;
int st[100002],r[55000],d[55000];
long vst,vr,vd;
char s[100001];
int quickselect(int *a, int st, int dr, int k)
{
  int i,ir,j,l,mid;
  int p,temp;

  l=st; ir=dr;
  for(;;)
  {
    if (ir <= l+1)
    {
          if (ir == l+1 && a[ir] < a[l]) { swap(a[l],a[ir]); }
          return a[k];
    }
    else {
          mid=(l+ir) >> 1;
          swap(a[mid],a[l+1]);
          if (a[l] > a[ir])   { swap(a[l],a[ir]);   }
          if (a[l+1] > a[ir]) { swap(a[l+1],a[ir]); }
          if (a[l] > a[l+1])  { swap(a[l],a[l+1]);  }

          i=l+1; j=ir;
          p=a[l+1];
          for (;;)
          {
            do i++; while (a[i] < p);
            do j--; while (a[j] > p);
            if (j < i) break;
            swap(a[i],a[j]);
          }
          a[l+1]=a[j]; a[j]=p;
          if (j >= k) ir=j-1;
          if (j <= k) l=i;
        }
  }
}
int main()
{while (fin>>s[l]) l++;
while (i<l)
{if (s[i]==',')
i++;
else
{if (s[i]=='(')
     ++i,r[++vr]=vst+1;
if (s[i]=='[')
    ++i,d[++vd]=vst+1;
if (s[i]>='0'&&s[i]<='9'||s[i]=='-')
{nrnumere++;int ok=1;
if (s[i]=='-') i++,ok=-1;
int numar=s[i]-'0';i++;
if (s[i]>='0'&&s[i]<='9')
numar=numar*10+s[i]-'0',i++;
st[++vst]=numar*ok;
}
if (s[i]==')')
{int sum,pdsum;
sum=pdsum=st[r[vr]];
for (int k=r[vr]+1;k<=vst;k++)
{if (sum+st[k]>st[k])
sum+=st[k];
else
    sum=st[k];
if (sum>pdsum) pdsum=sum;
}
st[r[vr]]=pdsum;
vst=r[vr];
vr--;++i;
}
if (s[i]==']')
{st[d[vd]]=quickselect(st,d[vd],vst,(vst+d[vd])/2);
vst=d[vd];vd--;
i++;
}
}
}
for (i=1;i<=vst;i++)
    solutie+=st[i];
fout<<nrnumere<<'\n'<<solutie<<'\n';
}
