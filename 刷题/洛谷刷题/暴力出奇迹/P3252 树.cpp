#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int u,v;
}fuck[100010];
int head[100010],fa[100010],w[100010];
int x,y,n,s,tot=0,ans=0;

inline void add(int x,int y)
{
    fuck[++tot].u=head[x];
    fuck[tot].v=y;
    head[x] = tot;
}

void dfs(int x,int dis)
{
    if(dis>s)
        return;
    if(dis==s)
    {
        ans++;
        return;
    }
    for(int i=head[x];i;i=fuck[i].u)
    {
        int nxt=fuck[i].v;
        if(fa[x]!=nxt)
            dfs(nxt,dis+w[nxt]);
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> s;
    for(int i=1;i<=n;i++)
        cin>>w[i];
    
    for(int i=1;i<=n-1;i++)
    {
        cin>>x>>y;
        add(x,y);
        fa[y]=x;
    }

    for(int i=1;i<=n;i++)
    {
        dfs(i,w[i]);    
    }
    cout<<ans<<endl;

    return 0;
}
