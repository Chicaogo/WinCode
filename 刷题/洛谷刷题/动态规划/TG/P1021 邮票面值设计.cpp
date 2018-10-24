#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int maxn = 20;
int k,n,ans=0;
int dp[maxn*100],num[maxn],qwq[maxn];

void dfs(int x)
{
    if(x==k+1)
    {
        memset(dp,0,sizeof(dp));
        int i=0;
        while(dp[i]<=n)
        {
            i++;
            dp[i]=INF;
            for(int j=1;j<=k&&i-num[j]>=0;j++)
            {
                dp[i]=min(dp[i],dp[i-num[j]]+1);
            }
        }
        if(i-1>ans)
        {
            for(int j=1;j<=k;j++)
            {
                qwq[j]=num[j];
                ans=i-1;
            }
        }
        return;
    }
    for(int i=num[x-1]+1;i<=num[x-1]*n+1;i++)
    {
        num[x]=i;
        dfs(x+1);
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> k;

    num[1] = 1;
    dfs(2);
    
    for(int i = 1;i <= k;++i) cout << qwq[i] << " ";

    cout << endl <<"MAX="<< ans;

    return 0;
}
