#include<bits/stdc++.h>
using namespace std;

int root;
int n,dp[6666][2],vis[6666],h[6666];
vector<int> son[6666];

void DP(int x);

inline void init()
{
    cin >> n;
    for(int i = 1;i <= n;++i) cin >> h[i];
    for(int i = 2;i <= n;++i)
    {
        int x,y;
        cin >> x >> y;
        vis[x] = 1;
        son[y].push_back(x);
    }
    for(int i = 1;i <= n;++i)
    {
        if(!vis[i])
        {
            root = i;
            break;
        }
    }
    DP(root);
}

void DP(int x)
{
    dp[x][0] = 0;
    dp[x][1] = h[x];
    for(int i = 0;i < son[x].size();++i)
    {
        int y = son[x][i];
        DP(y);
        dp[x][0] += max(dp[y][0],dp[y][1]);
        dp[x][1] += dp[y][0];
    }
}

int main(int argc, char const *argv[])
{
    init();
    cout << max(dp[root][1],dp[root][0]);
    getchar();getchar();getchar();
    return 0;
}