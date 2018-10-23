#include<bits/stdc++.h>
using namespace std;

int dp[10010],tong[10010];
int n,k;

struct qwq
{
    int begin,end;
    bool operator < (const qwq &waw)
    {
        return begin > waw.begin;
    }
}num[10010];


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);//输出速度优化 

    cin >> n >> k;

    for(int i = 1;i <= k;++i)
    {
        cin >> num[i].begin >> num[i].end;
        tong[num[i].begin]++;
    }
    
    sort(num+1,num+k+1);

    int x = 1;

    for(int i = n;i>=1;i--)
    {
        if(!tong[i])
        {
            dp[i] = dp[i+1] + 1;
        }
        else
            for(int j = 1;j <= tong[i];j++)
            {
                dp[i]=max(dp[i],dp[i+num[x].end]);
                x++;
            }
    }

    cout << dp[1] ;

    return 0;
}
