#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
const int MAXW = 10000;

int dp[MAXN][MAXW];
int w[MAXN],v[MAXN];
int n,W;

int main(int argc, char const *argv[])
{
    cin >> n >> W;
    
    for(int i=0;i<n;++i) cin >> w[i] >> v[i];
    
    for(int i=n-1;i>=0;--i)
    {
        for(int j=0;j<=W;++j)
        {
            if(j < w[i]) dp[i+1][j] = dp[i][j];
            else dp[i][j] = max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);
        }
    }

    printf("%d",dp[0][W]);

    getchar();getchar();getchar();
    return 0;
}

/*
4 5
2 3
1 2
3 4
2 2

7
*/