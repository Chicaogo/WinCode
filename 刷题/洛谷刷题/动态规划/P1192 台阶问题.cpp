#include<bits/stdc++.h>
using namespace std;

const int mod = 100003;
int dp[100010],n,k;

int dfs(int x)
{
    if(x == 0) return 1;
    if(dp[x]!=-1) return dp[x];
    int ans = 0;
    for(int i = 1;i <= max(min(x,k),1);++i)
        ans = (ans + dfs(x - i))%mod;

    dp[x] = ans;
    return ans;
}

inline void init()
{
    memset(dp,-1,sizeof(dp));
    dp[0] = 1;
    cin >> n >> k;
    cout << dfs(n) % mod;
}

int main(int argc, char const *argv[])
{
    init();
    return 0;
}