#include <iostream>
#include <cstdio>

using namespace std;

int adunare();
int inmultire();
int termen();

char *p,s[100010];

int adunare()
{
    int t1,t2;
    t1=inmultire();
    while (*p=='+'||*p=='-')
    {
        if (*p=='+')
        {
            p++;
            t2=inmultire();
            t1+=t2;
        }
        else
        {
            p++;
            t2=inmultire();
            t1-=t2;
        }
    }
    return t1;
}

int inmultire()
{
    int t1,t2;
    t1=termen();
    while (*p=='*'||*p=='/')
    {
        if (*p=='*')
        {
            p++;
            t2=termen();
            t1*=t2;
        }
        else
        {
            p++;
            t2=termen();
            t1/=t2;
        }
    }
    return t1;
}

int termen()
{
    int t;
    if (*p=='(')
    {
        p++;
        t=adunare();
        p++;
    }
    else
    {
        t=0;
        while (*p>='0'&&*p<='9')
            t=t*10+*p-'0',p++;
    }
    return t;
}

int main()
{
    freopen("evaluare.in","r",stdin);
    freopen("evaluare.out","w",stdout);
    cin >> s;
    p=s;
    cout << adunare();
}
