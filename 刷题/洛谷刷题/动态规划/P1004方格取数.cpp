#include<bits/stdc++.h>
using namespace std;

long long dp[10][10][10][10];
int mapp[10][10];
long long ans;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            mapp[i][j] = 0;

    bool cnt = 1;
    while(cnt)
    {
        int x,y,osu;
        cin >> x >> y >> osu;
        if(x==0 && y==0 && osu==0) cnt = 0;
        else mapp[x][y] = osu;
    }

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            for(int k=1;k<=n;++k)
            {
                for(int l=1;l<=n;++l)
                {
                    dp[i][j][k][l]=max(dp[i-1][j][k-1][l],max(dp[i][j-1][k][l-1],max(dp[i-1][j][k][l-1],dp[i][j-1][k-1][l])))+mapp[i][j]+mapp[k][l];
                    if(i == k && j == l) dp[i][j][k][l] -= mapp[i][j];
                }
            }
        }
    }
    
    printf("%d\n",dp[n][n][n][n]);

    return 0;
}