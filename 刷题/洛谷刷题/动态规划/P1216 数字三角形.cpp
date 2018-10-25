#include<bits/stdc++.h>
using namespace std;

int mapp[10010][10010],dp[10010][10010];
int n;

void init()
{
    cin >> n;
    
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= i;++j)
        {
            cin >> mapp[i][j];
        }
    }
}

void DP()
{
    for(int i = n;i >=1;i--)
    {
        for(int j = 1;j <= i;++j)
        {
            dp[i][j] = max(dp[i+1][j+1],dp[i+1][j])+mapp[i][j];
        }
    }
    cout << dp[1][1];
}

int main(int argc, char const *argv[])
{
    init();
    DP();
    return 0;
}