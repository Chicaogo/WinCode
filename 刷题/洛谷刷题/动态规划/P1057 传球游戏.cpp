#include<bits/stdc++.h>
using namespace std;
int n,m,dp[100][100];

void init();
void DP();

inline void init()
{
    cin >> n >> m;
    dp[0][1] = 1;dp[1][n] = 1;dp[1][2] = 1;
    DP();
}

inline void DP()
{
    for(int i = 1;i <= m;++i)
    {
        for(int j = 1;j <= n;++j)
        {
            if(j == 1) dp[i][j] = dp[i-1][n] + dp[i-1][2];
            else if(j == n) dp[i][j] = dp[i-1][n-1] + dp[i-1][1];
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
        }
    }
    cout << dp[m][1];
}

int main(int argc, char const *argv[])
{
    init();
    return 0;
}