#include <cstdio>
#include <queue>
#define nmax 760

using namespace std;

FILE *fin=fopen("volum.in","r");
FILE *fout=fopen("volum.out","w");

int n,m,i,j,a[nmax][nmax];
bool use[nmax][nmax];
int dx[]= {0,-1,0,1};
int dy[]= {-1,0,1,0};

class cmp
{
public:
    bool operator()(pair <int, int> A, pair <int, int> B)
    {
        return a[A.first][A.second]>a[B.first][B.second];
    }
};

priority_queue <pair <int, int>, vector <pair <int, int> >, cmp> H;

int main()
{
    fscanf(fin,"%d%d",&n,&m);
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            fscanf(fin,"%d",&a[i][j]);
    for (i=1; i<=n; i++)
    {
        use[i][0]=use[i][m+1]=use[i][1]=use[i][m]=1;
        H.push(make_pair(i,1));
        H.push(make_pair(i,m));
    }
    for (i=1; i<=m; i++)
    {
        use[0][i]=use[n+1][i]=use[1][i]=use[n][i]=1;
        H.push(make_pair(1,i));
        H.push(make_pair(n,i));
    }
    long long ans=0;
    while (!H.empty())
    {
        i=H.top().first;
        j=H.top().second;
        //fprintf(fout,"%d\n",a[i][j]);
        H.pop();
        //continue;
        for (int k=0; k<4; k++)
            if (!use[i+dx[k]][j+dy[k]])
            {
                use[i+dx[k]][j+dy[k]]=1;
                if (a[i+dx[k]][j+dy[k]]<a[i][j])
                    ans=ans+a[i][j]-a[i+dx[k]][j+dy[k]];
                a[i+dx[k]][j+dy[k]]=max(a[i+dx[k]][j+dy[k]],a[i][j]);
                H.push(make_pair(i+dx[k],j+dy[k]));
            }
    }
    fprintf(fout,"%lld\n",ans);
    fclose(fin);
    fclose(fout);
}
