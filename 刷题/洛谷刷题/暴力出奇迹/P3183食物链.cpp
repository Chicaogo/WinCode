#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define il inline

il int read()
{
    int x = 0,t=1;char ch = getchar();
    while(ch<'0' || ch>'9'){if(ch == '-') t=-1;ch = getchar();}
    while(ch>='0'&&ch<='9'){x = x*10+ch-'0';ch = getchar();}
    return x*t;
}

const int  maxn = 100010;
int head[maxn],ru[maxn],cu[maxn],vis[maxn];
int tot = 0, n, m;

struct edge
{
    int x,y,next;
}G[maxn<<1];

il void addedge(int x,int y)
{
    G[++tot].x = x;
    G[tot].y = y;
    G[tot].next = head[x];
    head[x] = tot;
}

int dfs(int u)
{
    if(vis[u]) return vis[u];
    ll ans = 0;
    if(ru[u] && !cu[u]) ++ans;
    for(int i=head[u];i;i=G[i].next)
    {
        int v = G[i].y;
        ans += dfs(v);
    }
    vis[u] = ans;
    return ans;
}

int main(int argc, char const *argv[])
{
    n = read(); m = read();

    for(int i=1,u,v;i<=m;++i)
    {
        u = read(); v = read();
        cu[u]++; ru[v]++;
        addedge(u,v);
    }

    ll ans = 0;

    for(int i = 1;i <= m;++i)
    {
        if(!ru[i]) ans+=dfs(i);
    }

    cout << ans;

    getchar();getchar();getchar();
    return 0;
}
