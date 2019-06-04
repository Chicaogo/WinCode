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

    for(int i = 1;i <= n;++i)
        dp[n][i] = num[n][i];

    for(int i = n-1;i > 0;--i)
        for(int j = 1;j <= i;++j)
            dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + num[i][j];

    cout << dp[1][1] << endl;

    system("pause");
    return 0;
}