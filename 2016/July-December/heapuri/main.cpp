#include <cstdio>
#include <iostream>

using namespace std;

int m,i,heap[400010],n,poz[200010],ordcron,pos[200010];


void inserare(int x)
{
    heap[++n]=x;
    int ind=n;
    while (ind>1&&heap[ind]<heap[ind/2])
        swap(heap[ind],heap[ind/2]),swap(poz[pos[ind]],poz[pos[ind/2]]),swap(pos[ind],pos[ind/2]),ind/=2;
}

void stergere(int x)
{
    int ind=poz[x];
    heap[ind]=heap[n];
    poz[pos[n]]=poz[pos[ind]];
    pos[ind]=pos[n];
    heap[n]=2000000;
    n--;
    bool ok;
    do
    {
        ok=0;
        if (ind>1&&heap[ind]<heap[ind/2])
            swap(heap[ind],heap[ind/2]),swap(poz[pos[ind]],poz[pos[ind/2]]),swap(pos[ind],pos[ind/2]),ind/=2,ok=1;
        else if ((heap[ind*2]<heap[ind]&&2*ind<=n)||(heap[ind*2+1]<heap[ind]&&2*ind+1<=n))
        {
            if (heap[ind*2]<heap[ind*2+1])
                swap(heap[ind],heap[ind*2]),swap(poz[pos[ind]],poz[pos[ind*2]]),swap(pos[ind],pos[ind*2]),ind*=2;
            else
                swap(heap[ind],heap[ind*2+1]),swap(poz[pos[ind]],poz[pos[ind*2+1]]),swap(pos[ind],pos[ind*2+1]),ind=ind*2+1;
            ok=1;
        }
    }
    while (ok);
}

int main()
{
    FILE *IN=fopen("heapuri.in","r");
    FILE *OUT=fopen("heapuri.out","w");
    fscanf(IN,"%d",&m);
    for (i=0; i<=2*m+1; i++)
        heap[i]=2000000000;
    for (i=1; i<=m; i++)
    {
        int cod,x;
        fscanf(IN,"%d",&cod);
        if (cod==1)
            fscanf(IN,"%d",&x),poz[++ordcron]=n+1,pos[n+1]=ordcron,inserare(x);
        else if (cod==2)
            fscanf(IN,"%d",&x),stergere(x);
        else
            fprintf(OUT,"%d\n",heap[1]);
        /*for (int z=1; z<=n; z++)
            fprintf(OUT,"%d %d %d  ",heap[z],pos[z],poz[z]);*/
      //  fprintf(OUT,"\n");
    }
}
