#include<bits/stdc++.h>
using namespace std;

const int maxn = 10010;
const int maxn = 10010;
int n,m,tong[maxm],ans;
bool vis[maxn],love[maxn][maxm];

inline void init()
{
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
    {
        int x; cin >> x;
        for(int j = 1;j <= x;++j)
        {
            int qwq; cin >> qwq;
            love[x][qwq] = true;
        }
    }
}

bool dfs(int x)
{
    for(int i = 1;i <= m;++i)
    {
        if(!vis[i] && love[x][i])
        {
            vis[i] = true;
            if(tong[i]==0 || dfs(tong[i]))
            {
                tong[i] = x;
                return true;
            }
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    init();
    
    for(int i = 1;i <= m;++i)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i)) ans++;
    }

    cout << ans;

    return 0;
}
