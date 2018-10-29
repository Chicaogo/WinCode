#include <bits/stdc++.h>
using namespace std;

const int maxn = 150010;
int n,ans;
int dp[maxn];   

struct qwq
{
    int l,r;

    int len()
    {
        return r-l+1;
    }

    bool operator < (const qwq &a)
    {
        if(r == a.r) return l < a.l;
        return r < a.r;
    }
}num[maxn];

inline void init()
{
    cin >> n;
    for(int i = 0;i < n;++i)
        cin >> num[i].l >> num[i].r;

    sort(num,num+n);
}

inline void DP()
{
    for(int i = 0;i < n;++i)
    {
        int maxn = 0;
        for(int j = 0;j <= i;++j)
        {
            if(num[j].r < num[i].l)
                maxn = max(maxn,dp[j]);
        }
        dp[i] = maxn + num[i].len();
        ans = max(ans,dp[i]);
    }
}

int main(int argc, char const *argv[])
{
    init();
    DP();
    cout << ans;
    return 0;
}
