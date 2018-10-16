#include<bits/stdc++.h>
using namespace std;

#define P pair<int,int>
const int maxn = 5010;
const int maxm = 10000;
const int inf = 2147483647;

inline int read()
{
    int x = 0,t = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') t = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = x*10 + ch - '0';ch = getchar();}
    return x*t;
}

struct edge
{
    int u,v,w,next;
}G[maxm];

int aa[5555],bb[5555],cc[5555];
int n,m,s,e,a,b,d;bool duan[101][101];
int cnt = 0,head[maxm],dis[maxn],vis[maxn];
priority_queue< P , vector<P> , greater< P > > q;

inline void add(int u,int v,int w)
{
    G[++cnt].u = u;
    G[cnt].v = v;
    G[cnt].w = w;
    G[cnt].next = head[u];
    head[u] = cnt;
}

inline void dijkstra()
{
    for(int i = 1;i <= n;++i)
        dis[i] = inf;
    
    dis[s] = 0;
    q.push(make_pair(0,s));

    while(!q.empty())
    {
        int x = q.top().second;
        q.pop();

        if(!vis[x])
        {
            vis[x] = 1;
            for(int i = head[x];i;i = G[i].next)
            {
                int v = G[i].v;
                dis[v] = min(dis[v] , dis[x]+G[i].w);
                q.push(make_pair(dis[v],v));
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    n=read(),m=read();

    for(int i=1;i<=m;i++){
        cin>>aa[i]>>bb[i]>>cc[i];
    }
    d = read();
    for(int i=1;i<=d;i++)
    {
        a=read();b=read();
        duan[a][b]=1;
        duan[b][a]=1;
    }
    for(int i=1;i<=m;i++)
    {
        if(duan[aa[i]][bb[i]]==0)
        {
            add(aa[i],bb[i],0);
            add(bb[i],aa[i],0);
        }
        else {
            add(aa[i],bb[i],cc[i]);
            add(bb[i],aa[i],cc[i]);
        }
    }

    cin >> s >> e;

    dijkstra();
    
    cout << dis[e];

    return 0;
}
