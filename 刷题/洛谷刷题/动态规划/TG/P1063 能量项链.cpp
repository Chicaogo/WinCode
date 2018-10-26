#include<bits/stdc++.h>
using namespace std;

int head[520],tail[520],dp[520][520];
int n,ans;

inline void init()
{
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        cin >> head[i];
        head[i+n] = head[i];
    }
    for(int i = 1;i <= 2*n-1;++i)
    {
        tail[i] = head[i+1];
    }
    tail[2*n] = head[1];
}

inline void DP()
{
    for(int i=1;i<=2*n-1;i++) dp[i][i]=0;
    for(int q=1;q <= n-1;++q)
    {
        for(int i = 1;i <= 2*n-q;++i)
        {
            int j = i+q;
            for(int k = i;k <= j-1;++k)
                dp[i][j] = max(dp[i][j],dp[i][k] + dp[k+1][j] + head[i] * tail[k] * tail[j]);
        }
    }
}

inline void outqwq()
{
    for(int i = 1;i <= n;++i)
    {
        ans = max(ans,dp[i][i+n-1]);
    }
    cout << ans;
}

int main(int argc, char const *argv[])
{
    init();
    DP();
    outqwq();
    return 0;
}
