#include<bits/stdc++.h>
using namespace std;

int n,num[101][101];
int dp[101][101];
int ans;

int main(void)
{
    cin >> n;

    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= i;++j)
            cin >> num[i][j];

    dp[1][1] = num[1][1];

    for(int i = 2;i <= n;++i)
        for(int j = 1;j <= i;++j)
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + num[i][j];
    
    for(int i = 1;i <= n;++i)
        ans = max(ans,dp[n][i]);

    cout << ans << endl;

    system("pause");
    return 0;
}