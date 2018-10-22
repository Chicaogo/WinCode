#include<bits/stdc++.h>
using namespace std;

const int maxx = 1e3+10;
int n,cnt = 0,fa[maxx*maxx];

struct edge{
    int u,v,w;
    bool operator < (const edge &qwq)
    {
        return w < qwq.w;
    }
}G[maxx*maxx];

inline void init()
{
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        int w;
        cin >> w;
        G[++cnt].u = 0;
        G[cnt].v = i;
        G[cnt].w = w;
    }
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= n;++j)
        {
            int w;
            cin >> w;
            if(i > j)
            {
                G[++cnt].u = i;
                G[cnt].v = j;
                G[cnt].w = w;
            }
        }
    }
    for(int i = 1;i <= cnt;++i) fa[i] = i;
}    

inline int fin(int x)
{
    return fa[x] == x ? x : fa[x] = fin(fa[x]);
}

inline int kul()
{
    sort(G+1,G+cnt+1);
    int ans = 0,qwq = 0;
    
    for(int i = 1;i <= cnt;++i)
    {
        int x = fin(G[i].u),y = fin(G[i].v);
        if(x != y)
        { 
            fa[x] = y;
            ++qwq;
            ans += G[i].w;
        }
        if(qwq == n) break;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    init();
    cout << kul();
    return 0;
}
