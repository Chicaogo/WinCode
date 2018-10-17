#include<bits/stdc++.h>
using namespace std;

int mapp[250][250],n,m,dp[250][250];

int main(int argc, char const *argv[])
{
    cin >> m >> n;
    int mid = n/2 + 1;
    
    memset(mapp,-9999,sizeof(mapp));
    
    for(int i = 1;i <= m;++i)
    {
        for(int j = 1;j <= n;++j)
        {
            cin >> mapp[i][j];
        }
    }
    
    for(int i = 1;i <= m;++i)
    {
        for(int j = 1;j <= n;++j)
        {
            dp[i][j] = max(max(dp[i-1][j],dp[i-1][j-1]),dp[i-1][j+1])+mapp[i][j];
            //cout << dp[i][j]<<" ";
        }
        cout << endl;
    }

    cout<<max(max(dp[m][mid],dp[m][mid-1]),dp[m][mid+1]);

    return 0;
}
