#include<bits/stdc++.h>
using namespace std;

int dp1[100010],dp2[100010];
int num[100010];
int cnt = 0;
int ans1,ans2;

int main(int argc, char const *argv[])
{
    while(scanf("%d",&num[++cnt]) != EOF) continue;

    for(int i=1;i<=cnt;++i)
    {
        dp1[i] = 1;
        for(int j=1;j <= i;++j)
        {
            if(num[j] > num[i]) dp1[i] = max(dp1[i],dp1[j]+1);
        }
        ans1 = max(dp1[i],ans1);
    }

    cout << ans1 <<endl;
    
    
    for(int i=1;i<=cnt;++i)
    {
        dp2[i] = 1;
        for(int j=1;j <= i;++j)
        {
            if(num[j] > num[i]) dp2[i] = max(dp2[i],dp2[j]+1);
        }
        ans2 = max(dp2[i],ans2);
    }

    cout << ans2 <<endl;

    return 0;
}
