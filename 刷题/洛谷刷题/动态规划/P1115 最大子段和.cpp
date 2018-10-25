#include<bits/stdc++.h>
using namespace std;

int n,dp[200010],num,ans = -9999999;

int main(int argc, char const *argv[])
{
    cin >> n;

    for(int i = 1;i <= n;++i)
    {
        cin >> num;
        dp[i] = max(dp[i-1]+num,num);
        ans = max(dp[i],ans);
    }

    cout<< ans <<endl;
    
    getchar();getchar();getchar();
    return 0;
}