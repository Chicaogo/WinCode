#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000005;
int bp,n;
int a[maxn],dp[maxn][2],g[maxn];

int main(void) 
{
    scanf("%d %d", &n,&bp);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    int now=0;
    for (int i=1;i<=n;i++)
    {
        if ((1 << (now+1))<=i) ++now;
        g[i]=now;
    }
    int t = 0;
    printf("0\n");
    now = 2;
    for (int j = 0; (1 << j) <= bp; ++j) 
    {
        t = 1 - t;
        if (j == 0) 
            for (int i = 1; i <= n; ++i) dp[i][t] = a[i];
        else 
            for (int i = 1; i <= n - (1 << j) + 1; ++i) 
                dp[i][t] = min(dp[i][1 - t], dp[i + (1 << (j - 1))][1 - t]);
        while (now <= n && min(now - 1, bp) < (1 << (j + 1))) 
        {
            int l=now-bp;
            if (l<=0) l=1;
            int r=now-1;
            int x = g[r - l + 1];
            int ans = min(dp[l][t], dp[r - (1 << x) + 1][t]);
            printf("%d\n",ans);
            ++now;
        }
    }
    return 0;
}