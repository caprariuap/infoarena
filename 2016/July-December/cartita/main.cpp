#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int p,n,m,k,g,i,j,xc,yc,nr,start;
short int matrix[210][210];
int d[210][210];
bool siguranta[210][210];
bool use[210][210];
int coordx[210],coordy[210];

int dx[4]= {0,-1,0,1};
int dy[4]= {-1,0,1,0};

struct casuta
{
    int x,y;
};
queue <casuta> q;

vector <int> v[210];

void p1()
{
    if (matrix[xc][yc]>0)
        printf("%d %d %d\n",xc,yc,0);
    else
    {
        casuta z;
        z.x=xc;
        z.y=yc;
        q.push(z);
        while (!q.empty())
        {
            casuta z=q.front();
            q.pop();
            for (i=0; i<=3; i++)
                if (siguranta[z.x+dx[i]][z.y+dy[i]]&&(!d[z.x+dx[i]][z.y+dy[i]]||d[z.x+dx[i]][z.y+dy[i]]>d[z.x][z.y]+1))
                {
                    casuta z2;
                    z2.x=z.x+dx[i];
                    z2.y=z.y+dy[i];
                    d[z2.x][z2.y]=d[z.x][z.y]+1;
                    q.push(z2);
                    if (matrix[z2.x][z2.y]>0)
                    {
                        printf("%d %d %d\n",z2.x,z2.y,d[z2.x][z2.y]);
                        return;
                    }
                }
        }
    }
}

bool ok=0;

void filll(int X,int Y)
{

    if (ok) return;
    use[X][Y]=1;
    if (matrix[X][Y]>0)
        start=matrix[X][Y],ok=1;
    for (i=0; i<4; i++)
        if (siguranta[X+dx[i]][Y+dy[i]]&&!use[X+dx[i]][Y+dy[i]])
            filll(X+dx[i],Y+dy[i]);
}

void euler(int z)
{
    while (v[z].size()>0)
    {
        int y=v[z][v[z].size()-1];
        v[z].pop_back();
        for (int j=0; j<v[y].size(); j++)
            if (v[y][j]==z)
            {
                swap(v[y][j],v[y][v[y].size()-1]);
                v[y].pop_back();
                break;
            }
        euler(y);
    }
    printf("%d %d\n",coordx[z],coordy[z]);
}

void p2()
{
    if (matrix[xc][yc]>0)
        euler(matrix[xc][yc]);
    else
    {
        casuta z;
        z.x=xc;
        z.y=yc;
        q.push(z);
        while (!q.empty())
        {
            casuta z=q.front();
            q.pop();
            for (i=0; i<=3; i++)
                if (siguranta[z.x+dx[i]][z.y+dy[i]]&&(!d[z.x+dx[i]][z.y+dy[i]]||d[z.x+dx[i]][z.y+dy[i]]>d[z.x][z.y]+1))
                {
                    casuta z2;
                    z2.x=z.x+dx[i];
                    z2.y=z.y+dy[i];
                    d[z2.x][z2.y]=d[z.x][z.y]+1;
                    q.push(z2);
                    if (matrix[z2.x][z2.y]>0)
                    {
                        euler(matrix[z2.x][z2.y]);
                        return;
                    }
                }
        }
    }
}

int main()
{
    freopen("cartite.in","r",stdin);
    freopen("cartite.out","w",stdout);
    scanf("%d",&p);
    scanf("%d %d",&n,&m);
    scanf("%d %d",&xc,&yc);
    scanf("%d",&k);
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            matrix[i][j]=-1,siguranta[i][j]=1;
    for (i=1; i<=k; i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        matrix[a][b]=siguranta[a][b]=0;
        if (c==1)
            matrix[a-1][b]=matrix[a+1][b]=matrix[a][b-1]=matrix[a][b+1]=siguranta[a-1][b]=siguranta[a+1][b]=siguranta[a][b-1]=siguranta[a][b+1]=0;
        else if (c==2)
        {
            for (j=1; j<=2; j++)
                matrix[a+j][b]=matrix[a][b+j]=siguranta[a+j][b]=siguranta[a][b+j]=0;
            matrix[a+1][b+1]=siguranta[a+1][b+1]=0;
            matrix[a-1][b+1]=matrix[a+1][b-1]=siguranta[a-1][b+1]=siguranta[a+1][b-1]=0;
            matrix[a-1][b-1]=matrix[a][b-1]=matrix[a-1][b]=siguranta[a-1][b-1]=siguranta[a][b-1]=siguranta[a-1][b]=0;
            if (a>2) matrix[a-2][b]=siguranta[a-2][b]=0;
            if (b>2) matrix[a][b-2]=siguranta[a][b-2]=0;
        }
    }
    scanf("%d",&g);
    for (i=1; i<=g; i++)
    {
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        int ga1,ga2;
        if (matrix[a][b]<1)
            matrix[a][b]=++nr;
        ga1=matrix[a][b];
        coordx[ga1]=a;
        coordy[ga1]=b;
        if (matrix[c][d]<1)
            matrix[c][d]=++nr;
        ga2=matrix[c][d];
        coordx[ga2]=c;
        coordy[ga2]=d;
        v[ga1].push_back(ga2);
        v[ga2].push_back(ga1);
    }
    if (p==1)
        p1();
    else
        p2();
}
