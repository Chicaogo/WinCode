#include<bits/stdc++.h>
using namespace std;

int n,k,ans = 0;

void dfs(int x,int sum,int cnt)
{
    if(cnt == k)
    {
        if(sum == n) ans++;
        return;
    }
    else
    {
        for(int i = x;sum+i*(k-cnt) <= n;++i)
        {
            dfs(i,sum+i,cnt+1);
        }
    }
}


int main(int argc, char const *argv[])
{
    cin >> n >> k;

    dfs(1,0,0);

    cout << ans;
    
    return 0;
}
