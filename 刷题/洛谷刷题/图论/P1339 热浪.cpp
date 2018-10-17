#include<bits/stdc++.h>
using namespace std;

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

const int maxn = 100010;
const int maxm = 500010;
const int inf = 1 << 30;

struct edge
{
    int u,v,w,next;
}num[maxm];

int k = 0,head[maxm];
inline void add(int x,int y,int w)
{
    num[++k].u = x;
    num[k].v = y;
    num[k].w = w;
    num[k].next = head[x];
    head[x] = k;
}

#define P pair< int , int >
priority_queue< P , vector< P > ,greater< P > >qwq;
int n , m , s , t , dis[maxn] , vis[maxn];

inline void dijkstra()
{
    for(int i = 1;i <= n;++i) dis[i] = inf;

    dis[s] = 0;
    qwq.push(make_pair(0,s));

    while(!qwq.empty())
    {
        int x = qwq.top().second;
        qwq.pop();

        if(!vis[x])
        {
            vis[x] = 1;
            for(int i = head[x];i;i = num[i].next)
            {
                int v = num[i].v;
                dis[v] = min(dis[v],dis[x]+num[i].w);
                qwq.push(make_pair(dis[v],v));
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    n = read(),m = read();s = read();t = read();

    for(int i = 1;i <= m;++i)
    {
        int u = read(), v = read() , w = read();
        add(u,v,w);
        add(v,u,w);
    }

    dijkstra();

    cout << dis[t] << endl;

    return 0;
}
