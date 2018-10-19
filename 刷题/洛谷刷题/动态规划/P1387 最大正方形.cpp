#include<bits/stdc++.h>
using namespace std;

int mapp[110][110],dp[110][110];
int n,m,ans = 0;

int main(int argc, char const *argv[])
{
    cin >> n >> m;

    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= m;++j)
        {
            cin >> mapp[i][j];
        }
    }

    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= m;++j)
        {
            if(mapp[i][j]) dp[i][j] = min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
            ans = max(ans,dp[i][j]);
        }
    }

    cout << ans;

    return 0;
}
