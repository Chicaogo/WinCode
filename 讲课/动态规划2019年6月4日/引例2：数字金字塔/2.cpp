#include<bits/stdc++.h>
using namespace std;

int n,num[101][101];
int dp[101][101];
int ans;

int dfs(int x,int y)
{
    if(dp[x][y]) return dp[x][y];
    if(x == n) return dp[x][y] = num[x][y];
    return dp[x][y] = max(dfs(x+1,y),dfs(x+1,y+1))+num[x][y];
}

int main(void)
{
    cin >> n;

    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= i;++j)
            cin >> num[i][j];

    cout << dfs(1,1) << endl;

    system("pause");
    return 0;
}