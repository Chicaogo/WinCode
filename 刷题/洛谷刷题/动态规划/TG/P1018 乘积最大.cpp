#include<bits/stdc++.h>
using namespace std;

long long dp[45][45],num[45][45];
bool tong[45][45];
int n,k;
char ch[45];

inline void init()
{
    cin >> n >> k;
    cin >> ch;

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(i <= j)
            {
                for(int k = i;k <= j;k++)
                {
                    num[i][j]*=10;
                    num[i][j]+=ch[k]-'0';
                }
            }
        }
    }
}

long long dfs(int n,int k)
{
    if(k == 0) return num[0][n-1];
    if(tong[n-1][k-1]) return dp[n-1][k-1];

    for(int i = k;i < n;i++)
        dp[n-1][k-1] = max(dp[n-1][k-1],dfs(i,k-1)*num[i][n-1]);

    tong[n-1][k-1] = true;

    return dp[n-1][k-1];
}

int main(int argc, char const *argv[])
{
    init();
    cout << dfs(n,k);
    getchar();getchar();getchar();
    return 0;
}