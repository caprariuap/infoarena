#include <cstdio>
#include <vector>
#include <queue>
#include <fstream>
#define nmax 10010

using namespace std;

FILE *fin=fopen("atac2.in","r");
FILE *fout=fopen("atac2.out","w");

vector <int> v[300],vi[nmax+5];
int n,ni,m,u,X,i,j,distbfs[nmax+5],dbf[300],d[nmax+5],p[nmax+5],S,D,flux,cm,cost[300][300],C[300][300],reald[300],f[300][300],un[300],index[nmax+5];

void bfs(int start)
{
    queue <int> Q;
    for (i=1; i<=ni; i++)
        distbfs[i]=1e8;
    distbfs[start]=0;
    Q.push(start);
    while (!Q.empty())
    {
        int nod=Q.front();
        Q.pop();
        for (i=0; i<vi[nod].size(); i++)
        {
            int vecin=vi[nod][i];
            if (distbfs[vecin]>distbfs[nod]+1)
            {
                distbfs[vecin]=distbfs[nod]+1;
                Q.push(vecin);
            }
        }
    }
    distbfs[start]=0;
    for (j=0; j<vi[X].size(); j++)
    {
        int A,B;
        A=index[start];
        B=index[vi[X][j]];
        v[A].push_back(B);
        v[B].push_back(A);
        cost[A][B]=distbfs[vi[X][j]];
        cost[B][A]=-cost[A][B];
        C[A][B]=1;
        //fprintf(fout,"%d %d %d %d %d\n",start,A,vi[X][j],B,cost[A][B]);
    }
}

void bellmanford()
{
    queue <int> Q;
    bool inQ[300];
    for (i=1; i<=n; i++)
        inQ[i]=0;
    for (i=1; i<=n; i++)
        dbf[i]=1e9;
    dbf[index[S]]=0;
    Q.push(index[S]);
    inQ[index[S]]=1;
    while (!Q.empty())
    {
        int nod=Q.front();
        Q.pop();
        inQ[nod]=0;
        for (i=0; i<v[nod].size(); i++)
        {
            int vecin=v[nod][i];
            if (C[nod][vecin]&&dbf[vecin]>dbf[nod]+cost[nod][vecin])
            {
                dbf[vecin]=dbf[nod]+cost[nod][vecin];
                if (!inQ[vecin])
                    Q.push(vecin),inQ[vecin]=1;
            }
        }
    }
}

bool dijkstra()
{
    priority_queue<pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > H;
    for (i=1; i<=n; i++)
        d[i]=1e9,p[i]=-1;
    d[index[S]]=0;
    reald[index[S]]=0;
    H.push(make_pair(d[index[S]],index[S]));
    while (!H.empty())
    {
        int nod=H.top().second,dist=H.top().first;
        H.pop();
        if (dist>d[nod])
            continue;
        for (i=0; i<v[nod].size(); i++)
        {
            int vecin=v[nod][i];
            if (C[nod][vecin]>f[nod][vecin])
            {
                int aux=cost[nod][vecin]+dbf[nod]-dbf[vecin];
                if (dist+aux<d[vecin])
                {
                    d[vecin]=dist+aux;
                    reald[vecin]=reald[nod]+cost[nod][vecin];
                    H.push(make_pair(d[vecin],vecin));
                    p[vecin]=nod;
                }
            }
        }
    }
    if (p[index[D]]==-1)
        return 0;
    for (i=1; i<=n; i++)
        dbf[i]=reald[i];
    int fmin=1e9;
    for (i=index[D]; i!=index[S]; i=p[i])
        if (C[p[i]][i]-f[p[i]][i]<fmin)
            fmin=C[p[i]][i]-f[p[i]][i];
    flux+=fmin;
    cm=cm+fmin*reald[index[D]];
    for (i=index[D]; i!=index[S]; i=p[i])
    {
        f[p[i]][i]+=fmin;
        f[i][p[i]]-=fmin;
    }
    return 1;
}

int main()
{
    fscanf(fin,"%d%d%d%d",&ni,&m,&u,&X);
    for (i=1; i<=u; i++)
        fscanf(fin,"%d",&un[i]);
    for (i=1; i<=m; i++)
    {
        int A,B;
        fscanf(fin,"%d%d",&A,&B);
        vi[A].push_back(B);
        vi[B].push_back(A);
    }
    n=0;
    for (i=1; i<=u; i++)
        index[un[i]]=++n;
    for (i=0; i<vi[X].size(); i++)
        index[vi[X][i]]=++n;
    //fprintf(fout,"DADADA%d\n",n);
    S=nmax+1;
    D=nmax+2;
    index[S]=++n;
    index[D]=++n;
    for (int I=1; I<=u; I++)
        bfs(un[I]);
    for (i=1; i<=u; i++)
    {
        int A,B;
        A=index[S];
        B=index[un[i]];
        v[A].push_back(B);
        v[B].push_back(A);
        cost[A][B]=0;
        cost[B][A]=-cost[A][B];
        C[A][B]=1;
    }
    for (i=0; i<vi[X].size(); i++)
    {
        int A,B;
        A=index[vi[X][i]];
        B=index[D];
        v[A].push_back(B);
        v[B].push_back(A);
        cost[A][B]=0;
        cost[B][A]=-cost[A][B];
        C[A][B]=1;
    }
    bellmanford();
//    for (i=1; i<=n; i++)
//    {
//        for (j=1; j<=n; j++)
//            fprintf(fout,"%d ",cost[i][j]);
//        fprintf(fout,"\n");
//    }
//    fprintf(fout,"\n");
//    for (i=1; i<=n; i++)
//    {
//        for (j=0; j<v[i].size(); j++)
//            fprintf(fout,"%d ",v[i][j]);
//        fprintf(fout,"\n");
//    }
    flux=cm=0;
    while (dijkstra());
    fprintf(fout,"%d\n",cm);
    fclose(fin);
    fclose(fout);
    return 0;
}
