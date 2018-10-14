#include<bits/stdc++.h>
using namespace std;

const int maxn = 100010;
const long long mo = 1e9 + 7;

long long ans = 0;
int dp[maxn][maxn],xx[maxn],cnt = 0;
int n , m , k;

void dfs(int x,int y,int num)
{
    if(num == 0 && n+m-2 == cnt) ans=ans%mo+1;
    if(n+m-2 != cnt)
    {
        cnt++;
        if(xx[x])
        {
            if(dp[x][y+1]) num--;
            dfs(x,y+1,num);
            xx[x]--;
        }
        else
        {
            dfs(x+1,y,num);
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> m >> k;
    int maxx = 0 , maxy = 0;
    for(int i = 1 ;i <= k;++i)
    {
        int x,y;
        cin >> x >> y;
        dp[x][y] = 1;
        xx[x] ++;
    }

    dfs(1,1,k);
    cout << ans;

    getchar();getchar();getchar();
    return 0;
}
