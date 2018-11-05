#include <cstdio>
#include <fstream>

using namespace std;

ifstream fin("trie.in");
ofstream fout("trie.out");

struct nod
{
    nod *next[30];
    int sf,nrfii;
    nod()
    {
        sf=0;
        for(int i=0; i<27; i++)
            next[i]=0;
    }
};

nod *rad= new nod;

void ins(char *w)
{
    int ind=0;
    nod *p=rad;
    while (w[ind]!=0)
    {
        if (p->next[w[ind]-'a']==NULL)
        {
            nod *n=new nod;
            p->next[w[ind]-'a']=n;
        }
        p->nrfii++;
        p=p->next[w[ind]-'a'];
        ind++;
    }
    p->sf++;
}

bool sterge(char *w,nod *p)
{
    if(w[0]==0)
    {
        p->sf--;
        if(p->sf==0&&p->nrfii==0) return 1;
        return 0;
    }
    if (sterge(w+1,p->next[w[0]-'a'])==1)
    {
        p->next[w[0]-'a']=0;
        delete p->next[w[0]-'a'];
        if(p->nrfii==1&&p->sf==0)
            return 1;
        p->nrfii--;
        return 0;
    }
    else
    {
        p->nrfii--;
        return 0;
    }
}

int cautare(char *w)
{
    int ind=0;
    nod *p=rad;
    while (w[ind]!=0)
        if (p->next[w[ind]-'a'])
            p=p->next[w[ind++]-'a'];
        else return 0;
    return p->sf;
}

int prefix(char *w)
{
    int ind=0,nr=0;
    nod *p=rad;
    while (w[ind]!=0)
        if (p->next[w[ind]-'a'])
            p=p->next[w[ind++]-'a'],nr++;
        else return nr;
    return nr;
}

int main()
{
    int op;
    char w[25];
    fin>>op>>w;
    while (!fin.eof())
    {
        if (op==0)
            ins(w);
        else if (op==1)
            sterge(w,rad);
        else if (op==2)
            fout<<cautare(w)<<'\n';
        else if (op==3)fout<<prefix(w)<<'\n';
        op=-1;
        fin>>op>>w;
    }
    return 0;
}
