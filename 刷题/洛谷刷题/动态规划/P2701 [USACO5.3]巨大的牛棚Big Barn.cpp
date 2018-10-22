#include<bits/stdc++.h>
using namespace std;

int n,m,mapp[1010][1010];
int dp[1010][1010];

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
    {
        int x,y;
        cin >> x >> y;
        mapp[x][y] = 1;
    }

    int maxx = -1;

    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= n;++j)
        {
            if(!mapp[i][j])
            {
                dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
            }
            maxx = max(maxx,dp[i][j]);
        }
    }

    cout << maxx;

    return 0;
}
