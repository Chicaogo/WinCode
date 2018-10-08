#include<bits/stdc++.h>
using namespace std;

long long dp[51][51][51][51];
int mapp[51][51];
long long ans;

int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n >> m;

    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin >> mapp[i][j];

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            for(int k=1;k<=n;++k)
            {
                for(int l=j+1;l<=m;++l)
                {
                    dp[i][j][k][l]=max(dp[i-1][j][k-1][l],max(dp[i][j-1][k][l-1],max(dp[i-1][j][k][l-1],dp[i][j-1][k-1][l])))+mapp[i][j]+mapp[k][l];
                }
            }
        }
    }
    
    printf("%lld\n",dp[n][m-1][n-1][m]);

    return 0;
}