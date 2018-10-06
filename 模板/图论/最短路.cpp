#include<bits/stdc++.h>
#define P pair<long long,int>
using namespace std;

const long long inf = 2147483647;
const int maxn = 100086;
const int maxm = 521314;

inline int read()
{
    int x=0,t=1;
    char ch = getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch == '-') t=-1;
        ch = getchar();
    }
    while(ch>='0' && ch<='9')
    {
        x =x*10+ch-'0';
        ch = getchar();
    }
    return x*t;
}//快速读入代码

int n,m,s;  //n:点的个数 m:有向边的个数 s:起点

/*************************floyd**************************/
/*
int a[maxn][maxn];

inline void floyd()
{
    for(int k=1;k<=n;++k)
    {
        //k 中转点
        for(int i=1;i<=n;++i)
        {
            //i 起点
            if(i==k || a[i][k]==inf) continue;
            //起点和中转点重合时 跳出循环
            for(int j=1;j<=n;++j)
            {
                //j终点
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                //选择从i->j的直接距离还是中转距离
            }
        }
    }
}
*/
/************************dijkstra************************/

struct edge
{
    int u,v,w,next;
}G[maxm];

int head[maxm],vis[maxn],cnt=0;
long long dis[maxn];
priority_queue< P , vector< P > , greater< P > > q;
//堆优化dijksra //q 每次走最小的

inline void addedge(int u,int v,int w)
{
    G[++cnt].u = u;
    G[cnt].v = v;
    G[cnt].w = w;
    G[cnt].next = head[u];
    head[u] = cnt;
}//链式前向星存图 玄学存图

inline void dijkstra()
{
    for(int i=1;i<=n;++i)
        dis[i]=2147483647;
    //dis 用来更新到每个顶点的最短距离
    dis[s] = 0;
    //初始化 赋初值

    q.push(make_pair(0,s));
    //初始化起点

    while(!q.empty())
    {
        //队列为空时就走完了整个图
        int x=q.top().second;
        q.pop();
        //取出头元素最小的呢个数的 坐标

        if(!vis[x])
        //如果这个点更新过就不再更新了
        {
            vis[x]=1;
            for(int i = head[x];i;i = G[i].next)
            //链式前向星更新每一个相连点的最小距离
            {
                int v = G[i].v;
                dis[v] = min(dis[v],dis[x]+G[i].w);
                q.push(make_pair(dis[v],v));
            }
        }
    }

}

/***************************SPFA**************************/
/*
int tot=0,head[maxn];
long long dis[maxn];
bool vis[maxn];
struct Edge
{
      int next,to,w;
}h[maxm];

void add(int u,int v,int w)
{
    h[++tot].next=head[u];
    h[tot].to=v;
    h[tot].w=w;
    head[u]=tot;
}
//上面和dijkstra算法基本上一样

queue<int> q;
//队列优化

inline void spfa()
{
    memset(dis,inf,sizeof(dis));
    int u,v;
    q.push(s);
    dis[s] = 0;

    vis[s] = 1;

    while(!q.empty())
    {
        u=q.front();
        q.pop();
        vis[u] = 1;
        for(int i=head[u];i;i=h[i].next)
        {
            v=h[i].to;
            if(dis[v]>dis[u]+h[i].w)
            {
                dis[v]=dis[u]+h[i].w;
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
*/

int main(int argc, char const *argv[])
{/*
//—————————————————————————flyod————————————————————————//
    //floyd 本质是枚举
    n=read();m=read();s=read();

    memset(a,inf,sizeof(a));
    //初始化a数组为最大值

    int u,v,w;

    for(int i=1;i<=m;++i)
    {
        u=read();v=read();w=read();
        a[u][v]=min(a[u][v],w);
        //从u->v的距离
    }

    floyd();
    
    a[s][s]=0;
    for(int i=1;i<=n;++i)
    {
        printf("%d ",a[s][i]);
    }
    //答案输出
*/
//———————————————————————dijkstra———————————————————————//

    //dijkstra  本质是贪心
    n=read(),m=read(),s=read();

    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        x=read(),y=read(),z=read();
        addedge(x,y,z);
    }

    dijkstra();

    for(int i=1;i<=n;i++)
    {
        printf("%lld ",dis[i]);
    }

//————————————————————————SPFA————————————————————————//
/*
    //SPFA  还算是贪心吧
    n=read(),m=read(),s=read();

    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        x=read(),y=read(),z=read();
        add(x,y,z);
    }

    spfa();

    for(int i=1;i<=n;i++)
    {
        printf("%lld ",dis[i]);
    }
*/
    getchar();getchar();getchar();
    return 0;
}
