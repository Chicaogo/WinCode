#include<bits/stdc++.h>
using namespace std;

const int inf = ~(1<<31);
int num[520];
bool qwq[520];
int n,a,b,ans = inf;

void dfs(int now,int cnt)
{
    if(now == b) ans = min(ans,cnt);
    if(cnt < ans)
    {
        qwq[now] = true;
        if(now + num[now] <= n && !qwq[now+num[now]]) dfs(now+num[now],cnt+1);
        if(now - num[now] >= 1 && !qwq[now-num[now]]) dfs(now-num[now],cnt+1);
        qwq[now] = false;
    }
}


int main(int argc, char const *argv[])
{
    qwq[1] = 1;
    
    cin >> n >> a >> b;

    for(int i=1;i<=n;i++) cin >> num[i];

    dfs(a,0);

    if(ans == inf) cout << "-1";
    else cout << ans;

    return 0;
}
