#include<bits/stdc++.h>
using namespace std;

const int maxn = 10010;
int n,num[maxn],dp[maxn][2][2];

int main(int argc, char const *argv[])
{
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> num[i];

    dp[0][0][0] = dp[0][0][1] = 1;

    for(int i = 1;i <= n;++i)
    {
        if(num[i] == 0)
        {
            dp[i][0][0] += dp[i-1][0][0];
        }
        
        if(num[i] == 1)
        {
            dp[i][1][0] += dp[i-1][0][1];
            dp[i][0][0] += dp[i-1][1][0];
            dp[i][0][1] += dp[i-1][0][0];
        }

        if(num[i] == 2)
        {
            dp[i][0][1] += dp[i-1][1][0];
            dp[i][1][1] += dp[i-1][0][0];
            dp[i][1][0] += dp[i-1][1][1];
        }
        if(num[i] == 3)
        {
            dp[i][1][1] += dp[i-1][1][1];
        }
    }

    int ans = dp[n][0][0] + dp[n][1][0];

    cout << ans;

    return 0;
}
