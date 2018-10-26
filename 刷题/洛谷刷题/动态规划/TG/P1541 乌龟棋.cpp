#include<bits/stdc++.h>
using namespace std;

const int maxn = 66;
int dp[maxn][maxn][maxn][maxn],tong[5];
int num[maxn*10],n,m;

inline void init()
{
    cin >> n >> m;
    for(int i = 1;i <= n;++i) cin >> num[i];
    dp[0][0][0][0] = num[1];
    for(int i = 1;i <= m;++i)
    {
        int x = 0;
        cin >> x;
        tong[x]++;
    }
}

inline void DP()
{
    for(int a = 0;a <= tong[1];++a)
    for(int b = 0;b <= tong[2];++b)
    for(int c = 0;c <= tong[3];++c)
    for(int d = 0;d <= tong[4];++d)
    {
        int l = a + b*2 +c*3 + d*4 + 1;
        if(a) dp[a][b][c][d] = max(dp[a][b][c][d],dp[a-1][b][c][d]+num[l]);
        if(b) dp[a][b][c][d] = max(dp[a][b][c][d],dp[a][b-1][c][d]+num[l]);
        if(c) dp[a][b][c][d] = max(dp[a][b][c][d],dp[a][b][c-1][d]+num[l]);
        if(d) dp[a][b][c][d] = max(dp[a][b][c][d],dp[a][b][c][d-1]+num[l]);
    }
    cout << dp[tong[1]][tong[2]][tong[3]][tong[4]];
}

int main(int argc, char const *argv[])
{
    init();
    DP();
    return 0;
}